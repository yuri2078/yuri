#ifndef LIST_H
#define LIST_H

#include "allocator.h"

namespace yuriSTL
{

template <typename T>
struct node {
	node<T>* front_; // 指向上一个节点
	node<T>* next_; // 指向下一个节点
	T* data_; // 保存本身的数据
};

template <typename T>
class list
{
public:
	typedef T value_type;
	typedef T& reference; // 引用 只接受左值引用
	typedef const T& const_reference; // 引用 接受左值也接受右值
	typedef T&& rvalue_reference; // 右值引用

private:
	node<T> *head; // 定义一个头节点
    node<T> *tail; // 定义一个尾节点
    size_type size; // 保存节点个数
	allocator<node<T>> alloc_node; // node 内存分配器
	allocator<T> alloc_value; // value 内存分配器

public:
    list() {
        // 先将所有指针指向nullptr
		head = tail = alloc_node.allocate();
		head->next_ = nullptr;
        // 设置个数为0
        size = 0;
    }

    // 左值尾部插入
    void push_back(reference value) noexcept {
		tail->data_ = alloc_value.allocate();
		alloc_value.construct(tail->data_, value);
		tail->next_ = alloc_node.allocate();
		tail = tail->next_;
    }

    // 右值尾部插入
    void push_back(rvalue_reference value) noexcept {
		tail->data_ = alloc_value.allocate();
		alloc_value.construct(tail->data_, value);
		tail->next_ = alloc_node.allocate();
		tail = tail->next_;
		tail->next_ = nullptr;
    }

	void showAllValue()
	{
		node<T> *h = head;
		while (h) {
			std::cout << *h->data_ << " ";
			h = h->next_;
		}
		std::cout << *head->data_;
		std::cout << std::endl;
	}

	



};
} // namespace yuriSTL


#endif