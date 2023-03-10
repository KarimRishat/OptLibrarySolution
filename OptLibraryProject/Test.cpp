#include "Test.h"

void Tests::test1()
{
    constexpr size_t n = 5;
    Point<n> p1 = { 5.9, 3.0, 4.4, 4.503, 10.3 };
    Point<n> p2 = { 6.0, 3.5, 4.3, 6.503, 20.3 };
    Point<n> p3 = p1 + p2;
    std::cout << p1 << '\n' << "+\n" << p2 << '\n' << p3 << '\n';

}

void Tests::test2()
{
    constexpr size_t n = 5;
    Point<n> p1 = { 5.9, 3.0, 4.4, 4.503, 10.3 };
    Point<n> p2 = { 6.0, 3.5, 4.3, 6.503, 20.3 };
    Point<n> p3 = p2 - p1;
    std::cout << '\n' << p2 << '\n' <<"-\n" << p1 << '\n' << p3 << '\n';
}

void Tests::test3()
{
    double x = 5.5;
    constexpr size_t n = 5;
    Point<n> p1 = { 5.9, 3.0, 4.4, 4.503, 10.3 };
    Point<n> p2 = p1 + x;
    std::cout <<'\n' << p1 << "\n+\n" << x << '\n' << p2 << '\n';
}

void Tests::test4()
{
    double x = 5.5;
    constexpr size_t n = 5;
    Point<n> p1 = { 5.9, 3.0, 4.4, 4.503, 10.3 };
    Point<n> p2 = p1 - x;
    std::cout << '\n' << p1 << "\n-\n" << x << '\n' << p2 << '\n';
}

void Tests::test5()
{
    constexpr size_t n = 5;
    Point<n> p1 = { 5.9, 3.0, 4.4, 4.503, 10.3 };
    Point<n> p2 = { 6.0, 3.5, 4.3, 6.503, 20.3 };
    Point<n> p3 = p1 * p2;
    std::cout << '\n' << p1 << '\n' << "*\n" << p2 << '\n' << p3 << '\n';
}

void Tests::test6()
{
    constexpr size_t n = 5;
    Point<n> p1 = { 5.9, 3.0, 4.4, 4.503, 10.3 };
    Point<n> p2 = { 6.0, 3.5, 4.3, 6.503, 20.3 };
    Point<n> p3 = p1 / p2;
    std::cout << '\n' << p1 << '\n' << "/\n" << p2 << '\n' << p3 << '\n';
}

void Tests::test7()
{
    double x = 5.5;
    constexpr size_t n = 5;
    Point<n> p1 = { 5.9, 3.0, 4.4, 4.503, 10.3 };
    Point<n> p2 = p1 * x;
    std::cout << '\n' << p1 << "\n*\n" << x << '\n' << p2 << '\n';
}

void Tests::test8()
{
    double x = 5.5;
    constexpr size_t n = 5;
    Point<n> p1 = { 5.9, 3.0, 4.4, 4.503, 10.3 };
    Point<n> p2 = p1 / x;
    std::cout << '\n' << p1 << "\n/\n" << x << '\n' << p2 << '\n';
}

void Tests::test9()
{
    constexpr size_t n = 5;
    Point<n> p1 = { 0.0, 0.0, 0.0, 0.0, 0.0 };
    Point<n> p2 = { 0.0, 0.0, 0.0, 0.0, 0.0 };
    bool p3 = p2 || p1;
    std::cout << '\n' << p2 << '\n' << "||\n" << p1 << '\n' << p3 << '\n';
}

void Tests::test10()
{
    constexpr size_t n = 5;
    Point<n> p1 = { 5.9, 3.0, 4.4, 4.503, 10.3 };
    Point<n> p2 = sqrt(p1);
    std::cout << '\n' <<"sqrt(" << p1 << ")\n" << p2 << '\n';
}

void Tests::test11()
{
    constexpr size_t n = 5;
    Point<n> p1 = { -5.9, 3.0, -4.4, 4.503, 10.3 };
    Point<n> p2 = abs(p1);
    std::cout << '\n' << "abs(" << p1 << ")\n" << p2 << '\n';
}

void Tests::testDotProd()
{
    constexpr size_t n = 2;
    Point<n> p1 = { 5.0, 3.0};
    Point<n> p2 = { 6.0, 3.5};
    double res = DotProd(p1, p2);
    std::cout << "\n SCALAR PROIZVEDENIE\n" << res;
}

void Tests::PointvalPlus()
{
    constexpr size_t n = 5;
    Point<n> p1 = { 5.9, 3.0, 4.4, 4.503, 10.3 };
    Point<n> p2 = { 6.0, 3.5, 4.3, 6.503, 20.3 };
    double v1 = 302.55, v2 = 905.15;
    PointVal<n> f1{ p1,v1 };
    PointVal<n> f2{ p2,v2 };
    PointVal<n> f3 = f1 + f2;
    std::cout << '\n' << f1 << '\n' << "+\n" << f2 << '\n' 
        <<"result:\n"<< f3 << '\n';
}

void Tests::PointValMinus()
{
    constexpr size_t n = 5;
    Point<n> p1 = { 5.9, 3.0, 4.4, 4.503, 10.3 };
    Point<n> p2 = { 6.0, 3.5, 4.3, 6.503, 20.3 };
    double v1 = 302.55, v2 = 905.15;
    PointVal<n> f1{ p1,v1 };
    PointVal<n> f2{ p2,v2 };
    PointVal<n> f3 = f1 - f2;
    std::cout << '\n' << f1 << '\n' << "-\n" << f2 << '\n' 
        << "result:\n" << f3 << '\n';
}

void Tests::PointvalMult()
{
    constexpr size_t n = 5;
    Point<n> p1 = { 5.9, 3.0, 4.4, 4.503, 10.3 };
    Point<n> p2 = { 6.0, 3.5, 4.3, 6.503, 20.3 };
    double v1 = 302.55, v2 = 905.15;
    PointVal<n> f1{ p1,v1 };
    PointVal<n> f2{ p2,v2 };
    PointVal<n> f3 = f1 * f2;
    std::cout << '\n' << f1 << '\n' << "*\n" << f2 << '\n'
        << "result:\n" << f3 << '\n';
}

void Tests::PointvalDiv()
{
    constexpr size_t n = 5;
    Point<n> p1 = { 5.9, 3.0, 4.4, 4.503, 10.3 };
    Point<n> p2 = { 6.0, 3.5, 4.3, 6.503, 20.3 };
    double v1 = 302.55, v2 = 905.15;
    PointVal<n> f1{ p1,v1 };
    PointVal<n> f2{ p2,v2 };
    PointVal<n> f3 = f1 / f2;
    std::cout << '\n' << f1 << '\n' << "/\n" << f2 << '\n'
        << "result:\n" << f3 << '\n';
}

void Tests::Pointvalsqrt()
{
    constexpr size_t n = 5;
    Point<n> p1 = { 5.9, 3.0, 4.4, 4.503, 10.3 };
    double v1 = 302.55;
    PointVal<n> f1{ p1,v1 };
    PointVal<n> f2 = sqrt(f1);
    std::cout << '\n' << "sqrt(" << f1 << ")\n" << f2 << '\n';
}

void Tests::Pointvalabs()
{
    constexpr size_t n = 5;
    Point<n> p1 = { -5.9, 3.0, -4.4, 4.503, 10.3 };
    double v1 = -302.55;
    PointVal<n> f1{ p1,v1 };
    PointVal<n> f2 = abs(f1);
    std::cout << '\n' << "abs(" << f1 << ")\n" << f2 << '\n';
}

void Tests::PointvalPlusScal()
{
    double x = 5.5;
    constexpr size_t n = 5;
    Point<n> p1 = { 5.9, 3.0, 4.4, 4.503, 10.3 };
    double v1 = -302.55;
    PointVal<n> f1{ p1,v1 };
    PointVal<n> f2 = f1 + x;
    std::cout << '\n' << f1 << '\n' << "+\n" << x << '\n'
        << "result:\n" << f2 << '\n';
}

void Tests::PointvalMinusScal()
{
    double x = 5.5;
    constexpr size_t n = 5;
    Point<n> p1 = { 5.9, 3.0, 4.4, 4.503, 10.3 };
    double v1 = -302.55;
    PointVal<n> f1{ p1,v1 };
    PointVal<n> f2 = f1 - x;
    std::cout << '\n' << f1 << '\n' << "-\n" << x << '\n'
        << "result:\n" << f2 << '\n';
}

void Tests::PointvalMultScal()
{
    double x = 5.5;
    constexpr size_t n = 5;
    Point<n> p1 = { 5.9, 3.0, 4.4, 4.503, 10.3 };
    double v1 = -302.55;
    PointVal<n> f1{ p1,v1 };
    PointVal<n> f2 =  x * f1;
    std::cout << '\n' << f1 << '\n' << "*\n" << x << '\n'
        << "result:\n" << f2 << '\n';
}

void Tests::PointvalDivScal()
{
    double x = 5.5;
    constexpr size_t n = 5;
    Point<n> p1 = { 5.9, 3.0, 4.4, 4.503, 10.3 };
    double v1 = -302.55;
    PointVal<n> f1{ p1,v1 };
    PointVal<n> f2 = f1 / x;
    std::cout << '\n' << f1 << '\n' << "/\n" << x << '\n'
        << "result:\n" << f2 << '\n';
}

void Tests::SetOfPoints()
{
    constexpr size_t n = 5;
    Point<n> p1 = { 1, 2, 3, 4, 5 };
    Point<n> p2 = { 6, 7, 8, 9, 10 };
    Point<n> p3 = { 1, 2, 3, 5, 3 };
    Point<n> p4 = { 1, 1, 2, 1, 3 };
    Point<n> p5 = { 1, 2, 2, 15, 10 };
    OptLib::SetOfPoints<n,Point<n>> set1 = { p1, p2, p3, p4, p5 };
    OptLib::SetOfPoints<n, Point<n>> set2 = { p2, p1, p5, p4, p3 };
    std::cout << '\n' << set1 <<'\n'<< set2;
}

void Tests::SetOfPointsMult()
{
    constexpr size_t n = 5;
    Point<n> p1 = { 1, 2, 3, 4, 5 };
    Point<n> p2 = { 6, 7, 8, 9, 10 };
    Point<n> p3 = { 1, 2, 3, 5, 3 };
    Point<n> p4 = { 1, 1, 2, 1, 3 };
    Point<n> p5 = { 1, 2, 2, 15, 10 };
    OptLib::SetOfPoints<n, Point<n>> set1 = { p1, p2, p3, p4, p5 };
    OptLib::SetOfPoints<n, Point<n>> set2 = { p2, p1, p5, p4, p3 };
    std::cout << '\n' << set1 * set2;
}

void Tests::MeanTest()
{
    constexpr size_t n = 2;
    constexpr size_t count = 3;
    Point<n> p1 = { 1, 0 };
    Point<n> p2 = { 0, 1 };
    Point<n> p3 = { 0, 0 };
    OptLib::SetOfPoints<count, Point<n>> set1{ p1, p2, p3 };
    RawSetOfPoints<count, Point<n>> RawSet{ set1 };
    Point<n> res = RawSet.Mean();
    std::cout <<"Mean:\n"<< res<<'\n';
}

void Tests::DispTest()
{
    constexpr size_t n = 2;
    constexpr size_t count = 3;
    Point<n> p1 = { 1, 0 };
    Point<n> p2 = { 0, 1 };
    Point<n> p3 = { 0, 0 };
    OptLib::SetOfPoints<count, Point<n>> set1{ p1, p2, p3 };
    RawSetOfPoints<count, Point<n>> RawSet{ set1 };
    Point<n> res = RawSet.Variance();
    std::cout <<"Variance:\n"<< res;
}

void Tests::SOPVAL()
{
    /*constexpr size_t n = 5;
    Point<n> p1 = { 1, 2, 3, 4, 5 };
    Point<n> p2 = { 6, 7, 8, 9, 10 };
    Point<n> p3 = { 1, 2, 3, 5, 3 };
    Point<n> p4 = { 1, 1, 2, 1, 3 };
    Point<n> p5 = { 1, 2, 2, 15, 10 };*/
    constexpr size_t n = 5;
    Point<n> p1 = { 5.9, 3.0, 4.4, 4.503, 10.3 };
    Point<n> p2 = { 6.0, 3.5, 4.3, 6.503, 20.3 };
    Point<n> p3 = { 1, 2, 3, 5, 3 };
    Point<n> p4 = { 1, 1, 2, 1, 3 };
    Point<n> p5 = { 1, 2, 2, 15, 10 };
    double v1 = 302.55, v2 = 905.15, v3 = 0.15, v4 = 1.5, v5 = 0.9;
    PointVal<n> f1{ p1,v1 };
    PointVal<n> f2{ p2,v2 };
    PointVal<n> f3{ p3,v3 };
    PointVal<n> f4{ p4,v4 };
    PointVal<n> f5{ p5,v5 };
    OptLib::SetOfPoints<n, PointVal<n>> set1 = { f1, f2, f3, f4, f5 };
    OptLib::SetOfPointsVal<n, Point<n>, PointVal<n>> SOPV{ std::move(set1) };
    std::cout << '\n' <<"SetOfPointsVal1:\n" << SOPV << '\n';
}

void Tests::SOPVAL2()
{
    constexpr size_t n = 5;
    Point<n> p1 = { 5.9, 3.0, 4.4, 4.503, 10.3 };
    Point<n> p2 = { 6.0, 3.5, 4.3, 6.503, 20.3 };
    Point<n> p3 = { 1, 2, 3, 5, 3 };
    Point<n> p4 = { 1, 1, 2, 1, 3 };
    Point<n> p5 = { 1, 2, 2, 15, 10 };
    std::array<double, n>&& vals{ 0.5, 0.4,0.3,0.2,0.1 };
    OptLib::SetOfPoints<n, Point<n>> set1 = { p1, p2, p3, p4, p5 };
    OptLib::SetOfPointsVal<n, Point<n>, PointVal<n>> SOPV{ std::move(set1), std::move(vals) };
    std::cout << '\n' << "SetOfPointsVal2:\n" << SOPV << '\n';
}

void Tests::SortSopv()
{
    constexpr size_t n = 5;
    Point<n> p1 = { 5.9, 3.0, 4.4, 4.503, 10.3 };
    Point<n> p2 = { 6.0, 3.5, 4.3, 6.503, 20.3 };
    Point<n> p3 = { 1, 2, 3, 5, 3 };
    Point<n> p4 = { 1, 1, 2, 1, 3 };
    Point<n> p5 = { 1, 2, 2, 15, 10 };
    std::array<double, n>&& vals{ 1.5, 2.4,0.3,0.02,0.189 };
    OptLib::SetOfPoints<n, Point<n>> set1 = { p1, p2, p3, p4, p5 };
    OptLib::SetOfPointsValSort<n, Point<n>, PointVal<n>> sortedSOPV{ std::move(set1),std::move(vals) };
    std::cout << '\n' << "SetOfPointsVal2:\n" << sortedSOPV << '\n';
}


