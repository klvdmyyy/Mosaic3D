add_executable(MosaicEditor Source/Mosaic3D.cpp "Source/Editor.h" "Source/Editor.cpp")

target_link_libraries(MosaicEditor PRIVATE
	MosaicSystem
	MosaicGI)