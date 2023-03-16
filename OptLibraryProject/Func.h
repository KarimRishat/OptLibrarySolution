#pragma once
#include <cmath>
#include "FuncInterface.h"


namespace OptLib
{
	namespace ConcreteFunc
	{


		template <size_t dim>
		class paraboloid : public FuncInterface::IFuncWithGrad<dim>{};

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
				return Point<2>{cos(p[0]+p[1])};
			}

			Point<2> hess(const Point<2>& p) const override
			{
				return Point<2>{sin(p[0] + p[1])};
			}

		};
	}
}