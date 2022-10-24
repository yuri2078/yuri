#include <iostream>
#include <ostream>
#include <string>
#include <vector>
using std::string;
using std::vector;

int indexKMP(const string &s, const string & t, int start, const vector<int> &next)
{
	int i = start - 1, j = 0;
	while (i < s.length() && j < t.length()) {
		if (j == -1 || s[i] == t[j]) {
			i++;
			j++;
		}else {
            j = next[j];
        }
	}
	if (j >= t.length()) {
		return i - t.length() + 1;
    }
	return 0;
}

//求取模式串next值
void getNext(const string & t, vector<int> &next)
{
	int i = 0, j = -1;
	next[0] = -1;
	while (i < t.length()) {
		if (j == -1 || t[i] == t[j]) {
			i++;
			j++;
			next[i] = j;
		}
		else {
            j = next[j];
        }
	}
}

int main(int argc, const char* argv[])
{
	string s, t;
	std::cin >> t;
	vector<int> next(t.length());

	getNext(t, next);
	for (int x : next) {
		std::cout << x << " ";
	}
	std::cout << std::endl;
	return 0;
}
