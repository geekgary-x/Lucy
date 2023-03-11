#pragma once
#include <boost/smart_ptr/shared_ptr.hpp>
#include <boost/smart_ptr/make_shared.hpp>

class GLFWwindow;

namespace Lucy
{
	class MainWindow
	{
	public:
		friend boost::shared_ptr<MainWindow> boost::make_shared<MainWindow>();
	public:
		MainWindow(MainWindow&) = delete;
		static boost::shared_ptr<MainWindow> getMainWindow();
		void loop();
		~MainWindow();
	private:
		MainWindow();

		static boost::shared_ptr<MainWindow> s_MainWindow;

		GLFWwindow* m_GLFWwindow;
	};
}