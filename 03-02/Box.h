#pragma once
#include <algorithm>
#include <type_traits>

template<typename T1, typename T2> 
class Box {
public:
	T1 num1_;
	T2 num2_;

	Box(T1 num1, T2 num2) : num1_(num1), num2_(num2) {}

	// 二つの値を比較して小さい値を返す
	auto Min() {
		using Common = std::common_type_t<T1, T2>;
		return std::min(static_cast<Common>(num1_), static_cast<Common>(num2_));
	}
};