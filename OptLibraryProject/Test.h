#pragma once
#include <iostream>
#include "Simplex.h"
#include "SimplexStream.h"
#include "Func.h"
#include "ConcreteState.h"
using namespace OptLib;
namespace Tests
{
    //point
    void test1();   //p1+p2
    void test2();   //p1-p2
    void test3();   //p1+x
    void test4();   //p1-x
    void test5();   //p1*p2
    void test6();   //p1 / p2
    void test7();   //p1*x
    void test8();   //p1 / x
    void test9();   //p1 || p2
    void test10();  //sqrt p1
    void test11();  //abs p1
    void testDotProd();  //dotprod

    //PointVal
    void PointvalPlus();
    void PointValMinus();
    void PointvalMult();
    void PointvalDiv();
    void Pointvalsqrt();
    void Pointvalabs();
    void PointvalPlusScal();
    void PointvalMinusScal();
    void PointvalMultScal();
    void PointvalDivScal();

    //SetOfPoints
    void SetOfPoints();
    void SetOfPointsMult();
    void SetOfPointsTrPoint();

    void MeanTest();
    void DispTest();

    //SetOfPointsVal
    void SOPVAL();
    void SOPVAL2();

    //SortSOPV
    void SortSopv();


    //Function
    void Func1();
    void FuncGrad();
    void FuncHess();
    void FunParabFind();
    void TestGradParab();
    void TestHessParab();


    void GradDirectTest();


    //funcParam
    void FuncParam();
    void ParamPlaneTest();

    //optim
    void simplexTest(); 


}

