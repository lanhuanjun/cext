SET(LIB_NAME cext)
SET(SOURCE_FILES ce_string.h ce_string.c)

add_library(${LIB_NAME} SHARED ${SOURCE_FILES})