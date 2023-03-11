#include <iostream>
#include "Core/test.h"
#include <UI/MainWindow.h>
int main(int argc, char *argv[])
{
    auto mainwindow = Lucy::MainWindow::getMainWindow();
    mainwindow->loop();
}
