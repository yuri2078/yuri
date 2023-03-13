#include <fstream>
#include <iostream>
#include <regex>
#include <string>
#include <vector>

using namespace std;

typedef struct Data {
	string database_name;
	vector<string> titles;
	vector<vector<string>> values;
	int titles_len;
	int values_len;
	Data()
	{
		titles_len = 0;
		values_len = 0;
	}
} Data;

int getTitle(fstream& fst, Data& data)
{
	vector<string>& titles = data.titles;
	string str;
	getline(fst, data.database_name);
	cout << "读取到的数据库名字 -> " << data.database_name << endl;
	getline(fst, str);
	regex rege("\\S+");
	smatch match;
	while (regex_search(str, match, rege)) {
		titles.push_back(match[0].str());
		str = match.suffix().str();
	}
	data.titles_len = titles.size();
	cout << "读取到的标题共有 -> " << data.titles_len << " 个\n\n";
	for (auto title: titles) {
		cout << title << " ";
	}
	cout << endl;
	return data.titles_len;
}

int getValues(fstream& fst, Data& data)
{
	string str;
	vector<vector<string>>& values = data.values;
	regex rege("\\S+");
	smatch match;
	while (getline(fst, str)) {
		vector<string> value;
		while (regex_search(str, match, rege)) {
			value.push_back(match[0].str());
			str = match.suffix().str();
		}
		values.push_back(value);
	}
	data.values_len = values.size();
	cout << "\n\n读取到的数据共有 ->  " <<  data.values_len << " 条\n\n";

	for (auto value: values) {
		for (auto val: value) {
			cout << val << " ";
		}
		cout << endl;
	}
	return data.values_len;
}

int dataProcessing(Data& data)
{
	fstream fst;
	fst.open("out.sql", ios::out);
	fst << "insert into " + data.database_name + " (\n    ";
	for (int i = 0; i < data.titles_len; i++) {
		fst << data.titles[i];
		if (i == data.titles_len - 1) {
			fst << "\n) values ";
		} else {
			fst << ", ";
		}
	}

	for (int i = 0; i < data.values.size(); i++) {
		fst << "(";
		for (int j = 0; j < data.values[i].size(); j++) {
			if (data.values[i][j] == "NULL") {
				fst << data.values[i][j];
			} else {
				fst << "'" + data.values[i][j] + "'";
			}
			
			if (j != data.values[i].size() - 1) {
				fst << ", ";
			}
		}
		if (i != data.values.size() - 1) {
			fst << "),\n";
		} else {
			fst << ");\n";
		}

	}
	fst.close();
	return 0;
}

int main()
{
	fstream fst;
	Data data;
	fst.open("in.txt", ios::in);
	if (!fst.is_open()) {
		cout << "文件打开失败!"
		     << " 请在同级目录中将数据存入in.txt\n";
		return 1;
	}
	getTitle(fst, data);
	getValues(fst, data);
	dataProcessing(data);
	fst.close();
	return 0;
}