#pragma once
#include "StateInterfaceh.h"
namespace OptLib
{
	namespace ConcreteState
	{
		template<size_t dim>
		using SimplexValSort = SetOfPointsValSort<dim + 1,
			Point<dim>, PointVal<dim>>;

		template<size_t dim>
		using SimplexValNoSort = SetOfPointsVal<dim + 1,
			Point<dim>, PointVal<dim>>;

		template<size_t dim>
		using StateDirect = StateInterface::IStateSimplex<dim, 
			SimplexValSort<dim>>;	//State for direct optimize methods

		
		class StateSegment : public
			StateInterface::IStateSimplex<1, SimplexValNoSort<1>>
		{
		public:
			StateSegment(const StateSegment&) = default;	//cope constr
			StateSegment(SetOfPoints<2,Point<1>>&& State,
				FuncInterface::IFunc<1> *f):
				StateInterface::IStateSimplex<1, SimplexValNoSort<1>>
				(std::move(OrderPointInSegment(State)), f) {}

		protected:
			SetOfPoints<2, Point<1>> OrderPointInSegment
				(SetOfPoints<2, Point<1>>& set)
			{
				if (set[0] > set[1])
				{
					std::swap(set[0], set[1]);
				}
				return set;
			}

		};
		
	}//concrete
}//OptLib