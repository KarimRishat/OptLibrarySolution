#pragma once

#include <cmath>
#include "FuncInterface.h"
const double M_PI = 3.14159265358979323846;

namespace OptLib
{
	namespace ConcreteFunc
	{


		template <size_t dim>
		class paraboloid : public FuncInterface::IFuncWithHess<dim>
		{
			SetOfPoints<dim, Point<dim>> A;
		public:

			double operator() (const Point<dim>& p) const override
			{
				SetOfPoints<dim, Point<1>> x_{ Tr(p) };
				SetOfPoints<dim, Point<1>> mult = x_ * A;
				double res = mult * p;
				return res;
			}			//f = tr(x)*A*x

			paraboloid(SetOfPoints<dim, Point<dim>>&& sop) :
				A{ std::move(sop) } {}
			

			Point<dim> grad(const Point<dim>& p) const override
			{
				Point<dim> res;

				for (size_t i = 0; i < dim; i++)
				{
					double sum = 0;
					sum += 2 * p[i] * A[i][i];
					for (size_t j = 0; j < dim; j++)
					{
						if (j != i)
						{
							sum += p[j] * (A[j][i] + A[i][j]);
						}
					}
					res[i] = sum;
				}
				return res;
			}

			SetOfPoints<dim,Point<dim>> hess(const Point<dim>& p) const override
			{
				SetOfPoints<dim, Point<dim>> res;
				for (size_t i = 0; i < dim; i++)
				{
					res[i][i] = 2 * A[i][i];
					for (size_t j = 0; j < dim; j++)
					{
						if (i != j)
						{
							res[i][j] = A[i][j] + A[j][i];
						}							
					}
				}
				return res;
			}

		};

		template <size_t dim>
		class plane : public FuncInterface::IFuncWithGrad<dim> {
			double k,b;
		public:

			double operator() (const Point<dim>& p) const override
			{
				Point<dim> res = k * p;
				return pointToDouble(res) + b;
			}

			Point<dim> grad(const Point<dim>& p) const override
			{
				Point<dim> res;
				for (size_t i = 0; i < dim; i++)
				{
					res[i] = k;
				}
				return res;
			}

			plane(double& k, double& b) :k{ k }, b{ b } {}

		};


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

			SetOfPoints<1,Point<1>> hess(const Point<1>& p) const override
			{
				return { Point<1>{sin(p[0])} };
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

			SetOfPoints<2, Point<2>> hess(const Point<2>& p) const override
			{
				return { Point<2>{-sin(p[0]), 0}, Point<2>{0, -sin(p[1])} };
			}

		};


		template<typename point, typename func>
		class FuncAlongGradDirection :
			public FuncInterface::IFuncWithGrad<1>
		{
			
			point grad0;
			point x0;
			func* f;
		public:
			double operator() (const Point<1>& gamma) const override
			{
				point x;
				x = x0 - pointToDouble(gamma) * grad0;
				return (*f)(x);
				
			}
			
			FuncAlongGradDirection(const point& x0,func* f) :
				x0{ x0 }, f{ f }, grad0{ f->grad(x0) } {}

			Point<1> grad(const Point<1>& p) const override
			{
				point x = (-1) * f->grad(x0 - pointToDouble(p) * grad0);
				Point<1> s{ DotProd(x,grad0)};
				return s;
			}

		};

		//Переделать гиссиан - квадратная матрица	-	done




		//FUNC WITH PARAM


		//c*exp(-(x-mu)^2/(sigma^2))
		//mu  - point[0], sigma - point[1]
		template<size_t dimX>
		class ExpWithParam:public FuncInterface::IFuncParam<dimX, 2*dimX>
		{
		public:
			double operator()(const Point<dimX>& x,
				const Point<2*dimX>& p)	const override
			{
				double C = 1.0;
				double arg = (double)dimX/2;
				for (size_t i = 0; i < dimX; i++)
				{
					if (p[dimX + i] < 0)
						return 0.0;
					double sigma = std::sqrt(1 / p[dimX + i]);
					C *= std::pow(sigma,arg);
				}
				double PI2 = std::sqrt(M_PI * 2);
				C *= 1 / (std::pow(PI2, arg));

				Point<dimX> res;
				for (size_t i = 0; i < dimX; i++)
				{
					double y = x[i];
					double mu = p[i];
					double sigma = p[dimX + i];
					//res[i] = (x[i] - p[i]) * (x[i] - p[i]) / p[dimX + i];
					res[i] = (y - mu) * (y - mu) / sigma;
				}
				return C*exp((-0.5)*pointToDouble(res));
			}
		};
	}
}