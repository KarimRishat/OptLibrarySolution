#pragma once
#include "Simplex.h"
template<class Stream, size_t dim>
Stream& operator << (Stream& o, const OptLib::Point<dim>& p)
{
	o <<'(' << p[0];
	
		for (size_t i = 1; i < p.size(); ++i)
		{
			o << ", " << p[i];
		}
	o << ')';
	return o;
}

template<class Stream, size_t dim>
Stream& operator << (Stream& o, const OptLib::PointVal<dim>& p)
{
	o << "x = (" << p[0];

	for (size_t i = 1; i < p.p.size(); ++i)
	{
		o << ", " << p[i];
	}
	o << ")\tf(x) = "<<p.val;
	return o;
}