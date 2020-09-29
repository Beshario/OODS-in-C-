#include <vtkPoints.h>
#include <vtkLine.h>
#include <vtkCellArray.h>
#include <vtkSmartPointer.h>
#include <vtkXMLPolyDataWriter.h>
#include <vtkPolyData.h>

int main(int argc, char *argv[])
{
  //Setup point coordinates
  vtkSmartPointer<vtkPoints> points = vtkSmartPointer<vtkPoints>::New();
  points->InsertNextPoint ( 1.0, 0.0, 0.0 );
  points->InsertNextPoint ( 0.0, 0.0, 1.0 );
  points->InsertNextPoint ( 0.0, 0.0, 0.0 );

  //create a line between each pair of points
  vtkSmartPointer<vtkLine> line0 = vtkSmartPointer<vtkLine>::New();
  line0->GetPointIds()->SetId ( 0,0 ); // second 0 is the 0th element in points
  //first 1 means this needs to be the secondpoint, second 1, means we wanna add the second point
  //in points (( 0.0, 0.0, 1.0 ) as second point
  line0->GetPointIds()->SetId ( 1,1 );

  vtkSmartPointer<vtkLine> line1 = vtkSmartPointer<vtkLine>::New();
  //assigning point 1 and 2 as a first and secon point to line respectively.
  line1->GetPointIds()->SetId ( 0,1 );
  line1->GetPointIds()->SetId ( 1,2 );

  vtkSmartPointer<vtkLine> line2 = vtkSmartPointer<vtkLine>::New();
  line2->GetPointIds()->SetId ( 0,2 );
  line2->GetPointIds()->SetId ( 1,0 );

  //create a cell array to store the line in
  vtkSmartPointer<vtkCellArray> lines = vtkSmartPointer<vtkCellArray>::New();
  lines->InsertNextCell ( line0 );
  lines->InsertNextCell ( line1 );
  lines->InsertNextCell ( line2 );

  //create a polydata to store everything in
  vtkSmartPointer<vtkPolyData> polydata = vtkSmartPointer<vtkPolyData>::New();

  //add the points and lines to the polydata
  polydata->SetPoints ( points );
  polydata->SetLines ( lines );

  //write the polydata to a file
  vtkSmartPointer<vtkXMLPolyDataWriter> writer = vtkSmartPointer<vtkXMLPolyDataWriter>::New();
  writer->SetFileName ( "TriangleLines.vtp" );
#if VTK_MAJOR_VERSION <= 5
  writer->SetInput ( polydata );
#else
  writer->SetInputData ( polydata );
#endif
  writer->Write();

  return EXIT_SUCCESS;
}
