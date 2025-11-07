#include "Editor.h"

#include <iostream>
#include <chrono>
#include <thread>

class ConsoleSink : public System::LogSink
{
public:
	void Log(System::LogLevel level, const std::string& category, const std::string& message) override
	{
		std::cout <<
			std::format("[{}]:[{}] {}", LogLevelToString(level), category, message)
			<< std::endl;

		if (level == System::LogLevel::Critical)
		{
			throw std::runtime_error("Runtime exception catched. See logs for more info.");
		}
	}
};

Editor::Editor() : mWindow({ 800, 600 }, "Mosaic3D")
{
	System::Logger::AddSink("Editor", std::make_unique<ConsoleSink>());
}

Editor::~Editor()
{
}

int Editor::Run()
{
	try
	{
		std::this_thread::sleep_for(std::chrono::seconds(2));
		return 0;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}
}