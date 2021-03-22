/*************************************************************
 * @author lanyeo
 * @date 2020/12/22
 * @brief
 * @history

************************************************************/

#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "ce_string.h"

typedef struct tagCEString {
    uint32_t len;
    uint32_t buf_len;
    char data[0];
} CESTRING;

#define CONVERT_TO_CESTRING(p) ((CESTRING*)p)
const uint32_t kAllocSize[] = {32, 64, 128, 256, 512, 1024, 2048, 4096, 8192};

CESTRING_S* AllocCAString(size_t size)
{
    size_t allocSize = size + 1;
    for (int i = 0; i < sizeof(kAllocSize) / sizeof(uint32_t); ++i) {
        if (size < kAllocSize[i]) {
            allocSize = kAllocSize[i];
            break;
        }
    }
    CESTRING* pCeString = (CESTRING*)malloc(sizeof(CESTRING) + allocSize * sizeof(char));
    memset(pCeString, 0, sizeof(CESTRING_S) + allocSize * sizeof(char));
    pCeString->buf_len = allocSize;
    return (CESTRING_S)pCeString;
}

CESTRING_S* CreateCEString(const char* str)
{
    return CreateCEStringLen(str, UINT32_MAX);
}

CESTRING_S* CreateCEStringLen(const char* str, size_t len)
{
    size_t strLen = 0;
    if (str != NULL) {
        strLen = strlen(str);
    }
    if (strLen < len) {
        len = strLen;
    }
    CESTRING* pCeString = (CESTRING*)AllocCAString(len);
    pCeString->len = len;
    memcpy(pCeString->data, str, sizeof(char) * len);
    return (CESTRING_S)pCeString;
}

const char* CEString2Char(const CESTRING_S* pCeString)
{
    return (const char*)CONVERT_TO_CESTRING(pCeString)->data;
}

size_t CEStringLen(const CESTRING_S *pCeString)
{
    return pCeString == NULL ? 0 : ((CESTRING*)pCeString)->len;
}

int CEStringCmp(const CESTRING_S *pCEStrA, const CESTRING_S *pCEStrB)
{
    if (pCEStrA == NULL && pCEStrB == NULL) {
        return 0;
    }
    if (pCEStrA == NULL) {
        return CONVERT_TO_CESTRING(pCEStrB)->len == 0 ? 0 : CONVERT_TO_CESTRING(pCEStrB)->data[0];
    }
    if (pCEStrB == NULL) {
        return CONVERT_TO_CESTRING(pCEStrA)->len == 0 ? 0 : 0 - CONVERT_TO_CESTRING(pCEStrA)->data[0];
    }
    return strcmp(CONVERT_TO_CESTRING(pCEStrA)->data, CONVERT_TO_CESTRING(pCEStrB)->data);
}

int32_t CEString2Int32(const CESTRING_S *pCeStr, int *result)
{
    if (pCeStr == NULL) {
        if (result != NULL) {
            *result = CESTRING_CODE_IS_NULL;
        }
        return 0;
    }
    long int ret = strtoll(CEString2Char(pCeStr), NULL, 10);
    if (result != NULL) {
        if (errno == 0) {
            *result = CESTRING_CODE_OK;
        } else {
            *result = errno != ERANGE ? CESTRING_CODE_INVALID : CESTRING_CODE_OVERFLOW;
        }
    }
    return ret;
}

int64_t CEString2Int64(const CESTRING_S *pCeStr, int *result)
{
    if (pCeStr == NULL) {
        if (result != NULL) {
            *result = CESTRING_CODE_IS_NULL;
        }
        return 0;
    }
    long long ret = strtoll(CEString2Char(pCeStr), NULL, 10);
    if (result != NULL) {
        if (errno == 0) {
            *result = CESTRING_CODE_OK;
        } else {
            *result = errno != ERANGE ? CESTRING_CODE_INVALID : CESTRING_CODE_OVERFLOW;
        }
    }
    return ret;
}

long double CEString2LongDouble(const CESTRING_S *pCeStr, int *result)
{

    if (pCeStr == NULL) {
        if (result != NULL) {
            *result = CESTRING_CODE_IS_NULL;
        }
        return 0;
    }
    long double ret = strtold(CEString2Char(pCeStr), NULL);
    if (result != NULL) {
        if (errno == 0) {
            *result = CESTRING_CODE_OK;
        } else {
            *result = errno != ERANGE ? CESTRING_CODE_INVALID : CESTRING_CODE_OVERFLOW;
        }
    }
    return ret;
}

CESTRING_S *CEStringCpy(CESTRING_S *pDest, const CESTRING_S *pSrc)
{
    if (pSrc == NULL) {
        return pDest;
    }
    return CEStringAppend(pDest, CEString2Char(pSrc));
}

CESTRING_S *CEStringNCpy(CESTRING_S *pDest, const CESTRING_S *pSrc, size_t n)
{
    if (pSrc == NULL) {
        return pDest;
    }
    return CEStringNAppend(pDest, CEString2Char(pSrc), n);
}

CESTRING_S *CEStringAppend(CESTRING_S *pDest, const char *str)
{
    return CEStringNAppend(pDest, str, UINT32_MAX);
}

CESTRING_S *CEStringNAppend(CESTRING_S *pDest, const char *str, size_t n)
{
    if (str == NULL) {
        return pDest;
    }
    if (pDest == NULL) {
        return CreateCEStringLen(str, n);
    }
    size_t len = strlen(str);
    if (n < len) {
        len = n;
    }
    CESTRING* p = CONVERT_TO_CESTRING(pDest);
    CESTRING* pA = CONVERT_TO_CESTRING(pDest);
    if (len > pA->buf_len - pA->len) {
        p = (CESTRING*)AllocCAString(pA->len + len);
        memcpy(p->data, pA->data, pA->len * sizeof(char));
        p->len = pA->len;
    }
    memcpy(p->data + p->len, str, len * sizeof(char));
    return (CESTRING_S*)p;
}

void CEStringClear(CESTRING_S *pSrc)
{
    if (pSrc == NULL) {
        return ;
    }
    CESTRING* p = CONVERT_TO_CESTRING(pSrc);
    memset(p->data, 0, sizeof(char) * p->buf_len);
}

int32_t CEStringFindFirst(const CESTRING_S *str, char ch) {
    if (str == NULL) {
        return -1;
    }
    CESTRING* p = CONVERT_TO_CESTRING(str);
    for (int32_t i = 0; i < p->len; ++i) {
        if (ch == p->data[i]) {
            return i;
        }
    }
    return -1;
}

int32_t CEStringFindLast(const CESTRING_S *str, char ch) {
    if (str == NULL) {
        return -1;
    }
    CESTRING* p = CONVERT_TO_CESTRING(str);
    for (int32_t i = p->len - 1; i >= 0; --i) {
        if (ch == p->data[i]) {
            return i;
        }
    }
    return -1;
}

int32_t CEStringFindFirstStr(const CESTRING_S *str, const char *target) {
    if (str == NULL || target == NULL) {
        return -1;
    }
    CESTRING* p = CONVERT_TO_CESTRING(str);
    char* t = strstr(p->data, target);
    if (t == NULL) {
        return -1;
    }
    return (uint32_t)(t - p->data) / sizeof(char);
}

char *CEStringIndex(const CESTRING_S *str, uint32_t index) {
    if (str == NULL) {
        return  NULL;
    }
    CESTRING* p = CONVERT_TO_CESTRING(str);
    if (p->len < index) {
        return NULL;
    }
    return &(p->data[index]);
}
