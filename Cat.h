#pragma once
#include "Animal.h"
#include <iostream>
using namespace std;
class Cat : public Animal {
public:
    // 重写纯虚函数
    void makeSound() const override {
        std::cout << "喵喵喵！\n";
    }
    
    // 重写虚函数
    void move() const override {
        std::cout << "猫在悄悄走路\n";
    }
    
    // 猫特有的方法
    void climb() const {
        std::cout << "猫在爬树\n";
    }
};