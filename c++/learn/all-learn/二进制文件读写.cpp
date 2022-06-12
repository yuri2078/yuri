#include <iostream>
#include <fstream>

int main()
{
    std::ifstream ifs;
    std::ofstream ofs;
    //或者直接指定 std::ofstream ofs("miku_copy.jpg",std::ios::out);
    ifs.open("file/miku.jpg", std::ios::in | std::ios::binary); //以二进制方法打开文件
    ofs.open("file/miku2.jpg", std::ios::out | std::ios::binary);
    if(!ifs.is_open() || !ofs.is_open())
    {
        std::cout << "打开 或 读取文件失败!\n";
        return 0;
    }

    char picture[204800] = {0};
    ifs.read(picture, 204800);
    ofs.write(picture, 204800);
    //通过二进制方法，读取复制数据
    //write 需要一个const char* 型的数据，所以需要转换
    
    ifs.close();
    ofs.close();
    return 0;
}