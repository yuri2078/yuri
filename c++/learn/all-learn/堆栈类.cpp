#include <iostream>

using std::cout;
using std::endl;
using std::string;

template <class T>
class SqStack
{
private:
    T *top;
    T *base;
    int size;
public:
    SqStack(int size)
    {
        this->base = (T * )(malloc(size * sizeof(T)));
        if(!this->base){
            cout << "分内存失败！\n";
        }
        this->size = size;
        top = base;
    }

    bool push(T data)
    {
        if(top-base == size)
        {
            base = (T *)realloc(base, (size + 1) * sizeof(T));
            if(!base){
                return false;
            }
            top = base + size;
            size++;
            cout << "容量不够，已经进行扩容处理\n";
        }

        *top = data;
        top++;

        return true;
    }

    T pop()
    {
        if(top == base)
        {
            cout << "堆栈已经为空，无法弹出数据\n";
            return 0;
        }
        top--;
        return *top;
    }

    T getDate()
    {
        if(top == base)
        {
            cout << "堆栈已经为空，无法获取数据\n";
            return 0;
        }
        return *(top - 1);
    }

    void showSqStack()
    {
        T *p = base;
        while(p != top)
        {
            cout << "number : " << *p << endl;
            p++;
        }

    }

    ~SqStack(){
        free(base);
    }

};

int main(int argc, const char **argv)
{

    SqStack<int> s1(3);
    s1.showSqStack();

    return 0;
}
