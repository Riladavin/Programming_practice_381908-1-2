//
// Created by Kirill Lakhov on 19.02.2020.
//
#include "Word.h"
#include "Dictionary.h"
#include "vector"
#include "iostream"
#include "string"

int main(){
    setlocale(LC_ALL, "Russian");
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

    word3->setTranslation(vector<string>{"����123","!@#."}); //������ �� �� ���� �� ����� ��������

    //������ �� ��������

    //������ �������
    auto dictionary  = new Dictionary();

    //������� �� �����

    //**��� �������� ��� �������� ���������� true/false ���������� ����� ��� ������� ��������**

    //�������� ����� � �������
    dictionary->addWord(word1);
    dictionary->addWord(word2);
    dictionary->addWord(word3);
    //��������� �� ����� ������ �� ���� ������ ������� (���� ��� ���������, ����������)
    word1->addTranslation("���");

    //���� ����� � ����� ��������� ��� ����������, ��� ����� ��������� ������������
    auto word4 = new Word("cat", "�����");
    dictionary->addWord(word4);

    //��������� ����������� ����� ���������� �����, � ������ ��� ������������� � �������, �������� ����� �������
    dictionary->mergeAddWord(word2);

    //��������� ������� ����� � ������� (0 - ���� ����� ���, ����� ��� id)
    dictionary->find("cat");

    //�������� ������ �� ����� � ������� (����� ���� ���������� ��������� ��� ������� � �������)
    if(dictionary->find("dog")) auto word5 = dictionary->get("dog");

    //������ ���������� ���� � �������
    int amount = dictionary->wordsCount();

    //�������� ������� �� ����� ����������� � ��������� ���� (.txt)
    dictionary->out("myDictionary.txt");

    //�������� ������� �� �����
    auto inDictionary = new Dictionary("readDictionary.txt");

    //��������� ��������� �������� �� ��������
    if(inDictionary->find("cake")) {
        Word* myWord = inDictionary->get("cake");
        myWord->setTranslation("����");
    }
    auto word6 = new Word("beauty", "�������");
    inDictionary->mergeAddWord(word6);

    //����� �������� ��� ���� ����
    inDictionary->out("testReadDictionary.txt");
    return 0;
}

