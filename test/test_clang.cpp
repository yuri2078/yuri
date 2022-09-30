#include <iostream>
#include <ostream>
#include <pthread.h>
#include <string>
#include <memory>

using namespace std;

class Person {
private:
	string name;
	int age;

public:
	Person() = default;
	Person(const string& name) {
		this->name = name;
		cout << this->name << "被构造\n";
	}
	~Person() {
		cout << this->name << "被析构\n";
    }

	void showInformation() {
		cout << "name : " << this->name << endl;
    }
	
};


int main() {

	auto p1 = make_shared<Person>("yuri is yes");

	p1->showInformation();
	return 0;
}