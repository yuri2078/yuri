#include "cyber/demo_protobuf/test_01/student.pb.h"

int main(int argc, char const *argv[])
{
    apollo::cyber::demo_protobuf::Student stu; //声明新的对象

    //添加新的数据
    stu.set_name("yuri"); 
    stu.set_age(18);
    stu.set_height(166);
    stu.add_books("终将成为你，安达与岛村");

    //打印数据

    std::cout << "打印数据 ------- \n";
    std::cout << "name : " << stu.name() << std::endl;
    std::cout << "age : " << stu.age() << std::endl;
    std::cout << "height : " << stu.height() << std::endl;
    auto books = stu.books();
    for(auto begin = books.begin(); begin != books.end();begin++){
        std::cout << " " << *begin;
    }
    std::cout << "\n输出结束\n";
    return 0;
}
