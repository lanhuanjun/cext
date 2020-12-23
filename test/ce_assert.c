/*************************************************************
 * @author huanjun lan
 * @date 2020/12/22
 * @brief
 * @history

************************************************************/

#include "ce_test.h"
#include <stdio.h>
#include <string.h>

void ca_assert_eq_uint32(uint32_t a, uint32_t b, const char* success, const char* fail)
{
    if (a == b) {
        printf("%s\n", success);
    } else {
        printf("%s\n", fail);
    }
}

void ca_assert_eq_char(const char* a, const char* b, const char* success, const char* fail)
{
    if (strcmp(a, b) == 0) {
        printf("%s\n", success);
    } else {
        printf("%s\n", fail);
    }
}