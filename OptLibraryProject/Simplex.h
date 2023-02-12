#include "stdafx.h"
#pragma once
namespace OptLib
{
	template<size_t dim>
	using Point = std::array<double, dim>;	// Point<7> p; - точка в 7-мимерном пространстве

	template<size_t dim>
	Point<dim> operator+(const Point<dim>& arr1,
		const Point<dim>& arr2)
	{
		Point<dim> result;
		std::transform(arr1.begin(), arr.end(),
			arr2.begin, result.begin(),
			std::plus<>{});
		return result;
	}
}
/*
	Print: x,a
	f(x1), f(x2)
	f(b(x1-x2))

	дз:
	Написать корень, +, -, *,/,||,
		на число +, -, *,/,
*/

