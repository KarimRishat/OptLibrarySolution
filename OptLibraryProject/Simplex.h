#pragma once
#include <functional>
#include <cmath>
#include "SimplexOps.h"

namespace OptLib
{
	
	//Binary ops Point
	template<size_t dim>
	Point<dim> operator+ (const Point<dim>& arr1,
							const Point<dim>& arr2)
	{
		Point<dim> result;
		std::transform(arr1.begin(), arr1.end(),
			arr2.begin(), result.begin(),
			SimplexOps::BinaryOps::plus<>{});
		return result;
	}

	template<size_t dim>
	Point<dim> operator- (const Point<dim>& arr1,
		const Point<dim>& arr2)
	{
		Point<dim> result;
		std::transform(arr1.begin(), arr1.end(),
			arr2.begin(), result.begin(),
			SimplexOps::BinaryOps::minus<>{});
		return result;
	}

	template<size_t dim>
	Point<dim> operator* (const Point<dim>& arr1,
		const Point<dim>& arr2)
	{
		Point<dim> result;
		std::transform(arr1.begin(), arr1.end(),
			arr2.begin(), result.begin(),
			SimplexOps::BinaryOps::multi<>{});
		return result;
	}

	template<size_t dim>
	Point<dim> operator/ (const Point<dim>& arr1,
		const Point<dim>& arr2)
	{
		Point<dim> result;
		std::transform(arr1.begin(), arr1.end(),
			arr2.begin(), result.begin(),
			SimplexOps::BinaryOps::div<>{});
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



	//UnaryOps Point
	template<size_t dim>
	Point<dim> operator+ (const Point<dim>& arr, double val) {
		Point<dim> result;
		std::transform(arr.begin(), arr.end(), result.begin(),
			SimplexOps::UnaryOps::plus<double>{val});
		return result;
	}

	template<size_t dim>
	Point<dim> operator- (const Point<dim>& arr, const double& val) {
		Point<dim> result;
		std::transform(arr.begin(), arr.end(), result.begin(),
			SimplexOps::UnaryOps::minus<double>{val});
		return result;
	}

	template<size_t dim>
	Point<dim> operator* (const Point<dim>& arr, const double& val) {
		Point<dim> result;
		std::transform(arr.begin(), arr.end(), result.begin(),
			SimplexOps::UnaryOps::mult<double>{val});
		return result;
	}
	template<size_t dim>
	Point<dim> operator* (const double& val, const Point<dim>& arr) {
		return arr * val;
	}

	template<size_t dim>
	Point<dim> operator/ (const Point<dim>& arr, const double& val) {
		Point<dim> result;
		std::transform(arr.begin(), arr.end(), result.begin(),
			SimplexOps::UnaryOps::div<double>{val});
		return result;
	}

	template<size_t dim>
	Point<dim> sqrt (const Point<dim>& arr) {
		Point<dim> result;
		std::transform(arr.begin(), arr.end(), result.begin(),
			SimplexOps::UnaryOps::sqrt{});
		return result;
	}


	template<size_t dim>
	Point<dim> abs(const Point<dim>& arr) {
		Point<dim> result;
		std::transform(arr.begin(), arr.end(), result.begin(),
			SimplexOps::UnaryOps::abs{});
		return result;
	}

	template<size_t dim>
	double DotProd(const Point<dim>& p1,const Point<dim>& p2)
	{
		Point<dim> result;
		double res = 0;
		std::transform(p1.begin(), p1.end(), p2.begin(), result.begin(), std::multiplies<>{});
		for (auto& el : result)
			res += el;
		return res;
	}


	/*template<size_t dim>
	double DotProd(Point<dim>& p1, Point<dim> p2)
	{
		Point<dim> p3 = p1 * p2;
		double res = 0.0;
		std::transform(p1.begin(), p1.end(), p2.begin(),
			res, SimplexOps::BinaryOps::DotProd{ res });
		return res;
	}*/



	template<size_t dim>
	struct RawPoint
	{
		RawPoint() = default;

		Point<dim> p;

		RawPoint(const Point<dim>& p) noexcept :
			p{ p } {}

		RawPoint(Point<dim>&& p) :
			p{ std::move(p) } {}

		double operator[] (size_t i) const
		{
			return p[i];
		}


		operator Point<dim>()	//оператор не€вного приведени€
		{
			return p;
		}
	};



	template<size_t dim>
	struct PointVal :public RawPoint<dim>
	{
		double val;
		PointVal() = default;	//PointVal(const PointVal &p) = default

		PointVal(Point<dim>&& p, double val) :
			RawPoint<dim>{ std::move(p) }, val{ val }{};

		PointVal(const Point<dim>& p, double val) :
			RawPoint<dim>{ p }, val{ val }{};

		template<size_t dim>
		bool operator < (const Point<dim>& rhs)
		{
			return this->val < rhs.val;
		}

		template<size_t dim>
		bool operator > (const Point<dim>& rhs)
		{
			return this->val < rhs.val;
		}

		template<size_t dim>
		bool operator ==(const Point<dim>& rhs)
		{
			return this->val == rhs.val;
		}

	};




	//POINTVALUE OPERATIONS
	
	template<size_t dim>
	PointVal<dim> operator+ (const PointVal<dim>& p1, const PointVal<dim>& p2)
	{
		PointVal<dim> res{ p1.p + p2.p, p1.val + p2.val };
		return res;
	}


	template<size_t dim>
	PointVal<dim> operator- (const PointVal<dim>& p1, const PointVal<dim>& p2)
	{
		PointVal<dim> res{ p1.p - p2.p, p1.val - p2.val };
		return res;
	}


	template<size_t dim>
	PointVal<dim> operator* (const PointVal<dim>& p1, const PointVal<dim>& p2)
	{
		PointVal<dim> res{ p1.p * p2.p, p1.val * p2.val };
		return res;
	}


	template<size_t dim>
	PointVal<dim> operator/ (const PointVal<dim>& p1, const PointVal<dim>& p2)
	{
		PointVal<dim> res{ p1.p / p2.p, p1.val / p2.val };
		return res;
	}

	template<size_t dim>
	PointVal<dim> sqrt (const PointVal<dim>& p1)
	{
		PointVal<dim> res{ sqrt(p1.p), std::sqrt(p1.val) };
		return res;
	}

	template<size_t dim>
	PointVal<dim> abs(const PointVal<dim>& p1)
	{
		PointVal<dim> res{ abs(p1.p), std::abs(p1.val) };
		return res;
	}


	template<size_t dim>
	PointVal<dim> operator+ (const PointVal<dim>& p1, const double& Scalar)
	{
		PointVal<dim> res{ p1.p + Scalar, p1.val };
		return res;
	}

	template<size_t dim>
	PointVal<dim> operator+ (const double& Scalar, const PointVal<dim>& p1)
	{
		return p1 + Scalar;
	}


	template<size_t dim>
	PointVal<dim> operator- (const PointVal<dim>& p1, const double& Scalar)
	{
		PointVal<dim> res{ p1.p - Scalar, p1.val };
		return res;
	}

	template<size_t dim>
	PointVal<dim> operator- (const double& Scalar, const PointVal<dim>& p1)
	{
		PointVal<dim> res{ Scalar - p1.p, p1.val };
		return res;
	}


	template<size_t dim>
	PointVal<dim> operator* (const PointVal<dim>& p1, const double& Scalar)
	{
		PointVal<dim> res{ p1.p * Scalar, p1.val };
		return res;
	}

	template<size_t dim>
	PointVal<dim> operator* (const double& Scalar, const PointVal<dim>& p1)
	{
		return p1 * Scalar;
	}

	template<size_t dim>
	PointVal<dim> operator/ (const PointVal<dim>& p1, const double& Scalar)
	{
		PointVal<dim> res{ p1.p / Scalar, p1.val };
		return res;
	}

	template<size_t dim>
	PointVal<dim> operator/ (const double& Scalar, const PointVal<dim>& p1)
	{
		PointVal<dim> res{ Scalar / p1.p , p1.val };
		return res;
	}



	/*20.02.2023 SET OF POINTS*/

	template<size_t count, typename point>
	using SetOfPoints = std::array<point, count>;
	//SetOfpoints<5,Points<3>> sop

	//TRANS
	template<size_t count, typename point>
	SetOfPoints<count, point> Tr(const SetOfPoints<count, point>& rhs)
	{
		SetOfPoints<count, point> Res;

		for (size_t i = 0; i < count; i++)
		{
			for (size_t j = 0; j < count; j++)//дл€ квадратных
			{
				Res[i][j] = rhs[j][i];
			}

		}
		return Res;
	}

	//Multiply with point
	template<size_t count, typename point>
	point operator*(const SetOfPoints<count, point>& rhs, const point& lhs)
	{
		point res;
		for (size_t i = 0; i < count; i++)
		{
			res[i] = DotProd(rhs[i], lhs);
		}

		return res;
	}

	template<size_t count, typename point>
	SetOfPoints<count,point> operator * (const SetOfPoints<count,point> set1,
		const SetOfPoints<count,point> set2)
	{
		SetOfPoints<count, point> res;
		SetOfPoints<count, point> Trans = Tr(set2);
		for (size_t i = 0; i < count; i++)
		{
			res[i] = set1 * Trans[i];
		}
		return Tr(res);
	}


	//”множение через —кал€рное произведение

	/*template <size_t count, typename point>
	SetOfPoints<count, point> operator* (const SetOfPoints<count, point>& A, 
		const SetOfPoints<count, point>& B) {
		SetOfPoints<count, point> C;
		std::transform(A.begin(), A.end(), B.begin(), C.begin(),
			[](const point& a, const point& b) {return DotProd(a,b);});
		return C;
	}*/




}//Optlib
/*
	Print: x,a
	f(x1), f(x2)
	f(b(x1-x2))

	дз:
	Ќаписать корень, +, -, *,/,||,
		на число +, -, *,/,
	New
		x+-double
		p1+-p2
		p,x /* double

	T(const T&) Ч конструктор копировани€
*/

