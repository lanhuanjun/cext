/*************************************************************
 * @author lanyeo
 * @date 2020/12/22
 * @brief
 * @history

************************************************************/

#ifndef CALGLIB_CA_STRING_H
#define CALGLIB_CA_STRING_H

#include <stdio.h>

typedef struct tagCAString {
    u_int32_t len;
    u_int32_t buf_len;
    char data[0];
} CASTRING_S;

/// 通过已有的c-style字符串构造castring。
/// \param str 请确保该字符串已\0结尾。
/// \return 申请的返回的指针将永远不为空，除非因设备内存不足，您需要手动释放(free)该内存。
CASTRING_S* CreateCAString(const char* str);

const char* CAString2Char(const CASTRING_S* pCaString);

#endif //CALGLIB_CA_STRING_H
