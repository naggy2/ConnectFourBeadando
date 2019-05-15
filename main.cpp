#include "Application.h"

int main()
{
    auto app = CreateApplication(400,400);
    //app->setBackgroundColor();
    app->Run();
    delete app;

}
