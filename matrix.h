#ifndef Matrix_H
#define Matrix_H

#include <iostream>
using namespace std;
class Matrix{
    long n, m;
public:
    long double A[100][100];
    Matrix(long N, long M)
    {
        n = N, m = M;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                A[i][j] = 0;
            }
        }
    }
    friend ostream &operator<<(ostream &X, Matrix a);
    friend istream &operator>>(istream &X, Matrix &a);
    friend Matrix operator+(Matrix A, Matrix b);
    friend Matrix operator-(Matrix a, Matrix b);
    Matrix Ta();
    Matrix operator++();
    Matrix operator++(int);
    bool operator<(Matrix B);
    bool operator<=(Matrix B);
    bool operator>=(Matrix B);
    bool operator>(Matrix B);
    Matrix operator*(const Matrix& b);
};

ostream &operator<<(ostream &X , Matrix a)
{
    if (a.m == 0 || a.n == 0)
    {
        cout << "Matrix is empty";

        return X;
    }

    for(int i = 0 ; i < a.n ; i++){
        for(int j = 0 ; j < a.m ; j++){
            X << a.A[i][j] << "\t";
        }
        X << "\n";
    }
    return X;
}
istream &operator>>(istream &X , Matrix &a){
    for(int i = 0 ; i < a.n ; i++){
        for(int j = 0 ; j < a.m ; j++){
            cout << "enter number of matrix in row " << i + 1 << " and in col " << j + 1 << ".\n";
            X >> a.A[i][j];
        }
    }
    return X;
}
Matrix operator+(Matrix a, Matrix b)
{
    Matrix c(0, 0);
        if(a.m == b.m && a.n == b.n)
        {
            c.m = a.m;
            c.n = a.n;
            for (int i = 0; i < a.n; i++){
                for (int j = 0; j < a.m; j++){
                    c.A[i][j] = a.A[i][j] + b.A[i][j];
                }
            }
        }
        else
        {
            cout << "this matrix can do.\n";
        }
        
    return c;
}
Matrix operator-(Matrix a, Matrix b)
{
    Matrix c(0, 0);
    if (a.m == b.m && a.n == b.n)
    {
        c.m = a.m;
        c.n = a.n;
        for (int i = 0; i < a.n; i++)
        {
            for (int j = 0; j < a.m; j++)
            {
                c.A[i][j] = a.A[i][j] - b.A[i][j];
            }
        }
    }
    return c;
}
Matrix Matrix::operator++(){
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            ++A[i][j];
        }
    }
    return *this;
}
Matrix Matrix::operator++(int)
{
    Matrix original(*this);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            A[i][j]++;
        }
    }
    return original;
}
    Matrix Matrix::Ta(){
        Matrix b(0, 0);
        b.n = m;
        b.m = n;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                b.A[j][i] = A[i][j];
            }
        }
        
        return b;
    }

Matrix Matrix::operator*(const Matrix& b)
{
    if (m != b.n)
    {
        cout << "Matrix dimensions are incompatible for multiplication.\n";
    }

    Matrix C(0, 0);
    C.n = n, C.m = b.m;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < b.m; ++j)
        {
            C.A[i][j] = 0;
            for (int k = 0; k < m; ++k)
            {
                C.A[i][j] += A[i][k] * b.A[k][j];
            }
        }
    }

    return C;
}


bool Matrix::operator<(Matrix B)
{
    if(n != B.n && m != B.n)
    {
        return false;
    }
    long double sumA = 0, sumB = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            sumA += A[i][j];
            sumB += B.A[i][j];
        }
    }
    if(sumA < sumB)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Matrix::operator<=(Matrix B)
{
    if (n != B.n && m != B.n)
    {
        return false;
    }
    long double sumA = 0, sumB = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            sumA += A[i][j];
            sumB += B.A[i][j];
        }
    }
    if (sumA <= sumB)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Matrix::operator>=(Matrix B)
{
    if (n != B.n && m != B.n)
    {
        return false;
    }
    long double sumA = 0, sumB = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            sumA += A[i][j];
            sumB += B.A[i][j];
        }
    }
    if (sumA >= sumB)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Matrix::operator>(Matrix B)
{
    if (n != B.n && m != B.n)
    {
        return false;
    }
    long double sumA = 0, sumB = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            sumA += A[i][j];
            sumB += B.A[i][j];
        }
    }
    if (sumA > sumB)
    {
        return true;
    }
    else
    {
        return false;
    }
}

#endif