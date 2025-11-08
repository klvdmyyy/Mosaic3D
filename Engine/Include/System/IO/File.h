#pragma once

#include <fstream>
#include <string>
#include <vector>

namespace System
{
	namespace IO
	{
		class File
		{
		private:
			std::fstream m_fstream;
			std::string m_filepath;

		public:
			File(const std::string& filepath);
			~File();

			inline bool IsOpen() const { return m_fstream.is_open(); }

			std::vector<char> ReadBytes();
		};
	}
}