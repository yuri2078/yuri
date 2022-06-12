#include <iostream>
#include <cstring>
class Furniture
{
protected:
    char _wood[20];
public:
    Furniture(const char *_wood)
    {
        strcpy(this->_wood, _wood);
    }
};

class Sofa : public Furniture
{
protected:
    double _length;
public:
    Sofa(double _length, const char *_wood) : Furniture(_wood)
    {
        this->_length = _length;
    }
    void display(void)
    {
        std::cout << "ɳ��������" << _length << "��    ������" << _wood << "\n";
    }
};

class Bed : public Furniture
{
protected:
    double _width;
public:
    Bed(double _width, const char *_wood) : Furniture(_wood)
    {
        this->_width = _width;
    }
    void display(void)
    {
        std::cout << "���Ŀ����" << _width << "��    ������" << _wood << "\n";
    }
};

class Sofabed : public Sofa, public Bed
{
public:
    Sofabed(double _length,const char *Sofa_wood, double _width, const char *Bed_wood) : Sofa(_length, Sofa_wood), Bed(_width, Bed_wood)
    {
        
    }
    void display(void)
    {
        std::cout << "ɳ������" << _length << "��         ";
        std::cout << "��" << _width << "��    ����Ϊ" << Sofa::_wood << "\n";
    }
};

int main()
{
    Sofa sofa(2.0,"̴��ľ");
    Bed bed(1.5,"����ľ");
    Sofabed sbed(1.8,"��ľ",1.5,"̴ľ");
    sofa.display();
    bed.display();
    sbed.display();
    return 0;
}