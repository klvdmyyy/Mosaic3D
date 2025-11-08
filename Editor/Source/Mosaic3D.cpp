#include "Editor.h"

#include <iostream>

#include "System/IO/File.h"

class ConsoleSink : public System::LogSink
{
private:
	System::LogLevel m_minLevel = System::LogLevel::Info;

public:
	ConsoleSink() {}
	ConsoleSink(System::LogLevel level) : m_minLevel(level) {}

	void Log(System::LogLevel level, const std::string& category, const std::string& message) override
	{
		if (level < m_minLevel) return;

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
	// Initialize logger sinks and categories.
	System::Logger::AddSink("Editor", std::make_unique<ConsoleSink>());

	System::Logger::AddSink("System", std::make_unique<ConsoleSink>());
	System::Logger::AddSink("System/IO", std::make_unique<ConsoleSink>(System::LogLevel::Warning));
	System::Logger::AddSink("System/Math", std::make_unique<ConsoleSink>(System::LogLevel::Warning));

	System::Logger::AddSink("WSI/Input", std::make_unique<ConsoleSink>(System::LogLevel::Debug));
	System::Logger::AddSink("WSI/Window", std::make_unique<ConsoleSink>());

	System::Logger::AddSink("GI", std::make_unique<ConsoleSink>());
	System::Logger::AddSink("GI/OpenGL", std::make_unique<ConsoleSink>());

	// Run application.
	return Editor().Run();
}