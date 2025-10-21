#pragma once
#include "Animal.h"
#include <iostream>
using namespace std;
class Dog : public Animal {
public:
    // 重写纯虚函数
    void makeSound() const override {
        std::cout << "汪汪汪！\n";
    }
    
    // 重写虚函数
    void move() const override {
        std::cout << "狗在跑步\n";
    }
    
    // 狗特有的方法
    void wagTail() const {
        std::cout << "狗在摇尾巴\n";
    }
};