#pragma once
#include "OptimizerInterface.h"
namespace OptLib
{
	template<size_t dim, typename state,
		template<size_t dim> typename func>
	class Optimizer
	{
	public:
		const PointVal<dim>& CurrentGuess()const 
		{
			return State->Guess();
		}

		Optimizer(state* State, func<dim>* f,
			OptimizerPrm prm) : State{ State }, f{ f },	//param - prm
			Prm{ prm }, s{ 0 }{}	//s  - size-t

		template<typename algo>
		PointVal<dim> Optimize()
		{
			bool g = false;
			while (!g && s<MaxIterCount)
			{
				OptimizerInterface::OptimizerAlgorithm<dim>
					::Proceed<algo, state, func>(State, f);
				++s;
				g = OptimizerInterface::OptimizerAlgorithm<dim>
					::IsConverged(State, tol_x(), tol_f());
			}
			return CurrentGuess();
		}

		template<typename algo>
		PointVal<dim> Continue(double eps_x, double eps_f)
		{
			Prm.eps_x = eps_x;
			Prm.eps_f = eps_f;
			s = 0;
			return Optimize<algo>();
		}

		double tol_f() { return Prm.eps_f; }
		size_t MaxIterCount() { return Prm.max_iter; }
		size_t CurIterCount() { return s; }

	protected:
		state* State;
		func* f;
		size_t s;		
		OptimizerPrm Prm;
	};//Optimizer


	struct OptimizerPrm
	{
		double eps_x, eps_f;
		size_t max_iter;
	};
	
}