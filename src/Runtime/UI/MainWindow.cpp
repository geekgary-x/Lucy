#include "MainWindow.h"
#include <iostream>
namespace Lucy
{
	boost::shared_ptr<MainWindow> MainWindow::s_MainWindow = nullptr;
	boost::shared_ptr<MainWindow> MainWindow::getMainWindow()
	{
		if (s_MainWindow==nullptr)
		{
			s_MainWindow = boost::make_shared<MainWindow>();
		}
		return s_MainWindow;
	}
	void MainWindow::loop()
	{
		
	}

	MainWindow::~MainWindow()
	{
		std::cout << "MainWindow destoried" << std::endl;
	}

}