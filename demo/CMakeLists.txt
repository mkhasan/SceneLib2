

set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find the Pangolin library installed on your system
#find_package(Pangolin REQUIRED)
find_package(Pangolin 0.8 REQUIRED)
include_directories(${Pangolin_INCLUDE_DIRS})
#link_directories(${Pangolin_LIBRARY_DIRS})
link_libraries(${Pangolin_LIBRARIES})

message(STATUS "Pangolin version: ${Pangolin_VERSION}")
message(STATUS "Pangolin include dirs: ${Pangolin_INCLUDE_DIRS}")
message(STATUS "Pangolin libraries: ${Pangolin_LIBRARIES}")
message(STATUS "Pangolin config: ${Pangolin_DIR}")

add_executable(pangolin_demo demo.cpp)

# Link your executable against Pangolin target
#target_link_libraries(pangolin_demo PRIVATE pangolin::pangolin)
