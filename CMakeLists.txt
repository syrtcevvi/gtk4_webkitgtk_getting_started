cmake_minimum_required(VERSION 3.19)
project(gtk4_webkitgtk_getting_started)

set(CMAKE_C_STANDARD 23)

FIND_PACKAGE(PkgConfig REQUIRED)
pkg_check_modules(GTK4 REQUIRED gtk4)
pkg_check_modules(WEBKITGTK REQUIRED webkitgtk-6.0)

INCLUDE_DIRECTORIES(${GTK4_INCLUDE_DIRS} ${WEBKITGTK_INCLUDE_DIRS})
LINK_DIRECTORIES(${GTK4_LIBRARY_DIRS} ${WEBKITGTK_LIBRARY_DIRS})

ADD_DEFINITIONS(${GTK4_CFLAGS_OTHER})

set(SOURCES_DIR "src")
set(SOURCES ${SOURCES_DIR}/main.c)

add_executable(gtk4_webkitgtk_getting_started ${SOURCES})
target_link_libraries(gtk4_webkitgtk_getting_started ${GTK4_LIBRARIES} ${WEBKITGTK_LIBRARIES})
