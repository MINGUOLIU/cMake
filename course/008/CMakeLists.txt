cmake_minimum_required(VERSION 3.26)

project(test)

set(test  ON)   #set  普通变量   
message(STATUS "test1=${test}")
option(test "test2" OFF )   #option缓存变量，不会覆盖set变量

message(STATUS "test2=${test}")
set(test OFF)
