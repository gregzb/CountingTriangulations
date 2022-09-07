cmake_minimum_required(VERSION 3.22)

project(CountingTriangulations)

add_executable(countingTriangulations main.cpp Point.cpp Polygon.cpp CountTriangulations.cpp Vec.cpp Utils.cpp)

find_package(SFML COMPONENTS window graphics audio system REQUIRED)

target_compile_features(countingTriangulations PUBLIC cxx_std_17)

target_link_libraries(countingTriangulations sfml-window sfml-graphics sfml-audio sfml-system)

add_compile_options(-fsanitize=address)
add_link_options(-fsanitize=address)

add_custom_command(TARGET countingTriangulations PRE_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy_directory
                       ${CMAKE_SOURCE_DIR}/resources/ $<TARGET_FILE_DIR:countingTriangulations>/resources)