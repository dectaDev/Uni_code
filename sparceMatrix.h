#ifndef SMatrix_H
#define SMatrix_h

#include <iostream>
#include "matrix.h" 
using namespace std;

class SMatrix{
    public:
    long row, col;
    double Valu;
};
class matrix{

    long number;
    SMatrix array[1000];

public :
    matrix(long num = 0){
        number = num;
    }
    friend istream& operator>>(istream& X, matrix &A);
    friend ostream& operator<<(ostream& X, matrix A);
    friend Matrix sparec(matrix a, long n, long m);
    friend matrix TA(matrix A, long num);

    matrix operator+(matrix B);
};

istream& operator>>(istream& X, matrix &A)
{
    if (A.number == 0)
    {
        cout << "i cant work";
        
        return X;
    }

    for(int i = 0; i < A.number; i++)
    {
        cout << "enter row : \n";
        X >> A.array[i].row;
        cout << "enter col : \n";
        X >> A.array[i].col;
        cout << "enter value : \n";
        X >> A.array[i].Valu;
    }

    return X;
}

ostream& operator<<(ostream& X, matrix A){
    for(int i = 0; i < A.number; i++)
    {
        X << A.array[i].row << "\t" << A.array[i].col << " : " << A.array[i].Valu << endl;       
    }

    return X;
}

Matrix sparec(matrix a, long n, long m)
{
    Matrix full(n, m);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            for (int k = 0; k < n*m; k++)
            {
                if (a.array[k].row == i && a.array[k].col == j)
                {
                    full.A[i][j] = a.array[k].Valu;
                }
            }
        }
        
    }

    return full;
}

matrix TA(matrix A, long num)
{
    matrix B(num);
    for (int i = 0; i < A.number; i++)
    {
        B.array[i].col = A.array[i].row;
        B.array[i].row = A.array[i].col;
        B.array[i].Valu = A.array[i].Valu;
    }

    return B;
}

#endif