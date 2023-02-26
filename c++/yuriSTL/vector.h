#ifndef VECTOR_H
#define VECTOR_H
// 自己写的vector容器

#include "allocator.h" 
#include "base.h"
namespace yuriSTL {

template <typename T>
class vector final
{
public:
	typedef T value_type; // 数据类型别名
	typedef T* iterator;  // 指针类型 / 迭代器
	typedef T& reference; // 引用 只接受左值引用
	typedef const T& const_reference ; // 引用 接受左值也接受右值

private:
	friend std::ostream& operator<<(std::ostream& cout, const_reference vec);
	value_type* begin_; // 指向一块内存的起始地址
	value_type* end_; // 最后一个元素的下一个位置
	value_type* tail_; // 内存块的最后一块地址
	allocator<T> alloc; // 新建分配内存的工具
	
	// 申请更大空间函数，默认为原来最大空间的两倍
	void relloc()
	{
		log("扩容!");
		// 保存原来的元素个数
		const int size = this->size();
		// 申请两倍的空间
		value_type* new_begin = alloc.allocate(size * 2);
		if (new_begin == nullptr) {
			yuriSTL::log("重新分配内存失败!");
			exit(1);
		}
		// 设置他新的end 和 tail 指针
		value_type* new_end = new_begin + size;
		value_type* new_tail = new_begin + size * 2;

		// 循环调用移动构造函数进行构造
		for (int i = 0; i < size; i++) {
			alloc.construct(new_begin + i, move(*(begin_ + i)));
		}
		// 将原来的内存调用析构函数进行析构 并对原内存i进行删除
		alloc.destroy(this->begin_, this->end_);
		alloc.deallocate(this->begin_);

		// 更新指针
		begin_ = new_begin;
		end_ = new_end;
		tail_ = new_tail;
    }

public:
	vector() noexcept
	{
		// 申请内存
		begin_ = alloc.allocate(16); 
		// 异常返回
		if (begin_ == nullptr) {
			yuriSTL::log("内存分配失败捏!");
			exit(1);
		}
		// 更新指针位置
		end_ = begin_; // 没有元素，此时end = begin
		tail_ = begin_ + 16; 
	}
	
	// 拷贝构造函数
	vector(vector<value_type> &v) noexcept
	{
		// 新建一块和他一样大的内存
		begin_ = alloc.allocate(v.max_size());
		// 异常返回
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
		// 移动资源
		begin_ = v.begin_;
		end_ = v.end_;
		tail_ = v.tail_;

		// 将原来的地址设置为nullptr
		v.begin_ = nullptr;
		v.end_ = nullptr;
		v.tail_ = nullptr;
	}

	// 使用n个对象初始化
	explicit vector(const size_type n)
	{
		// 申请空间
		begin_ = alloc.allocate(n);
		// 异常返回
		if (begin_ == nullptr) {
			yuriSTL::log("内存分配失败捏!");
			exit(1);
		}
		// 初始化内容
		for (int i = 0; i < n; i++) {
			alloc.construct(begin_ + i);
		}
		// 更新指针
		end_ = begin_ + n;
		tail_ = begin_ + n;
	}

	// 初始化n个元素
	vector(const size_type n, const_reference val)
	{
		// 申请空间
		begin_ = alloc.allocate(n);
		// 异常返回
		if (begin_ == nullptr) {
			yuriSTL::log("内存分配失败捏!");
			exit(1);
		}
		// 更新指针
		end_ = begin_ + n;
		tail_ = begin_ + n;
		// 初始化元素
		for (int i = 0; i < n; i++) {
			alloc.construct(begin_ + i, val);
		}
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
	// 使用const & 既可以接受左值也可以接受右值
	void push_back(const_reference val)
	{
		// 判断空间是不是满了
		if (end_ == tail_) {
			relloc();
		}
		// 插入，并更新指针
		alloc.construct(end_++, val);
	}

	// 从尾部插入元素 右值
	void push_back(value_type&& val)
	{
		// 判断空间是不是满了
		if (end_ == tail_) {
			relloc(); // 如果空间满了则重新分配空间默认 大小 X 2
		}
		// 通过完美转发传递参数
		alloc.construct(end_++, yuriSTL::forward<value_type>(val));
	}

	// 返回当前元素个数
    const int size() {
        return end_ - begin_;
    }

	// 返回最大元素个数
    const int max_size() {
        return tail_ - begin_;
    }

	// 重载[] 返回对应下标元素
	reference operator[](int k)
	{
        if (k >= end_ - begin_) {
			yuriSTL::log("错误！超出内存范围!");
			exit(2);
        }
        return *(begin_ + k);
	}

	// 返回对应元素个数
	reference at(const int k)
	{
		if (k >= end_ - begin_) {
			yuriSTL::log("错误！超出内存范围!");
			exit(2);
		}
        return *(begin_ + k);
	}

	// 返回首部元素
	reference front() 
	{
		if (empty()) {
			yuriSTL::log("当前元素为空!");
			exit(3);
		}
		return *begin_;
	}

	// 返回末尾元素
	reference back()
	{
		if (empty()) {
			yuriSTL::log("当前元素为空!");
			exit(3);
		}
		return *(end_ - 1);
	}

	// 返回开始 迭代器
	iterator begin() noexcept { return begin_; }

	// 返回末尾迭代器
	iterator end() noexcept { return end_; }

	// 判断容器是否为空
	const bool empty() { return end_ == begin_; }

	iterator data() noexcept { return begin_; }

	// 重载等号
	reference operator=(const vector<value_type> &v)
	{
		// 调用函数对之前的数据进行析构
		alloc.destroy(begin_, end_);
		// 删除掉之前申请的内存
		alloc.deallocate(begin_);
		// 重新申请内存
		begin_ = alloc.allocate(v.max_size());
		// 判断是否异常
        if (begin_ == nullptr) {
			yuriSTL::log("内存分配失败捏!");
			exit(1);
		}
		// 更新指针
		end_ = begin_ + v.size();
		tail_ = begin_ + v.max_size();
		// 完成初始化操作
		for (int i = 0; i < v.size(); i++) {
			*(begin_ + i) = *(v.begin_ + i);
		}

		return *this;
	}
};

// 重载输出，方便打印
template <typename T>
std::ostream& operator<<(std::ostream& cout, vector<T>& vec)
{
	const int size = vec.size();
	for (int i = 0; i < size; i++) {
		cout << vec[i] << " ";
	}
	cout << std::endl;
	return cout;
}

} // namespace yuriSTL

#endif