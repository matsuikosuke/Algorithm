#ifndef ARRAYDEQUE_H_
#define ARRAYDEQUE_H_


#include "array.h"

template<class T>
class ArrayDeque {
protected:
    array<T> a;
    int j;
    int n;
    void resize();
public:
    ArrayDeque();
    ArrayDeque(int len);
    virtual ~ArrayDeque();
    int size();
    int index();
    int length();
    T get(int i);
    T set(int i, T x);
    void add(int i, T x);
    T remove(int i);
};

template<class T>
ArrayDeque<T>::ArrayDeque() : a(1) {
    n = 0;
    j = 0;
}

template <class T>
ArrayDeque<T>::ArrayDeque(int len) : a(len) {
    n = 0;
    j = 0;
}

template<class T>
ArrayDeque<T>::~ArrayDeque() {
    //delete a;
}


template<class T> inline
int ArrayDeque<T>::size() {
    return n;
}


template<class T> inline
int ArrayDeque<T>::index() {
    return j;
}

template<class T> inline
int ArrayDeque<T>::length() {
    return a.length;
}

template<class T> inline
T ArrayDeque<T>::get(int i) {
    return a[(j+i)%a.length];
}

template<class T> inline
T ArrayDeque<T>::set(int i, T x) {
    if (a[(j + i) % a.length].empty()) n = (j + i + 1) % a.length;
    T y = a[(j + i) % a.length];
    a[(j + i) % a.length] = x;
    return y;
}

template<class T>
void ArrayDeque<T>::resize() {
    array<T> b(std::max(2 * n, 1));
    for (int k = 0; k < n; k++)
        b[k] = a[(j + k) % a.length];  //j番目を新しい0番目に置き、そこから順に配置していく
    a = b;
    j = 0;
}


template<class T>
void ArrayDeque<T>::add(int i, T x) {
    if (n + 1 >= a.length) resize();  //配列にこれ以上追加できない場合

    //配列a[0]...a[i-1]を左に１つずつずらす場合
    if (i < n / 2) {
        j = (j == 0) ? a.length - 1 : j - 1; //配列初期位置のjは左に-1だけずれるが、jが0ならば最後尾に循環する。
        for (int k = 0; k <= i - 1; k++) {
            a[(j + k) % a.length] = a[(j + k + 1) % a.length];
        }
    }
    //配列a[i+1]...a[n-1]を右に１つずつずらす場合
    else {
        //配列初期位置に変更はなし 
        //j = j;
        for (int k = n; k > i; k--) {
            a[(j + k) % a.length] = a[(j + k - 1) % a.length];
        }
    }

    a[(j + i) % a.length] = x;
    n++;
}


template<class T>
T ArrayDeque<T>::remove(int i) {
    T temp;
    T x = a[(j + i) % a.length];


    //配列a[0]...a[i-1]を右に１つずつずらす場合
    if (i < n / 2) {
        for (int k = i; k > 0; k--) {
            a[(j + k) % a.length] = a[(j + k - 1) % a.length];
        }
        a[j] = temp;
        j = (j + 1) % a.length;
    }
    //配列a[i+1]...a[n-1]を左に１つずつずらす場合
    else {
        a[j] = temp;
        for (int k = i; k < n-1; k++) {
            a[(j + k) % a.length] = a[(j + k + 1) % a.length];
        }
        //配列初期位置に変更はなし 
        //j = j;
    }
    n--;
    if (a.length >= 3 * n) resize(); //配列サイズが現在サイズより3倍以上の場合は、2倍のサイズに縮小する
    return x;
}


#endif /* ARRAYDEQUE_H_ */