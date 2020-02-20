#ifndef DLLIST_H_
#define DLLIST_H_

template<class T>
class DLList {
protected:
    class Node {
    public:
        T x;
        Node *prev, *next;
    };
    Node dummy;
    int n;

    Node* getNode(int i);
    Node* addBefore(Node *w, T x);
    void remove(Node *w);

public:
    DLList();
    virtual ~DLList();
    int size();
    T get(int i);
    T set(int i, T x);
    void add(int i, T x);
    T remove(int i);
    virtual void clear();

    //�f�o�b�O�p
    void node_address(int i);
    void dummy_address();
    void print_value();

};


template <class T>
DLList<T>::DLList() {
    dummy.next = &dummy;
    dummy.prev = &dummy;
    n = 0;
}

template<class T>
DLList<T>::~DLList() {
    clear();
}


template<class T> inline
int DLList<T>::size() {
    return n;
}

template<class T>
typename DLList<T>::Node*  DLList<T>::getNode(int i) {
    Node *p;
    //�擪����ړI�̃m�[�h��H��ꍇ
    if (i < n / 2) {
        p = dummy.next;
        for (int j = 0; j < i; j++) {
            p = p->next;
        }
    }
    //��������ړI�̃m�[�h��H��ꍇ
    else {
        p = &dummy;
        for (int j = n; j > i; j--) {
            p = p->prev;
        }
    }

    return (p);
}


//Node w �̒��O�ɒlx��Node u ��}��
template<class T>
typename DLList<T>::Node*  DLList<T>::addBefore(Node *w, T x) {
    Node *u = new Node;
    u->x = x;
    u->prev = w->prev;
    u->next = w;
    u->next->prev = u;
    u->prev->next = u;
    n++;
    return u;
}

template<class T>
void DLList<T>::remove(Node *w) {
    w->prev->next = w->next;
    w->next->prev = w->prev;
    delete w;

}

//�Ώ�Node�̒l���擾
template<class T>
T DLList<T>::get(int i) {
    return getNode(i)->x;
}

//�Ώ�Node�̒l���㏑��
template<class T>
T DLList<T>::set(int i, T x) {
    Node *u = getNode(i);
    T y = u->x;
    u->x = x;
    return y;
}

//i�Ԗڂ�Node���O�ɒlx��Node��}��
template<class T>
void DLList<T>::add(int i, T x) {
    addBefore(getNode(i), x);
}



//i�Ԗڂ�Node���폜
template<class T>
T DLList<T>::remove(int i) {
    Node *w = getNode(i);
    T x = w->x;
    remove(w);
    return x;
}


template<class T>
void DLList<T>::clear() {
    Node *u = dummy.next; //�ŏ���Node�̃A�h���X
    while (u != &dummy) {  //dummy�̃A�h���X�ɓ��B����܂�delete���Ă���
        Node *w = u->next;
        delete u;
        u = w;
    }
    n = 0;
}

//i�Ԗڂ�Node�̃A�h���X�\��
template<class T> inline
void DLList<T>::node_address(int i) {
    Node *w = getNode(i);
    std::cout << "Node[" << i << "] prev address = " << w->prev
        << ", Node[" << i << "] address = " << w
     << ", Node[" << i << "] next address = " << w->next
        << std::endl;
}

//Dummy Node�̃A�h���X�\��
template<class T> inline
void DLList<T>::dummy_address() {
    std::cout << "Dummy Node[] prev address = " << dummy.prev
        << ", Dummy Node[] address = " << &dummy
        << ", Dummy Node[] next address = " << dummy.next
        << std::endl;
}


template<class T>
void DLList<T>::print_value() {
    Node *u = dummy.next; //�ŏ���Node�̃A�h���X
    while (u != &dummy) {  //dummy�̃A�h���X�ɓ��B����܂ŕ\�����Ă���
        Node *w = u;
        u = u->next;
        printf("%s", w->x.c_str());
    }
    printf("\n");
}

#endif /* DLLIST_H_ */