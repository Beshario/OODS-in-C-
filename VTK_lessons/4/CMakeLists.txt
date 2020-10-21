cmake_minimum_required(VERSION 2.6)

project(TriangleLines)

find_package(VTK REQUIRED)
include(${VTK_USE_FILE})

add_executable(TriangleLines TriangleLines.cxx)
if(VTK_LIBRARIES)
  target_link_libraries(TriangleLines ${VTK_LIBRARIES})
else()
  target_link_libraries(TriangleLines vtkHybrid)
endif()
