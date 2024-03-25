#ifndef BINARY_H
#define BINARY_H

#include <iostream>
using namespace std;
template <typename T>
bool binary(T a[], T b, int max, int min = 0, int mid = 0)
{
    if(min == max){
        if(a[min] == b){
            return true;
        }else{
            return false;
        }
    }else if(min > max){
        return false;
    }
    mid = (min + max) / 2;
    if(a[mid] == b){
        return true;
    }else{
        if(a[mid] < b){
            min = mid + 1;
            return binary(a, b, max, min);
        }else{
            max = mid - 1;
            return binary(a, b, max, min);
        }
    }
}

template <typename U>
bool liner(U A[], U B, long n){
    for(int i = 0 ; i < n ; i++){
        if(A[i] == B){
            return true;
        }
    }
    return false;
}
#endif