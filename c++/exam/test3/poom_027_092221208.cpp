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
        std::cout << "沙发长度是" << _length << "米    材质是" << _wood << "\n";
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
        std::cout << "床的宽度是" << _width << "米    材质是" << _wood << "\n";
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
        std::cout << "沙发床长" << _length << "米         ";
        std::cout << "宽" << _width << "米    材质为" << Sofa::_wood << "\n";
    }
};

int main()
{
    Sofa sofa(2.0,"檀香木");
    Bed bed(1.5,"花梨木");
    Sofabed sbed(1.8,"梨木",1.5,"檀木");
    sofa.display();
    bed.display();
    sbed.display();
    return 0;
}