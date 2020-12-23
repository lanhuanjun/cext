/*************************************************************
 * @author lanyeo
 * @date 2020/12/22
 * @brief
 * @history

************************************************************/

#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "ce_string.h"

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
    CESTRING_S* pCeString = (CESTRING_S*)malloc(sizeof(CESTRING_S) + allocSize * sizeof(char));
    memset(pCeString, 0, sizeof(CESTRING_S) + allocSize * sizeof(char));
    pCeString->buf_len = allocSize;
    return pCeString;
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
    len = len > strLen ? strLen : len;
    CESTRING_S* pCeString = AllocCAString(len);
    pCeString->len = len;
    memcpy(pCeString->data, str, sizeof(char) * len);
    return pCeString;
}

const char* CEString2Char(const CESTRING_S* pCeString)
{
    return (const char*)pCeString->data;
}