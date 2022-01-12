#include "AuthController.h"

#include <jwt-cpp/jwt.h>

void AuthController::asyncHandleHttpRequest(
    const HttpRequestPtr &req,
    std::function<void(const HttpResponsePtr &)> &&callback) {
    try {
        auto token = jwt::decode(req->getCookie("token"));
        auto verifier = jwt::verify()
                            .allow_algorithm(jwt::algorithm::hs256{"very secretive token"})
                            .with_issuer("galax");
        verifier.verify(token);
    } catch (...) {
        HttpResponsePtr res = HttpResponse::newHttpResponse();
        res->setStatusCode(k401Unauthorized);
        res->setBody("401 Unauthorized");
        return callback(res);
    }
    auto token = jwt::decode(req->getCookie("token"));
    HttpResponsePtr res = HttpResponse::newHttpResponse();
    res->setBody("Hello, " + token.get_payload_claims()["username"].as_string());
    return callback(res);
}
