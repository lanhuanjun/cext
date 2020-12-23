/*************************************************************
 * @author lanyeo
 * @date 2020/12/22
 * @brief c字符串的封装
 * @history

************************************************************/

#ifndef CEXT_CA_STRING_H
#define CEXT_CA_STRING_H

#include <stdio.h>

typedef struct tagCEString {
    uint32_t len;
    uint32_t buf_len;
    char data[0];
} CESTRING_S;

/// 通过已有的c-style字符串构造castring。
/// \param str 请确保该字符串已\0结尾。
/// \return 申请的返回的指针将永远不为空，除非因设备内存不足，您需要手动释放(free)该内存。
CESTRING_S* CreateCEString(const char* str);

/// 通过已有的c-style字符串构造castring。
/// \param str 请确保该字符串已\0结尾。
/// \param len 传入大于str的长度则已str的长度为准，否则使用len的长度。
/// \return 申请的返回的指针将永远不为空，除非因设备内存不足，您需要手动释放(free)该内存。
CESTRING_S* CreateCEStringLen(const char* str, size_t len);

const char* CEString2Char(const CESTRING_S* pCeString);

#endif //CEXT_CA_STRING_H
