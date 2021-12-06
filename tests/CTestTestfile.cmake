# CMake generated Testfile for 
# Source directory: C:/Users/might/projects/orionengine2.0/OrionEngine2.0/tests
# Build directory: C:/Users/might/projects/orionengine2.0/tests
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
if("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test(orion_tst "C:/Users/might/projects/orionengine2.0/tests/bin/Debug/orion_tst.exe")
  set_tests_properties(orion_tst PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/might/projects/orionengine2.0/OrionEngine2.0/tests/CMakeLists.txt;11;add_test;C:/Users/might/projects/orionengine2.0/OrionEngine2.0/tests/CMakeLists.txt;0;")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test(orion_tst "C:/Users/might/projects/orionengine2.0/tests/bin/Release/orion_tst.exe")
  set_tests_properties(orion_tst PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/might/projects/orionengine2.0/OrionEngine2.0/tests/CMakeLists.txt;11;add_test;C:/Users/might/projects/orionengine2.0/OrionEngine2.0/tests/CMakeLists.txt;0;")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
  add_test(orion_tst "C:/Users/might/projects/orionengine2.0/tests/bin/MinSizeRel/orion_tst.exe")
  set_tests_properties(orion_tst PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/might/projects/orionengine2.0/OrionEngine2.0/tests/CMakeLists.txt;11;add_test;C:/Users/might/projects/orionengine2.0/OrionEngine2.0/tests/CMakeLists.txt;0;")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
  add_test(orion_tst "C:/Users/might/projects/orionengine2.0/tests/bin/RelWithDebInfo/orion_tst.exe")
  set_tests_properties(orion_tst PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/might/projects/orionengine2.0/OrionEngine2.0/tests/CMakeLists.txt;11;add_test;C:/Users/might/projects/orionengine2.0/OrionEngine2.0/tests/CMakeLists.txt;0;")
else()
  add_test(orion_tst NOT_AVAILABLE)
endif()
