cmake_minimum_required(VERSION 3.10)

# title project
project(CorrencyParallel)

# set version CXX
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED true)
# find openMP package
find_package(OpenMP REQUIRED)
# add the executable
add_executable(a example.cc)
if(OpenMP_CXX_FOUND)
    target_link_libraries(a PUBLIC OpenMP::OpenMP_CXX)
    if(MSVC)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /openmp:experimental")
    else()
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fopenmp")
    endif()
endif()
