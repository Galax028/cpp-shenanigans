#pragma once
#include <drogon/HttpSimpleController.h>

using namespace drogon;

class AuthController : public HttpSimpleController<AuthController> {
   public:
    virtual void asyncHandleHttpRequest(
      const HttpRequestPtr &req,
      std::function<void(const HttpResponsePtr &)> &&callback) override;
    PATH_LIST_BEGIN
    PATH_ADD("/home", Get);
    PATH_LIST_END
};
