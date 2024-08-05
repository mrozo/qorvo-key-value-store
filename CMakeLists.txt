cmake_minimum_required(VERSION 3.28)
project(
  mrozSdk
  VERSION 0.0.1
  DESCRIPTION "An sdk containing a key value storage for nvm memory.")
add_subdirectory(nvmSim/)
add_subdirectory(keyValueNvm/)
add_subdirectory(testHelper/)
add_subdirectory(interfaces/)
add_subdirectory(ext/)
