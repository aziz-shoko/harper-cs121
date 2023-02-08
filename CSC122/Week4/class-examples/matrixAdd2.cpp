#include <iostream>
#include "matrix.h"
#include "input.h"

using namespace std;

int Menu();
int MenuSave();
bool AddMatrix(Matrix& a, Matrix& b, Matrix& result);

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

int Menu()
{
	return ReadValue<int>("1. New Matrix\n2. Load Matrix\n",1,2);
}

int MenuSave()
{
	return ReadValue<int>("1. Save Result\n2. Quit\n",1,2);
}


int main()
{
   try {
      Matrix m1,m2,m3;
      cout << "Matrix 1:\n";
      int choice=Menu();
      if (choice==1) {
      	m1.Input();
      }
      else {
	string fname;
	cout << "Enter file name: ";
	cin >> fname;
	m1.Load(fname);
      }
      cout << "Matrix 2:\n";
      choice=Menu();
      if (choice==1) {
      	m2.Input();
      }
      else {
	string fname;
	cout << "Enter file name: ";
	cin >> fname;
	m2.Load(fname);
      }

      cout << "Matrix 1\n";
      m1.Display();
      cout << "Matrix 2\n";
      m2.Display();
      if ( AddMatrix(m1,m2,m3)==true) {
	cout << "Sum of matrices is: \n";
      	m3.Display();
	choice=MenuSave();
	if (choice==1) {
		string fname;
		cout << "Enter file name: ";
		cin >> fname;
		m3.Save(fname);
	}
	else {
		cout << "Bye!\n";
	}
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