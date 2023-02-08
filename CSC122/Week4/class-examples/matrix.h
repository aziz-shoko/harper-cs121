#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <string>

class Matrix 
{
   private:
	   std::vector< std::vector<double> > values;
   public:
	    enum {MAX_SIZE=100};
            Matrix();
	    bool Dimension(int rows, int cols);
	    void SetValue(int row, int col, double value);
	    double GetValue(int row, int col);
	    int Rows();
	    int Columns();
	    void Clear();
	    void Input();
	    void Display();
	    void Load(std::string fileName);
	    void Save(std::string fileName);
};

#endif
