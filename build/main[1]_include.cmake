if(EXISTS "D:/Projects/vscode/cpp_daily_practice/build/main[1]_tests.cmake")
  include("D:/Projects/vscode/cpp_daily_practice/build/main[1]_tests.cmake")
else()
  add_test(main_NOT_BUILT main_NOT_BUILT)
endif()