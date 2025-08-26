cmake_minimum_required(VERSION 3.20.0)

project(Jzero)

if(CMAKE_HOST_SYSTEM_NAME STREQUAL "Windows")
  set(FLEX_EXECUTABLE "D:/opt/win_flex_bison-2.5.25/win_flex.exe" CACHE PATH "Path to the custom Flex executable")
  set(BISON_EXECUTABLE "D:/opt/win_flex_bison-2.5.25/win_bison.exe" CACHE PATH "Path to the custom Bison executable")
endif()
find_package(FLEX REQUIRED)
find_package(BISON REQUIRED)
flex_target(scanner javalex.l "${CMAKE_CURRENT_SOURCE_DIR}/javalex.lex.cc")
bison_target(parser j0gram.y "${CMAKE_CURRENT_SOURCE_DIR}/j0gram.tab.cc" DEFINES_FILE "${CMAKE_CURRENT_SOURCE_DIR}/j0gram.tab.h" COMPILE_FLAGS --debug)
add_flex_bison_dependency(scanner parser)

# add_library(util STATIC ../util/util.c)
# target_include_directories(util PUBLIC ../util)

add_executable (j0
  ${FLEX_scanner_OUTPUTS}
  ${BISON_parser_OUTPUTS}
  x64.cc
  byc.cc
  serial.cc
  tac.cc
  typeinfo.cc
  tree.cc
  symtab.cc
  j0.cc
  )

# target_link_libraries(j0 PUBLIC util)

add_executable (j0x
  j0machine.cc
  j0x.cc
  )

# target_link_libraries(j0x PUBLIC util)

if(YY_NO_UNISTD_H)
  # target_compile_definitions(util PUBLIC YY_NO_UNISTD_H)
  target_compile_definitions(j0 PUBLIC YY_NO_UNISTD_H)
endif()
