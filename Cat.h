#pragma once
#include "Animal.h"
#include <iostream>
using namespace std;
class Cat : public Animal {
public:
    // ��д���麯��
    void makeSound() const override {
        std::cout << "��������\n";
    }
    
    // ��д�麯��
    void move() const override {
        std::cout << "è��������·\n";
    }
    
    // è���еķ���
    void climb() const {
        std::cout << "è������\n";
    }
};