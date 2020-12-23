SET(LIB_NAME cext)
SET(SOURCE_FILES ce_string.h ce_string.c)


IF (WIN32)
    add_library(${LIB_NAME} STATIC ${SOURCE_FILES})
ELSEIF (APPLE)
    add_library(${LIB_NAME} SHARED ${SOURCE_FILES})
ELSEIF (UNIX)
    add_library(${LIB_NAME} STATIC ${SOURCE_FILES})
ENDIF ()
