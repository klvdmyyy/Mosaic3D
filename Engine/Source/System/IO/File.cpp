#include "System/Logger.h"
#include "System/IO/File.h"

namespace System
{
	namespace IO
	{
		File::File(const std::string& filepath)
			: m_filepath(filepath)
		{
			m_fstream.open(filepath);
			if (!m_fstream.is_open())
			{
				Logger::Log(LogLevel::Error, "Failed to open file: {}", filepath);
			}
		}

		File::~File()
		{
			if (m_fstream.is_open())
			{
				m_fstream.close();
			}
		}

		std::vector<char> File::ReadBytes()
		{
			Logger::Log(LogLevel::Info, "Reading a bytes of the file: {}", m_filepath);
			std::vector<char> buffer;
			try
			{
				size_t fileSize = static_cast<size_t>(m_fstream.tellg());
				buffer.resize(fileSize);

				m_fstream.seekg(0);
				m_fstream.read(buffer.data(), fileSize);

				return buffer;
			}
			catch (std::ifstream::failure e)
			{
				Logger::Log(LogLevel::Critical, "Error reading a bytes of the file \'{}\'. Error message: {}", m_filepath, e.what());
				return {};
			}

			return buffer;
		}
	}
}