#include <iostream>
using namespace std;
int main()
{
    cout << "1234" << endl;
    cout.width(20);//设置宽度为10 等价于setw(10)
    cout.fill('*');//设置空白填充为'*'
    //设置左对齐
    cout.setf(ios_base::left); //等价于 cout << setiosflags(ios::right)
    cout << 3.1415926 << endl;
    //清除左对齐状态，默认是右对齐
    cout.unsetf(ios_base::left);//等价于 cout << resetiosflags(ios::right);
    cout.width(20);//若不重新指定宽度，后面将默认输出
    cout << 3.1415926 << endl;
    //若不指定填空字符，默认为上一次指定的字符。
    cout.setf(ios_base::showpoint);//以一般实数方式显示,默认保留五位小数
    cout.precision(6);//除小数点外保留6位有效数字
    cout << 3.1415926 << endl;
    cout.setf(ios_base::scientific);//以科学计数法显示，默认保留6位小数
    cout << 3.1415926 << endl;
    cout.precision(6);//e后面保留6位小数
    cout << 3.1415926 << endl;
    cout << hex << 123 << endl;//以十六进制输出
    cout << dec << 123 << endl;//以十进制输出
    cout << oct << 123 << endl;//以八进制输出
    char name[10];  //
    return 0;
}