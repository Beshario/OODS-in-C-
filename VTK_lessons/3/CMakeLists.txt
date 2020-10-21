cmake_minimum_required(VERSION 2.6)

project(TriangleVertices)

find_package(VTK REQUIRED)
include(${VTK_USE_FILE})

add_executable(TriangleVertices TriangleVertices.cxx)
if(VTK_LIBRARIES)
  target_link_libraries(TriangleVertices ${VTK_LIBRARIES})
else()
  target_link_libraries(TriangleVertices vtkHybrid)
endif()
