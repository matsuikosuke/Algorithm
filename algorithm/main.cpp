
#include <iostream>
#include "array.h"
#include "ArrayStack.h"


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
}