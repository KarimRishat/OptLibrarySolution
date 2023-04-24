#pragma once
#include "FuncInterface.h"

namespace OptLib {
	namespace FuncWithCounter {
		template<size_t dim>
		class IcounterFunc :
			public FuncInterface::IFunc<dim>
		{
			FuncInterface::IFunc<dim>* f;
		public:
			IcounterFunc(IFunc<dim>* f) : f{ f },
				Counter{0}{}
			double operator() (const Point<dim>& x) const override
			{
				const_cast<IcounterFunc*>(this)->Counter += 1;	//изменение в const методе состояние объекта 
				return (*f)(x);
			}
		protected:
			size_t Counter;
		};
	}
}