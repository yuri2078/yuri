#ifndef BASE_H
#define BASE_H


#include "type_traits.h"
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

typedef __SIZE_TYPE__ size_type; //数据类型重新定义

/*
move 函数 实现转换为右值引用 错误写法！
因为当T 为int & 时， T && 会被折叠成 int & 而不是int &&此时就会返回一个左值
使用 remove_reference 去除引用之后，才能正确的返回结果
	template <typename T>
	constexpr T&& move(T &&val) noexcept {
		return static_cast<T&&>(val);
	}
*/

// move 函数 实现转换为右值引用
template <typename T>
constexpr typename remove_reference<T>::__type&& move(T &&val) noexcept{
	return static_cast<typename remove_reference<T>::__type &&>(val);
}

// 完美转发 : 左值转发
template <typename T>
constexpr T&& forward(typename remove_reference<T>::__type& val) noexcept{
	return static_cast<T&&>(val);
}

/*
    有两个是为了类型一一对应 这里使用了 remove_reference 所以一个固定接受左值引用
	一个固定接受右值，当结果是左值的时候，与T&& 折叠，结果仍然是左值
	当结果是右值时，与T&&折叠结果仍然是右值，达到完美转发的效果
	他并不是所有值进来都转换成右值，这和move是不一样的，也不能和move一样！所以需要区别使用
	而不是直接一个函数无脑 返回 T&&
*/

// 完美转发 ： 右值转发
template <typename T>
constexpr T&& forward(typename remove_reference<T>::__type&& val) noexcept
{
	// 静态断言 如果传入的是个左值就报错
	static_assert(!is_lvalue_reference<T>().value, "ni bu neng yong forward jiang yi ge zuo zhi zhuan huan cheng you zhi");
	return static_cast<T&&>(val);
}


// 是简单类型什么都不用做
template <typename T>
void destroy__([[maybe_unused]] T* start, [[maybe_unused]] T* end, __true_type)
{
	
}

// 不是简单类型调用析构函数
template <typename T>
void destroy__(T* start, T* end, __false_type)
{
	// 循环调用析构函数
	for (; start != end; start++) {
		start->~T();
	}
}

// 简单指针，直接调用析构函数就行
template <typename T>
void destroy(T* ptr) {
	ptr->~T();
}

// 析构n个数据
template <typename T>
void destroy(T* start, T* end)
{
	// 判断是不是基础类型
	typename yuriSTL::is_type<T>::__type type;
	// 通过另一个函数完成最终析构
	destroy__(start, end, type);
}

// 打印日志函数，红色字体
template <typename T>
void log(T &&val){
	std::cout << "\e[31m" << val << "\e[0m\n";
}

// 打印日志函数，红色字体
template <typename T, typename ...Args>
void log(T &&val, Args ...args){
	std::cout << "\e[31m" << val << "\e[0m";
	log(args...);
} 



}// namespace yuriSTL
#endif // BASE_H