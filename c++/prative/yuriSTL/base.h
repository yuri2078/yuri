#ifndef BASE_H
#define BASE_H
#include <iostream>
/*
    这里实现了部分std 下的库函数
    std::move 将值转换成右值引用
    std::foward 完美转发
    std::remove_reference 移除引用
	std::is_lvalue_reference 判断是不是左值引用
*/

namespace yuriSTL
{

typedef __SIZE_TYPE__ size_type;
// 去除引用
// 原理： 不论接受什么类型，都将__type 重指为 他的原始类型
template <typename T>
struct remove_reference {
	typedef T __type;
};
template <typename T>

struct remove_reference<T&> {
	typedef T __type;
};
template <typename T>

struct remove_reference<T&&> {
	typedef T __type;
};

// move 函数 实现转换为右值引用
// template <typename T>
// constexpr T&& move(T &&val) noexcept {
// 	static_cast<T&&>(val);
// }

// move 函数 实现转换为右值引用
template <typename T>
constexpr typename remove_reference<T>::__type&& move(T &&val) noexcept{
	return static_cast<typename remove_reference<T>::__type &&>(val);
}

// b不是左值引用value 为false
template <typename T>
struct is_lvalue_reference {
	public: bool value = false;
};

// 是左值引用value 为true
template <typename T>
struct is_lvalue_reference<T&> {
	public: bool value = true;
};

// 完美转发 : 左值转发
template <typename T>
constexpr T&& forward(typename remove_reference<T>::__type& val) noexcept{
	return static_cast<T&&>(val);
}

/*
  有两个是为了防止出现 类型对应不上的问题
  例如 forward<int &&>(int &) 因为模板函数内所有引用都是左值引用
  而左边传入的是原始类型 可能为int && 此时万能引用就会对应不上
*/

// 完美转发 ： 右值转发
template <typename T>
constexpr T&& forward(typename remove_reference<T>::__type&& val) noexcept
{
	// 静态断言 如果传入的是个左值就报错
	// static_assert(!is_lvalue_reference<T>().value, "ni bu neng yong forward jiang yi ge zuo zhi zhuan huan cheng you zhi");
	return static_cast<T&&>(val);
}

/*
    声明两个结构体一个代表是基础类型 一个代表不是基础类型
    定义is_type 结构体 如果类型已经确定 他会生成 后面已经确定类型对应的is_type
    如果类型不是已经确定的 就会生成第一个 通过将 __type 指代不同的结构体
	在调用函数时 通过不同的参数重载函数 达到不同的效果
*/

// 判断是不是基础类型
struct __true_type {
};

struct __false_type {
};

// class 类型 需要析构
template <typename T>
struct is_type {
	typedef __false_type __type;
};

template <>
struct is_type<int> {
	typedef __true_type __type;
};

template <>
struct is_type<unsigned int> {
	typedef __true_type __type;
};

template <>
struct is_type<char> {
	typedef __true_type __type;
};

template <>
struct is_type<unsigned char> {
	typedef __true_type __type;
};

template <>
struct is_type<double> {
	typedef __true_type __type;
};

template <>
struct is_type<long double> {
	typedef __true_type __type;
};

template <>
struct is_type<float> {
	typedef __true_type __type;
};


template <>
struct is_type<long> {
	typedef __true_type __type;
};
template <>
struct is_type<long long> {
	typedef __true_type __type;
};

template <>
struct is_type<unsigned long> {
	typedef __true_type __type;
};

template <>
struct is_type<unsigned long long> {
	typedef __true_type __type;
};
// 待补充



template <typename T>
void destroy__(T* ptr, size_type size, __true_type)
{
	std::cout << "是基础类型捏\n";
}

template <typename T>
void destroy__(T* ptr, size_type size, __false_type)
{
	std::cout << "不是基础类型捏\n";
	for (int i = 0; i < size; i++) {
		ptr->~T();
		ptr++;
	}
}

template <typename T>
void destroy(T* ptr)
{
	std::cout << "默认析构\n";
	ptr->~T();
}
template <typename T>
void destroy(T* ptr, size_type size)
{
	typename is_type<T>::__type type;
	destroy__(ptr, size, type);
}



} // namespace yuriSTL

#endif // BASE_H