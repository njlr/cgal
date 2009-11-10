// Copyright (c) 2009 INRIA Sophia-Antipolis (France).
// All rights reserved.
//
// This file is part of CGAL (www.cgal.org); you may redistribute it under
// the terms of the Q Public License version 1.0.
// See the file LICENSE.QPL distributed with CGAL.
//
// Licensees holding a valid commercial license may use this file in
// accordance with the commercial license agreement provided with the software.
//
// This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
// WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
//
// $URL$
// $Id$
//
//
// Author(s)     : Stephane Tayeb
//
//******************************************************************************
// File Description :
//
//******************************************************************************

#include <string>

#include <CGAL/Cartesian.h>
#include <CGAL/Simple_cartesian.h>
#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Exact_predicates_exact_constructions_kernel.h>


template <class Triangle, class Query, class Result>
bool test_aux(const Triangle t,
              const Query& q,
              const std::string& name,
              const Result& expected)
{
  CGAL::Object object = CGAL::intersection(t,q);
  const Result* pr = CGAL::object_cast<Result>(&object);
  
  if ( (NULL != pr) && (expected == *pr) )
  {
    return true;
  }
  else
  {
    std::cout << "ERROR: intersection(" << name
              << ") did not answer the expected result !";  
    
    if ( NULL != pr )
      std::cout << " (answer: ["<< *pr << "])";
    
    std::cout << std::endl;
  }
  
  return false;
}

template <class K>
bool test()
{
	// types
  typedef typename K::FT FT;
  typedef typename K::Line_3 Line;
  typedef typename K::Point_3 Point;
  typedef typename K::Segment_3 Segment;
  typedef typename K::Ray_3 Ray;
  typedef typename K::Line_3 Line;
  typedef typename K::Triangle_3 Triangle;

  /* -------------------------------------
  // Test data is something like that (in t supporting plane)
  // Triangle is (p1,p2,p3)
  //
  //       +E          +1
  //                 /   \
  //        +C     6+  +8  +4      +B
  //              /   9++7  \
  //            3+-------+5--+2
  //     
  //         +F        +A      
  ------------------------------------- */
  
  Point p1(FT(1.), FT(0.), FT(0.));
  Point p2(FT(0.), FT(1.), FT(0.));
  Point p3(FT(0.), FT(0.), FT(1.));
  
  Triangle t(p1,p2,p3);
  
  // Edges of t 
  Segment s12(p1,p2);
  Segment s21(p2,p1);
  Segment s13(p1,p3);
  Segment s23(p2,p3);
  Segment s32(p3,p2);
  Segment s31(p3,p1);
  
  bool b = test_aux(t,s12,"t-s12",s12);
  b &= test_aux(t,s21,"t-s21",s21);
  b &= test_aux(t,s13,"t-s13",s13);
  b &= test_aux(t,s23,"t-s23",s23);

  // Inside points
  Point p4(FT(0.5), FT(0.5), FT(0.));
  Point p5(FT(0.), FT(0.75), FT(0.25));
  Point p6(FT(0.5), FT(0.), FT(0.5));
  Point p7(FT(0.25), FT(0.625), FT(0.125));
  Point p8(FT(0.5), FT(0.25), FT(0.25));
  
  Segment s14(p1,p4);
  Segment s41(p4,p1);
  Segment s24(p2,p4);
  Segment s42(p4,p2);
  Segment s15(p1,p5);
  Segment s25(p2,p5);
  Segment s34(p3,p4);
  Segment s35(p3,p5);
  Segment s36(p3,p6);
  Segment s45(p4,p5);
  Segment s16(p1,p6);
  Segment s26(p2,p6);
  Segment s62(p6,p2);
  Segment s46(p4,p6);
  Segment s48(p4,p8);
  Segment s56(p5,p6);
  Segment s65(p6,p5);
  Segment s64(p6,p4);
  Segment s17(p1,p7);
  Segment s67(p6,p7);
  Segment s68(p6,p8);
  Segment s86(p8,p6);
  Segment s78(p7,p8);
  Segment s87(p8,p7);
  
  b &= test_aux(t,s14,"t-s14",s14);
  b &= test_aux(t,s41,"t-s41",s41);
  b &= test_aux(t,s24,"t-s24",s24);
  b &= test_aux(t,s42,"t-s42",s42);
  b &= test_aux(t,s15,"t-s15",s15);
  b &= test_aux(t,s25,"t-s25",s25);
  b &= test_aux(t,s34,"t-s34",s34);
  b &= test_aux(t,s35,"t-s35",s35);
  b &= test_aux(t,s36,"t-s36",s36);
  b &= test_aux(t,s45,"t-s45",s45);
  b &= test_aux(t,s16,"t-s16",s16);
  b &= test_aux(t,s26,"t-s26",s26);
  b &= test_aux(t,s62,"t-s62",s62);
  b &= test_aux(t,s46,"t-s46",s46);
  b &= test_aux(t,s65,"t-s65",s65);
  b &= test_aux(t,s64,"t-s64",s64);
  b &= test_aux(t,s48,"t-s48",s48);
  b &= test_aux(t,s56,"t-s56",s56);
  b &= test_aux(t,s17,"t-t17",s17);
  b &= test_aux(t,s67,"t-t67",s67);
  b &= test_aux(t,s68,"t-s68",s68);
  b &= test_aux(t,s86,"t-s86",s86);
  b &= test_aux(t,s78,"t-t78",s78);
  b &= test_aux(t,s87,"t-t87",s87);
  
  // Outside points (in triangle plane)
  Point pA(FT(-0.5), FT(1.), FT(0.5));
  Point pB(FT(0.5), FT(1.), FT(-0.5));
  Point pC(FT(0.5), FT(-0.5), FT(1.));
  Point pE(FT(1.), FT(-1.), FT(1.));
  Point pF(FT(-1.), FT(0.), FT(2.));
  
  Segment sAB(pA,pB);
  Segment sBC(pB,pC);
  Segment s2E(p2,pE);
  Segment sE2(pE,p2);
  Segment s2A(p2,pA);
  Segment s6E(p6,pE);
  Segment sB8(pB,p8);
  Segment sC8(pC,p8);
  Segment s8C(p8,pC);
  Segment s1F(p1,pF);
  Segment sF6(pF,p6);
  
  b &= test_aux(t,sAB,"t-sAB",p2);
  b &= test_aux(t,sBC,"t-sBC",s46);
  b &= test_aux(t,s2E,"t-s2E",s26);
  b &= test_aux(t,sE2,"t-sE2",s62);
  b &= test_aux(t,s2A,"t-s2A",p2);
  b &= test_aux(t,s6E,"t-s6E",p6);
  b &= test_aux(t,sB8,"t-sB8",s48);
  b &= test_aux(t,sC8,"t-sC8",s68);
  b &= test_aux(t,s8C,"t-s8C",s86);
  b &= test_aux(t,s1F,"t-s1F",s13);
  b &= test_aux(t,sF6,"t-sF6",s36);
  
  // Outside triangle plane
  Point pa(FT(0.), FT(0.), FT(0.));
  Point pb(FT(2.), FT(0.), FT(0.));
  Point pc(FT(1.), FT(0.), FT(1.));
  Point pe(FT(1.), FT(0.5), FT(0.5));
  
  Segment sab(pa,pb);
  Segment sac(pa,pc);
  Segment sae(pa,pe);
  Segment sa8(pa,p8);
  Segment sb2(pb,p2);
  
  b &= test_aux(t,sab,"t-sab",p1);
  b &= test_aux(t,sac,"t-sac",p6);
  b &= test_aux(t,sae,"t-sae",p8);
  b &= test_aux(t,sa8,"t-sa8",p8);
  b &= test_aux(t,sb2,"t-sb2",p2);
  
  
  // -----------------------------------
  // Line queries
  // -----------------------------------
  // Edges of t 
  Line l12(p1,p2);
  Line l21(p2,p1);
  Line l13(p1,p3);
  Line l23(p2,p3);
  
  b &= test_aux(t,l12,"t-l12",s12);
  b &= test_aux(t,l21,"t-l21",s21);
  b &= test_aux(t,l13,"t-l13",s13);
  b &= test_aux(t,l23,"t-l23",s23);
  
  // In triangle
  Point p9_(FT(0.), FT(0.5), FT(0.5));
  Point p9(FT(0.25), FT(0.375), FT(0.375));
  
  Line l14(p1,p4);
  Line l41(p4,p1);
  Line l24(p2,p4);
  Line l42(p4,p2);
  Line l15(p1,p5);
  Line l25(p2,p5);
  Line l34(p3,p4);
  Line l35(p3,p5);
  Line l36(p3,p6);
  Line l45(p4,p5);
  Line l16(p1,p6);
  Line l26(p2,p6);
  Line l62(p6,p2);
  Line l46(p4,p6);
  Line l48(p4,p8);
  Line l56(p5,p6);
  Line l47(p4,p7);
  Line l89(p8,p9);
  Line l86(p8,p6);
  Line l68(p6,p8);
  Segment s89_res(p1,p9_);
  
  b &= test_aux(t,l14,"t-l14",s12);
  b &= test_aux(t,l41,"t-l41",s21);
  b &= test_aux(t,l24,"t-l24",s21);
  b &= test_aux(t,l42,"t-l42",s12);
  b &= test_aux(t,l15,"t-l15",s15);
  b &= test_aux(t,l25,"t-l25",s23);
  b &= test_aux(t,l34,"t-l34",s34);
  b &= test_aux(t,l35,"t-l35",s32);
  b &= test_aux(t,l36,"t-l36",s31);
  b &= test_aux(t,l45,"t-l45",s45);
  b &= test_aux(t,l16,"t-l16",s13);
  b &= test_aux(t,l26,"t-l26",s26);
  b &= test_aux(t,l62,"t-l62",s62);
  b &= test_aux(t,l46,"t-l46",s46);
  b &= test_aux(t,l48,"t-l48",s46);
  b &= test_aux(t,l56,"t-l56",s56);
  b &= test_aux(t,l47,"t-l47",s45);
  b &= test_aux(t,l89,"t-t89",s89_res);
  b &= test_aux(t,l68,"t-l68",s64);
  b &= test_aux(t,l86,"t-l86",s46);

  
  // Outside points (in triangle plane)
  Line lAB(pA,pB);
  Line lBC(pB,pC);
  Line l2E(p2,pE);
  Line lE2(pE,p2);
  Line l2A(p2,pA);
  Line l6E(p6,pE);
  Line lB8(pB,p8);
  Line lC8(pC,p8);
  Line l8C(p8,pC);
  Line l1F(p1,pF);
  Line lF6(pF,p6);
  
  b &= test_aux(t,lAB,"t-lAB",p2);
  b &= test_aux(t,lBC,"t-lBC",s46);
  b &= test_aux(t,l2E,"t-l2E",s26);
  b &= test_aux(t,lE2,"t-lE2",s62);
  b &= test_aux(t,l2A,"t-l2A",p2);
  b &= test_aux(t,l6E,"t-l6E",s26);
  b &= test_aux(t,lB8,"t-lB8",s46);
  b &= test_aux(t,lC8,"t-lC8",s64);
  b &= test_aux(t,l8C,"t-l8C",s46);
  b &= test_aux(t,l1F,"t-l1F",s13);
  b &= test_aux(t,lF6,"t-lF6",s31);
  
  // Outside triangle plane
  Line lab(pa,pb);
  Line lac(pa,pc);
  Line lae(pa,pe);
  Line la8(pa,p8);
  Line lb2(pb,p2);
  
  b &= test_aux(t,lab,"t-lab",p1);
  b &= test_aux(t,lac,"t-lac",p6);
  b &= test_aux(t,lae,"t-lae",p8);
  b &= test_aux(t,la8,"t-la8",p8);
  b &= test_aux(t,lb2,"t-lb2",p2);
  
  
	return b;
}

int main()
{
  std::cout << "Testing with Simple_cartesian<float>..." << std::endl ;
  bool b = test<CGAL::Simple_cartesian<float> >();
  
  std::cout << "Testing with Simple_cartesian<double>..." << std::endl ;
	b &= test<CGAL::Simple_cartesian<double> >();
  
  std::cout << "Testing with Cartesian<float>..." << std::endl ;
	b &= test<CGAL::Cartesian<float> >();
  
  std::cout << "Testing with Cartesian<double>..." << std::endl ;
	b &= test<CGAL::Cartesian<double> >();
  
  std::cout << "Testing with Exact_predicates_inexact_constructions_kernel..." << std::endl ;
  b &= test<CGAL::Exact_predicates_inexact_constructions_kernel>();
	
  std::cout << "Testing with Exact_predicates_exact_constructions_kernel..." << std::endl ;
  b &= test<CGAL::Exact_predicates_exact_constructions_kernel>();
  
  if ( b )
    return EXIT_SUCCESS;
  else
    return EXIT_FAILURE;
}