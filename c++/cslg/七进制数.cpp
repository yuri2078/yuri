#include <iostream>

using std::cout;
using std::cin;


void test(int x)
{
  if(x < 7){
    cout << x;
  }else{
    test(x / 7);
    cout << x % 7;
  }
}

int main()
{
  int x;
  cin >> x;
  if(x < 0)
  {
    x = -x;
    cout << "-";
  }
  test(x);
  cout << std::endl;
  return 0;
}
