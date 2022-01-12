#include "LoginController.h"

#include <jwt-cpp/jwt.h>

#include <chrono>

void LoginController::asyncHandleHttpRequest(
    const HttpRequestPtr &req,
    std::function<void(const HttpResponsePtr &)> &&callback) {
    const std::string realPassword = "DBBC0924E02D3397E4846E1A78C087C2";  // salt + Password1
    std::string username = req->getParameter("user");
    std::string passwd = req->getParameter("passwd");

    HttpResponsePtr res401 = HttpResponse::newHttpResponse();
    res401->setStatusCode(k401Unauthorized);
    res401->setBody("401 Unauthorized");

    if (username != "galax") {
        return callback(res401);
    }
    if (utils::getMd5("salt" + passwd) == realPassword) { // Do not use MD5 in a real application
        auto token = jwt::create()
                         .set_issuer("galax")
                         .set_type("JWT")
                         .set_payload_claim("username", jwt::claim(username))
                         .set_expires_at(std::chrono::system_clock::now() + std::chrono::hours{2})
                         .sign(jwt::algorithm::hs256{"very secretive token"});
        HttpResponsePtr res = HttpResponse::newRedirectionResponse("/home");
        res->addHeader("Set-Cookie", "token=" + std::string(token) + "; HttpOnly; SameSite=Strict"); // Secure way to store JWT tokens and prevents CSRF
        return callback(res);
    } else {
        return callback(res401);
    }
}
