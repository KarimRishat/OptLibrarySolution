#include <array>
#include <algorithm>
#include <functional>
#include <cmath>
#pragma once
namespace OptLib
{
	template<size_t dim>
	using Point = std::array<double, dim>;	// Point<7> p; - точка в 7-мимерном пространстве

	template<size_t dim>
	Point<dim> operator+ (const Point<dim>& arr1,
							const Point<dim>& arr2)
	{
		Point<dim> result;
		std::transform(arr1.begin(), arr2.end(),
			arr2.begin(), result.begin(),
			std::plus<>{});
		return result;
	}

	template<size_t dim>
	Point<dim> operator- (const Point<dim>& arr1,
		const Point<dim>& arr2)
	{
		Point<dim> result;
		std::transform(arr1.begin(), arr2.end(),
			arr2.begin(), result.begin(),
			std::minus<>{});
		return result;
	}

	template<size_t dim>
	Point<dim> operator* (const Point<dim>& arr1,
		const Point<dim>& arr2)
	{
		Point<dim> result;
		std::transform(arr1.begin(), arr2.end(),
			arr2.begin(), result.begin(),
			std::multiplies<>{});
		return result;
	}

	template<size_t dim>
	Point<dim> operator/ (const Point<dim>& arr1,
		const Point<dim>& arr2)
	{
		Point<dim> result;
		std::transform(arr1.begin(), arr2.end(),
			arr2.begin(), result.begin(),
			std::divides<>{});
		return result;
	}

	template<size_t dim>
	bool operator|| (const Point<dim>& arr1,
		const Point<dim>& arr2)
	{
		for (size_t i = 0; i < dim-1; i++)
		{
			if (arr1[i] || arr2[i])
				return true;
		}
		return false;
	}

	template<size_t dim>
	Point<dim> operator- (const Point<dim>& arr)
	{
		Point<dim> result;
		for (size_t i = 0; i < dim-1; i++)
		{
			result[i] = -arr[i];
		}
		return result;
	}

	template<size_t dim>
	Point<dim> operator+ (const Point<dim>& arr, const double& val) {
		Point<dim> result;
		for (size_t i = 0; i < dim-1; i++)
		{
			result[i] = arr[i] + val;
		}
		return result;
	}

	template<size_t dim>
	Point<dim> operator- (const Point<dim>& arr, const double& val) {
		Point<dim> result;
		for (size_t i = 0; i < dim - 1; i++)
		{
			result[i] = arr[i] - val;
		}
		return result;
	}

	template<size_t dim>
	Point<dim> operator* (const Point<dim>& arr, const double& val) {
		Point<dim> result;
		for (size_t i = 0; i < dim - 1; i++)
		{
			result[i] = arr[i] * val;
		}
		return result;
	}

	template<size_t dim>
	Point<dim> operator/ (const Point<dim>& arr, const double& val) {
		Point<dim> result;
		for (size_t i = 0; i < dim - 1; i++)
		{
			result[i] = arr[i] / val;
		}
		return result;
	}

	template<size_t dim>
	Point<dim> sqrt (const Point<dim>& arr) {
		Point<dim> result;
		for (size_t i = 0; i < dim - 1; i++)
		{
			result[i] = std::sqrt(arr[i]);
		}
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

