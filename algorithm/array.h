#ifndef ARRAY_H_
#define ARRAY_H_
#include <iostream>
#include <algorithm>

#include <stdlib.h>
#include <assert.h>

template<class T>
class array {
public:
    T *a;
public:
    int length;
    array(int len);
    array(int len, T init);
    virtual ~array();

    T& operator[](int i) {
        assert(i >= 0 && i < length);
        return a[i];
    }

    array<T>& operator=(array<T> &b) {
        if (a != NULL) delete[] a;
        a = b.a;
        b.a = NULL;
        length = b.length;
        return *this;
    }
};


template<class T>
array<T>::array(int len) {
    length = len;
    a = new T[length];
}


template<class T>
array<T>::array(int len, T init) {
    length = len;
    a = new T[length];
    for (int i = 0; i < length; i++)
        a[i] = init;
}


template<class T>
array<T>::~array() {
    if (a != NULL) delete[] a;
}

#endif // !ARRAY_H_