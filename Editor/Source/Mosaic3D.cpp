#include "Editor.h"

#include <iostream>

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

int main()
{
	System::Logger::AddSink("Editor", std::make_unique<ConsoleSink>());

	System::Logger::AddSink("WSI/Window", std::make_unique<ConsoleSink>());

	System::Logger::AddSink("GI", std::make_unique<ConsoleSink>());
	System::Logger::AddSink("GI/OpenGL", std::make_unique<ConsoleSink>());
	return Editor().Run();
}