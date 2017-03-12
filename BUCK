include_defs('//BUCKAROO_DEPS')

cxx_library(
  name = 'cgal-stl-extension',
  header_namespace = 'CGAL',
  exported_headers = subdir_glob([
    ('STL_Extension/include/CGAL', '**/*.h'),
  ]),
  headers = subdir_glob([
    ('Kernel_23/include/CGAL', 'enum.h'),
    ('Kernel_23/include/CGAL', 'Kernel/Same_uncertainty.h'),
    ('Profiling_tools/include/CGAL', 'Profile_counter.h'),
  ]),
  srcs = glob([
    'STL_Extension/src/**/*.cpp',
  ]),
  visibility = [
    'PUBLIC',
  ],
  deps = BUCKAROO_DEPS,
)
