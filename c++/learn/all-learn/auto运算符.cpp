#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

class Student
{

private:
  int age;

public:
  explicit Student()
  {
    age = 666;
  }

};

int main(int argc, char **argv)
{
    vector<int> v1;
    for(int i = 0; i < 10; i++){
      v1.push_back(i);
    }

    for (auto begin = v1.begin(); begin != v1.end(); begin++)
    {
      cout << *begin << " ";
    }
    cout << endl;
    for (vector<int>::iterator begin = v1.begin(); begin != v1.end(); begin++)
    {
      cout << *begin << " ";
    }
    cout << endl;
    return 0;
}
