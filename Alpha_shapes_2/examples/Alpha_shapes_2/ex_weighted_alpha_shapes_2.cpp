#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Weighted_alpha_shape_euclidean_traits_2.h>
#include <CGAL/Regular_triangulation_2.h>
#include <CGAL/Alpha_shape_2.h>

#include <iostream>
#include <fstream>
#include <vector>
#include <list>


typedef CGAL::Exact_predicates_inexact_constructions_kernel K;
typedef K::FT FT;
typedef K::Point_2 Point_base;
typedef K::Weighted_point_2  Point;

typedef CGAL::Weighted_alpha_shape_euclidean_traits_2<K> Gt;
typedef CGAL::Regular_triangulation_vertex_base_2<Gt> Rvb;
typedef CGAL::Alpha_shape_vertex_base_2<Gt,Rvb> Vb;
typedef CGAL::Regular_triangulation_face_base_2<Gt> Rf;
typedef CGAL::Alpha_shape_face_base_2<Gt, Rf>  Fb;

typedef CGAL::Triangulation_data_structure_2<Vb,Fb> Tds;
typedef CGAL::Regular_triangulation_2<Gt,Tds> Triangulation_2;

typedef CGAL::Alpha_shape_2<Triangulation_2>  Alpha_shape_2;

typedef Alpha_shape_2::Alpha_shape_edges_iterator Alpha_shape_edges_iterator;

template <class InputIterator, class OutputIterator>
void
alpha_edges(InputIterator begin, InputIterator end,
	    const FT &Alpha,
	    bool mode,
	    OutputIterator out)
  // Generate Alpha Shape
{
  std::vector<Gt::Segment_2> V_seg;
  Alpha_shape_2 A(begin,end);

  if (mode)
    { A.set_mode(Alpha_shape_2::GENERAL); }
  else
    { A.set_mode(Alpha_shape_2::REGULARIZED); };
  A.set_alpha(Alpha);

  for(Alpha_shape_edges_iterator it =  A.alpha_shape_edges_begin();
      it != A.alpha_shape_edges_end();
      ++it){
    *out++ = A.segment(*it);
  }
}

bool
file_input(std::list<Point>& L)
{

  std::ifstream is("./data/fin", std::ios::in);

  if(is.fail())
    {
      std::cerr << "unable to open file for input" << std::endl;
      return false;
    }

  CGAL::set_ascii_mode(is);

  int n;
  is >> n;
  std::cout << "Reading " << n << " points" << std::endl;
  for( ; n>0 ; n--)
    {
      Point_base p(0., 0.);
      is >> p;
      if(is) {
        L.push_back(Point (p, FT(10)));
      } else {
        return false;
      }
    }
  std::cout << "Points inserted" << std::endl;
  return true;
}


// Reads a list of points and returns a list of segments corresponding to
// the weighted Alpha Shape.
int main()
{
  std::list<Point> points;
  file_input(points);
  std::vector<Gt::Segment_2> segments;
  alpha_edges(points.begin(), points.end(),
	      FT(10000),Alpha_shape_2::GENERAL,
	      std::back_inserter(segments));
  std::cout << segments.size() << " alpha shape edges." << std::endl;
  return 0;
}
