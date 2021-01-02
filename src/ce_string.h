/*************************************************************
 * @author lanyeo
 * @date 2020/12/22
 * @brief c字符串的封装
 * @history

************************************************************/

#ifndef CEXT_CA_STRING_H
#define CEXT_CA_STRING_H

#include <stdio.h>
#include <stdbool.h>

enum CESTRING_CODE
{
    CESTRING_CODE_OK,
    /** 参数为NULL */
    CESTRING_CODE_IS_NULL,
    /** 非法的参数 */
    CESTRING_CODE_INVALID,
    /** 将其转化为对应数值类型溢出情况 */
    CESTRING_CODE_OVERFLOW,
};

typedef struct tagCEString {
    uint32_t len;
    uint32_t buf_len;
    char data[0];
} CESTRING_S;

/// 通过已有的c-style字符串构造cestring。
/// \param str 请确保该字符串已\0结尾，或者为NULL。
/// \return 申请的返回的指针将永远不为空，除非因设备内存不足，您需要手动释放(free)该内存。
CESTRING_S* CreateCEString(const char* str);

/// 通过已有的c-style字符串构造cestring。
/// \param str 请确保该字符串已\0结尾，或者为NULL。
/// \param len 传入大于str的长度则已str的长度为准，否则使用len的长度。
/// \return 申请的返回的指针将永远不为空，除非因设备内存不足，您需要手动释放(free)该内存。
CESTRING_S* CreateCEStringLen(const char* str, size_t len);


/// 将CEString转为普通的c-style字符串，注意返回的不需要释放。
/// \param pCeString 必须使用Create创建的的CEString。
/// \return c-style字符串，注意返回的不需要释放。
const char* CEString2Char(const CESTRING_S* pCeString);

/// 获取字符串长度，NULL将返回0
/// \param pCeString
/// \return
size_t CEStringLen(const CESTRING_S* pCeString);

/// 将pSrc的字符串拷贝到pDest
CESTRING_S* CEStringCpy(CESTRING_S* pDest, const CESTRING_S* pSrc);
CESTRING_S* CEStringNCpy(CESTRING_S* pDest, const CESTRING_S* pSrc, size_t n);
CESTRING_S* CEStringAppend(CESTRING_S* pDest, const char* str);
CESTRING_S* CEStringNAppend(CESTRING_S* pDest, const char* str, size_t n);

/// 比较两个字符串是否相等
/// 1. 两为NULL时返回0
/// 2. pCEStrA为NULL，pCEStrB不为NULL返回值为pCEStrB首个字符大小
/// 3. pCEStrB为NULL，pCEStrA不为NULL返回值为pCEStrA首个字符大小的负数
/// 4. 按照strcmp挨个比较字符串大小
/// \param pCEStrA
/// \param pCEStrB
/// \return
int CEStringCmp(const CESTRING_S* pCEStrA, const CESTRING_S* pCEStrB);

/// 转换为int32，如果超出INT32的数字范围，则返回数值的最大值和最小值，NULL时返回0。
/// \param pCeStr
/// \param result 使用此值判断返回值是否有效，可以为NULL。
/// 1. pCeStr为NULL时，result为CESTRING_CODE_IS_NULL
/// 2. pCeStr超出int32大小时，result为CESTRING_CODE_OVERFLOW
/// 3. pCeStr不能转换成正常int32时，result为CESTRING_CODE_INVALID
/// 4. 其他为OK
/// \return
int32_t CEString2Int32(const CESTRING_S* pCeStr, int* result);

/// 转换为int64，如果超出INT64的数字范围，则返回数值的最大值和最小值，NULL时返回0。
/// \param pCeStr
/// \param result 使用此值判断返回值是否有效，可以为NULL。
/// 1. pCeStr为NULL时，result为CESTRING_CODE_IS_NULL
/// 2. pCeStr超出int64大小时，result为CESTRING_CODE_OVERFLOW
/// 3. pCeStr不能转换成正常int64时，result为CESTRING_CODE_INVALID
/// 4. 其他为OK
/// \return
int64_t CEString2Int64(const CESTRING_S* pCeStr, int* result);

/// 转换为long double，如果超出INT64的数字范围，则返回数值的最大值HUG_VALL和最小值HUG_VALL，NULL时返回0。
/// \param pCeStr
/// \param result 使用此值判断返回值是否有效，可以为NULL。
/// 1. pCeStr为NULL时，result为CESTRING_CODE_IS_NULL
/// 2. pCeStr超出long double大小时，result为CESTRING_CODE_OVERFLOW
/// 3. pCeStr不能转换成正常long double时，result为CESTRING_CODE_INVALID
/// 4. 其他为OK
/// \return
long double CEString2LongDouble(const CESTRING_S* pCeStr, int* result);
#endif //CEXT_CA_STRING_H
