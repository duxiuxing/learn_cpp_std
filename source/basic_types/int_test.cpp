#include <gtest/gtest.h>
#include <sstream>
#include <stdlib.h>

#ifndef _STDINT
    #include <limits>
    typedef signed char int8_t;
    typedef short       int16_t;
    typedef int         int32_t;
    typedef long long   int64_t;

    typedef unsigned char      uint8_t;
    typedef unsigned short     uint16_t;
    typedef unsigned int       uint32_t;
    typedef unsigned long long uint64_t;

    #define INT8_MIN _I8_MIN
    #define INT8_MAX _I8_MAX
    #define UINT8_MAX _UI8_MAX

    #define INT16_MIN _I16_MIN
    #define INT16_MAX _I16_MAX
    #define UINT16_MAX _UI16_MAX

    #define INT32_MIN _I32_MIN
    #define INT32_MAX _I32_MAX
    #define UINT32_MAX _UI32_MAX

    #define INT64_MIN _I64_MIN
    #define INT64_MAX _I64_MAX
    #define UINT64_MAX _UI64_MAX
#endif

#define BUFFER_MAX UINT8_MAX

/*
    Description: int8转字符串
    Output: 值域范围内能正常转换
*/
TEST(int_test, int8_to_string) {
    typedef int8_t int_type;

    const int_type min_int = INT8_MIN;
    const int_type max_int = INT8_MAX;

    const char expect_str[] = "-128 ~ 127";

    // 使用_itoa_s()
    {
        char buffer[BUFFER_MAX];
        _itoa_s(min_int, buffer, BUFFER_MAX, 10);
        std::string actual_str = buffer;
        actual_str.append(" ~ ");
        _itoa_s(max_int, buffer, BUFFER_MAX, 10);
        actual_str.append(buffer);
        EXPECT_STREQ(expect_str, actual_str.c_str());
    }

    // 使用sprintf_s()
    {
        char actual_str[BUFFER_MAX];
        sprintf_s(actual_str, BUFFER_MAX, "%d ~ %d", min_int, max_int);
        EXPECT_STREQ(expect_str, actual_str);
    }

    // 使用std::to_string()
#if _MSC_VER >= 1900 // vs2015 or above    
    {
        std::string actual_str = std::to_string(min_int);
        actual_str.append(" ~ ");
        actual_str.append(std::to_string(max_int));
        EXPECT_STREQ(expect_str, actual_str.c_str());
    }
#elif _MSC_VER >= 1600 // vs2010 or above  
    {
        std::string actual_str = std::to_string((int64_t)min_int);
        actual_str.append(" ~ ");
        actual_str.append(std::to_string((int64_t)max_int));
        EXPECT_STREQ(expect_str, actual_str.c_str());
    }
#endif

    // 使用std::stringstream时，如果不带显式类型转换会被当做char处理
    {
        std::stringstream ss;
        ss << min_int << " ~ " << max_int;

        EXPECT_STRNE(expect_str, ss.str().c_str());
        EXPECT_STREQ("\x80 ~ \x7F", ss.str().c_str());
    }

    // 使用std::stringstream时，需要带显示类型转换
    {
        std::stringstream ss;
        ss << (int32_t)min_int << " ~ " << (int32_t)max_int;
        EXPECT_STREQ(expect_str, ss.str().c_str());
    }
}

/*
    Description: int16转字符串
    Output: 值域范围内能正常转换
*/
TEST(int_test, int16_to_string) {
    typedef int16_t int_type;

    const int_type min_int = INT16_MIN;
    const int_type max_int = INT16_MAX;

    const char expect_str[] = "-32768 ~ 32767";

    // 使用_itoa_s()
    {
        char buffer[BUFFER_MAX];
        _itoa_s(min_int, buffer, BUFFER_MAX, 10);
        std::string actual_str = buffer;
        actual_str.append(" ~ ");
        _itoa_s(max_int, buffer, BUFFER_MAX, 10);
        actual_str.append(buffer);
        EXPECT_STREQ(expect_str, actual_str.c_str());
    }

    // 使用sprintf_s()
    {
        char actual_str[BUFFER_MAX];
        sprintf_s(actual_str, BUFFER_MAX, "%d ~ %d", min_int, max_int);
        EXPECT_STREQ(expect_str, actual_str);
    }

    // 使用std::to_string()
#if _MSC_VER >= 1900 // vs2015 or above
    {
        std::string actual_str = std::to_string(min_int);
        actual_str.append(" ~ ");
        actual_str.append(std::to_string(max_int));
        EXPECT_STREQ(expect_str, actual_str.c_str());
    }
#elif _MSC_VER >= 1600 // vs2010 or above
    {
        std::string actual_str = std::to_string((int64_t)min_int);
        actual_str.append(" ~ ");
        actual_str.append(std::to_string((int64_t)max_int));
        EXPECT_STREQ(expect_str, actual_str.c_str());
    }
#endif

    // 使用std::stringstream
    {
        std::stringstream ss;
        ss << min_int << " ~ " << max_int;
        EXPECT_STREQ(expect_str, ss.str().c_str());
    }
}

/*
    Description: int32转字符串
    Output: 值域范围内能正常转换
*/
TEST(int_test, int32_to_string) {
    typedef int32_t int_type;

    const int_type min_int = INT32_MIN;
    const int_type max_int = INT32_MAX;

    const char expect_str[] = "-2147483648 ~ 2147483647";

    // 使用_itoa_s()
    {
        char buffer[BUFFER_MAX];
        _itoa_s(min_int, buffer, BUFFER_MAX, 10);
        std::string actual_str = buffer;
        actual_str.append(" ~ ");
        _itoa_s(max_int, buffer, BUFFER_MAX, 10);
        actual_str.append(buffer);
        EXPECT_STREQ(expect_str, actual_str.c_str());
    }

    // 使用sprintf_s()
    {
        char actual_str[BUFFER_MAX];
        sprintf_s(actual_str, BUFFER_MAX, "%d ~ %d", min_int, max_int);
        EXPECT_STREQ(expect_str, actual_str);
    }

    // 使用std::to_string()
#if _MSC_VER >= 1900 // vs2015 or above
    {
        std::string actual_str = std::to_string(min_int);
        actual_str.append(" ~ ");
        actual_str.append(std::to_string(max_int));
        EXPECT_STREQ(expect_str, actual_str.c_str());
    }
#elif _MSC_VER >= 1600 // vs2010 or above 
    {
        std::string actual_str = std::to_string((int64_t)min_int);
        actual_str.append(" ~ ");
        actual_str.append(std::to_string((int64_t)max_int));
        EXPECT_STREQ(expect_str, actual_str.c_str());
    }
#endif

    // 使用std::stringstream
    {
        std::stringstream ss;
        ss << min_int << " ~ " << max_int;
        EXPECT_STREQ(expect_str, ss.str().c_str());
    }
}

/*
    Description: 字符串转int32
    Output: 值域范围内能正常转换
*/
TEST(int_test, string_to_int32) {
    typedef int32_t int_type;

    const int_type min_int = INT32_MIN;
    const int_type max_int = INT32_MAX;

    const char min_str[] = "-2147483648";
    const char max_str[] = "2147483647";

    // 使用atoi()
    {
        EXPECT_EQ(min_int, atoi(min_str));
        EXPECT_EQ(max_int, atoi(max_str));
    }

    // 使用sscanf_s()
    {
        int_type actual_int = 0;
        sscanf_s(min_str, "%d", &actual_int);
        EXPECT_EQ(min_int, actual_int);

        sscanf_s(max_str, "%d", &actual_int);
        EXPECT_EQ(max_int, actual_int);
    }

#if _MSC_VER >= 1600 // vs2010 or above
    // 使用std::stoi()
    {
        EXPECT_EQ(min_int, std::stoi(min_str));
        EXPECT_EQ(max_int, std::stoi(max_str));
    }
#endif

    // 使用std::istringstream
    {
        int_type actual_int = 0;

        {
            std::istringstream ss;
            ss.str(min_str);
            ss >> actual_int;
            EXPECT_EQ(min_int, actual_int);
        }

        {
            std::istringstream ss;
            ss.str(max_str);
            ss >> actual_int;
            EXPECT_EQ(max_int, actual_int);
        }
    }
}

/*
    Description: int64转字符串
    Output: 值域范围内能正常转换
*/
TEST(int_test, int64_to_string) {
    typedef int64_t int_type;

    const int_type min_int = INT64_MIN;
    const int_type max_int = INT64_MAX;

    const char expect_str[] = "-9223372036854775808 ~ 9223372036854775807";

    // 使用_i64toa_s()
    {
        char buffer[BUFFER_MAX];
        _i64toa_s(min_int, buffer, BUFFER_MAX, 10);
        std::string actual_str = buffer;
        actual_str.append(" ~ ");
        _i64toa_s(max_int, buffer, BUFFER_MAX, 10);
        actual_str.append(buffer);
        EXPECT_STREQ(expect_str, actual_str.c_str());
    }

    // 使用sprintf_s()
    {
        char actual_str[BUFFER_MAX];
        sprintf_s(actual_str, BUFFER_MAX, "%lld ~ %lld", min_int, max_int);
        EXPECT_STREQ(expect_str, actual_str);
    }

#if _MSC_VER >= 1600 // vs2010 or above
    // 使用std::to_string()
    {
        std::string actual_str = std::to_string(min_int);
        actual_str.append(" ~ ");
        actual_str.append(std::to_string(max_int));
        EXPECT_STREQ(expect_str, actual_str.c_str());
    }
#endif

    // 使用std::stringstream
    {
        std::stringstream ss;
        ss << min_int << " ~ " << max_int;
        EXPECT_STREQ(expect_str, ss.str().c_str());
    }
}

/*
    Description: 字符串转int64
    Output: 值域范围内能正常转换
*/
TEST(int_test, string_to_int64) {
    typedef int64_t int_type;

    const int_type min_int = INT64_MIN;
    const int_type max_int = INT64_MAX;

    const char min_str[] = "-9223372036854775808";
    const char max_str[] = "9223372036854775807";

    // 使用_atoi64()
    {
        EXPECT_EQ(min_int, _atoi64(min_str));
        EXPECT_EQ(max_int, _atoi64(max_str));
    }

    // 使用sscanf_s()
    {
        int64_t actual_int = 0;
        sscanf_s(min_str, "%lld", &actual_int);
        EXPECT_EQ(min_int, actual_int);

        sscanf_s(max_str, "%lld", &actual_int);
        EXPECT_EQ(max_int, actual_int);
    }

#if _MSC_VER >= 1600 // vs2010 or above
    // 使用std::stoll()
    {
        EXPECT_EQ(min_int, std::stoll(min_str));
        EXPECT_EQ(max_int, std::stoll(max_str));
    }
#endif

    // 使用std::istringstream
    {
        int_type actual_int = 0;

        {
            std::istringstream ss;
            ss.str(min_str);
            ss >> actual_int;
            EXPECT_EQ(min_int, actual_int);
        }

        {
            std::istringstream ss;
            ss.str(max_str);
            ss >> actual_int;
            EXPECT_EQ(max_int, actual_int);
        }
    }
}

/*
    Description: uint8转字符串
    Output: 值域范围内能正常转换
*/
TEST(int_test, uint8_to_string) {
    typedef uint8_t int_type;

    const int_type min_int = 0;
    const int_type max_int = UINT8_MAX;

    const char expect_str[] = "0 ~ 255";

    // 使用_itoa_s()
    {
        char buffer[BUFFER_MAX];
        _itoa_s(min_int, buffer, BUFFER_MAX, 10);
        std::string actual_str = buffer;
        actual_str.append(" ~ ");
        _itoa_s(max_int, buffer, BUFFER_MAX, 10);
        actual_str.append(buffer);
        EXPECT_STREQ(expect_str, actual_str.c_str());
    }

    // 使用sprintf_s()
    {
        char actual_str[BUFFER_MAX];
        sprintf_s(actual_str, BUFFER_MAX, "%u ~ %u", min_int, max_int);
        EXPECT_STREQ(expect_str, actual_str);
    }

    // 使用std::to_string()
#if _MSC_VER >= 1900 // vs2015 or above
    {
        std::string actual_str = std::to_string(min_int);
        actual_str.append(" ~ ");
        actual_str.append(std::to_string(max_int));
        EXPECT_STREQ(expect_str, actual_str.c_str());
    }
#elif _MSC_VER >= 1600 // vs2010 or above 
    {
        std::string actual_str = std::to_string((uint64_t)min_int);
        actual_str.append(" ~ ");
        actual_str.append(std::to_string((uint64_t)max_int));
        EXPECT_STREQ(expect_str, actual_str.c_str());
    }
#endif

    // 使用std::stringstream without explicit type conversions
    {
        std::stringstream ss;
        ss << min_int << " ~ " << max_int;
        EXPECT_STRNE(expect_str, ss.str().c_str());

        EXPECT_STREQ("\x00 ~ \xFF", ss.str().c_str());
    }

    // 使用std::stringstream with explicit type conversions
    {
        std::stringstream ss;
        ss << (uint32_t)min_int << " ~ " << (uint32_t)max_int;
        EXPECT_STREQ(expect_str, ss.str().c_str());
    }
}

/*
    Description: uint16转字符串
    Output: 值域范围内能正常转换
*/
TEST(int_test, uint16_to_string) {
    typedef uint16_t int_type;

    const int_type min_int = 0;
    const int_type max_int = UINT16_MAX;

    const char expect_str[] = "0 ~ 65535";

    // 使用_itoa_s()
    {
        char buffer[BUFFER_MAX];
        _itoa_s(min_int, buffer, BUFFER_MAX, 10);
        std::string actual_str = buffer;
        actual_str.append(" ~ ");
        _itoa_s(max_int, buffer, BUFFER_MAX, 10);
        actual_str.append(buffer);
        EXPECT_STREQ(expect_str, actual_str.c_str());
    }

    // 使用sprintf_s()
    {
        char actual_str[BUFFER_MAX];
        sprintf_s(actual_str, BUFFER_MAX, "%u ~ %u", min_int, max_int);
        EXPECT_STREQ(expect_str, actual_str);
    }

    // 使用std::to_string()
#if _MSC_VER >= 1900 // vs2015 or above    
    {
        std::string actual_str = std::to_string(min_int);
        actual_str.append(" ~ ");
        actual_str.append(std::to_string(max_int));
        EXPECT_STREQ(expect_str, actual_str.c_str());
    }
#elif _MSC_VER >= 1600 // vs2010 or above 
    {
        std::string actual_str = std::to_string((uint64_t)min_int);
        actual_str.append(" ~ ");
        actual_str.append(std::to_string((uint64_t)max_int));
        EXPECT_STREQ(expect_str, actual_str.c_str());
    }
#endif

    // 使用std::stringstream
    {
        std::stringstream ss;
        ss << min_int << " ~ " << max_int;
        EXPECT_STREQ(expect_str, ss.str().c_str());
    }
}

/*
    Description: uint32转字符串
    Output: 值域范围内能正常转换
*/
TEST(int_test, uint32_to_string) {
    typedef uint32_t int_type;

    const int_type min_int = 0;
    const int_type max_int = UINT32_MAX;

    const char expect_str[] = "0 ~ 4294967295";

    // 不能使用_itoa_s()了，会越界，而要用_ui64toa_s
    {
        char buffer[BUFFER_MAX];
        _itoa_s(min_int, buffer, BUFFER_MAX, 10);
        std::string actual_str = buffer;
        actual_str.append(" ~ ");
        _itoa_s(max_int, buffer, BUFFER_MAX, 10);
        actual_str.append(buffer);
        EXPECT_STRNE(expect_str, actual_str.c_str());
        EXPECT_STREQ("0 ~ -1", actual_str.c_str());

        _ui64toa_s(min_int, buffer, BUFFER_MAX, 10);
        actual_str = buffer;
        actual_str.append(" ~ ");
        _ui64toa_s(max_int, buffer, BUFFER_MAX, 10);
        actual_str.append(buffer);
        EXPECT_STREQ(expect_str, actual_str.c_str());
    }

    // 使用sprintf_s()
    {
        char actual_str[BUFFER_MAX];
        sprintf_s(actual_str, BUFFER_MAX, "%u ~ %u", min_int, max_int);
        EXPECT_STREQ(expect_str, actual_str);
    }

    // 使用std::to_string()
#if _MSC_VER >= 1900 // vs2015 or above
    {
        std::string actual_str = std::to_string(min_int);
        actual_str.append(" ~ ");
        actual_str.append(std::to_string(max_int));
        EXPECT_STREQ(expect_str, actual_str.c_str());
    }
#elif _MSC_VER >= 1600 // vs2010 or above 
    {
        std::string actual_str = std::to_string((uint64_t)min_int);
        actual_str.append(" ~ ");
        actual_str.append(std::to_string((uint64_t)max_int));
        EXPECT_STREQ(expect_str, actual_str.c_str());
    }
#endif

    // 使用std::stringstream
    {
        std::stringstream ss;
        ss << min_int << " ~ " << max_int;
        EXPECT_STREQ(expect_str, ss.str().c_str());
    }
}

/*
    Description: 字符串转uint32
    Output: 值域范围内能正常转换
*/
TEST(int_test, string_to_uint32) {
    typedef uint32_t int_type;

    const int_type min_int = 0;
    const int_type max_int = UINT32_MAX;

    const char min_str[] = "0";
    const char max_str[] = "4294967295";

    // 使用_strtoui64()
    {
        EXPECT_EQ(min_int, _strtoui64(min_str, NULL, 10));
        EXPECT_EQ(max_int, _strtoui64(max_str, NULL, 10));
    }

    // 使用sscanf_s()
    {
        int_type actual_int = 0;
        sscanf_s(min_str, "%u", &actual_int);
        EXPECT_EQ(min_int, actual_int);

        sscanf_s(max_str, "%u", &actual_int);
        EXPECT_EQ(max_int, actual_int);
    }

#if _MSC_VER >= 1600 // vs2010 or above
    // 使用std::stoul()
    {
        EXPECT_EQ(min_int, std::stoul(min_str));
        EXPECT_EQ(max_int, std::stoul(max_str));
    }
#endif

    // 使用std::istringstream
    {
        int_type actual_int = 0;

        {
            std::istringstream ss;
            ss.str(min_str);
            ss >> actual_int;
            EXPECT_EQ(min_int, actual_int);
        }

        {
            std::istringstream ss;
            ss.str(max_str);
            ss >> actual_int;
            EXPECT_EQ(max_int, actual_int);
        }
    }
}

/*
    Description: uint64转字符串
    Output: 值域范围内能正常转换
*/
TEST(int_test, uint64_to_string) {
    typedef uint64_t int_type;

    const int_type min_int = 0;
    const int_type max_int = UINT64_MAX;

    const char expect_str[] = "0 ~ 18446744073709551615";

    // 使用_ui64toa_s()
    {
        char buffer[BUFFER_MAX];
        _ui64toa_s(min_int, buffer, BUFFER_MAX, 10);
        std::string actual_str = buffer;
        actual_str.append(" ~ ");
        _ui64toa_s(max_int, buffer, BUFFER_MAX, 10);
        actual_str.append(buffer);
        EXPECT_STREQ(expect_str, actual_str.c_str());
    }

    // 使用sprintf_s()
    {
        char actual_str[BUFFER_MAX];
        sprintf_s(actual_str, BUFFER_MAX, "%llu ~ %llu", min_int, max_int);
        EXPECT_STREQ(expect_str, actual_str);
    }

#if _MSC_VER >= 1600 // vs2010 or above 
    // 使用std::to_string()
    {
        std::string actual_str = std::to_string(min_int);
        actual_str.append(" ~ ");
        actual_str.append(std::to_string(max_int));
        EXPECT_STREQ(expect_str, actual_str.c_str());
    }
#endif

    // 使用std::stringstream
    {
        std::stringstream ss;
        ss << min_int << " ~ " << max_int;
        EXPECT_STREQ(expect_str, ss.str().c_str());
    }
}

TEST(int_test, string_to_uint64) {
    typedef uint64_t int_type;

    const int_type min_int = 0;
    const int_type max_int = UINT64_MAX;

    const char min_str[] = "0";
    const char max_str[] = "18446744073709551615";

    // 使用_strtoui64()
    {
        EXPECT_EQ(min_int, _strtoui64(min_str, NULL, 10));
        EXPECT_EQ(max_int, _strtoui64(max_str, NULL, 10));
    }

    // 使用sscanf_s()
    {
        int64_t actual_int = 0;
        sscanf_s(min_str, "%llu", &actual_int);
        EXPECT_EQ(min_int, actual_int);

        sscanf_s(max_str, "%llu", &actual_int);
        EXPECT_EQ(max_int, actual_int);
    }

#if _MSC_VER >= 1600 // vs2010 or above
    // 使用std::stoull()
    {
        EXPECT_EQ(min_int, std::stoull(min_str));
        EXPECT_EQ(max_int, std::stoull(max_str));
    }
#endif

    // 使用std::istringstream
    {
        int_type actual_int = 0;

        {
            std::istringstream ss;
            ss.str(min_str);
            ss >> actual_int;
            EXPECT_EQ(min_int, actual_int);
        }

        {
            std::istringstream ss;
            ss.str(max_str);
            ss >> actual_int;
            EXPECT_EQ(max_int, actual_int);
        }
    }
}
