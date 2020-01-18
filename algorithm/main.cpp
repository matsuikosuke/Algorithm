
#include <iostream>
#include "array.h"
#include "ArrayStack.h"


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
    std::cout << "ArrayStackTest[" << ArrayStackTest.length() << "]= ";
    for (int i = 0; i < ArrayStackTest.length(); i++) {
        if (!ArrayStackTest.get(i).empty()) {
            //std::cout << "ArrayStackTest[" << i << "] = " << ArrayStackTest.get(i) << std::endl;
            printf("%s", ArrayStackTest.get(i).c_str());
        }
        else {
            printf("*");
        }
    }
    std::cout << ": n = " << ArrayStackTest.size() << std::endl;


    /*for (int i = 0; i < 4; i++) {
        ArrayStackTest.set(i, i + 1);
    }*/

    ArrayStackTest.set(0, "b");
    ArrayStackTest.set(1, "r");
    ArrayStackTest.set(2, "e");
    ArrayStackTest.set(3, "d");
    std::cout << "ArrayStackTest[" << ArrayStackTest.length() << "]= ";
    for (int i = 0; i < ArrayStackTest.length(); i++) {
        if (!ArrayStackTest.get(i).empty()) {
            //std::cout << "ArrayStackTest[" << i << "] = " << ArrayStackTest.get(i) << std::endl;
            printf("%s", ArrayStackTest.get(i).c_str());
        }
        else {
            printf("*");
        }
    }
    std::cout << ": n = " << ArrayStackTest.size() << std::endl;

    ArrayStackTest.add(2, "e");
    std::cout << "ArrayStackTest[" << ArrayStackTest.length() << "]= ";
    for (int i = 0; i < ArrayStackTest.length(); i++) {
        if (!ArrayStackTest.get(i).empty()) {
            //std::cout << "ArrayStackTest[" << i << "] = " << ArrayStackTest.get(i) << std::endl;
            printf("%s", ArrayStackTest.get(i).c_str());
        }
        else {
            printf("*");
        }
    }
    std::cout << ": n = " << ArrayStackTest.size() << std::endl;

    ArrayStackTest.add(5, "r");
    std::cout << "ArrayStackTest[" << ArrayStackTest.length() << "]= ";
    for (int i = 0; i < ArrayStackTest.length(); i++) {
        if (!ArrayStackTest.get(i).empty()) {
            //std::cout << "ArrayStackTest[" << i << "] = " << ArrayStackTest.get(i) << std::endl;
            printf("%s", ArrayStackTest.get(i).c_str());
        }
        else {
            printf("*");
        }
    }
    std::cout << ": n = " << ArrayStackTest.size() << std::endl;

    ArrayStackTest.add(5, "e");
    std::cout << "ArrayStackTest[" << ArrayStackTest .length() << "]= ";
    for (int i = 0; i < ArrayStackTest.length(); i++) {
        if (!ArrayStackTest.get(i).empty()) {
            //std::cout << "ArrayStackTest[" << i << "] = " << ArrayStackTest.get(i) << std::endl;
            printf("%s", ArrayStackTest.get(i).c_str());
        }
        else {
            printf("*");
        }
    }
    std::cout << ": n = " << ArrayStackTest.size() << std::endl;
    
    ArrayStackTest.remove(4);
    std::cout << "ArrayStackTest[" << ArrayStackTest.length() << "]= ";
    for (int i = 0; i < ArrayStackTest.length(); i++) {
        if (!ArrayStackTest.get(i).empty()) {
            //std::cout << "ArrayStackTest[" << i << "] = " << ArrayStackTest.get(i) << std::endl;
            printf("%s", ArrayStackTest.get(i).c_str());
        }
        else {
            printf("*");
        }
    }
    std::cout << ": n = " << ArrayStackTest.size() << std::endl;

    ArrayStackTest.remove(4);
    std::cout << "ArrayStackTest[" << ArrayStackTest.length() << "]= ";
    for (int i = 0; i < ArrayStackTest.length(); i++) {
        if (!ArrayStackTest.get(i).empty()) {
            //std::cout << "ArrayStackTest[" << i << "] = " << ArrayStackTest.get(i) << std::endl;
            printf("%s", ArrayStackTest.get(i).c_str());
        }
        else {
            printf("*");
        }
    }
    std::cout << ": n = " << ArrayStackTest.size() << std::endl;

    ArrayStackTest.remove(4);
    std::cout << "ArrayStackTest[" << ArrayStackTest.length() << "]= ";
    for (int i = 0; i < ArrayStackTest.length(); i++) {
        if (!ArrayStackTest.get(i).empty()) {
            //std::cout << "ArrayStackTest[" << i << "] = " << ArrayStackTest.get(i) << std::endl;
            printf("%s", ArrayStackTest.get(i).c_str());
        }
        else {
            printf("*");
        }
    }
    std::cout << ": n = " << ArrayStackTest.size() << std::endl;

    ArrayStackTest.set(2, "i");
    std::cout << "ArrayStackTest[" << ArrayStackTest.length() << "]= ";
    for (int i = 0; i < ArrayStackTest.length(); i++) {
        if (!ArrayStackTest.get(i).empty()) {
            //std::cout << "ArrayStackTest[" << i << "] = " << ArrayStackTest.get(i) << std::endl;
            printf("%s", ArrayStackTest.get(i).c_str());
        }
        else {
            printf("*");
        }
    }
    std::cout << ": n = " << ArrayStackTest.size() << std::endl;


    ArrayStackTest.add(2, "s");
    ArrayStackTest.add(2, "s");
    ArrayStackTest.add(2, "s");
    ArrayStackTest.add(2, "s");
    std::cout << "ArrayStackTest[" << ArrayStackTest.length() << "]= ";
    for (int i = 0; i < ArrayStackTest.length(); i++) {
        if (!ArrayStackTest.get(i).empty()) {
            //std::cout << "ArrayStackTest[" << i << "] = " << ArrayStackTest.get(i) << std::endl;
            printf("%s", ArrayStackTest.get(i).c_str());
        }
        else {
            printf("*");
        }
    }
    std::cout << ": n = " << ArrayStackTest.size() << std::endl;


    ArrayStackTest.remove(7);
    std::cout << "ArrayStackTest[" << ArrayStackTest.length() << "]= ";
    for (int i = 0; i < ArrayStackTest.length(); i++) {
        if (!ArrayStackTest.get(i).empty()) {
            //std::cout << "ArrayStackTest[" << i << "] = " << ArrayStackTest.get(i) << std::endl;
            printf("%s", ArrayStackTest.get(i).c_str());
        }
        else {
            printf("*");
        }
    }
    std::cout << ": n = " << ArrayStackTest.size() << std::endl;

    ArrayStackTest.add(7,"z");
    std::cout << "ArrayStackTest[" << ArrayStackTest.length() << "]= ";
    for (int i = 0; i < ArrayStackTest.length(); i++) {
        if (!ArrayStackTest.get(i).empty()) {
            //std::cout << "ArrayStackTest[" << i << "] = " << ArrayStackTest.get(i) << std::endl;
            printf("%s", ArrayStackTest.get(i).c_str());
        }
        else {
            printf("*");
        }
    }
    std::cout << ": n = " << ArrayStackTest.size() << std::endl;

    ArrayStackTest.remove(1);
    std::cout << "ArrayStackTest[" << ArrayStackTest.length() << "]= ";
    for (int i = 0; i < ArrayStackTest.length(); i++) {
        if (!ArrayStackTest.get(i).empty()) {
            //std::cout << "ArrayStackTest[" << i << "] = " << ArrayStackTest.get(i) << std::endl;
            printf("%s", ArrayStackTest.get(i).c_str());
        }
        else {
            printf("*");
        }
    }
    std::cout << ": n = " << ArrayStackTest.size() << std::endl;
}