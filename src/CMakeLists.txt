cmake_minimum_required(VERSION 3.5.1)

include(GNUInstallDirs)

add_library(${PROJECT_NAME}
  STATIC
    vector.cpp
    matrix.cpp
)

set_target_properties(${PROJECT_NAME} PROPERTIES VERSION ${PROJECT_VERSION})

target_include_directories(${PROJECT_NAME}
 PUBLIC
  include
)

install(TARGETS ${PROJECT_NAME}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})