message(STATUS "PATH=$ENV{PATH}")
set(MY_VAR "hello world" CACHE STRING "This is my variable")
message(The value of MY_VAR is: ${MY_VAR})