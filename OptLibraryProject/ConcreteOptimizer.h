#pragma once
#include "Optimizer.h"

namespace OptLib
{
	namespace ConcreteOptimizer
	{
		template<size_t dim>
		class NelderMead
		{
		public:
			static PointVal<dim> Proceed
			(ConcreteState::StateNelderMead<dim>& State,
				const FuncInterface::IFunc<dim>* f)
			{
				double alpha = State.alpha;
				double beta = State.beta;
				double gamma = State.gamma;
				SetOfPoints<dim + 1, PointVal<dim>> NewSimplex =
					State.GuessDomain().Points();	//написать метод для Points (StateInterface)
				PointVal<dim>& xl = NewSimplex[0];
				PointVal<dim>& xh = NewSimplex[dim];
				PointVal<dim>& xg = NewSimplex[dim-1];
				PointVal<dim> XC = NewSimplex[0].p;			//центр масс
				for (size_t i = 1; i < dim; i++)
				{
					XC += NewSimplex[i].p;
				}

				PointVal<dim> xc{ 
					FuncInterface::CreateFromPoint<dim>(XC / (double)dim, f) };		
				//написать функцию создающую pointval

				PointVal<dim> xr{ FuncInterface::CreateFromPoint<dim>
					(xc.p * (1.0 + alpha) - xh.p * alpha, f)};
				if (xr.val < xl.val)
				{
					PointVal<dim> xe{ FuncInterface::CreateFromPoint<dim>
						(xc * (1.0 - gamma) + xr * gamma, f) };
					if (xe.val < xr.val)
					{
						xh = xe;
					}
					else
					{
						xh = xr;
					}
					State.SetDomain(std::move(NewSimplex));
					return State.Guess();
				}

				if (xr.val < xg.val)
				{
					xh = xr;
					State.SetDomain(std::move(NewSimplex));
					return State.Guess();
				}

				if (xr.val < xh.val)
				{
					xh = xr;
					PointVal<dim> xs{
						FuncInterface::CreateFromPoint<dim>(xh.p * beta + xc.p * (1 - beta), f) };
					if (xs.val < xh.val)
					{
						xh = xs;
						State.SetDomain(std::move(NewSimplex));
						return State.Guess();
					}
					State.UpdateDomain(SqeezeSimplex(xl.p, NewSimplex), f);
					return State.Guess();
				}

			}



		protected:
			static auto SqeezeSimplex(const Point<dim>& xl,
				const SetOfPoints<dim + 1, PointVal<dim>> Simplex)
			{
				SetOfPoints<dim + 1, Point<dim>> NewSimplex;
				for (size_t i = 0; i < dim+1; i++)
				{
					NewSimplex[i] = Point<dim>{ xl + (Simplex[i].p - xl) / 2.0 };
				}
				return NewSimplex;
			}
		};

		template<size_t dim>
		class Newton
		{
		/*public:
			static PointVal<dim> Proceed
			(ConcreteState::StateNewton<dim>& State,
				const FuncInterface::IFunc<dim>* f)*/
		protected:
			static Point<dim> GaussSolver(FuncInterface::IHess<dim> A, FuncInterface::IGrad<dim> B)
			{
				// forward loop
				for (int i = 0; i < dim; i++)
				{
					for (int j = i + 1; j < dim; j++)
					{
						double ratio = A[j][i] / A[i][i];
						A[j] = A[j] - ratio * A[i];
						B[j] = B[j] - ratio * B[i];
					}
				}
				// make diagonal of ones
				for (int i = 0; i < dim; i++)
				{
					B[i] = B[i] / A[i][i];
					A[i] = A[i] / A[i][i];
				}
				// backward loop
				for (int i = dim - 1; i > -1; i--)
				{
					for (int j = i + 1; j < dim; j++)
					{
						double ratio = A[i][j] / A[j][j];
						A[i] = A[i] - A[j] * ratio;
						B[i] = B[i] - ratio * B[j];
					}
				}
				return B;
			}

		public:
			static PointVal<dim> Proceed(ConcreteState::StateNewton<dim>& State, const FuncInterface::IFuncWithHess<dim>* f)
			{
				const auto& g = State.Guess();
				Point<dim> dx{ GaussSolver(f->hess(g.P), -1 * f->grad(g.P)) };

				State.UpdateState(FuncInterface::CreateFromPoint<dim>(g.P + dx, f));
				return State.Guess();
			}

		};//class Newton

		template< size_t dim>
		struct NewtonParams
		{
		public:
			using OptAlgo = OptLib::ConcreteOptimizer::Newton<dim>;
			using StateType = ConcreteState::StateNewton<dim>;

		public:
			Point<dim> StartPoint;
			NewtonParams(Point<dim>&& sop)
				:StartPoint{ std::move(sop) }
			{}
			StateType CreateState(FuncInterface::IFuncWithHess<1>* f)
			{
				return { std::move(StartPoint), f };
			}
		};


	}
}