#pragma once
#include <cmath>
#include "FuncInterface.h"


namespace OptLib
{
	namespace ConcreteFunc
	{


		template <size_t dim>
		class paraboloid : public FuncInterface::IFuncWithGrad<dim>{
		public:

			double operator() (const Point<dim>& p) const override
			{
				Point<dim> res = p * p;
				return pointToDouble(res);
			}


			double operator() (const Point<dim>& x, SetOfPoints <dim, Point<dim>> A)	//f = tr(x)*A*x
			{
				SetOfPoints<dim, Point<1>> x_{ Tr(x) };
				SetOfPoints<dim, Point<1>> mult = x_ * A;
				double res = mult * x;
				return res;
			}

			Point<dim> grad(const Point<dim>& p) const override
			{
				return 2*p;
			}
		};

		template <size_t dim>
		class plane : public FuncInterface::IFuncWithGrad<dim> {};


		class sinus : public OptLib::FuncInterface::IFuncWithHess<1> {
		public:

			double operator() (const Point<1>& p) const override
			{
				return { std::sin(p[0]) };
			}

			Point<1> grad(const Point<1>& p) const override
			{
				return Point<1>{cos(p[0])} ;
			}

			Point<1> hess(const Point<1>& p) const override
			{
				return Point<1>{sin(p[0])};
			}

		};

		class sinus2 : public OptLib::FuncInterface::IFuncWithHess<2> {
		public:

			double operator() (const Point<2>& p) const override
			{
				return std::sin(p[0]+p[1]);
			}

			Point<2> grad(const Point<2>& p) const override
			{
				return Point<2>{cos(p[0]), std::cos(p[1])};
			}

			Point<2> hess(const Point<2>& p) const override
			{
				return Point<2>{sin(p[0]), sin(p[1])};
			}

		};

	}
}