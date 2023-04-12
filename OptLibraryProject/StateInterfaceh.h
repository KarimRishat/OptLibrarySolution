#pragma once
#include "FuncInterface.h"
namespace OptLib
{
	namespace StateInterface
	{
		template<size_t dim>
		class IState
		{
		protected:
			PointVal<dim> its_guess;
		public:
			virtual bool IsConverged(double abs_tol,	//abs погрешность
				double rel_tol) const = 0;	//относительная погрешность	
			//сошелся
			/*
			*	|xi-xi-1| < eps1
			*	|xi-xi-1| < eps2*|xi+xi-1|			
			*/

			const PointVal<dim>& Guess() const
			{
				return its_guess;
			}

		};//iState


		template<size_t dim, typename simplex>
		class IStateSimplex:
			public IState<dim>
		{
		public:
			bool IsConverged(double abs_tol, double rel_tol) const override
			{
				auto [avg, disp] = GuessDomain().Dispersion();	//структура из двух дабллов - поинтов
				auto [var, std] {
					OptLib::VarCoef<PointVal<dim>>(avg, disp)	//коеф вариации sqrt(disp)/mu	(simplex.h RawSet)
				};	//structured binding

				for (size_t i = 0; i < dim; i++)
				{
					
					bool f = (((std[i]) < abs_tol) || (var[i] < rel_tol)) && 
						(((std.val) < abs_tol) || (var.val < rel_tol));
					if (!f) return false;
				}
				
				return f;
			}

		};//simplex
		//Нужна сортировка которая была в simplex



	}//StateName
}//opt

