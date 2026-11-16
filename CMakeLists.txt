# Configuration de CMake pour TP C++ Moderne esimed
cmake_minimum_required(VERSION 3.29)

# Nom du projet et de l'exécutable généré
project(exemples_cours_cpp)

# Forcer l'utilisation de C++ 23
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# Tout doit être parfait
set(CMAKE_COMPILE_WARNING_AS_ERROR ON)
# Ne pas utiliser les extensions de CMake
set(CMAKE_CXX_EXTENSIONS OFF)

# Répertoire contenant les sources des exercices
set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
# Répertoire contenant les sources des tests unitaires
set(TESTS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/tests)

# Pour "import std"
include(cmake/std.cmake)
include(cmake/compile_options.cmake)

#######################################################
# Liste des fichiers sources des modules des exercices
file(GLOB PROJECT_FILES CONFIGURE_DEPENDS "${SRC_DIR}/*.ixx")
# Liste des fichiers sources des tests unitaires
file(GLOB TEST_FILES CONFIGURE_DEPENDS "${TESTS_DIR}/*.cpp")
# Liste des fichiers d'implémentation des modules
file(GLOB PROJECT_IMPLEMENTATION_FILES CONFIGURE_DEPENDS "${SRC_DIR}/*.cpp")
list(REMOVE_ITEM PROJECT_IMPLEMENTATION_FILES "${SRC_DIR}/main.cpp")
# Exécutable principal
add_executable(${PROJECT_NAME}
        ${SRC_DIR}/main.cpp
        ${PROJECT_IMPLEMENTATION_FILES}
)

#######################################################

# Pour les tests unitaires
include(cmake/catch2.cmake)

target_sources(${PROJECT_NAME}
        PUBLIC
        FILE_SET CXX_MODULES
        FILES
        ${PROJECT_FILES}
)
compile_options(${PROJECT_NAME})

# Exécutable pour les tests unitaires
add_executable(tests ${TEST_FILES} ${PROJECT_IMPLEMENTATION_FILES})
target_sources(tests
        PUBLIC
        FILE_SET CXX_MODULES
        FILES
        ${PROJECT_FILES}
)
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain std-cxx-modules)

# Configuration automatique pour CTest
include(CTest)
include(Catch)
catch_discover_tests(tests)
