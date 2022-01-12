#pragma once
#include <drogon/HttpSimpleController.h>

using namespace drogon;

class LoginController : public HttpSimpleController<LoginController> {
   public:
    virtual void asyncHandleHttpRequest(
        const HttpRequestPtr &req,
        std::function<void(const HttpResponsePtr &)> &&callback) override;
    PATH_LIST_BEGIN
    PATH_ADD("/login", Post);
    PATH_LIST_END
};
