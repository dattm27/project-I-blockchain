# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

if(EXISTS "/Users/dattran/project-vanet-blockchain/iroha/external/src/reactive_extensions_rxcpp-stamp/reactive_extensions_rxcpp-gitclone-lastrun.txt" AND EXISTS "/Users/dattran/project-vanet-blockchain/iroha/external/src/reactive_extensions_rxcpp-stamp/reactive_extensions_rxcpp-gitinfo.txt" AND
  "/Users/dattran/project-vanet-blockchain/iroha/external/src/reactive_extensions_rxcpp-stamp/reactive_extensions_rxcpp-gitclone-lastrun.txt" IS_NEWER_THAN "/Users/dattran/project-vanet-blockchain/iroha/external/src/reactive_extensions_rxcpp-stamp/reactive_extensions_rxcpp-gitinfo.txt")
  message(STATUS
    "Avoiding repeated git clone, stamp file is up to date: "
    "'/Users/dattran/project-vanet-blockchain/iroha/external/src/reactive_extensions_rxcpp-stamp/reactive_extensions_rxcpp-gitclone-lastrun.txt'"
  )
  return()
endif()

execute_process(
  COMMAND ${CMAKE_COMMAND} -E rm -rf "/Users/dattran/project-vanet-blockchain/iroha/external/src/reactive_extensions_rxcpp"
  RESULT_VARIABLE error_code
)
if(error_code)
  message(FATAL_ERROR "Failed to remove directory: '/Users/dattran/project-vanet-blockchain/iroha/external/src/reactive_extensions_rxcpp'")
endif()

# try the clone 3 times in case there is an odd git clone issue
set(error_code 1)
set(number_of_tries 0)
while(error_code AND number_of_tries LESS 3)
  execute_process(
    COMMAND "/usr/local/bin/git"
            clone --no-checkout --config "advice.detachedHead=false" "https://github.com/Reactive-Extensions/rxcpp.git" "reactive_extensions_rxcpp"
    WORKING_DIRECTORY "/Users/dattran/project-vanet-blockchain/iroha/external/src"
    RESULT_VARIABLE error_code
  )
  math(EXPR number_of_tries "${number_of_tries} + 1")
endwhile()
if(number_of_tries GREATER 1)
  message(STATUS "Had to git clone more than once: ${number_of_tries} times.")
endif()
if(error_code)
  message(FATAL_ERROR "Failed to clone repository: 'https://github.com/Reactive-Extensions/rxcpp.git'")
endif()

execute_process(
  COMMAND "/usr/local/bin/git"
          checkout "f38fb8e3c30b01b07c57e08039b2942f1685224d" --
  WORKING_DIRECTORY "/Users/dattran/project-vanet-blockchain/iroha/external/src/reactive_extensions_rxcpp"
  RESULT_VARIABLE error_code
)
if(error_code)
  message(FATAL_ERROR "Failed to checkout tag: 'f38fb8e3c30b01b07c57e08039b2942f1685224d'")
endif()

set(init_submodules TRUE)
if(init_submodules)
  execute_process(
    COMMAND "/usr/local/bin/git" 
            submodule update --recursive --init 
    WORKING_DIRECTORY "/Users/dattran/project-vanet-blockchain/iroha/external/src/reactive_extensions_rxcpp"
    RESULT_VARIABLE error_code
  )
endif()
if(error_code)
  message(FATAL_ERROR "Failed to update submodules in: '/Users/dattran/project-vanet-blockchain/iroha/external/src/reactive_extensions_rxcpp'")
endif()

# Complete success, update the script-last-run stamp file:
#
execute_process(
  COMMAND ${CMAKE_COMMAND} -E copy "/Users/dattran/project-vanet-blockchain/iroha/external/src/reactive_extensions_rxcpp-stamp/reactive_extensions_rxcpp-gitinfo.txt" "/Users/dattran/project-vanet-blockchain/iroha/external/src/reactive_extensions_rxcpp-stamp/reactive_extensions_rxcpp-gitclone-lastrun.txt"
  RESULT_VARIABLE error_code
)
if(error_code)
  message(FATAL_ERROR "Failed to copy script-last-run stamp file: '/Users/dattran/project-vanet-blockchain/iroha/external/src/reactive_extensions_rxcpp-stamp/reactive_extensions_rxcpp-gitclone-lastrun.txt'")
endif()
