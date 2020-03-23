#include"matrix.h"
#include <chrono>
#include <ctime>

//�����������
void Matrix::Create(int xx)
{
    row = xx;
    mat = new int* [xx];
    for (int i = 0; i < xx; i++)
    {
        mat[i] = new int[xx];
    }
}

Matrix::Matrix(const Matrix& m)
{
    Create(m.row);
    for (int i = 0; i < m.row; i++)
    {
        for (int j = 0; j < m.row; j++)
        {
            mat[i][j] = m.mat[i][j];
        }
    }
}

Matrix::Matrix(int nrow, int elem)
{
    Create(nrow);
    for (int i = 0; i < nrow; i++)
    {
        for (int j = 0; j < nrow; j++)
        {
            mat[i][j] = elem;
        }
    }
}

Matrix::Matrix(string name)
{
    ifstream in(name);  //���� ��������� � ����� �������
    in >> row;
    Create(row);
    for (int i = 0; i < row; i++)
        for (int j = 0; j < row; j++)
            in >> mat[i][j];
}

//����������
Matrix :: ~Matrix()
{
    for (int i = 0; i < row; i++)
        delete[] mat[i];
    if (mat != NULL)
        delete[] mat;
    row = 0;
}

//������
bool Matrix::IsDiagonal()
{
    for (int i = 0; i < row; i++)
    {
        long long sum = 0;
        for (int j = 0; j < row; j++)
        {
            if (j == i) continue;
            sum += abs(mat[i][j]);
        }
        if (sum > abs(mat[i][i]))
        {
            return false;
        }
    }
    return true;
}

Matrix Matrix::Transpos()
{
    Matrix res(row);
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < row; j++)
        {
            res(j, i) = mat[i][j];
        }
    }
    return res;
}

Matrix Matrix::operator*(const int x)
{
    Matrix res(row);
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < row; j++)
        {
            res(i, j) = mat[i][j] * x;
        }
    }
    return res;
}

Matrix Matrix::operator*(const Matrix& m)
{
    if (row == m.row)
    {
        Matrix res(row);
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < row; j++)
            {
                int x = 0;
                for (int k = 0; k < row; k++)
                    x += mat[i][k] * m.mat[k][j];
                res(i, j) = x;
            }
        }
        return res;
    }
    else
    {
        cout << "������� ����� ������ ����" << endl;
        throw 1;
    }
}

Matrix& Matrix::operator=(const Matrix& m)
{
    if (row == m.row)
    {
        for (int i = 0; i < row; i++)
            delete[] mat[i];
        if (mat != NULL)
            delete[] mat;
        row = m.row;
        Create(row);
    }
    if (this == &m) return *this;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < row; j++)
        {
            mat[i][j] = m.mat[i][j];
        }
    }
    return *this;
}

Matrix Matrix::operator+(const Matrix& m)
{
    if (row == m.row)
    {
        Matrix res(row);
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < row; j++)
            {
                res(i, j) = mat[i][j] + m.mat[i][j];
            }
        }
        return res;
    }
    else
    {
        cout << "������� ����� ������ ����" << endl;
        throw 1;
    }
}

int& Matrix::operator()(int i, int j)
{
    if (i < row && j < row && i >= 0 && j >= 0)
    {
        return mat[i][j];
    }
    else
    {
        cout << "������ �������� ���" << endl;
        throw 1;
    }
}

//���� � �����
ostream& operator<<(ostream& ofstream, const Matrix& m)
{
    for (int i = 0; i < m.row; i++)
    {
        for (int j = 0; j < m.row; j++)
        {
            ofstream << m.mat[i][j] << " ";
        }
        ofstream << "\n";
    }
    return ofstream;
}

istream& operator>>(istream& ofstream, Matrix& m)
{
    cout << "������� ���������� ��������� � ������";
    int r;
    cin >> r;
    cout << "������� �������� �������: " << endl;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < r; j++)
        {
            ofstream >> m.mat[i][j];
        }
    }
    return ofstream;
}
