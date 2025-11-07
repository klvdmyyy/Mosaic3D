# CMakeList.txt: проект CMake для Mosaic3D; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

# Включение горячей перезагрузки для компиляторов MSVC, если поддерживается.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project(Mosaic3D)

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS TRUE)

set(MOSAIC_BINARIES_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/Binaries)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${MOSAIC_BINARIES_DIRECTORY})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${MOSAIC_BINARIES_DIRECTORY})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${MOSAIC_BINARIES_DIRECTORY})
set(CMAKE_PDB_OUTPUT_DIRECTORY ${MOSAIC_BINARIES_DIRECTORY}/PDB)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED 20)

add_subdirectory(ThirdParty/glfw-3.4)

add_subdirectory(Engine)
add_subdirectory(Editor)
