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

			IStateSimplex(SetOfPoint<dim+1,Point<dim>>&& State, 
				FuncInterface::IFunc<dim>* f)
			{
				UpdateDomain(std::move(State), f)
			}
			IStateSimplex() {}

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
				
				return true;
			}

			simplex GuessDomain() {
				return its_guess_domain;
			}

			std::array<double, dim + 1> FuncVals(const SetOfPoints<dim + 1, Point<dim>>&
				State, const IFunc<dim>* f)
			{
				return (*f)(State);
			}

			void UpdateDomain(SetOfPoints<dim + 1, Point<dim>>&& State,
				std::array<double, dim + 1 >> && fvals)
			{
				SetDomain(simplex{
					simplex::make_field(std::move(State), std::move(fvals))
					});
			}

			virtual void SetDomain(SetOfPoints<dim + 1, PointVal<dim>>&& State) {
				its_guess_domain = simplex{ std::move(State) };
				its_guess = GuessDomain().Mean();
			}

			void UpdateDomain(SetOfPoints<dim + 1, Point<dim>>&& State,
				const FuncInterface::IFunc<dim>* f)
			{
				UpdateDomain(std::move(State), std::move(FuncVals(State, f));
			}

		protected:
			simplex its_guess_domain;	//sopVal
			

		};//simplex
		//Нужна сортировка которая была в simplex



	}//StateName
}//opt

