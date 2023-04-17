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

			template<typename algo, /*typename state,*/	//algorithm, state type(can be different from algos state
				template<size_t dim> typename func>
			static PointVal<dim> Proceed(algo::state_type* State, const func<dim>* f)
			{
				return algo::Proceed(*State, f);
			}

			/*
			* class Algo{
				public: using state_type = StatePoint
			}
			*/
		};


		


	}//interface
}//opt