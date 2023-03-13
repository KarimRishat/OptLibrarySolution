#pragma once
#include <math.h>
#include "Simplex.h"

namespace OptLib
{
	namespace FuncInterface
	{
		template <size_t dim>
		class IFunc
		{
		public:
			virtual double operator() (const Point<dim>& p) const = 0;

			template<size_t count>
			Point<count> operator() 
				(const SetOfPoints<count, Point<dim>>& s) const {
				Point<count> out;
				for (size_t i = 0; i < count; i++)
				{
					out[i] = (*this)(s[i]);
				}
				return out;
			}
			//перегруз круглых скобок для сетофпоинтс и поинт

			/*template<size_t count>
			IFunc(const SetOfPoints<count, Point<dim>> s) {
				this->operator()(s);
			}*/


		};

		template<size_t dim>
		class IGrad {
		public:
			virtual Point<dim> grad(const Point<dim>& p) const = 0;

			template<size_t count>
			const SetOfPoints<count, Point<dim>> grad
				(const SetOfPoints<count, Point<dim>>& set) {
				SetOfPoints< count, Point<dim>> out;
				for (size_t i = 0; i < count; i++)
				{
					out[i] = grad(set[i]);
				}
				return out;
			}


			/*template<size_t count>
			IGrad(const SetOfPoints<count, Point<dim>>& s) {
				grad(s);
			}*/

		};

		template<size_t dim>
		class IHess
		{
		public:
			virtual Point<dim> hess(const Point<dim>& p) const = 0;
		};



		template<size_t dim>
		class IFuncWithGrad :
			public IFunc<dim>,
			public IGrad<dim>
		{

		};



		template<size_t dim>
		class IFuncWithHess :
			public IFuncWithGrad<dim>,
			public IHess<dim>
		{

		};

		template<size_t dim>
		class sin : public IFuncWithHess<dim>
		{
		public:
			/*double operator() (Point<dim> p) const override
			{

			}

			Point<dim> grad(const Point<dim>& p) const override 
			{
				
			}

			Point<dim> hess(const Point<dim> p) const override 
			{

			}*/
			
		};


		template <size_t dim>
		class paraboloid : public IFuncWithGrad
		{};

		template <size_t dim>
		class plane : public IFuncWithGrad {};
		

		class Sin : public sin<1> {
		public:
			double operator() (Point<1> p) const override
			{

			}
		};

	}//FuncInterface
}
