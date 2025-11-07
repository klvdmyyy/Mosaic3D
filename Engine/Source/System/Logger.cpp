#include "System/Logger.h"

#include <iostream>
#include <chrono>
#include <fstream>

using std::chrono::system_clock;

static std::ofstream gLogFile{};

namespace System
{
	[[nodiscard]]
	std::string LogSink::LogLevelToString(LogLevel level) noexcept
	{
		switch (level)
		{
		case LogLevel::Debug: return "Debug";
		case LogLevel::Info: return "Info";
		case LogLevel::Warning: return "Warning";
		case LogLevel::Error: return "Error";
		case LogLevel::Critical: return "Critical";
		default: return "Unknown";
		}
	}
	void Logger::AddSink(const std::string& category, std::unique_ptr<LogSink> sink)
	{
		std::lock_guard<std::mutex> syncGuard(Instance().mSync);
		Instance().mSinks[category].push_back(std::move(sink));
	}

	void Logger::WriteLog(LogLevel level, const std::string& category, const std::string& message)
	{
		std::lock_guard<std::mutex> syncGuard(Instance().mSync);
		auto it = Instance().mSinks.find(category);
		if (it != Instance().mSinks.end())
		{
			for (auto& sink : it->second)
			{
				sink->Log(level, category, message);
			}
		}
	}
}
