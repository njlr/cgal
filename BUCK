include_defs('//BUCKAROO_DEPS')

cxx_library(
  name = 'cgal-profiling-tools',
  header_namespace = 'CGAL',
  exported_headers = subdir_glob([
    ('Profiling_tools/include/CGAL', '**/*.h'),
  ]),
  headers = subdir_glob([
    ('Kernel_23/include/CGAL', '**/*.h'),
    ('STL_Extension/include/CGAL', '**/*.h'),
  ]),
  srcs = glob([
    'Profiling_tools/src/**/*.cpp',
  ]),
  visibility = [
    'PUBLIC',
  ],
  deps = BUCKAROO_DEPS,
)
