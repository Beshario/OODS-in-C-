cmake_minimum_required(VERSION 2.6)

project(TrianglePoints)

find_package(VTK REQUIRED)
include(${VTK_USE_FILE})

add_executable(TrianglePoints TrianglePoints.cxx)
if(VTK_LIBRARIES)
  target_link_libraries(TrianglePoints ${VTK_LIBRARIES})
else()
  target_link_libraries(TrianglePoints vtkHybrid)
endif()
