#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cassert>
 
using namespace std;

#include "Matrica.h"
 
Matrica::Matrica(int matrixRows, int matrixCols)
{
    rows = (matrixRows > 0 ? matrixRows : 3);
    cols = (matrixCols > 0 ? matrixCols : 3);
    ptr = new int[rows * cols];
    assert(ptr != 0); 
 
   for (int i = 0; i < rows; ++i)
   {
        for(int j = 0; j < cols; ++j)
        {
            ptr[i * cols + j] = 0;

        }
   }
}
 
Matrica::Matrica(const Matrica &matrix) 
    : rows(matrix.rows), cols(matrix.cols)
{
   ptr = new int[rows * cols];
   assert(ptr != 0);     
 
   for (int i = 0; i < matrix.rows; ++i)
   {
        for(int j = 0; j < matrix.cols; ++j)
        {
            ptr[i * cols + j] = matrix.ptr[i * cols + j];
        }
   }    
} 

Matrica::~Matrica()
{
   delete [] ptr;           
} 

 
const Matrica &Matrica::operator=(const Matrica &right)
{
   if (&right != this) {  
      
      if (rows != right.rows || cols != right.cols) 
      {
         delete [] ptr;
         rows = right.rows;
         cols = right.cols;        
         ptr = new int[rows * cols];
         assert( ptr != 0 ); 
      }
 
      for (int i = 0; i < rows; ++i)
      {
            for(int j = 0; j < cols; ++j)
            {
                ptr[i * cols + j] = right.ptr[i * cols + j];
            }
      }    
   } 
 
   return *this;   
}
 
bool Matrica::operator==(const Matrica &right) const
{
   if (rows != right.rows || cols != right.cols)
      return false; 

   for (int i = 0; i < rows; ++i)
   {
        for(int j = 0; j < cols; ++j)
        {
            if(ptr[i * cols + j] != 
            right.ptr[i * cols + j])
             return false;
        }
   }
 
   return true;    
}

bool Matrica::operator!=(const Matrica &right) const
{
   if (rows != right.rows || cols != right.cols)
      return true; 
 
   for (int i = 0; i < rows; ++i)
   {
        for(int j = 0; j < cols; ++j)
        {
            if(ptr[i * cols + j] != 
            right.ptr[i * cols + j])
             return true;
        }
   }
 
   return false;    
}
 

int &Matrica::operator[](int subscript)
{
   assert(0 <= subscript && subscript < rows * cols);
   return ptr[subscript]; 
} 
 

const int &Matrica::operator[](int subscript) const
{
   assert(0 <= subscript && subscript < rows * cols);
   return ptr[subscript]; 
}

Matrica Matrica::operator+(const Matrica &matrix) const
{
    Matrica temp(*this);
    if(rows != matrix.rows || cols != matrix.cols)
    {
        cout << "Ovie dve matrici ne se kompatibilni "
             "za sobiranje.\n";
             return temp;
    }
    else
    {
        temp.rows = rows;
        temp.cols = cols;
        for (int i = 0; i < rows; ++i)
        {
            for(int j = 0; j < cols; ++j)
            {
                temp[i * cols + j] =  ptr[i * cols + j] + 
                                    matrix.ptr[i * matrix.cols + j];
            }
        }  
    }
    return temp;
}

Matrica Matrica::operator-(const Matrica &matrix) const
{
    Matrica temp(*this);
    if(rows != matrix.rows || cols != matrix.cols)
    {
        cout << "Ovie dve matrici ne se kompatibilni "
             "za odzemanje.\n";
             return temp;
    }
    else
    {
        temp.rows = rows;
        temp.cols = cols;
        for (int i = 0; i < rows; ++i)
        {
            for(int j = 0; j < cols; ++j)
            {
                temp[i * cols + j] =  ptr[i * cols + j] - 
                                    matrix.ptr[i * matrix.cols + j];
            }
        }  
    }
    return temp;
}

Matrica Matrica::operator*(const Matrica &matrix) const
{
    if(cols != matrix.rows)
    {
        cout << "Ovie dve matrici ne se kompatibilni "
             "za mnozenje.\n";
             return *this;
    }
    else
    {
        Matrica temp(rows, matrix.cols);
        for (int i = 0; i < rows; ++i)
        {
            for(int j = 0; j < matrix.cols; ++j)
            {
                for(int k = 0; k < cols; ++k)
                {
                     temp[i * matrix.cols + j] +=  ptr[i * cols + k] * 
                                    matrix.ptr[k * matrix.cols + j];
                }
            }
        }
        return temp;  
    }
}

Matrica Matrica::operator*(const int number) const
{
    Matrica temp(rows, cols);
    for(int i = 0; i < rows; ++i)
    {
        for(int j = 0; j < cols; ++j)
        {
            temp[i * cols + j] =  ptr[i * cols + j] * number;
        }
    }
    return temp;
}

Matrica operator*(int number, Matrica matrix)
{
    Matrica temp(matrix.rows, matrix.cols);
    for(int i = 0; i < matrix.rows; ++i)
    {
        for(int j = 0; j < matrix.cols; ++j)
        {
            temp[i * matrix.cols + j] =  
                matrix.ptr[i * matrix.cols + j] * number;
        }
    }
    return temp; 
}
 
istream &operator>>(istream &input, Matrica &matrix)
{
   for (int i = 0; i < matrix.rows; ++i)
   {
        for(int j = 0; j < matrix.cols; ++j)
        {
            input >> matrix.ptr[i * matrix.cols + j];
        }
   }
   return input; 
}
 
ostream &operator<<(ostream &output, const Matrica &matrix)
{
   for (int i = 0; i < matrix.rows; ++i)
   {
        for(int j = 0; j < matrix.cols; ++j)
        {
            output << setw(5) << matrix.ptr[i * matrix.cols + j];
        }
        output << endl;
   }
 
   return output;   
}
