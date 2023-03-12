#include <iostream>
#include <Lucy/UI/MainWindow.h>
int main(int argc, char *argv[])
{
    auto mainwindow = Lucy::Singleton<Lucy::MainWindow>::getInstance();
    mainwindow->loop();
}
