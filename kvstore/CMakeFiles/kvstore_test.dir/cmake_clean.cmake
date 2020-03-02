file(REMOVE_RECURSE
  "kvstore_test.pdb"
  "kvstore_test"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/kvstore_test.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
