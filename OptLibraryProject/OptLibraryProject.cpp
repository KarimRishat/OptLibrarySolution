#pragma once
#include <iostream>
#include "Test.h"


int main()
{
    Tests::test1();
    Tests::test2();
    Tests::test3();
    Tests::test4();
    Tests::test5();
    Tests::test6();
    Tests::test7();
    Tests::test8();
    Tests::test9();
    Tests::test10();
    Tests::test11();
    std::cout <<'\n' << '\t' << "POINT VAL\n";
    Tests::PointvalPlus();
    Tests::PointValMinus();
    Tests::PointvalMult();
    Tests::PointvalDiv();
    Tests::Pointvalsqrt();
    Tests::Pointvalabs();
    Tests::PointvalPlusScal();
    Tests::PointvalMinusScal();
    Tests::PointvalMultScal();
    Tests::PointvalDivScal();

}
