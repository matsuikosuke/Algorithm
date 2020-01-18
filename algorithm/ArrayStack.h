#ifndef ARRAYSTACK_H_
#define ARRAYSTACK_H_

#include "array.h"

template<class T>
class ArrayStack {
protected:
    array<T> a;
    int n;
public:
    ArrayStack();
    ArrayStack(int len);
    virtual ~ArrayStack();
    int size();
    int length();
    T get(int i);
    T set(int i, T x);
    void add(int i, T x);
    T remove(int i);
    void resize(); 
};


template <class T>
ArrayStack<T>::ArrayStack() : a(1) {
    n = 0;
}

template <class T>
ArrayStack<T>::ArrayStack(int len) : a(len) {
    n = 0;
}


template<class T>
ArrayStack<T>::~ArrayStack() {
}

template<class T> inline
int ArrayStack<T>::size() {
    return n;
}

template<class T> inline
int ArrayStack<T>::length() {
    return a.length;
}

template<class T> inline
T ArrayStack<T>::get(int i) {
    return a[i];
}

template<class T> inline
T ArrayStack<T>::set(int i, T x) {
    if (a[i].empty()) n++;
    T y = a[i];
    a[i] = x;
    return y;
}

template<class T>
void ArrayStack<T>::add(int i, T x) {
    if (n >= a.length) resize();  //配列にこれ以上追加できない場合

    for (int j = n; j > i; j--) {
        a[j] = a[j - 1];
    }
    a[i] = x;
    n++;
}


template<class T>
T ArrayStack<T>::remove(int i) {
    T x = a[i];
    T temp;


    for (int j = i; j < n-1; j++) {
        a[j] = a[j + 1];
    }
    if (n == a.length) {
        a[n - 1] = temp;
    }
    else
    {
        a[n - 1] = a[n];
    }
    n--;

    if (a.length >= 3 * n) resize(); //配列サイズが現在サイズより3倍以上の場合は、2倍のサイズに縮小する
    return x;
}


template<class T>
void ArrayStack<T>::resize() {
    array<T> b(std::max(2 * n, 1));
    for (int i = 0; i<n; i++) {
        b[i] = a[i];
    }
    a = b;
}

#endif /* ARRAYSTACK_H_ */