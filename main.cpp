#include "Application.h"
#include "stdio.h"

int main(void)
{
    Application *app = new Application();
    app->init();
    app->start();

    sleep(1);
    app->stop();
    return 0;
}
