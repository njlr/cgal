include_defs('//BUCKAROO_DEPS')

def merge_dicts(x, y):
  z = x.copy()
  z.update(y)
  return z

flatten = lambda l: [item for sublist in l for item in sublist]

VERSION_H = """
#ifndef CGAL_VERSION_H
#define CGAL_VERSION_H

#define CGAL_VERSION 4.10-I-900
#define CGAL_VERSION_NR 1041000900
#define CGAL_SVN_REVISION 99999

#define CGAL_RELEASE_DATE 20170311

#include <CGAL/version_macros.h>

#endif
"""

COMPILER_CONFIG_H = """
#define CGAL_USE_GMP 1
#define CGAL_USE_MPFR 1
#define CGAL_BUILD_SHARED_LIBS 1
#define CGAL_USE_CORE 1
#define CGAL_HAS_IMAGEIO 1
"""

modules = [
  'AABB_tree',
  'Advancing_front_surface_reconstruction',
  'Algebraic_foundations',
  'Algebraic_kernel_d',
  'Algebraic_kernel_for_circles',
  'Algebraic_kernel_for_spheres',
  'Alpha_shapes_2',
  'Alpha_shapes_3',
  'Apollonius_graph_2',
  'Arithmetic_kernel',
  'Arrangement_on_surface_2',
  'BGL',
  'Barycentric_coordinates_2',
  'Boolean_set_operations_2',
  'Bounding_volumes',
  'Box_intersection_d',
  'CGAL_Core',
  'CGAL_ImageIO',
  'CGAL_ipelets',
  'Cartesian_kernel',
  'Circular_kernel_2',
  'Circular_kernel_3',
  'Circulator',
  'Combinatorial_map',
  'Cone_spanners_2',
  'Conic_2',
  'Convex_decomposition_3',
  'Convex_hull_2',
  'Convex_hull_3',
  'Convex_hull_d',
  'Distance_2',
  'Distance_3',
  'Documentation',
  'Envelope_2',
  'Envelope_3',
  'Filtered_kernel',
  'Generator',
  'Geomview',
  'HalfedgeDS',
  'Hash_map',
  'Homogeneous_kernel',
  'Inscribed_areas',
  'Installation',
  'Interpolation',
  'Intersections_2',
  'Intersections_3',
  'Interval_skip_list',
  'Interval_support',
  'Inventor',
  'Jet_fitting_3',
  'Kernel_23',
  'Kernel_d',
  'Kinetic_data_structures',
  'Kinetic_framework',
  'LEDA',
  'Linear_cell_complex',
  'Maintenance',
  'Matrix_search',
  'Mesh_2',
  'Mesh_3',
  'Minkowski_sum_2',
  'Minkowski_sum_3',
  'Miscellany',
  'Modifier',
  'Modular_arithmetic',
  'Nef_2',
  'Nef_3',
  'Nef_S2',
  'NewKernel_d',
  'Number_types',
  'OpenNL',
  'Operations_on_polyhedra',
  'Optimal_transportation_reconstruction_2',
  'Optimisation_basic',
  'Partition_2',
  'Periodic_2_triangulation_2',
  'Periodic_3_triangulation_3',
  'Point_set_2',
  'Point_set_processing_3',
  'Point_set_shape_detection_3',
  'Poisson_surface_reconstruction_3',
  'Polygon',
  'Polygon_mesh_processing',
  'Polyhedron',
  'Polyhedron_IO',
  'Polyline_simplification_2',
  'Polynomial',
  'Polytope_distance_d',
  'Principal_component_analysis',
  'Profiling_tools',
  'Property_map',
  'QP_solver',
  'Random_numbers',
  'Ridges_3',
  'STL_Extension',
  'Scale_space_reconstruction_3',
  'Scripts',
  'SearchStructures',
  'Segment_Delaunay_graph_2',
  'Segment_Delaunay_graph_Linf_2',
  'Skin_surface_3',
  'Snap_rounding_2',
  'Solver_interface',
  'Spatial_searching',
  'Spatial_sorting',
  'Straight_skeleton_2',
  'Stream_lines_2',
  'Stream_support',
  'Subdivision_method_3',
  'Surface_mesh',
  'Surface_mesh_deformation',
  'Surface_mesh_parameterization',
  'Surface_mesh_segmentation',
  'Surface_mesh_shortest_path',
  'Surface_mesh_simplification',
  'Surface_mesh_skeletonization',
  'Surface_mesher',
  'Sweep_line_2',
  'TDS_2',
  'TDS_3',
  'Three',
  'Triangulation',
  'Triangulation_2',
  'Triangulation_3',
  'Union_find',
  'Visibility_2',
  'Voronoi_diagram_2',
]

genrule(
  name = 'version.h',
  out = 'version.h',
  cmd = 'echo "' + VERSION_H + '" > $OUT',
)

genrule(
  name = 'compiler_config.h',
  out = 'compiler_config.h',
  cmd = 'echo "' + COMPILER_CONFIG_H + '" > $OUT',
)

cxx_library(
  name = 'cgal',
  header_namespace = 'CGAL',
  exported_headers = merge_dicts({
    'version.h': ':version.h',
    'compiler_config.h': ':compiler_config.h',
  },
  subdir_glob(flatten([
    [
      (x + '/include/CGAL', '**/*.h'),
      (x + '/include/CGAL', '**/*.hpp'),
      (x + '/include/CGAL', '**/*.tcc')
    ] for x in modules
  ]))),
  srcs = flatten([ glob([
    x + '/src/**/*.cpp',
  ]) for x in modules ]),
  visibility = [
    'PUBLIC',
  ],
  deps = BUCKAROO_DEPS,
)
