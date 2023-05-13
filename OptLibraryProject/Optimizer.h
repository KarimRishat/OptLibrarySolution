#pragma once
#include "OptimizerInterface.h"
namespace OptLib
{
	struct OptimizerPrm
	{
		double eps_x, eps_f;
		size_t max_iter;
		OptimizerPrm(double a, double b, size_t c):
			eps_x{ a }, eps_f{ b }, max_iter{ c }{}
	};


	template <size_t dim, typename state,
		/*template<size_t dim> */typename func>
	class Optimizer
	{
	public:
		const PointVal<dim>& CurrentGuess()const 
		{
			return State->Guess();
		}

		Optimizer(state* State, func* f,
			OptimizerPrm prm) : State{ State }, f{ f },	//param - prm
			Prm{ prm }, s{ 0 }{}	//s  - size-t

		template<typename algo>
		PointVal<dim> Optimize()
		{
			bool g = false;
			while (!g && s<MaxIterCount())
			{
				std::cout << "Current state: " << State->Guess() << "\n";
				/*State = */OptimizerInterface::OptimizerAlgorithm<dim>::
					template Proceed< algo, state, func/*<dim>*/>(State, f);
				++s;
				g = OptimizerInterface::OptimizerAlgorithm<dim>
					::IsConverged(State, tol_x(), tol_f());
			}
			std::cout << "Optimization ended\n";
			std::cout << "Total number of iterations is s = " << CurIterCount() << '\n';
			std::cout << "Final guess is x = " << CurrentGuess() << '\n';
			return CurrentGuess();
		}

		template<typename algo>
		PointVal<dim> Continue(double eps_x, double eps_f)
		{
			this->Prm.eps_x = eps_x;
			this->Prm.eps_f = eps_f;
			s = 0;
			return Optimize<algo>();
		}
		double tol_x() { return Prm.eps_x; }
		double tol_f() { return this->Prm.eps_f; }
		size_t MaxIterCount() { return this->Prm.max_iter; }
		size_t CurIterCount() { return s; }

	protected:
		state* State;
		func* f;
		size_t s;		
		OptimizerPrm Prm;

		
	};//Optimizer



	


}