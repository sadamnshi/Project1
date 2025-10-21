#pragma once
#include "Animal.h"
#include <iostream>
using namespace std;
class Bird : public Animal {
public:
    // 重写纯虚函数
    void makeSound() const override {
        std::cout << "叽叽喳喳！\n";
    }
    
    // 重写虚函数
    void move() const override {
        std::cout << "鸟在飞翔\n";
    }
    
    // 鸟特有的方法
    void fly() const {
        std::cout << "鸟在高空飞行\n";
    }
};