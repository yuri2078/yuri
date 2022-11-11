#include "yuri.h"
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int cost(const vector<int> &p1,const vector<int> &p2 ){
	int x_1 = abs(p1[0] - p2[0]);
	int x_2 = abs(p1[1] - p2[1]);
	return x_1 > x_2 ? x_2 : x_1;
}

void getValue(vector<vector<int>>& v, vector<vector<int>>& marix)
{
	const int size = v.size();
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			marix[i][j] = marix[j][i] = cost(v[i], v[j]);
        }
    }
}

int result(vector <vector<int>> & v)
{
	const int size = v.size();
	yuri::clear_log();
	yuri::Data data;
	auto& marix = data.getData(size, size, -1);
	getValue(v, marix);
	data.outData();
	yuri::log(" ----- ");
	vector<int> map(size, 1);
	map[0] = 0;
	int k = 0;
	int len = 0;
	while (k != size - 1) {
		
		int min = -1;
		for (int i = 0; i < size; i++) {
			if (map[i]) {
				if (min == -1 || marix[k][i] < marix[k][min]) {
					min = i;
				}
			}
		}
		map[min] = 0;
		len += marix[k][min];
		yuri::log(map);
		yuri::log("min : ", min);
		
		for (int i = 0; i < size; i++) {
			if (map[i]) {
				if (len + marix[min][i] < marix[0][i]) {
					marix[0][i] = len + marix[min][i];
                }
            }
		}
		k = min;
		data.outData();
		yuri::log("");
		
	}
	return marix[0][size - 1];
}
	

int main()
{
	
	yuri::Data data;
	vector<vector<int>> & v = data.getData();
	cout << result(v) << endl;

    return 0;
}