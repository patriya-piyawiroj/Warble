file(REMOVE_RECURSE
  "func_server.pdb"
  "func_server"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/func_server.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
