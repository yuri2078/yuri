#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int x;
    cin >> x;
    vector<int> v(x, 0);
    for (int i = 0; i < x;i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    if(x%2){
        cout << v[x / 2] << endl;
    }else if ((v[x / 2 - 1] + v[x / 2])%2){
        cout << (v[x / 2 - 1] + v[x / 2]) / 2 + 1;
    }else{
        cout << (v[x / 2 - 1] + v[x / 2]) / 2;
    }
    return 0;
}