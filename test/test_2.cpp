
#include <iostream>
#include <ostream>
#include <string>
#include <unordered_map>
#include <utility>
using namespace std;
int main()
{
	string s = "iijfj";
	cout << s.find('f') << s.rfind('f') << endl;
	return 0;
}