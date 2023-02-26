#include <iostream>
#include <vector>

class list
{
private:
	int* data;
	int* next;

public:
	list(int x)
	    : next(nullptr)
	{
		data = new int(x);
	}

	~list()
	{
		delete data;
		data = nullptr;
	}

	class iterator
	{
	private:
		int* data;

	public:
		
		iterator(int* data) : data(data)
		{
		}

		int operator*()
		{
			return *data;
		}
		
	};

	iterator begin() noexcept
	{
		iterator itr(this->data);
		return itr;
	}

	iterator end() noexcept
	{
		return nullptr;
	}

	void addData(int x)
	{
		this->next = new int(x);

	}
	
};

int main()
{
	// list head(20);
	// list::iterator begin = head.begin();
	// std::cout << "*begin = " << *begin << std::endl;
	// std::cout << *head << std::endl;
	// std::vector<int> vec(20);
	// std::cout << vec.size() << std::endl;

}