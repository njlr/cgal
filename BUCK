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
  ]),
  srcs = glob([
    'STL_Extension/src/**/*.cpp',
  ]),
  visibility = [
    'PUBLIC',
  ],
  deps = BUCKAROO_DEPS,
)

cxx_binary(
  name = 'test',
  srcs = glob([
    'Distance_2/test/Distance_2/*.cpp',
  ]),
  deps = [
    ':cgal-distance-2',
  ],
)
