include(soci_define_backend_target)

if (SOCI_EMPTY_AUTO)
  set(DEPENDENCY_MODE "DISABLE")
else()
  set(DEPENDENCY_MODE "ERROR")
endif()

soci_define_backend_target(
  BACKEND_NAME "Empty"
  TARGET_NAME "soci_empty"
  ALIAS_NAME "Empty"
  REQUIRED_COMPONENTS SOCI::Core
  SOURCE_FILES
    "blob.cpp"
    "factory.cpp"
    "row-id.cpp"
    "session.cpp"
    "standard-into-type.cpp"
    "standard-use-type.cpp"
    "statement.cpp"
    "vector-into-type.cpp"
    "vector-use-type.cpp"
  MISSING_DEPENDENCY_BEHAVIOR "${DEPENDENCY_MODE}"
  ENABLED_VARIABLE "SOCI_EMPTY"
)

if (NOT SOCI_EMPTY)
  return()
endif()
