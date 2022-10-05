#include <iostream>
#include <ostream>
#include <type_traits>

using namespace std;
//命名空间
// c++ 有许多的函数、变量、他们放在不同的房间
//需要加上房间的名字才能找到他们
// 有一个基本的房间，放了许多的基础的东西。这个房间是std

namespace yuri {
typedef std::string yuri_name;
typedef int yuri_age;

} // namespace yuri

int main(int argc, const char** argv) {
	int x;
	cin >> x;
	for (int i=0; i<x; i++) {
        cout << i << " ";
        }
    

	yuri::yuri_name hello = "yuri is yes!";
	cout << "yuri name is : " << hello << endl;
	

	return 0;
}

