//
// Created by yuri on 22-11-10.
//

#ifndef LOG_YURI_H
#define LOG_YURI_H


#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <ctime>

// class MyIterator : public std::iterator<std::random_access_iterator_tag, T t>

namespace yuri
{

class Aerror
{
public:
	Aerror() = default;
	~Aerror() = default;

	template <typename T>
	Aerror& operator<<(T &&s)
	{
		std::cout << "\e[31m" << s << "\e[0m";
		return *this;
	}

	// 日志类
};


class Yuri
{
private:
	Aerror error;
	bool is_single;
	std::string in_file;
	std::string out_file;
	unsigned int col;
	unsigned int row;
	std::unique_ptr<std::vector<std::vector<int>>> data;
	std::unique_ptr<std::vector<int>> data_single;

	// 检查文件类型设置为私有
	void checkFile(std::fstream& fst, std::string& load, std::ios_base::openmode __mode)
	{
		fst.open(load, __mode);
		if (!fst.is_open()) {
			// 打开失败则新建一个
			if (__mode == std::ios::in) {
				std::cout << "\n\n文件读取 打开错误! 错误位置 " << load << std::endl;
				std::exit(2);
			}
			fst.open(load, std::ios::out);
			if (!fst.is_open()) {
				std::cout << "\n\n文件打开错误! 错误位置 " << load << std::endl;
				std::exit(3);
			}
		}
	}
public:
	Yuri()
	{
		is_single = false;
		this->in_file = "in.txt";
		this->out_file = "out.txt";
		this->col = 0;
		this->row = 0;
		data = nullptr;
		data_single = nullptr;
	}

	~Yuri() = default;

	std::vector<std::vector<int>>& getData()
	{
		std::fstream fst;
		checkFile(fst, in_file, std::ios::in);
		fst >> row >> col;
		data = std::make_unique<std::vector<std::vector<int>>>(
			row, std::vector<int>(col));
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				fst >> (*data)[i][j];
			}
		}
		fst.close();
		return (*data);
	}

	std::vector<int>& getData(bool)
	{
		this->is_single = true;
		this->row = 1;
		std::fstream fst;
		checkFile(fst, in_file, std::ios::in);
		fst >> col;
		data_single = std::make_unique<std::vector<int>>(col);
		for (int i = 0; i < col; i++) {
			fst >> (*data_single)[i];
		}
		fst.close();
		return (*data_single);
	}


	void outData(bool clean_ = false)
	{
		std::fstream fst;
		if (clean_) {
			checkFile(fst, out_file, std::ios::out);
		} else {
			checkFile(fst, out_file, std::ios::app);
		}
		
		if (is_single && data_single) {
			for (int x: (*data_single)) {
				fst << x << " ";
			}
			fst << "\n";
		} else if (data) {
			for (auto v: (*data)) {
				for (int x: v) {
					fst << x << " ";
				}
				fst << "\n";
			}
		}
		fst.close();
	}

	template <typename T>
	Yuri& operator<< (T value)
	{
		std::fstream fst;
		checkFile(fst, out_file, std::ios::app);
		fst << value;
		fst.close();
		return *this;
	}

	
	void cleanLog()
	{
		std::fstream fst;
		fst.open(out_file, std::ios::out);
		fst.close();
	}

	template <typename T, typename ...Args>
	static clock_t used_time(T cp, Args&&...args)
	{
		clock_t start, end;
		start = clock();
		cp(args...);
		end = clock();
		return end - start;
	}

	std::string setOutFile(std::string&& out)
	{
		this->out_file = out;
		return this->out_file;
	}

	std::string setInFile(std::string&& out)
	{
		this->out_file = out;
		return this->out_file;
	}

	// 返回最大的下标(仅限一维数组)
	int getMaxVal()
	{
		if (is_single == false) {
			error << "错误捏，不是一维数组\n";
			return -1;
		}
		int max_val = -1, size = this->data_single->size();
		for (int i = 0; i < size; i++) {
			if ((max_val = -1) || (*data_single)[i] < (*data_single)[max_val]) {
				max_val = i;
			}
		}
		return max_val;
	}
};



} // namespace yuri



#endif //LOG_YURI_H
