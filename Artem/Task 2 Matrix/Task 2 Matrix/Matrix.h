#pragma once
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<numeric>
#include<stdio.h>

using namespace std;

class Matrix
{
private:
	int** Matr;
	int n;
	void Create(int size);
public:
	Matrix(int _n =2, int _elem=2);   
	Matrix(const Matrix& matr);  
	~Matrix();   


	Matrix operator+(const Matrix& matr1);
	Matrix& operator=(const Matrix& matr);
	Matrix operator*(const Matrix& matr);
	Matrix operator*(int x);
	int& operator()(int i, int j);

	Matrix Transpose();
	bool IsDagonalDominance();

	friend ofstream& operator<<(ofstream& ofstream,  Matrix& matr);
	friend ifstream& operator>>(ifstream& ofstream, Matrix& matr);
};