#ifndef TYPE_TRAITS_H
#define TYPE_TRAITS_H


// 存放一些萃取模板
namespace yuriSTL {

/*
    知识点:
    引用折叠: 当有一个为左值时 && & 都会折叠成 &, 只有都是 && 才会折叠成&&
	举例 : 函数接受 T &x。传入 T && 或者 T &时 x 都为 T & 类型
    函数接受 T &&x。传入 T &时 x 为 T & 类型  传入 T && 时， x 为 T &&类型
	但是 x 肯定是 & 左值引用，因为他有名字，有名字就是左值引用
*/


// 去除引用
// 原理： 不论接受什么类型，都将__type 重指为 他的原始类型
// 传入 int    生成第一个 T -> int
// 传入 int &  生成第二个 T -> int
// 传入 int && 生成第三个 T -> int
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


// b不是左值引用value 为false
template <typename T>
struct is_lvalue_reference {
	bool value = false;
};

// 是左值引用value 为true
template <typename T>
struct is_lvalue_reference<T&> {
	bool value = true;
};

// b不是右值引用value 为false
template <typename T>
struct is_rvalue_reference {
	bool value = false;
};

// 是左值引用value 为true
template <typename T>
struct is_rvalue_reference<T&&> {
	bool value = true;
};

// 判断是不是基础类型
struct __true_type {
};

/*
    声明两个结构体一个代表是基础类型 一个代表不是基础类型
    定义is_type 结构体 如果类型已经确定 他会生成 后面已经确定类型对应的is_type
    如果类型不是已经确定的 就会生成第一个 通过将 __type 指代不同的结构体
	在调用函数时 通过不同的参数重载函数 达到不同的效果
*/

struct __false_type {
};

// class 类型 需要析构
template <typename T>
struct is_type {
	typedef __false_type __type;
};

template <>
struct is_type<bool> {
	typedef __true_type __type;
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
} // namespace yuriSTL

#endif