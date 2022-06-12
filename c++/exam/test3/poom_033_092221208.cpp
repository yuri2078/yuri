#include <iostream>
class Matrix
{
private:
    int matrix[2][3];

public:
    friend Matrix operator+(const Matrix &m1, const Matrix &m2);
    friend std::istream &operator>>(std::istream &cin, Matrix &m);
    friend std::ostream &operator<<(std::ostream &cout, const Matrix &m);
    
    Matrix()
    {
        for (int i = 0; i < 2;i++)
        {
            for (int j = 0; j < 3;j++)
            {
                matrix[i][j] = 0;
            }
        }
    }
};

Matrix operator+ (const Matrix &m1, const Matrix &m2)
{
    Matrix m;
    for (int i = 0; i < 2;i++)
    {
        for (int j = 0; j < 3;j++)
        {
            m.matrix[i][j] = m1.matrix[i][j] + m2.matrix[i][j];
        }
    }
    return m;
}

std::istream & operator>> (std::istream &cin,Matrix &m)
{
    std::cout << "input value of matrix:\n";
    for (int i = 0; i < 2;i++)
    {
        for (int j = 0; j < 3;j++)
        {
            std::cin >> m.matrix[i][j];
        }
    }
    return std::cin;
}

std::ostream & operator<< (std::ostream &cout, const Matrix &m)
{
    for (int i = 0; i < 2;i++)
    {
        for (int j = 0; j < 3;j++)
        {
            std::cout << m.matrix[i][j] << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
    return std::cout;
}

int main()
{
    Matrix m1, m2;
    std::cin >> m1 >> m2;
    std::cout << "\nmatrix a:\n" << m1 << "matrix b:\n" << m2;
    std::cout << "\nmatrix c = matrix a + matrix b :\n" << m1 + m2;
    return 0;
}
