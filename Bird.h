#pragma once
#include "Animal.h"
#include <iostream>
using namespace std;
class Bird : public Animal {
public:
    // ��д���麯��
    void makeSound() const override {
        std::cout << "ߴߴ������\n";
    }
    
    // ��д�麯��
    void move() const override {
        std::cout << "���ڷ���\n";
    }
    
    // �����еķ���
    void fly() const {
        std::cout << "���ڸ߿շ���\n";
    }
};