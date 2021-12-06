set(BINARY ${CMAKE_PROJECT_NAME}_tst)
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd")

include_directories(../sdlInclude/include ../include)

SET(SOURCES src/main.cpp src/Formula-test.cpp src/sample1_unittest.cpp src/rapidTest.cpp "src/CollisionMapTest.cpp" "src/SystemTests.cpp")

add_executable(${BINARY} ${SOURCES})

add_test(NAME ${BINARY} COMMAND ${BINARY})

target_link_libraries(${BINARY} PUBLIC ${CMAKE_PROJECT_NAME}_lib gtest rapidcheck_gtest SDL2 SDL2main SDL2_image SDL2.dll SDL2_image.dll)

