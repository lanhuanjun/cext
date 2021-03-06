/*************************************************************
 * @author lanyeo
 * @date 2020/12/22
 * @brief
 * @history

************************************************************/

#ifndef CEXT_CA_TEST_H
#define CEXT_CA_TEST_H

#include <stdint.h>

void ce_string_test();

void ca_assert_eq_uint32(uint32_t a, uint32_t b, const char* success, const char* fail);

void ca_assert_eq_char(const char* a, const char* b, const char* success, const char* fail);

#endif //CEXT_CA_TEST_H
