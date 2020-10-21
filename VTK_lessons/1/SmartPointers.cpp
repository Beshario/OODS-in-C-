#include <vtkFloatArray.h>
#include <vtkSmartPointer.h>
#include <vtkVersion.h>
#include <iostream>
void WithSmartPointers();
void WithoutSmartPointers();

int main(int argc, char *argv[])
{
  std::cout << vtkVersion::GetVTKSourceVersion() << std::endl;
  std::cout << vtkVersion::GetVTKMajorVersion() << std::endl;
  std::cout << vtkVersion::GetVTKMinorVersion() << std::endl;
  WithSmartPointers();
  WithoutSmartPointers();

  return 0;
}

void WithSmartPointers()
{
  vtkSmartPointer<vtkFloatArray> Distances = vtkSmartPointer<vtkFloatArray>::New();
}

void WithoutSmartPointers()
{
  //normal pointer of float arrays
  vtkFloatArray* Distances = vtkFloatArray::New();
  Distances->Delete();
}
