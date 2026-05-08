#include <iostream>
#include <zwindow.h>
#include <qguiapplication.h>
#include <vulkan/vulkandevice.h>

int main(int argc, char* argv[])
{
	QGuiApplication app (argc, argv);

	zwin::WindowConfig winConfig{};
	auto pWin = zwin::ZWindow::Create(winConfig);
	pWin->show();

	return app.exec();
}