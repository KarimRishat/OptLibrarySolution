#pragma once
#include <algorithm>
#include <array>
#include <functional>

namespace OptLib
{
	template<size_t dim>
	using Point = std::array<double, dim>;	// Point<7> p; - точка в 7-мимерном пространстве

	namespace SimplexOps
	{
		namespace UnaryOps
		{
			template <class Scalar>
			struct plus
			{
			protected:
				Scalar scalar;
			public:
				constexpr plus(Scalar value) :scalar{ value } {};
				template<class T = void>
				T operator() (const T& lhs)
				{
					return lhs + scalar;
				}
			
			};

			template <class Scalar>
			struct minus
			{
			protected:
				Scalar scalar;
			public:
				minus(Scalar value) :scalar{ value } {};
				template<class T = void>
				constexpr T operator() (const T& lhs)
				{
					return lhs - scalar;
				}

			};

			template <class Scalar>
			struct mult
			{
			protected:
				Scalar scalar;
			public:
				mult(Scalar value) :scalar{ value } {};
				template<class T = void>
				constexpr T operator() (const T& lhs)
				{
					return lhs * scalar;
				}

			};


			template <class Scalar>
			struct div
			{
			protected:
				Scalar scalar;
			public:
				div(Scalar value) :scalar{ value } {};
				template<class T = void>
				constexpr T operator() (const T& lhs)
				{
					return lhs / scalar;
				}

			};


			struct abs
			{
				abs() {};
				template <class T = void>
				constexpr T operator() (const T& lhs)
				{
					return std::abs(lhs);
				}
			};

			struct sqrt
			{
				sqrt() {};
				template <class T = void>
				constexpr T operator() (const T& lhs)
				{
					return std::sqrt(lhs);
				}

			};
			
		}


		namespace BinaryOps
		{
			template <class T = void>
			using plus = std::plus<T>;


			template <class T = void>
			using minus = std::minus<T>;

			template <class T = void>
			using multi = std::multiplies<T>;


			template <class T = void>
			using div = std::divides<T>;
		}
	}
}


