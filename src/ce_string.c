/*************************************************************
 * @author huanjun lan
 * @date 2020/12/22
 * @brief
 * @history

************************************************************/

#include <stdlib.h>
#include <string.h>

#include "ce_string.h"

const u_int32_t kAllocSize[] = {32, 64, 128, 256, 512, 1024, 2048, 4096, 8192};

CASTRING_S* AllocCAString(size_t size)
{
    size_t allocSize = size + 1;
    for (int i = 0; i < sizeof(kAllocSize) / sizeof(u_int32_t); ++i) {
        if (size < kAllocSize[i]) {
            allocSize = kAllocSize[i];
            break;
        }
    }
    CASTRING_S* pCaString = (CASTRING_S*)malloc(sizeof(CASTRING_S) + allocSize * sizeof(char));
    memset(pCaString, 0, sizeof(CASTRING_S) + allocSize * sizeof(char));
    pCaString->buf_len = allocSize;
    return pCaString;
}

CASTRING_S* CreateCAString(const char* str)
{
    size_t len = 0;
    if (str != NULL) {
        len = strlen(str);
    }
    CASTRING_S* pCaString = AllocCAString(len);
    pCaString->len = len;
    memcpy(pCaString->data, str, sizeof(char) * len);
    return pCaString;
}


const char* CAString2Char(const CASTRING_S* pCaString)
{
    return (const char*)pCaString->data;
}