#include <iostream>
#include <vector>
#include <fstream>
#include "input.h"
#include "matrix.h"

Matrix::Matrix()
{
   ;
}

int Matrix::Rows()
{
   return values.size();
}

int Matrix::Columns()
{
   return (Rows() > 0)?values[0].size():0;
}

void Matrix::Clear()
{
   values.clear();
}

bool Matrix::Dimension(int rows, int cols)
{
   bool rv=false;
   Clear();
   if (rows >= 0 && rows <= MAX_SIZE &&
       cols >= 0 && cols <= MAX_SIZE) {
      rv=true;
      std::vector<double> rowTemplate(cols);
      for (int i=0; i<rows; i++) {
         values.push_back(rowTemplate);
      }
   }
   return rv;
}

void Matrix::Display()
{
   if (values.empty() == 0) {
      for (int r=0; r<Rows(); r++) {
         for (int c=0; c<Columns(); c++) {
            std::cout.width(15);
	    std::cout.precision(2);
	    std::cout.setf(std::ios::showpoint|std::ios::fixed|std::ios::right);
	    std::cout << values[r][c];
         }
	 std::cout << std::endl;
      }
      std::cout << std::endl;
   }
   else {
      std::cout << "Matrix has no dimensions.\n";
   }
}

void Matrix::Input()
{
   int rows=ReadValue<int>("Rows? ", 1, MAX_SIZE);
   int cols=ReadValue<int>("Cols? ", 1, MAX_SIZE);
   Dimension(rows,cols);
   for (int r=0; r<Rows(); r++) {
      for (int c=0; c<Columns(); c++) {
         std::cout << "Position "<<r+1<<","<<c+1<<": ";
	 std::cin >> values[r][c];
      }
   }
}

void Matrix::SetValue(int row, int col, double value)
{
   try {
      values.at(row).at(col)=value;
   }
   catch (std::exception e) {
      throw("row,col out of matrix range");
   }
}

double Matrix::GetValue(int row, int col)
{
   try {
      return values.at(row).at(col);
   }
   catch (std::exception e) {
      throw("row,col out of matrix range");
   }
}


void Matrix::Save(std::string fileName)
{
	std::ofstream out(fileName,std::ios::out);
	if (out.is_open()) {
		out << Rows() << " " << Columns();
		if (out.fail()) {
			out.close();
			throw("Error writing to file");
		}
		for (long r=0;r<Rows();r++) {
			for (long c=0;c<Columns();c++) {
				out << " " << values[r][c];
				if (out.fail()) {
					out.close();
					throw("Error writing to file");
				}
			}
		}
		out.close();
	}
	else {
		throw("Cannot open output file");
	}

}

void Matrix::Load(std::string fileName)
{
	std::ifstream in (fileName,std::ios::in);
	if (in.is_open()) {
		long rows=0,columns=0;
		in >> rows >> columns;
		if (in.fail()) {
			in.close();
			throw("Error reading from file");
		}
		if (!Dimension(rows,columns)) {
			in.close();
			throw("Could not dimension matrix");
		}
		for (long r=0;r<rows;r++) {
			for (long c=0;c<columns;c++) {
				in >> values[r][c];
			}
			if (in.fail()) {
				in.close();
				throw("Error reading from file");
			}
		}
		
	}
	else {
		throw("Cannot open input file");
	}
}