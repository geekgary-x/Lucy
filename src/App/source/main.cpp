#include <iostream>
#include "Core/test.h"
#include <Lucy/UI/MainWindow.h>
int main(int argc, char *argv[])
{
    auto mainwindow = Lucy::MainWindow::getMainWindow();
    mainwindow->loop();
}
