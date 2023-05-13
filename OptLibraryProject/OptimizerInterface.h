#pragma once
#include "ConcreteState.h"
namespace OptLib
{
	namespace OptimizerInterface
	{

		template<size_t dim>
		class OptimizerAlgorithm
		{
		public:
			static bool IsConverged
			(const StateInterface::IState<dim>* State,
				double abs_tol, double rel_tol)
			{
				return State->IsConverged(abs_tol, rel_tol);
			}
			//algorithm, state type(can be different from algos state
			template<typename algo, typename state,/*template<size_t dim>*/ typename func>
			static PointVal<dim> Proceed
			(state* State,
				const func* f)
			{
				return algo::Proceed(*State, f);
			}

		};
	}//interface
}//opt



		/*
		* class Algo{
			public: using state_type = StatePoint
		}
		*/