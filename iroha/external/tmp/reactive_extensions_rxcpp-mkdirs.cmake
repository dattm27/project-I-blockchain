# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/Users/dattran/project-vanet-blockchain/iroha/external/src/reactive_extensions_rxcpp"
  "/Users/dattran/project-vanet-blockchain/iroha/external/src/reactive_extensions_rxcpp-build"
  "/Users/dattran/project-vanet-blockchain/iroha/external"
  "/Users/dattran/project-vanet-blockchain/iroha/external/tmp"
  "/Users/dattran/project-vanet-blockchain/iroha/external/src/reactive_extensions_rxcpp-stamp"
  "/Users/dattran/project-vanet-blockchain/iroha/external/src"
  "/Users/dattran/project-vanet-blockchain/iroha/external/src/reactive_extensions_rxcpp-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/Users/dattran/project-vanet-blockchain/iroha/external/src/reactive_extensions_rxcpp-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/Users/dattran/project-vanet-blockchain/iroha/external/src/reactive_extensions_rxcpp-stamp${cfgdir}") # cfgdir has leading slash
endif()
