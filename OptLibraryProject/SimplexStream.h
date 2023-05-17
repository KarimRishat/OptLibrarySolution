#pragma once
#include "Simplex.h"
#include "FuncInterface.h"
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
	std::ostream os;
	os.setf(std::ios::left);
	os.width(50);
	return os<<o;
}

template <class Stream, size_t count, typename point>
Stream& operator<< (Stream& os, const OptLib::SetOfPoints<count, point>& p) {
	
	for (const auto& x : p) {
		os << x << "\n";
	}
	
	return os;
}


template <class Stream, size_t count, typename point, typename PointVal>
Stream& operator<< (Stream& os, const OptLib::SetOfPointsVal<count, point, PointVal>& SOPV) {

	os << SOPV.ItsSetOfPoints;

	return os;
}

template <class Stream, size_t count, typename point, typename PointVal>
Stream& operator<< (Stream& os, const OptLib::SetOfPointsValSort<count, point, PointVal>& SOPV) {

	os << SOPV.ItsSetOfPoints;

	return os;
}



//template <class Stream, size_t count, typename point, typename pointVal>
//Stream& operator<<(Stream& os, const OptLib::SetOfPointsVal<count, point, pointVal>& set) {
//	for (const auto& x : p) {
//		os << x << "\n";
//	}
//	return os;
//}


