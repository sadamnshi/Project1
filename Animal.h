#pragma once
#include <iostream>
using namespace std;
class Animal {
public:
    // 虚析构函数，确保正确释放派生类对象
    virtual ~Animal() = default;
    
    // 纯虚函数，使Animal成为抽象基类
    virtual void makeSound() const = 0;
    
    // 虚函数，可以被派生类重写
    virtual void move() const {
        std::cout << "动物在移动\n";
    }
    
    // 非虚函数
    void sleep() const {
        std::cout << "动物在睡觉\n";
    }
};