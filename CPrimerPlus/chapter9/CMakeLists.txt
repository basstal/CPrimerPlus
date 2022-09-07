cmake_minimum_required(VERSION 3.10)

project(chapter9)

file( GLOB APP_SOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.c )
message(STATUS ${APP_SOURCES})
foreach( SOURCEFILE ${APP_SOURCES} )
    # I used a simple string replace, to cut off .cpp.
    string( REPLACE ".c" "" EXERCISE_NAME ${SOURCEFILE} )
    message(STATUS "EXERCISE_NAME : " ${EXERCISE_NAME})
    add_executable( "C09_${EXERCISE_NAME}" ${SOURCEFILE} )
    # # Make sure YourLib is linked to each app
    # target_link_libraries( ${EXERCISE_NAME} YourLib )
endforeach( SOURCEFILE ${APP_SOURCES} )