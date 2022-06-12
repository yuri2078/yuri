#include <iostream>
#include <fstream> //对文件进行操作必须要的头文件
//包含三个类
//ofstream 读操作 o output f file
//ifstream 读操作 i input
//fstream 读写操作 f 可读可写

int main()
{
    std::ofstream ofs; //建立文件输出流对象
    //或者直接指定 std::ofstream ofs("out.txt",std::ios::out);
    std::ifstream ifs; //建立文件读取流对象
    
    //ios::ate 初始位置 文件尾
    //ios::app 追加方式写文件
    //ios::trunc 如果文件存在先删除
    //ios::binary 以二进制方式打开文件
    ofs.open("file//out.txt", std::ios::out); //ios::out 以写方式打开
    ofs << "file//out.txt : hello world\n"; //写入文件
    ifs.open("file//in.txt", std::ios::in); //ios::in 以读方式打开
    //判断文件是否正常打开
    if(!ifs.is_open() || !ofs.is_open())
    {
        std::cout << "文件没有正常打开！\n";
        return 0;
    }

    std::string str1;

    //这种读取方式不会读取空格和回车 这两个会默认为一次读取结束标志
    //如过时字符类型读取 则一次读取一个字符，同样不会读取空格回车
    //utf 编码下，中文会乱码
    while(ifs >> str1) //读取文件，到尾部了会返回一个假
    {
        std::cout << str1 << " 读取暂停 ";
    }
    std::cout << "\n第二种读取方法\n";
    //让文件指针从新指向开头
    ifs.clear();
    ifs.seekg(0, std::ios::beg);
    // beg 从开头向后移动 cur 从当前向后移动 end 从结尾向后移动
    char str2[100] = {0};
    //使用gitline 必须要字符数组，前面数组，后面大小
    while(ifs.getline(str2,sizeof(str2))) //不会读取换行
    {
        std::cout << str2 << "读取暂停";
    }

    std::cout << "\n第三种读取方法\n";
    //让文件指针从新指向开头
    ifs.clear();
    ifs.seekg(0, std::ios::beg);
    std::string str3;
    //使用gitline 前面输入流 后面读取位置
    while(getline(ifs,str3))
    {
        std::cout << str3 << "读取暂停";
    }

    std::cout << "\n第四种读取方法\n";
    //让文件指针从新指向开头
    ifs.clear();
    ifs.seekg(0, std::ios::beg);
    char c;
    while((c = ifs.get()) != EOF)
    {
        std::cout << c ;
        // 这种方法可以读取空格和回车
    }

    

    ifs.close();//关闭文件
    ofs.close(); 
    return 0;
}