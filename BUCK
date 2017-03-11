include_defs('//BUCKAROO_DEPS')

def merge_dicts(x, y):
  z = x.copy()
  z.update(y)
  return z

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

prebuilt_cxx_library(
  name = 'cgal-installation',
  header_only = True,
  header_namespace = 'CGAL',
  exported_headers = merge_dicts({
    'version.h': ':version.h',
    'compiler_config.h': ':compiler_config.h',
  },
  subdir_glob([
    ('Installation/include/CGAL', '**/*.h'),
  ])),
  visibility = [
    'PUBLIC',
  ],
  deps = BUCKAROO_DEPS,
)
