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
			virtual SetOfPoints<dim,Point<dim>> hess(const Point<dim>& p) const = 0;
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

		template<size_t dimX, size_t dimP>
		class IFuncParam
		{
		public:
			virtual double operator()(const Point<dimX>& x,
				const Point<dimP>& p) const = 0;
			template<size_t count>
			Point<count> operator() (const SetOfPoints<count, Point<dimX>>& sop,
				const Point<dimP>& p) const
			{
				Point<count> out;
				for (size_t i = 0; i < count; i++)
				{
					out[i] = (*this)(sop[i], p);
				}
				return out;
			}
		};



		//for sigma and mu
		
		/*template<class Tag>
		class MySet
		{
		public:
			double value;
			MySet(double v) :
				value{ v } {}
		};*/

		//operator""~meter
		/*using Mean = MySet<struct Mean {} > ;
		using DispSqr = MySet<struct disp_sqr {} > ;*/




		

	}//FuncInterface
}
