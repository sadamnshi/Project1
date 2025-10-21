#pragma once
#include <iostream>
using namespace std;
class Animal {
public:
    // ������������ȷ����ȷ�ͷ����������
    virtual ~Animal() = default;
    
    // ���麯����ʹAnimal��Ϊ�������
    virtual void makeSound() const = 0;
    
    // �麯�������Ա���������д
    virtual void move() const {
        std::cout << "�������ƶ�\n";
    }
    
    // ���麯��
    void sleep() const {
        std::cout << "������˯��\n";
    }
};