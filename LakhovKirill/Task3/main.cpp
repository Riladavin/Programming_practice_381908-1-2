//
// Created by Kirill Lakhov on 19.02.2020.
//
#include "Word.h"
#include "vector"
#include "iostream"
#include "string"

int main(){
    //������ �� �������

    //�������� �����
    auto word1 = new Word(); //��� �������� � �����
    auto word2 = new Word("cat","���"); //����� � ���� �������
    auto word3 = new Word("cake", vector<string>{"����","��������"}); //����� � ��������� ��������

    //���������� �����
    word1->setWord("dog");

    //����������� �������(�������� ���������) (����� ������ ��������� ��������� ��������)
    word1->setTranslation("������");

    //�������� �������(���� ������ ��� ���, �������) (����� ������ ��������� ��������� ��������)
    word1->addTranslation("�������");



    return 0;
}

