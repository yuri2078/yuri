#pragma once
#include <iostream>

template <class T>
class Array
{
private:
    int len;
    int size;
    T *array;

public:
    Array(int size);
    ~Array();
    Array(const Array &a); //深拷贝
    void display(void); //打印函数
    void addArray(T x); //打印函数
    void delArray(void); //打印函数 
    Array &operator=(const Array &a)
    {
        std::cout << "\n类模板 = 号重载 调用\n";
        int length = this->len < a.len ? this->len : a.len;
        this->len = length;
        for (int i = 0; i < length;i++)
        {
            this->array[i] = a.array[i];
        }
        return *this;
    }

    T& operator[](int i)
    {
        if(i < this->len && i > -1)
            return this->array[i];
        else
        {
            std::cout << "\n没有值给你返回捏！ 那就给你返回第一个吧\n";
            return this->array[0];
        }
    }
};


template <class T>
Array<T>::Array(int size)
{
    std::cout << "\n类模板 构造函数调用\n";
    if(size < 1)
    {
        std::cout << "\n都小于1了你创建个棒槌捏!帮你改成1了\n";
        size = 1;
    }
    this->len = this->size = size;
    array = new T[size];
    for (int i = 0; i < size;i++)
    {
        this->array[i] = i;
    }
}

template <class T>
Array<T>::~Array()
{
    if(this->array != NULL)
    {
        delete[] array; //删除整个数组
        array = NULL;
        std::cout << "\n类模板 析构函数调用\n";
    }
}

template <class T>
Array<T>::Array(const Array &a)
{
    std::cout << "\n类模板 拷贝构造函数调用\n";
    this->len = a.len;
    this->size = a.size;
    this->array = new T[a.size];
    for (int i = 0; i < a.size;i++)
    {
        this->array[i] = a.array[i];
    }
}

template <class T>
void Array<T>::display(void)
{
    std::cout << "size = " << this->size << "\n";
    std::cout << "len = " << this->len << "\n";
    for(int i = 0; i < this->len;i++)
    {
        std::cout << "array[" << i << "] = " << array[i] << "  ";
    }
    std::cout << "\n";
}

template <class T>
void Array<T>::addArray(T x)
{
    if(this->size == this->len)
    {
        std::cout << "\n空间已经满了，赶紧爬\n";
    }
    else
    {
        this->array[len] = x;
        len++;
    }
}

template <class T>
void Array<T>::delArray(void)
{
    if(len == 0)
    {
        std::cout << "\n都删光光了呀！\n";
    }
    else
    {
        len--;
    }
}


