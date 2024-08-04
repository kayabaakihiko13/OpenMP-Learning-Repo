cmake_minimum_required(VERSION 3.10)

project(Intro)

# set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# find OpenMp package
find_package(OpenMP REQUIRED)

# add the executable
add_executable(out main.cc)

# link OpenMP and set compiler flags
if(OpenMP_CXX_FOUND)
    target_link_libraries(out PUBLIC OpenMP::OpenMP_CXX)

    #set compiler flags for experimental OpenMP features
    if(MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /openmp:experimental")
    else()
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fopenmp")
    endif()
endif()
