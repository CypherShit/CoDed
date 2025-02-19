find_path(GPERFTOOLS_INCLUDE_DIR
  NAMES gperftools/malloc_extension.h
)

find_library(GPERFTOOLS_LIBRARIES
  NAMES tcmalloc
)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(Gperftools DEFAULT_MSG
  GPERFTOOLS_LIBRARIES GPERFTOOLS_INCLUDE_DIR)

mark_as_advanced(GPERFTOOLS_INCLUDE_DIR GPERFTOOLS_LIBRARIES)
