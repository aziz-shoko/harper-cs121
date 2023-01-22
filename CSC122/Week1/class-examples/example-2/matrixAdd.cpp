#include <iostream>
#include "matrix.h"

using namespace std;

bool AddMatrix(Matrix& a, Matrix& b, Matrix& result)
{
        bool rv=false;
        if (a.Rows()==b.Rows() && a.Columns()==b.Columns()) {
                rv=true;
                result.Dimension(a.Rows(),a.Columns());
                for (int r=0;r<a.Rows();r++) {
                        for (int c=0;c<a.Columns();c++) {
                                result.SetValue(r,c,a.GetValue(r,c)+b.GetValue(r,c));
                        }
                }
        }
        return rv;
}


int main()
{
   try {
      Matrix m1,m2,m3;
      cout << "Enter matrix 1:\n";
      m1.Input();
      cout << "Enter matrix 2:\n";
      m2.Input();
      cout << "Matrix 1\n";
      m1.Display();
      cout << "Matrix 2\n";
      m2.Display();
      if ( AddMatrix(m1,m2,m3)==true) {
	cout << "Sum of matrices is: \n";
      	m3.Display();
      }
      else {
	cout << "Matrices cannot be added.\n";
      }
   }
   catch (const char* msg) {
      cerr << msg << endl;
   }
   return 0;
}