set(CMAKE_C_STANDARD 11)

SET(SOURCE_FILES ce_test.h
        ce_string_test.c
        ce_test.c
        ce_assert.c)


add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} cext)