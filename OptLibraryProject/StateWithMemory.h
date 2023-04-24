#pragma once
#include "StateInterfaceh.h"
#include "ConcreteState.h"

namespace OptLib {
	namespace StateWithMemory {
		template<size_t dim, typename state = 
			StateInterface::IStateSimplex<dim, ConcreteState::SimplexValSort<dim>>>
		class StateSimplexMemory:public state
		{
			state* State;
		public:
			StateSimplexMemory(state* State, FuncInterface::IFunc<dim> *f):
				state( (*State)GuessDomain().PointNoVal(),f ), State {State}	
				//написать PoinntnoVal для setofPointVal
			{
				a_Memory.push_back(*State);// copies current state to a memory
			}

			const std::vector<state>& Memory() { return a_Memory; }
			void SetDomain(SetOfPoints<dim + 1, PointVal<dim>>&& newDomain) override
			{
				(*State).SetDomain(std::move(newDomain));
				a_Memory.push_back(*State); // copies updated state to a memory
			}

			protected:
				std::vector<state> a_Memory;

		};//StateSimplMem


		template<size_t dim>
		class StatePointImproved : ConcreteState::StatePoint<dim>
		{
			ConcreteState::StatePoint<dim>* State;
		public:
			StatePointImproved(ConcreteState::StatePoint<dim>* State) : State{ State }
			{
				a_Memory.push_back(new ConcreteState::StatePoint<dim>(*State)); // copies current state to a memory
			}
			void UpdateState(const PointVal<dim>& v) override
			{
				(*State).UpdateState(v);
				a_Memory.push_back(new ConcreteState::StatePoint<dim>(*State)); // copies updated state to a memory
			}
			const std::vector<ConcreteState::StatePoint<dim>*>& Memory() { return a_Memory; }
		protected:
			std::vector<ConcreteState::StatePoint<dim>*> a_Memory;
		};

	}
}