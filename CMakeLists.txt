# CMakeList.txt: projekt CMake dla elementu baza_new, dołącz źródło i zdefiniuj
# tutaj logikę specyficzną dla projektu.
#
cmake_minimum_required (VERSION 3.8)

project ("baza_new")

# Dodaj źródło do pliku wykonywalnego tego projektu.
add_executable (baza_new "baza_new.cpp" "baza_new.h" "randomgen.h"  "pojazdy.hpp" "data.hpp")

# TODO: Dodaj testy i zainstaluj elementy docelowe w razie potrzeby.
