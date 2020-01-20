#ifndef ARRAYQUEUE_H_
#define ARRAYQUEUE_H_


#include "array.h"

template<class T>
class ArrayQueue {
protected:
    array<T> a;
    int j;
    int n;
    void resize();
public:
    ArrayQueue();
    ArrayQueue(int len);
    virtual ~ArrayQueue();
    int size();
    int index();
    int length();
    T get(int i);
    bool add(T x);
    T remove();
};

template<class T>
ArrayQueue<T>::ArrayQueue() : a(1) {
    n = 0;
    j = 0;
}

template <class T>
ArrayQueue<T>::ArrayQueue(int len) : a(len) {
    n = 0;
    j = 0;
}

template<class T>
ArrayQueue<T>::~ArrayQueue() {
    //delete a;
}


template<class T> inline
int ArrayQueue<T>::size() {
    return n;
}


template<class T> inline
int ArrayQueue<T>::index() {
    return j;
}

template<class T> inline
int ArrayQueue<T>::length() {
    return a.length;
}

template<class T> inline
T ArrayQueue<T>::get(int i) {
    return a[i];
}


template<class T>
void ArrayQueue<T>::resize() {
    array<T> b(std::max(2 * n, 1));
    for (int k = 0; k < n; k++)
        b[k] = a[(j + k) % a.length];  //j�Ԗڂ�V����0�Ԗڂɒu���A�������珇�ɔz�u���Ă���
    a = b;
    j = 0;
}


template<class T>
bool ArrayQueue<T>::add(T x) {
    if (n+1 >= a.length) resize();  //�z��ɂ���ȏ�ǉ��ł��Ȃ��ꍇ

    a[(j+n)%a.length] = x;
    n++;
    return true;
}


template<class T>
T ArrayQueue<T>::remove() {
    T temp;
    T x = a[j];
    a[j] = temp;
    j = (j + 1) % a.length;
    n--;
    if (a.length >= 3*n) resize(); //�z��T�C�Y�����݃T�C�Y���3�{�ȏ�̏ꍇ�́A2�{�̃T�C�Y�ɏk������
    return x;
}


#endif /* ARRAYQUEUE_H_ */