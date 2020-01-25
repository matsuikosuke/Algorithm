#ifndef SLLIST_H_
#define SLLIST_H_
#include <stdlib.h>

template<class T>
class SLList {
    //T null;
protected:
    class Node {
    public:
        T x;
        Node *next;
        Node(T x0) {
            x = x0;
            next = NULL;
        }
    };
    Node *head;
    Node *tail;
    int n;

public:
    SLList();
    virtual ~SLList();
    int size();
    void head_address();
    void next_address();
    void tail_address();
    void print_value();
    void print_value(int i);
    T push(T x);
    T pop();
    T remove();
    bool add(T x);
};


template <class T>
SLList<T>::SLList() {
    //null = (T)NULL;
    n = 0;
    head = NULL;
    tail = NULL;
}



template<class T>
SLList<T>::~SLList() {
    Node *u = head;
    while (u != NULL) {
        Node *w = u;
        u = u->next;
        delete w;
    }
}

template<class T> inline
int SLList<T>::size() {
    return n;
}

template<class T> inline
void SLList<T>::head_address() {
    std::cout << head << std::endl;
}

template<class T> inline
void SLList<T>::tail_address() {
    std::cout << tail << std::endl;
}

template<class T> inline
void SLList<T>::next_address() {
    Node *u = head;
    std::cout << u->next << std::endl;
}

template<class T>
void SLList<T>::print_value() {
    Node *u = head;
    while (u != NULL) {
        Node *w = u;
        u = u->next;
        printf("%s", w->x.c_str());
    }
    printf("\n");
}


template<class T>
void SLList<T>::print_value(int i) {
    Node *u = head;
    int indx = 0;
    while (u != NULL) {
        Node *w = u;
        u = u->next;
        if (indx == i) {
            std::cout << "This address is " << w << ", " 
                      << "Next address is " << u << ", " << "value is ";
            printf("%s", w->x.c_str());
            printf("\n");
        }
        indx++;
    }
}

template<class T> 
T SLList<T>::push(T x) {
    Node *u = new Node(x);
    u->next = head;
    head = u;
    if (n == 0)
        tail = u;
    n++;
    return x;
}

template<class T> 
T SLList<T>::pop() {
    if (n == 0) return NULL;
    T x = head->x;
    Node *u = head;
    head = head->next;
    delete u;
    if (--n == 0) tail = NULL;
    return x;
}

template<class T>
T SLList<T>::remove() {
    if (n == 0) return NULL;
    T x = head->x;
    Node *u = head;
    head = head->next;
    delete u;
    if (--n == 0) tail = NULL;
    return x;
}

template<class T>
bool SLList<T>::add(T x) {
    Node *u = new Node(x);
    if (n == 0) {
        head = u;
    }
    else {
        tail->next = u;
    }
    tail = u;
    n++;
    return true;
}

#endif /* SLLIST_H_ */