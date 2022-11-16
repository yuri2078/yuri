#include <iostream>
#include <string>

template <typename value_type>
class vector
{
private:
	value_type* begin;
	value_type* end;
	value_type* tail;

public:
	vector() noexcept
	{
        begin = static_cast<value_type*>(::operator new(16 * sizeof(value_type)));
        if (begin == nullptr) {
            std::cout << "分配失败捏\n";
		}
		end = begin;
		tail = begin + 16;
	}

	vector(vector<value_type> &v) noexcept
	{
		std::cout << "拷贝构造函数调用\n";
        begin = static_cast<value_type*>(::operator new(v.max_size() * sizeof(value_type)));
        if (begin == nullptr) {
            std::cout << "分配失败捏\n";
		}
		end = begin + v.size();
		tail = begin + v.max_size();
		for (int i = 0; i < v.size(); i++) {
			*(begin + i) = *(v.begin + i);
		}
	}

	vector(vector<value_type> &&v) noexcept
	{
		std::cout << "移动构造函数调用\n";
		begin = v.begin;
		end = v.end;
		tail = v.tail;
		v.begin = nullptr;
		v.end = nullptr;
		v.tail = nullptr;
	}

	~vector()
	{
		if (begin == nullptr) {
			return;
		}
		::operator delete(begin);
		begin = nullptr;
		end = nullptr;
		tail = nullptr;
	}
	
	void push_back(value_type& value)
	{
		if (end == tail) {
			relloc();
        }
		*end++ = value;
	}

	void push_back(value_type&& value)
	{
		if (end == tail) {
			relloc();
		}
		std::cout << "move 调用移动\n";
		*end++ = std::move(value);
	}

	void relloc()
	{
		std::cout << "内存不足，已经进行扩容处理\n";
		value_type* new_begin = static_cast<value_type*>(::operator new(size() * 2 * sizeof(value_type)));
		if (new_begin == nullptr) {
			std::cout << "重新分配内存失败捏\n";
			exit(1);
		}
		value_type* new_end = new_begin + size();
		value_type* new_tail = new_begin + size() * 2;
		value_type * start = begin;
		for (int i = 0; start != end; i++) {
			*(new_begin + i) = *start++;
        }
		delete begin;
		begin = new_begin;
		end = new_end;
		tail = new_tail;
    }
    
    const int size(){
        return end - begin;
    }
    const int max_size(){
        return tail - begin;
    }
	
	value_type& operator[](int k)
	{
        if (k >= end - begin) {
			std::cout << "错误!超出数据范围\n";
			exit(2);
        }
        return *(begin + k);
	}

	value_type& at(int k)
	{
        if (k >= end - begin) {
			std::cout << "错误!超出数据范围\n";
			exit(2);
        }
        return *(begin + k);
	}

	void operator=(vector<value_type> &v)
	{
		std::cout << "= 号重造函数\n";
        begin = static_cast<value_type*>(::operator new(v.max_size() * sizeof(value_type)));
        if (begin == nullptr) {
			std::cout << "分配失败捏\n";
			exit(1);
		}
		end = begin + v.size();
		tail = begin + v.max_size();
		for (int i = 0; i < v.size(); i++) {
			*(begin + i) = *(v.begin + i);
		}
	}
};


int main()
{
	vector<int> vec;
	for (int i = 0; i < 20; i++) {
		vec.push_back(i);
	}
	vec.push_back(66);
	vector<int> v(std::move(vec));
	std::cout << vec[1] << std::endl;
	// vector<int>* v = new vector<int>;
	// *v = vec;
	vector<vector<int>> vv;
	vv.push_back(v);
	vv[0][1] = 555;
	vv.push_back(v);
	vv.push_back(v);
	for (int j = 0; j < vv.size(); j++) {
		for (int i = 0; i < vv[j].size(); i++) {
			std::cout << vv[j][i] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
    return 0;
}