#ifndef VECTOR_H
#define VECTOR_H
// 自己写的vector容器

#include "allocator.h" 
#include "base.h"
#include <stdexcept>
namespace yuriSTL {


template <typename T>
class vector
{
public:
	typedef T value_type;
	typedef T* iterator;
	
private:
	value_type* begin_; // 内存开始
	value_type* end_; // 最后一个元素的下一个位置
	value_type* tail_; // 内存块的最后一块地址
	yuriSTL::allocator<T> alloc; // 新建分配内存的工具

public:
	vector() noexcept
	{
		begin_ = alloc.allocate(16); // 默认分一块内存
        if (begin_ == nullptr) {
			yuriSTL::log("内存分配失败捏!");
			exit(1);
		}
		// 更细指针位置
		end_ = begin_; 
		tail_ = begin_ + 16;
	}
	
	// 拷贝构造函数
	vector(vector<value_type> &v) noexcept
	{
		// 新建一块和他一样大的内存
        begin_ = alloc.allocate(v.max_size());
        if (begin_ == nullptr) {
			yuriSTL::log("内存分配失败捏!");
			exit(1);
		}
		// 更新指针区域
		const int size = v.size();
		end_ = begin_ + size;
		tail_ = begin_ + v.max_size();
		// 调用构造函数进行构造
		for (int i = 0; i < size; i++) {
			alloc.construct(begin_ + i, *(v.begin() + i));
		}
	}

	// 移动构造函数
	vector(vector<value_type> &&v) noexcept
	{
		// 将源地址 复制过来
		begin_ = v.begin_;
		end_ = v.end_;
		tail_ = v.tail_;

		// 将原来的地址设置为nullptr
		v.begin_ = nullptr;
		v.end_ = nullptr;
		v.tail_ = nullptr;
	}

	// 析构函数
	~vector()
	{
		// 调用函数对类进行析构
		alloc.destroy(begin_, end_);
		// 删除掉申请的内存
		alloc.deallocate(begin_);

		// 将他们设置为nullptr 防止被重新利用
		begin_ = nullptr;
		end_ = nullptr;
		tail_ = nullptr;
	}

	// 从尾部插入元素 左值
	void push_back(value_type& value)
	{
		if (end_ == tail_) {
			relloc();
        }
		alloc.construct(end_++, value);
	}

	// 从尾部插入元素 右值
	void push_back(value_type&& value)
	{
		if (end_ == tail_) {
			relloc();
		}
		// 通过完美转发  传递参数
		alloc.construct(end_++, yuriSTL::forward<value_type>(value));
	}

	// 申请更大空间函数，默认为原来最大空间的两倍
	void relloc()
	{
		// 保存原来的元素个数
		const int size = this->size();
		// 申请两倍的空间
		value_type* new_begin = alloc.allocate(this->size() * 2);
		if (new_begin == nullptr) {
			yuriSTL::log("重新分配内存失败!");
			exit(1);
		}
		// 设置他新的end 和 tail 指针
		value_type* new_end = new_begin + size;
		value_type* new_tail = new_begin + size * 2;

		// 循环调用移动构造函数进行构造
		for (int i = 0; i < size; i++) {
			alloc.construct(new_begin + i, yuriSTL::move(*(begin_ + i)));
		}

		// 将原来的内存调用析构函数进行析构 并对原内存i进行删除
		alloc.destroy(this->begin_, this->end_);
		alloc.deallocate(this->begin_);

		// 更新指针
		begin_ = new_begin;
		end_ = new_end;
		tail_ = new_tail;
    }

	// 返回当前元素个数
    const int size(){
        return end_ - begin_;
    }

	// 返回最大元素个数
    const int max_size(){
        return tail_ - begin_;
    }

	// 重载[] 返回对应下标元素
	value_type& operator[](int k)
	{
        if (k >= end_ - begin_) {
			yuriSTL::log("错误！超出内存范围!");
			exit(2);
        }
        return *(begin_ + k);
	}

	// 返回对应元素个数
	value_type& at(const int k)
	{
        if (k >= end_ - begin_) {
			yuriSTL::log("错误！超出内存范围!");
			exit(2);
        }
        return *(begin_ + k);
	}

	// 返回首部元素
	value_type& front() 
	{
		if (empty()) {
			yuriSTL::log("当前元素为空!");
			exit(3);
		}
		return *begin_;
	}

	// 返回末尾元素
	value_type& back()
	{
		if (empty()) {
			yuriSTL::log("当前元素为空!");
			exit(3);
		}
		return *(end_ - 1);
	}

	// 返回开始 迭代器
	iterator begin() const{
		return this->begin_;
	}

	// 返回末尾迭代器
	iterator end() const{
		return this->end_;
	}

	// 判断容器是否为空
	bool empty(){
		return end_ == begin_;
	}

	// 重载等号
	void operator=(vector<value_type> &v)
	{
        begin_ = alloc.allocate(v.max_size());
        if (begin_ == nullptr) {
			yuriSTL::log("内存分配失败捏!");
			exit(1);
		}
		end_ = begin_ + v.size();
		tail_ = begin_ + v.max_size();
		for (int i = 0; i < v.size(); i++) {
			*(begin_ + i) = *(v.begin_ + i);
		}
	}
};

}  // namespace yuriSTL 

#endif