#include <drogon/drogon.h>
int main() {
    drogon::app().loadConfigFile("../config.jsonc").run();
    return 0;
}
