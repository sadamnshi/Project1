#pragma once
#include "Animal.h"
#include <iostream>
using namespace std;
class Dog : public Animal {
public:
    // ��д���麯��
    void makeSound() const override {
        std::cout << "��������\n";
    }
    
    // ��д�麯��
    void move() const override {
        std::cout << "�����ܲ�\n";
    }
    
    // �����еķ���
    void wagTail() const {
        std::cout << "����ҡβ��\n";
    }
};