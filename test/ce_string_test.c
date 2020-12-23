/*************************************************************
 * @author huanjun lan
 * @date 2020/12/22
 * @brief
 * @history

************************************************************/

#include "ce_test.h"
#include "../src/ce_string.h"

#include <stdlib.h>

void ca_string_test()
{
    CASTRING_S * pCaString = CreateCAString(NULL);
    ca_assert_eq_uint32(pCaString->buf_len, 32, "pass!", "fail");
    ca_assert_eq_char(CAString2Char(pCaString), "", "pass!", "fail");
    free(pCaString);
    pCaString = CreateCAString("");
    ca_assert_eq_uint32(pCaString->buf_len, 32, "pass!", "fail");
    ca_assert_eq_char(CAString2Char(pCaString), "", "pass!", "fail");
    free(pCaString);
    pCaString = CreateCAString("12345678");
    ca_assert_eq_uint32(pCaString->buf_len, 32,"pass!", "fail");
    ca_assert_eq_char(CAString2Char(pCaString), "12345678", "pass!", "fail");
    free(pCaString);
    pCaString = CreateCAString("1234567812345678123456781234567");
    ca_assert_eq_uint32(pCaString->buf_len, 32, "pass!", "fail");
    ca_assert_eq_char(CAString2Char(pCaString), "1234567812345678123456781234567", "pass!", "fail");
    free(pCaString);
    pCaString = CreateCAString("12345678123456781234567812345678");
    ca_assert_eq_uint32(pCaString->buf_len, 64, "pass!", "fail");
    ca_assert_eq_char(CAString2Char(pCaString), "12345678123456781234567812345678", "pass!", "fail");
    free(pCaString);
}