include_defs('//BUCKAROO_DEPS')

prebuilt_cxx_library(
  name = 'cgal-distance-2',
  header_only = True,
  header_namespace = 'CGAL',
  exported_headers = subdir_glob([
    ('Distance_2/include/CGAL', '**/*.h'),
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
