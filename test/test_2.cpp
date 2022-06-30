#include <iostream>
using std::cout;
using std::endl;
template <class T> 
class output{
	private:T _var;//变量
	public:
		output(const T& v):_var(v){}
		T var(){return _var;}};
int main(){
	output<double> x(1.0);
	output<int> j(3);
	output<char*> str("5.0");
	cout<<x.var()<<"  "<<j.var()<<endl;
	cout<<str.var()<<endl;
	return 0;}
