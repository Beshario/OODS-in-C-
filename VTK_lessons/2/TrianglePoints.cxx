#include <vtkSmartPointer.h>
#include <vtkPoints.h>
#include <vtkXMLPolyDataWriter.h>
#include <vtkPolyData.h>

int main(int argc, char *argv[])
{
  //create a an object with set of points
  vtkSmartPointer<vtkPoints> points = vtkSmartPointer<vtkPoints>::New();
                          //(x,y,z)
  points->InsertNextPoint ( 1.0, 0.0, 0.0 );
  points->InsertNextPoint ( 0.0, 0.0, 0.0 );
  points->InsertNextPoint ( 0.0, 1.0, 0.0 );

  //create a polydata
  vtkSmartPointer<vtkPolyData> polydata = vtkSmartPointer<vtkPolyData>::New();

  //add the points to the polydata
  polydata->SetPoints ( points );

  //write the polydata to a file
  vtkSmartPointer<vtkXMLPolyDataWriter> writer = vtkSmartPointer<vtkXMLPolyDataWriter>::New();
  writer->SetFileName ( "TrianglePoints.vtp" );
#if VTK_MAJOR_VERSION <= 5
  writer->SetInput( polydata );
#else
  writer->SetInputData( polydata );
#endif
  writer->Write();

  return EXIT_SUCCESS;
}
