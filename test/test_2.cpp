#include <iostream>
#include <string>
#include <exception>
using namespace std;

void func_inner(){
    throw "Unknown Exception";  //抛出异常
    cout<<"[1]This statement will not be executed."<<endl;
}

void func_outer(){
    func_inner();
    cout<<"[2]This statement will not be executed."<<endl;
}

int main(){
    try{
        func_outer();
        cout<<"[3]This statement will not be executed."<<endl;
    }catch(const char* &e){
        cout<<e<<endl;
    }
    {
        {
            
        }
    }

    return 0;
}