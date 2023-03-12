#pragma once
#include <Lucy/Core/Singleton.hpp>
class GLFWwindow;
namespace Lucy
{
	class MainWindow : public Singleton<MainWindow>
	{
	public:
		friend boost::shared_ptr<MainWindow> boost::make_shared<MainWindow>();
	public:
		void loop();
		~MainWindow();
	private:
		MainWindow();
		GLFWwindow* m_GLFWwindow;
	};
}