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
			StateSegment(const StateSegment&) = default;	//copy constr
			StateSegment(SetOfPoints<2,Point<1>>&& State,
				FuncInterface::IFunc<1> *f):
				StateInterface::IStateSimplex<1, SimplexValNoSort<1>>
				(std::move(OrderPointInSegment(State)), f) {}

		protected:
			SetOfPoints<2, Point<1>> OrderPointInSegment
				(SetOfPoints<2, Point<1>>& set)
			{
				if (set[0][0] > set[1][0])
				{
					std::swap(set[0], set[1]);
				}
				return set;
			}

		};//StateSegment



		template<size_t dim>
		class StatePoint : public StateInterface::IState<dim>
		{
		protected:
			PointVal<dim> dx{};
		public:
			bool IsConverged(double abs_tol, double rel_tol) const override
			{
				const auto& stad = dx;
				auto var{ abs<dim>(dx / this->Guess()) };
				for (size_t i = 0; i < dim; i++)
				{

					bool f = (((stad[i]) < abs_tol) || (var[i] < rel_tol)) &&
						(((stad.val) < abs_tol) || (var.val < rel_tol));
					if (!f) return false;
				}

				return true;
			}

			virtual void UpdateState(const PointVal<dim>& v)
			{
				dx = abs<dim>(v - this->Guess());
				this->its_guess = v;
			}

		};




		template<size_t dim>
		class StateNelderMead
			:public StateDirect<dim>
		{
		public:
			const double alpha, beta, gamma;
			StateNelderMead(SetOfPoints<dim+1,Point<dim>>&& State,
				FuncInterface::IFunc<dim> *f,
				double alpha, double beta, double gamma):
				StateDirect<dim>(std::move(State), f),
				alpha{ alpha }, beta{ beta }, gamma{ gamma }{}
		};


		template<size_t dim>
		class StateNewton :public StatePoint<dim>
		{
		public:
			StateNewton(Point<dim>&& x0, const FuncInterface::IFuncWithHess<dim>* f)
			{
				this->its_guess = FuncInterface::CreateFromPoint<dim>(std::move(x0), f);
			}
		};

		
	}//concrete
}//OptLib