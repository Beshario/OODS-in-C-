cmake_minimum_required(VERSION 2.6)

project(TrianglePolygon)

find_package(VTK REQUIRED)
include(${VTK_USE_FILE})

add_executable(TrianglePolygon TrianglePolygon.cxx)
if(VTK_LIBRARIES)
  target_link_libraries(TrianglePolygon ${VTK_LIBRARIES})
else()
  target_link_libraries(TrianglePolygon vtkHybrid)
endif()
