#include <iterator>
#include <type_traits>
namespace yuriSTL
{

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
template <typename T>
constexpr T&& move(T &&val) noexcept {
	static_cast<T&&>(val);
}

template <typename T>
constexpr typename remove_reference<T>::__type&& move(T &&val) noexcept{
	static_cast<typename remove_reference<T>::__type &&>(val);
}

template <typename T>
constexpr T&& forward(typename std::remove_reference<T>::type& val) noexcept{
	return static_cast<T&&>(val);
}

template <typename T>
constexpr T&& forward(typename std::remove_reference<T>::type&& val) noexcept
{
	// 静态断言 如果传入的是个左值就报错
	static_assert(!std::is_lvalue_reference<T>::value, "不能使用forward 将右值转换位左值"); 
	return static_cast<T&&>(val);
}


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

} // namespace yuriSTL