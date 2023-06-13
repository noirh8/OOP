#pragma once
#include <iostream>
#include "PhanSo.cpp"
template <typename T>
    T Min(T a, T b) {
        return (a<b) ? a : b;
    }
template <typename T>
    T Max(T a, T b) {
        return (a>b) ? a : b;
    }
template <typename T>
    T MaxMang(T a[], int n) {
        T maxArr = a[0];
        for(int i=0; i<n; i++) {
            if(a[i] > maxArr) maxArr = a[i];
        }
        if(maxArr<0) maxArr = 0;
        return maxArr;
    }
template <typename T>
    void XepMang(T a[], int n) {
        for(int i=0; i<n-1; i++) {
            for(int j=i+1; i<n; j++) {
                if(a[i]>a[j]) {
                    T temp = a[i];
                    a[i]=a[j];
                    a[j]=temp;
                }
            }
        }
    }
