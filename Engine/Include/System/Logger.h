#pragma once

#include <string>
#include <format>
#include <mutex>
#include <unordered_map>
#include <vector>
#include <memory>

namespace System
{
	enum class LogLevel
	{
		Debug,
		Info,
		Warning,
		Error,
		Critical,
	};

	class LogSink
	{
	public:
		[[nodiscard]]
		virtual std::string LogLevelToString(LogLevel level) noexcept;
		virtual void Log(LogLevel level, const std::string& category, const std::string& message) = 0;
	};

	class Logger
	{
	private:
		std::unordered_map<std::string, std::vector<std::unique_ptr<LogSink>>> mSinks{};
		std::mutex mSync{};

		static Logger& Instance()
		{
			static Logger instance{};
			return instance;
		}

		void WriteLog(LogLevel level, const std::string& category, const std::string& message);
	public:

		static void AddSink(const std::string& category, std::unique_ptr<LogSink> sink);

		template<class... Args>
		static void Log(LogLevel level, const std::string& category, std::string_view fmt, Args&& ...args)
		{
			Instance().WriteLog(level, category, std::vformat(fmt, std::make_format_args(args...)));
		}
	};
}

#undef DEFINE_LOG_FUNCTION