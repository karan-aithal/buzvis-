# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/media/karan/New Volume/8Python/BUZVIS++/buzvis-/_deps/fmt-src"
  "/media/karan/New Volume/8Python/BUZVIS++/buzvis-/_deps/fmt-build"
  "/media/karan/New Volume/8Python/BUZVIS++/buzvis-/_deps/fmt-subbuild/fmt-populate-prefix"
  "/media/karan/New Volume/8Python/BUZVIS++/buzvis-/_deps/fmt-subbuild/fmt-populate-prefix/tmp"
  "/media/karan/New Volume/8Python/BUZVIS++/buzvis-/_deps/fmt-subbuild/fmt-populate-prefix/src/fmt-populate-stamp"
  "/media/karan/New Volume/8Python/BUZVIS++/buzvis-/_deps/fmt-subbuild/fmt-populate-prefix/src"
  "/media/karan/New Volume/8Python/BUZVIS++/buzvis-/_deps/fmt-subbuild/fmt-populate-prefix/src/fmt-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/media/karan/New Volume/8Python/BUZVIS++/buzvis-/_deps/fmt-subbuild/fmt-populate-prefix/src/fmt-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/media/karan/New Volume/8Python/BUZVIS++/buzvis-/_deps/fmt-subbuild/fmt-populate-prefix/src/fmt-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
