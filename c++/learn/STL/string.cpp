#include <iostream>
#include <string> 
//因为iostream 中有包含string 所以可以不用，不过最好写一下。
//每个库包含的类不同
//他是const char * 类型

int main()
{
//构造函数
    std::string str1; //默认构造函数
    std::string str2(str1); //拷贝构造函数，直接拷贝另一个
    std::string str3(11, 'c'); //用11个 c初始化字符串
    std::string str4("hello world"); //用别的字符串初始换string

//重载等于号
    str1 = str2; //直接string 赋值
    str1 = "hello world"; //直接赋值字符串
    str1 = 'c'; //直接赋值字符

//通过成员函数赋值
    str1.assign(str2); //把str2 直接赋值给自己
    str1.assign("hello"); //把字符串直接赋值给自己
    str1.assign("helo world", 10); //把字符串前10个字符赋值给自己
    str1.assign(10,'a'); //把10个a赋值给自己
    
    //通过成员函数连接
    str1.append("str2", 3); //把字符串前10个链接到str1 大于个数则报错 且只能是字符串，不能是string
    str1.append(str1, 1, 10); //把字符串从第1开始 的10个赋值给str1 可以是string 也可以是字符串
    std::cout << str1.find('e') << "\n";
    std::string str;
    std::cout << str1 << "\n";
    str.append(str1,10, 2);
    std::cout << str;
    //查找和替换
    // int find(const string& str, int pos = 0) const; //查找str第一次出现位置,从pos开始查找
    // int find(const char* s, int pos = 0) const; //查找s第一次出现位置,从pos开始查找
    // int find(const char* s, int pos, int n) const; //从pos位置查找s的前n个字符第一次位置
    // int find(const char c, int pos = 0) const; //查找字符c第一次出现位置
    // int rfind(const string& str, int pos = npos) const; //查找str最后一次位置,从pos开始查找
    // int rfind(const char* s, int pos = npos) const; //查找s最后一次出现位置,从pos开始查找
    // int rfind(const char* s, int pos, int n) const; //从pos查找s的前n个字符最后一次位置
    // int rfind(const char c, int pos = 0) const; //查找字符c最后一次出现位置
    // string& replace(int pos, int n, const string& str); //替换从pos开始n个字符为字符串str
    // string& replace(int pos, int n,const char* s); //替换从pos开始的n个字符为字符串s

    //字符串比较 比较ascii 字符，大于返回1，小于返回-1
    // int compare(const string &s) const; //与字符串s比较
    // int compare(const char *s) const; //与字符串s比较

    //字符串存取

    // char& operator[](int n); //通过[]方式取字符
    // char& at(int n); //通过at方法获取字符

//插入和删除

    // string& insert(int pos, const char* s); //插入字符串
    // string& insert(int pos, const string& str); //插入字符串
    // string& insert(int pos, int n, char c); //在指定位置插入n个字符c
    // string& erase(int pos, int n = npos); //删除从Pos开始的n个字符

//提取想要的字符串

    // string substr(int pos = 0, int n = npos) const;
    return 0;
}