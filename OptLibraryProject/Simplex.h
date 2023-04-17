#pragma once
#include <functional>
#include <cmath>
#include <vector>
#include <cassert>
#include <array>
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
	
	/*template<size_t dim>
	operator double(const Point<dim>& p) {
		double sum = 0;
		for (double value : p) {
			sum += value;
		}
		return sum;
	}*/
	//The conversion operator must be a non-static member function or a non-member function

	

	template<size_t dim>
	double pointToDouble(const Point<dim>& p) {
		double sum = 0;
		for (size_t i = 0; i < dim; ++i) {
			sum += p[i];
		}
		return sum;
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
		PointVal<dim> res{ abs<dim>(p1.p), std::abs(p1.val) };
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

	template<size_t dim>
	SetOfPoints < dim, Point<1>> Tr(const Point<dim>& p)
	{
		SetOfPoints<dim, Point<1>> SOP;
		for (size_t i = 0; i < dim; i++)
		{
			Point<1> q{ p[i] };
			SOP[i] = q;
		}
		return SOP;
	}

	//diffferent
	/*template<size_t dim, size_t count>
	SetOfPoints < dim, Point<count>> Tr(const SetOfPoints<count, Point<dim>>& set)
	{
		SetOfPoints<dim, Point<count>> SOP;
		for (size_t i = 0; i < dim; i++)
		{
			Point<count> q{ p[i] };
			SOP[i] = q;
		}
		return SOP;
	}*/


	//TRANS FOR RECTANGLE MATRIX
	/*static constexpr size_t Dim = dim;*/

	//template<size_t count, typename point>
	//auto Tr(const SetOfPoints<count, point>& rhs)
	//{
	//	SetOfPoints<count, point> Res;

	//	for (size_t i = 0; i < count; i++)
	//	{
	//		for (size_t j = 0; j < count; j++)//дл€ квадратных
	//		{
	//			Res[i][j] = rhs[j][i];
	//		}

	//	}
	//	return Res;
	//}

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

	template<size_t dim>
	SetOfPoints<dim, Point<1>> operator* (const SetOfPoints<dim, Point<1>> x,
		const SetOfPoints<dim, Point<dim>> A)
	{
		SetOfPoints<dim, Point<1>> res;
		for (size_t i = 0; i < dim; i++)
		{
			Point<1>  q{ 0.0 };
			for (size_t j = 0; j < dim; j++)
			{
				q = q + x[j][0] * A[i][j];
			}
			res[i] = q;
		}
		return res;
	}

	template<size_t dim>
	double operator* (const SetOfPoints<dim, Point<1>> x,
		const Point<dim> p)
	{
		double res = 0.0;
		for (size_t i = 0; i < dim; i++)
		{
			res += x[i][0] * p[i];
		}
		return res;
	}

	//different 
	/*template<size_t count1, size_t dim, size_t count2>
	SetOfPoints<count2, Point<count1>> operator* (const SetOfPoints<dim, Point<count1>> set1,
		const SetOfPoints<count2, Point<dim>> set2)
	{
		SetOfPoints<count2, Point<count1>> res;
		for (size_t i = 0; i < count2; i++)
		{
			for (size_t j = 0; j < count1; j++)
			{

			}
		}
		return res;
	}*/


	


	//”множение через —кал€рное произведение

	/*template <size_t count, typename point>
	SetOfPoints<count, point> operator* (const SetOfPoints<count, point>& A, 
		const SetOfPoints<count, point>& B) {
		SetOfPoints<count, point> C;
		std::transform(A.begin(), A.end(), B.begin(), C.begin(),
			[](const point& a, const point& b) {return DotProd(a,b);});
		return C;
	}*/




	//27.02


	

	

	template<size_t count, typename point>
	class RawSetOfPoints
	{
	/*protected:
		SetOfPoints<count, point> ItsSetOfPoints;*/
	public:
		SetOfPoints<count, point> ItsSetOfPoints;
		RawSetOfPoints() = default;
		RawSetOfPoints(SetOfPoints<count, point>&& s) :
			ItsSetOfPoints{ std::move(s) } {}	//moving construct
		RawSetOfPoints(const SetOfPoints<count, point>& sop) :
			ItsSetOfPoints{ sop } {}
		const point& operator [](size_t i)
		{
			assert(i < count);
			return ItsSetOfPoints[i];
		}

		point Mean() const
		{
			point out{ ItsSetOfPoints[0] };
			if constexpr (count > 1)
			for (size_t i = 1; i < count; i++)
			{
				out = out + ItsSetOfPoints[i];
			}
			out = out / count;
			return out;
		}


		point Variance() const	//дисперси€
		{
			point mean = Mean();
			point out = (ItsSetOfPoints[0] - mean) * (ItsSetOfPoints[0] - mean);
			if constexpr (count > 1) {				
				for (size_t i = 1; i < count; i++)
				{
					out = out + (ItsSetOfPoints[i] - mean) * (ItsSetOfPoints[i] - mean);
				}
				out = out / count;
			}
			return out;
		}


		std::pair<point, point> Dispersion() const
		{
			point avg = Mean();
			point disp =  Variance();
			return{ avg,disp };
		}
	
	};


	template<typename point>
	std::pair<point, point> VarCoef(const point& avg, const point& disp)
	{
		std::pair<point,point> res;
		res.second = OptLib::sqrt(disp);
		res.first = res.second / OptLib::abs(avg);
		return res;
	}


	template<size_t count, typename point, typename pointVal>
	class SetOfPointsVal : public RawSetOfPoints<count, pointVal>
	{

	public:
		static SetOfPoints<count, pointVal>
			make_field(SetOfPoints<count, point>&& s,
				std::array<double, count>&& vals)
		{
			SetOfPoints<count, pointVal> P;
			for (size_t i = 0; i < count; i++)
			{
				P[i] = pointVal{ s[i],vals[i] };
			}
			return P;
			
			
		}
		
		SetOfPointsVal() = default;

		SetOfPointsVal(SetOfPoints<count, pointVal>&& s) :
			RawSetOfPoints<count,pointVal>{ std::move(s) } {}	//moving construct


		SetOfPointsVal(SetOfPoints<count, point>&& s,
			std::array<double,count>&&Pval) :SetOfPointsVal<count,point,
			pointVal>{std::move(make_field(std::move(s),std::move(Pval)))}{}

			
		SetOfPointsVal(std::array<double, count>&& vals) {
			return make_field(vals);
		}
	};
	



	template<size_t count, typename point, typename pointval>
	class SetOfPointsValSort:
		public SetOfPointsVal<count, point, pointval>
	{
		
	private:
		void Sort() {
			/*std::sort(std::begin(this->ItsSetOfPoints), std::end(this->ItsSetOfPoints));*/

			//std::sort(ItsSetOfPoints.begin(), ItsSetOfPoints.end());

			std::sort(std::begin(this->ItsSetOfPoints), std::end(this->ItsSetOfPoints),
				[](const auto& lhs, const auto& rhs) {
					return lhs.val < rhs.val; });
		}
	public:

		SetOfPointsValSort(SetOfPointsVal<count, point, pointval>&& s):
			SetOfPointsVal<count, pointval>{std::move(s)}
		{
			this->Sort();
		}

		SetOfPointsValSort(SetOfPoints<count,point>&& s, 
			std::array<double,count>&& vals):
			SetOfPointsVal<count, point, pointval>{std::move(s),std::move(vals)} 
		{
			this->Sort();
		}
	};



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

