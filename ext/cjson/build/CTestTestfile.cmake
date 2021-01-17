# CMake generated Testfile for 
# Source directory: /home/escapechar/saturn/ext/cjson
# Build directory: /home/escapechar/saturn/ext/cjson/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(cJSON_test "/home/escapechar/saturn/ext/cjson/build/cJSON_test")
set_tests_properties(cJSON_test PROPERTIES  _BACKTRACE_TRIPLES "/home/escapechar/saturn/ext/cjson/CMakeLists.txt;240;add_test;/home/escapechar/saturn/ext/cjson/CMakeLists.txt;0;")
subdirs("tests")
subdirs("fuzzing")
