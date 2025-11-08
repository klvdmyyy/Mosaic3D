add_library(assimp INTERFACE)

target_link_directories(assimp INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/lib/x64)
target_include_directories(assimp INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(assimp INTERFACE assimp-vc143-mt.lib)