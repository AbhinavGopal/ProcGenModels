cmake_minimum_required(VERSION 3.13)
project(CursesWrapperTester LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 14)

find_package(Threads REQUIRED) #needed to build google test
include(FetchContent) #so we can pull in google test
FetchContent_Declare( #declare information about google test
        googletest #its variable name
        #its location on the internet
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG master #what branch we want
        )

#download google test
FetchContent_GetProperties(googletest)
if (NOT googletest_POPULATED)
    FetchContent_Populate(googletest)
endif ()
add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})


add_executable(CursesWrapperTester
        main.cpp tests.cpp tests.h CursesWrapperTest.cpp CursesWrapperTest.h)
target_compile_options(CursesWrapperTester PRIVATE -Wall -Werror)

add_subdirectory(CursesWrapper)
target_link_libraries(CursesWrapperTester PRIVATE
        CursesWrapper
        gtest)

if (${USE_REAL_CURSES})
else ()
    #use fake curses for testing
    #bring in the sources
    add_subdirectory(FakeCurses)
    target_link_libraries(CursesWrapperTester PRIVATE FakeCurses)
endif ()
