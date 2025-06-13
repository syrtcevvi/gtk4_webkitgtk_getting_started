cmake_minimum_required(VERSION 3.19)
# I experience some troubles getting clang++ 14 to work with CMake on Ubuntu 22.04
# Btw, we don't need C++ here, so here I precisely specify the only used language: C
project(gtk4_webkitgtk_getting_started C)

set(CMAKE_C_STANDARD 23)

FIND_PACKAGE(PkgConfig REQUIRED)
pkg_check_modules(ADWAITA REQUIRED libadwaita-1)
pkg_check_modules(WEBKITGTK REQUIRED webkitgtk-6.0)

INCLUDE_DIRECTORIES(${ADWAITA_INCLUDE_DIRS} ${WEBKITGTK_INCLUDE_DIRS})
LINK_DIRECTORIES(${ADWAITA_LIBRARY_DIRS} ${WEBKITGTK_LIBRARY_DIRS})

ADD_DEFINITIONS(${ADWAITA_CFLAGS_OTHER})

set(SOURCES_DIR "src")
set(SOURCES ${SOURCES_DIR}/main.c)

add_executable(gtk4_webkitgtk_getting_started ${SOURCES})
target_link_libraries(gtk4_webkitgtk_getting_started ${ADWAITA_LIBRARIES} ${WEBKITGTK_LIBRARIES})
