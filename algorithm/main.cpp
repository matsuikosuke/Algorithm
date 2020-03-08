
#include <iostream>
#include "array.h"
#include "ArrayStack.h"
#include "ArrayQueue.h"
#include "ArrayDeque.h"
#include "SLList.h"
#include "DLList.h"
#include "ChainedHashTable.h"


void show_ArrayStack(ArrayStack<std::string> &array_stack) { //参照渡しにしないと本関数を実行終了時にデストラクタが呼ばれてarray_stackが廃棄されてしまいエラーを起こす
    std::cout << "ArrayStackTest[" << array_stack.length() << "]= ";
    for (int i = 0; i < array_stack.length(); i++) {
        if (!array_stack.get(i).empty()) {
            //std::cout << "ArrayStackTest[" << i << "] = " << ArrayStackTest.get(i) << std::endl;
            printf("%s", array_stack.get(i).c_str());
        }
        else {
            printf("*");
        }
    }
    std::cout << ": n = " << array_stack.size() << std::endl;
}

void show_ArrayQueue(ArrayQueue<std::string> &array_queue) { //参照渡しにしないと本関数を実行終了時にデストラクタが呼ばれてarray_stackが廃棄されてしまいエラーを起こす
    std::cout << "ArrayQueueTest[" << array_queue.length() << "]= ";
    for (int i = 0; i < array_queue.length(); i++) {
        if (!array_queue.get(i).empty()) {
            printf("%s", array_queue.get(i).c_str());
        }
        else {
            printf("*");
        }
    }
    std::cout << ": j = " << array_queue.index() <<  ", n = " << array_queue.size() << std::endl;
}



void show_ArrayDeque(ArrayDeque<std::string> &array_deque) { //参照渡しにしないと本関数を実行終了時にデストラクタが呼ばれてarray_stackが廃棄されてしまいエラーを起こす
    std::cout << "ArrayDequeTest[" << array_deque.length() << "]= ";
    for (int i = 0; i < array_deque.length(); i++) {
        if (!array_deque.get(i).empty()) {
            printf("%s", array_deque.get(i).c_str());
        }
        else {
            printf("*");
        }
    }
    std::cout << ": j = " << array_deque.index() << ", n = " << array_deque.size() << std::endl;
}


int main() {
    // chap2:arrayクラスのテスト
    std::cout << std::endl;
    std::cout << "chap2:array" << std::endl;

    array<int> test1(5);
    array<int> test2(10);

    for (int i = 0; i < 5; i++) {
        test1.a[i] = i;
        test2.a[i] = i + 5;
        test2.a[i + 5] = i + 5 * 2;
    }


    for (int i = 0; i < 5; i++) {
        std::cout << "test1[" << i << "] = " << test1.a[i] << std::endl;
    }

    for (int i = 0; i < 10; i++) {
        std::cout << "test2[" << i << "] = " << test2.a[i] << std::endl;
    }

    test1 = test2;

    for (int i = 0; i < 10; i++) {
        std::cout << "test1[" << i << "] = " << test1.a[i] << std::endl;
    }

    //test1 = test2;を使用した時点でtest2は廃棄されている。
    /*for (int i = 0; i < 10; i++) {
        std::cout << "test2[" << i << "] = " << test2.a[i] << std::endl;
    }*/


    // chap2.1:ArrayStackクラスのテスト
    std::cout << std::endl;
    std::cout << "chap2.1:ArrayStack" << std::endl;


    ArrayStack<std::string> ArrayStackTest(6);
    show_ArrayStack(ArrayStackTest);


    /*for (int i = 0; i < 4; i++) {
        ArrayStackTest.set(i, i + 1);
    }*/

    ArrayStackTest.set(0, "b");
    ArrayStackTest.set(1, "r");
    ArrayStackTest.set(2, "e");
    ArrayStackTest.set(3, "d");
    show_ArrayStack(ArrayStackTest);

    ArrayStackTest.add(2, "e");
    show_ArrayStack(ArrayStackTest);

    ArrayStackTest.add(5, "r");
    show_ArrayStack(ArrayStackTest);

    ArrayStackTest.add(5, "e");
    show_ArrayStack(ArrayStackTest);
    
    ArrayStackTest.remove(4);
    show_ArrayStack(ArrayStackTest);

    ArrayStackTest.remove(4);
    show_ArrayStack(ArrayStackTest);

    ArrayStackTest.remove(4);
    show_ArrayStack(ArrayStackTest);

    ArrayStackTest.set(2, "i");
    show_ArrayStack(ArrayStackTest);


    ArrayStackTest.add(2, "s");
    ArrayStackTest.add(2, "s");
    ArrayStackTest.add(2, "s");
    ArrayStackTest.add(2, "s");
    show_ArrayStack(ArrayStackTest);


    ArrayStackTest.remove(7);
    show_ArrayStack(ArrayStackTest);

    ArrayStackTest.add(7,"z");
    show_ArrayStack(ArrayStackTest);

    ArrayStackTest.remove(1);
    show_ArrayStack(ArrayStackTest);

    // chap2.2:ArrayQueueクラスのテスト
    std::cout << std::endl;
    std::cout << "chap2.2:ArrayQueue" << std::endl;



    ArrayQueue<std::string> ArrayQueueTest(6);
    show_ArrayQueue(ArrayQueueTest);

    ArrayQueueTest.add("a");
    ArrayQueueTest.add("a");
    ArrayQueueTest.add("a");
    ArrayQueueTest.add("b");
    ArrayQueueTest.add("c");
    ArrayQueueTest.remove();
    ArrayQueueTest.remove();
    show_ArrayQueue(ArrayQueueTest);

    ArrayQueueTest.add("d");
    show_ArrayQueue(ArrayQueueTest);

    ArrayQueueTest.add("e");
    show_ArrayQueue(ArrayQueueTest);

    ArrayQueueTest.remove();
    show_ArrayQueue(ArrayQueueTest);

    ArrayQueueTest.add("f");
    show_ArrayQueue(ArrayQueueTest);

    ArrayQueueTest.add("g");
    show_ArrayQueue(ArrayQueueTest);

    ArrayQueueTest.add("h");
    show_ArrayQueue(ArrayQueueTest);

    ArrayQueueTest.remove();
    show_ArrayQueue(ArrayQueueTest);


    // chap2.3:ArrayDequeクラスのテスト
    std::cout << std::endl;
    std::cout << "chap2.3:ArrayDeque" << std::endl;

    ArrayDeque<std::string> ArrayDequeTest(12);
    show_ArrayDeque(ArrayDequeTest);

    ArrayDequeTest.set(0, "a");
    ArrayDequeTest.set(1, "b");
    ArrayDequeTest.set(2, "c");
    ArrayDequeTest.set(3, "d");
    ArrayDequeTest.set(4, "e");
    ArrayDequeTest.set(5, "f");
    ArrayDequeTest.set(6, "g");
    ArrayDequeTest.set(7, "h");
    show_ArrayDeque(ArrayDequeTest);

    ArrayDequeTest.remove(2);
    show_ArrayDeque(ArrayDequeTest);
    
    ArrayDequeTest.add(4, "x");
    show_ArrayDeque(ArrayDequeTest);

    ArrayDequeTest.add(3, "y");
    show_ArrayDeque(ArrayDequeTest);

    ArrayDequeTest.add(3, "z");
    show_ArrayDeque(ArrayDequeTest);


    // chap3.1:SLListクラスのテスト
    std::cout << std::endl;
    std::cout << "chap3.1:SLList" << std::endl;


    SLList<std::string> SLListTest;
    SLListTest.add("a");
    SLListTest.add("b");
    SLListTest.add("c");
    SLListTest.add("d");
    SLListTest.add("e");
    SLListTest.print_value();
    SLListTest.print_value(0);
    SLListTest.print_value(1);
    SLListTest.print_value(2);
    SLListTest.print_value(3);
    SLListTest.print_value(4);
    SLListTest.print_value(5);

    SLListTest.add("x");
    SLListTest.print_value();

    SLListTest.remove();
    SLListTest.print_value();

    SLListTest.pop();
    SLListTest.print_value();
    
    SLListTest.push("y");
    SLListTest.print_value();

    // chap3.2:DLListクラスのテスト
    std::cout << std::endl;
    std::cout << "chap3.2:DLList" << std::endl;


    DLList<std::string> DLListTest;
    DLListTest.dummy_address();
    DLListTest.node_address(0);

    DLListTest.add(0, "a");
    DLListTest.add(1, "b");
    DLListTest.add(2, "c");
    DLListTest.add(3, "d");
    DLListTest.add(4, "e");

    for (int i=0; i < DLListTest.size(); i++) {
        printf("%s, ", DLListTest.get(i).c_str());
        DLListTest.node_address(i);
    }

    DLListTest.dummy_address();

    DLListTest.print_value();


    DLListTest.add(3, "x");
    DLListTest.print_value();

    DLListTest.remove(3);
    DLListTest.print_value();

    DLListTest.add(0, "y");
    DLListTest.print_value();

    DLListTest.remove(0);
    DLListTest.print_value();

    DLListTest.add(DLListTest.size(), "z");
    DLListTest.print_value();

    DLListTest.remove(DLListTest.size()-1);
    DLListTest.print_value();
}