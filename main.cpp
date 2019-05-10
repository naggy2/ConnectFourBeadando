#include "graphics.hpp"
#include "Application.h"
#include "Connectfour.h"

#include "Statictext.h"

int main()
{
    auto app = CreateApplication(400,400);
    app->Run();
    delete app;

}
