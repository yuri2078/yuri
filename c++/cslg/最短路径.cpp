#include <iostream>
#include <vector>

using namespace std;

int cost(vector<vector<int>> &v, int i, int j){
    return min(abs(v[i][0] - v[j][0]), abs(v[i][1] - v[j][1]));
}

int main()
{
    int n, cost_sum(0);
    cin >> n;
    vector<vector<int>> point(n, vector<int> (2, 0));
    for (int i = 0; i < n;i++){
        cin >> point[i][0] >> point[i][1];
    }

    for (int i(0); i < n - 1;)
    {
        int k(i + 1);
        for (int j(i + 2); j < n; j++)
        {
            if(cost(point, i, j) < cost(point, i, k)){
                k = j;
            }
        }
        // cout << "i = " << i << "  k == " << k
        //      << "sum =" << cost(point, i, k) << endl;
        // cost_sum += cost(point, i, k);
        i = k;
    }
    cout << cost_sum << endl;
    return 0;
}