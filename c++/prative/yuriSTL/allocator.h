#ifndef ALLOCATOR_H
#define ALLOCATOR_H

#include <utility>
namespace yuriSTL {

template <typename T>
class allocator
{
public:
	typedef T value_type; // 基础数据类型
	typedef T* pointer; // 基础数据指针
	typedef const T* const_pointer; // const 指针
	typedef const T& const_reference; // const 引用
	typedef __SIZE_TYPE__ size_type;  // 数量类型

private:
	size_type max_size = 0;

public:
	allocator() = default;
	~allocator() = default;

// 分配初始化空间函数
	// 默认分配一个存储空间
	static pointer allocate() {
		return static_cast<pointer>(::operator new(sizeof(value_type)));
	}

	// 分配size个空间
	static pointer allocate(size_type size)
	{
		if (size == 0) {
			return nullptr;
        }
		return static_cast<pointer>(::operator new(size * sizeof(value_type)));
	}

// 销毁空间函数
	static void deallocate(pointer ptr)
	{
		if (ptr == nullptr) {
			return;
		}
		::operator delete(ptr);
    }

	static void deallocate(pointer ptr, size_type size)
	{
		if (ptr == nullptr) {
			return;
		}
		::operator delete(ptr);
    }

// 构造初始化空间的函数
	template <typename... Args>
	static void construct(pointer ptr, Args&& ...args){
		::new(ptr) value_type(std::forward<Args>(args)...);
	}

// 删除空间
	void destroy(pointer ptr)
	{
		ptr->~value_type();
	}

};


} // namespace yuriSTL


#endif // ALLOCATOR_H