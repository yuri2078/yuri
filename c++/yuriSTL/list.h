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
        // 设置个数为0
        size = 0;
	}

	~list()
	{
		node<T> *temp;
		while (head->data_) {
			alloc_value.destroy(head->data_);
			alloc_value.deallocate(head->data_);
			temp = head;
			head = head->next_;
			alloc_node.deallocate(temp);
		}

		tail = head = nullptr;
	}

    // 左值尾部插入
	void push_back(const_reference value) noexcept
	{
		// 申请数据空间并初始化
		tail->data_ = alloc_value.allocate();
		alloc_value.construct(tail->data_, value);
		// 生成并更新尾节点
		tail->next_ = alloc_node.allocate();
		tail->next_->front_ = tail;
		tail = tail->next_;
		size++;
    }

    // 右值尾部插入
	void push_back(rvalue_reference value) noexcept
	{
		// 申请数据空间并初始化
		tail->data_ = alloc_value.allocate();
		alloc_value.construct(tail->data_, move(value));
		// 生成并更新尾节点
		tail->next_ = alloc_node.allocate();
		tail->next_->front_ = tail;
		tail = tail->next_;
		size++;
	}

	// 左值头部插入
	void push_front(const_reference value) noexcept
	{
		// 个数加一
		size++; 
		// 新建新节点、数据 并进行初始化
		node<T>* node = alloc_node.allocate();
		node->data_ = alloc_value.allocate();
		// 左值初始化函数调用
		alloc_value.construct(node->data_, value);
		// 更新节点
		head->front_ = node;
		node->next_ = head;
		head = node;
	}

	// 右值头部插入
	void push_front(rvalue_reference value) noexcept {
		// 个数加一
		size++;
		// 新建新节点、数据 并进行初始化
		node<T>* node = alloc_node.allocate();
		node->data_ = alloc_value.allocate();
		// 右值move函数调用
		alloc_value.construct(node->data_, move(value));
		// 更新节点
		head->front_ = node;
		node->next_ = head;
		head = node;
	}

	// 展示数据
	void showAllValue()
	{
		node<T>* new_head = head;
		std::cout << "当前容量 -> " << size << std::endl;
		while (new_head->data_) {
			if (new_head->next_->data_ == nullptr) {
				std::cout << "tail : " << *new_head->data_ << "\n";
				break;
			}
			if (new_head->front_ == nullptr) {
				std::cout << "head : " << *new_head->data_ << "\n";
			} else {
				std::cout << " front : " << *new_head->front_->data_ << "  prev : "
				          << *new_head->data_ << "\n";
			}
			new_head = new_head->next_;
		}
		std::cout << std::endl;
	}

	
};
} // namespace yuriSTL


#endif