#ifndef SORT_H
#define SORT_H

#include <iostream>
using namespace std;

template <typename U>
void pow(U &a, U &b){
    long c;
    c = a , a = b , b = c;

    return ;
}
template <typename T>
void sort(T A[] , long n){
    long m = n;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m - 1 ; j++){
            if(A[j+1] < A[j]){
                pow(A[j] , A[j+1]);
            }
        }
      m--;
    }

    return ;
}

template <typename V>
void ascending_order(V a[], long n)
{
    int min, item;
    for (int i = 0; i < n - 1; i++)
    {
        min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[min])
            {
                min = j;
            }
        }
        item = a[i], a[i] = a[min], a[min] = item;
    }
    
    return ;
}
#endif