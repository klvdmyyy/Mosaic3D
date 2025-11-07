
macro(add_engine_module NAME)
	add_library("Mosaic${NAME}" SHARED)

	file(GLOB_RECURSE MOSAIC_${NAME}_SOURCES
		${CMAKE_CURRENT_SOURCE_DIR}/Include/${NAME}/*.cpp
		${CMAKE_CURRENT_SOURCE_DIR}/Source/${NAME}/*.cpp)

	target_sources("Mosaic${NAME}" PRIVATE ${MOSAIC_${NAME}_SOURCES})
	target_include_directories("Mosaic${NAME}" PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/Source/${NAME})
	target_include_directories("Mosaic${NAME}" PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Include)
endmacro()

add_engine_module(System)

add_engine_module(GI)
target_link_libraries(MosaicGI PRIVATE glfw)