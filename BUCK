include_defs('//BUCKAROO_DEPS')

cxx_library(
  name = 'cgal-kernel-23',
  header_namespace = 'CGAL',
  exported_headers = subdir_glob([
    ('Kernel_23/include/CGAL', '**/*.h'),
  ]),
  srcs = glob([
    'Kernel_23/src/**/*.cpp',
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
