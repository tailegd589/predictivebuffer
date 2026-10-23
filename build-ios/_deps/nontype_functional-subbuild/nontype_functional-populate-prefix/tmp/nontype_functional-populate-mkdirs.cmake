# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file LICENSE.rst or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION ${CMAKE_VERSION}) # this file comes with cmake

# If CMAKE_DISABLE_SOURCE_CHANGES is set to true and the source directory is an
# existing directory in our source tree, calling file(MAKE_DIRECTORY) on it
# would cause a fatal error, even though it would be a no-op.
if(NOT EXISTS "/data/data/com.termux/files/home/predictivebuffer/build/build-ios/_deps/nontype_functional-src")
  file(MAKE_DIRECTORY "/data/data/com.termux/files/home/predictivebuffer/build/build-ios/_deps/nontype_functional-src")
endif()
file(MAKE_DIRECTORY
  "/data/data/com.termux/files/home/predictivebuffer/build/build-ios/_deps/nontype_functional-build"
  "/data/data/com.termux/files/home/predictivebuffer/build/build-ios/_deps/nontype_functional-subbuild/nontype_functional-populate-prefix"
  "/data/data/com.termux/files/home/predictivebuffer/build/build-ios/_deps/nontype_functional-subbuild/nontype_functional-populate-prefix/tmp"
  "/data/data/com.termux/files/home/predictivebuffer/build/build-ios/_deps/nontype_functional-subbuild/nontype_functional-populate-prefix/src/nontype_functional-populate-stamp"
  "/data/data/com.termux/files/home/predictivebuffer/build/build-ios/_deps/nontype_functional-subbuild/nontype_functional-populate-prefix/src"
  "/data/data/com.termux/files/home/predictivebuffer/build/build-ios/_deps/nontype_functional-subbuild/nontype_functional-populate-prefix/src/nontype_functional-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/data/data/com.termux/files/home/predictivebuffer/build/build-ios/_deps/nontype_functional-subbuild/nontype_functional-populate-prefix/src/nontype_functional-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/data/data/com.termux/files/home/predictivebuffer/build/build-ios/_deps/nontype_functional-subbuild/nontype_functional-populate-prefix/src/nontype_functional-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
