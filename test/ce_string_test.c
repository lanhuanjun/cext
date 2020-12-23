/*************************************************************
 * @author lanyeo
 * @date 2020/12/22
 * @brief
 * @history

************************************************************/

#include "ce_test.h"
#include "../src/ce_string.h"

#include <stdlib.h>

void ce_string_test()
{
    printf("start test string-------------------------\n");
    CESTRING_S * pCeString = CreateCEString(NULL);
    ca_assert_eq_uint32(pCeString->buf_len, 32, "pass!", "fail");
    ca_assert_eq_char(CEString2Char(pCeString), "", "pass!", "fail");
    free(pCeString);
    pCeString = CreateCEString("");
    ca_assert_eq_uint32(pCeString->buf_len, 32, "pass!", "fail");
    ca_assert_eq_char(CEString2Char(pCeString), "", "pass!", "fail");
    free(pCeString);
    pCeString = CreateCEString("12345678");
    ca_assert_eq_uint32(pCeString->buf_len, 32, "pass!", "fail");
    ca_assert_eq_char(CEString2Char(pCeString), "12345678", "pass!", "fail");
    free(pCeString);
    pCeString = CreateCEString("1234567812345678123456781234567");
    ca_assert_eq_uint32(pCeString->buf_len, 32, "pass!", "fail");
    ca_assert_eq_char(CEString2Char(pCeString), "1234567812345678123456781234567", "pass!", "fail");
    free(pCeString);
    pCeString = CreateCEString("12345678123456781234567812345678");
    ca_assert_eq_uint32(pCeString->buf_len, 64, "pass!", "fail");
    ca_assert_eq_char(CEString2Char(pCeString), "12345678123456781234567812345678", "pass!", "fail");
    free(pCeString);

    pCeString = CreateCEStringLen("12345", 2);
    ca_assert_eq_char(CEString2Char(pCeString), "12", "pass!", "fail");
    free(pCeString);
    pCeString = CreateCEStringLen("12345", 6);
    ca_assert_eq_char(CEString2Char(pCeString), "12345", "pass!", "fail");
    free(pCeString);
    pCeString = CreateCEStringLen("12345", 0);
    ca_assert_eq_char(CEString2Char(pCeString), "", "pass!", "fail");
    free(pCeString);
    printf("finish test string-------------------------\n");
}