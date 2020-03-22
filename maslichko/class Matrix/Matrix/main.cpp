#include <iostream>
#include <fstream>
#include "matrix.h"

int main()
{
    setlocale(LC_ALL, "rus");
    int q, w, t;
    Matrix m1(4, 7), m2(4, 6), m3(4), m4(4);
    m3 = m1; //������������
    cout << m3 << endl;
    cout << "��������� ��������� ������: " << endl;
    m3 = m1 * m2; //��������� ������
    cout << m3 << endl;
    cout << "��������� �������� ������: " << endl;
    m4 = m1 + m2; //��������
    cout << m4 << endl;
    cout << "��������� ��������� ������� �� ����� 15: " << endl;
    m4 = m1 * 15; //��������� �� �����
    cout << m4 << endl;
    
    cout << "�������� �������" << endl;
    cout << "������� ���� �������: ";
    cin >> t; 
    Matrix m5(t);
    cin >> m5; //�������� �������

    cout << endl;
    cout << "����������������� �������" << endl;
    cout << m5.Transpos() << endl; //����������������

    //cin >> m5;
    cout << "������������ ������������: ";
    cout << m5.Diagonal() << endl; //������������ ������������
  
    cout << "������� ������� �������� ��������: "; 
    cin >> q >> w; //���� �������� ��������
    cout << m3(q, w); //����� �������� � ���������
  
    system("pause");
}