#pragma once
#include <Lucy/Core/Singleton.hpp>
namespace vk
{
	namespace raii
	{
		namespace su
		{
			struct SurfaceData;
		}
	}
}

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
		boost::shared_ptr<vk::raii::su::SurfaceData> m_surface;
	};
}