#include "Application.h"

int main()
{
    auto app = CreateApplication(500,500);
    app->Run();
    delete app;

}
