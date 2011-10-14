#include <CGAL/Linear_cell_complex.h>
#include <CGAL/Linear_cell_complex_constructors.h>
#include <CGAL/Linear_cell_complex_operations.h> 
#include <iostream>
#include <vector>

typedef CGAL::Combinatorial_map_with_points<4,5> LCC_4;
typedef LCC_4::Dart_handle Dart_handle;
typedef LCC_4::Point Point;
typedef LCC_4::Vector Vector;
typedef LCC_4::FT FT;

// Functor used to display all the vertices of a given volume
template<class LCC> 
struct Display_vol_vertices : public std::unary_function<LCC, void>
{
  Display_vol_vertices(const LCC& alcc) : 
    lcc(alcc), 
    nb_volume(0)
  {}

  void operator() (typename LCC::Dart& d) 
  { 
    std::cout<<"Volume "<<++nb_volume<<" : ";
    for (typename LCC::template 
	   One_dart_per_incident_cell_range<0,3>::const_iterator 
	   it=lcc.template one_dart_per_incident_cell<0,3>
	   (lcc.dart_handle(d)).begin(),
	   itend=lcc.template one_dart_per_incident_cell<0,3>
	   (lcc.dart_handle(d)).end();
	 it!=itend; ++it)
      {
        std::cout << LCC::point(it) << "; ";
      }
    std::cout<<std::endl;
  }
private:
  const LCC& lcc;
  unsigned int nb_volume;
};

int main()
{
  LCC_4 lcc;
	
  // Create two tetrahedra.
  FT p1[5]={ 0, 0, 0, 0, 0}; std::vector<FT> v1(p1,p1+5);
  FT p2[5]={ 0, 2, 0, 0, 0}; std::vector<FT> v2(p2,p2+5);
  FT p3[5]={ 0, 1, 2, 0, 0}; std::vector<FT> v3(p3,p3+5);
  FT p4[5]={ 2, 1, 0, 0, 0}; std::vector<FT> v4(p4,p4+5);
  FT p5[5]={-1, 0, 0, 0, 0}; std::vector<FT> v5(p5,p5+5);
  FT p6[5]={-1, 2, 0, 0, 0}; std::vector<FT> v6(p6,p6+5);
  FT p7[5]={-1, 1, 2, 0, 0}; std::vector<FT> v7(p7,p7+5);
  FT p8[5]={-3, 1, 2, 0, 0}; std::vector<FT> v8(p8,p8+5);
  
  Dart_handle d1 = CGAL::make_tetrahedron(lcc,
					  Point(5, v1.begin(), v1.end()),
					  Point(5, v2.begin(), v2.end()),
					  Point(5, v3.begin(), v3.end()),
					  Point(5, v4.begin(), v4.end()));  
  
  Dart_handle d2 = CGAL::make_tetrahedron(lcc,
					  Point(5, v5.begin(), v5.end()),
					  Point(5, v6.begin(), v6.end()),
					  Point(5, v7.begin(), v7.end()),
					  Point(5, v8.begin(), v8.end()));

  // Display the vertices of each volume by iterating on darts.
  std::for_each(lcc.one_dart_per_cell<3>().begin(),
		lcc.one_dart_per_cell<3>().end(),
		Display_vol_vertices<LCC_4>(lcc));
 
  lcc.display_characteristics(std::cout);
  std::cout<<", valid="<<lcc.is_valid()<<std::endl;

  lcc.sew<4>(d1,d2);
  
  lcc.display_characteristics(std::cout);
  std::cout<<", valid="<<lcc.is_valid()<<std::endl;

  // Add one vertex on the middle of an edge.
  Dart_handle d3 = CGAL::insert_middle_cell_0_in_cell_1(lcc,d1);
  CGAL_assertion( lcc.is_valid() );

  lcc.display_characteristics(std::cout);
  std::cout<<", valid="<<lcc.is_valid()<<std::endl;

	// Add one edge to cut the face in two.
  Dart_handle d4 = CGAL::insert_cell_1_in_cell_2(lcc,d3,d1->beta(0));
  CGAL_assertion( lcc.is_valid() );
	
  lcc.display_characteristics(std::cout);
  std::cout<<", valid="<<lcc.is_valid()<<std::endl;

  // We use the removal operations to get back to the initial cube.
  CGAL::remove_cell<LCC_4,1>(lcc,d4);
  CGAL_assertion( lcc.is_valid() );

  CGAL::remove_cell<LCC_4,0>(lcc,d3);
  CGAL_assertion( lcc.is_valid() );

  lcc.unsew<4>(d1);

  lcc.display_characteristics(std::cout);
  std::cout<<", valid="<<lcc.is_valid()<<std::endl;

	return EXIT_SUCCESS;
}

