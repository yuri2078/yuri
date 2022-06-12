#include <iostream>

class CMatrix
{
private:
    int m_nRow;
    int m_nCol;
    int **m_pData;
public:
    CMatrix() { m_nRow = m_nCol = 0; }
    CMatrix(int m_nRow, int m_nCol);
    CMatrix(const CMatrix &m);
    ~CMatrix();
    void output(void);
    int Get_m_nRow(void) { return m_nRow; }
    int Get_m_nCol(void) { return m_nCol; }
};

CMatrix::CMatrix(int m_nRow, int m_nCol)
{
    this->m_nRow = m_nRow;
    this->m_nCol = m_nCol;
    std::cout << "请初始化" << m_nRow << "行" << m_nCol << "列矩阵元素\n";
    m_pData = new int *[m_nRow];
    for (int i = 0; i < m_nRow;i++)
    {
        m_pData[i] = new int[m_nCol];
        for (int j = 0; j < m_nCol;j++)
        {
            std::cin >> m_pData[i][j];
        }
    }
}

CMatrix::~CMatrix()
{
    for (int i = 0; i < m_nRow;i++)
    {
        delete m_pData[i];
    }
    delete m_pData;    
}

CMatrix::CMatrix(const CMatrix &m)
{
    m_nRow = m.m_nRow;
    m_nCol = m.m_nCol;
    m_pData = new int *[m.m_nRow];
    for (int i = 0; i < m_nRow;i++)
    {
        m_pData[i] = new int[m.m_nCol];
        for (int j = 0; j < m_nCol;j++)
        {
            m_pData[i][j] = m.m_pData[i][j];
        }
    }
}

void CMatrix::output(void)
{
    for (int i = 0; i < m_nRow;i++)
    {
        for (int j = 0; j < m_nCol;j++)
        {
            std::cout << m_pData[i][j] << " ";
        }
        std::cout << "\n";
    }
}

int main()
{
    int row, col;
    std::cout << "请输入矩阵的行数：";
    std:: cin >> row;
    std::cout << "请输入矩阵的列数：";
    std:: cin >> col;
    CMatrix m1(row, col);
    std::cout << "使用拷贝构造函数后，m2对象的矩阵为\n";
    CMatrix m2(m1);
    m2.output();
    return 0;
}