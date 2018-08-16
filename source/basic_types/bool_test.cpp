#include <gtest/gtest.h>
#include <sstream>

#define BUFFER_MAX 256

/*
    Description: 布尔值转字符串
    Output: true显示为1，false显示为0
*/
TEST(bool_test, convert_to_string) {
    const char expect_str[] = "true=1, false=0";

    // 使用_itoa_s()
    {
        std::string actual_str = "true=";
        char buffer[BUFFER_MAX];
        _itoa_s(true, buffer, BUFFER_MAX, 10);
        actual_str.append(buffer);
        actual_str.append(", false=");
        _itoa_s(false, buffer, BUFFER_MAX, 10);
        actual_str.append(buffer);
        EXPECT_STREQ(expect_str, actual_str.c_str());
    }

    // 使用sprintf_s()
    {
        char actual_str[BUFFER_MAX];
        sprintf_s(actual_str, BUFFER_MAX, "true=%u, false=%u", true, false);
        EXPECT_STREQ(expect_str, actual_str);
    }

    // 使用std::stringstream
    {
        std::stringstream ss;
        ss << "true=" << true << ", false=" << false;
        EXPECT_STREQ(expect_str, ss.str().c_str());
    }

#ifdef _STDINT
    // 使用std::to_string()
    {
#if _MSC_VER <= 1600 // vs2010 or previous
        std::string actual_str = "true=";
        actual_str.append(std::to_string((uint64_t)true));
        actual_str.append(", false=");
        actual_str.append(std::to_string((uint64_t)false));
        EXPECT_STREQ(expect_str, actual_str.c_str());
#else
        std::string actual_str = "true=";
        actual_str.append(std::to_string(true));
        actual_str.append(", false=");
        actual_str.append(std::to_string(false));
        EXPECT_STREQ(expect_str, actual_str.c_str());
#endif
    }
#endif // #ifdef _STDINT
}

/*
    Description: 布尔值转宽字符串
    Output: true显示为1，false显示为0
*/
TEST(bool_test, convert_to_wstring) {
    const wchar_t expect_str[] = L"true=1, false=0";

    // 使用_itow_s()
    {
        std::wstring actual_str = L"true=";
        wchar_t buffer[BUFFER_MAX];
        _itow_s(true, buffer, BUFFER_MAX, 10);
        actual_str.append(buffer);
        actual_str.append(L", false=");
        _itow_s(false, buffer, BUFFER_MAX, 10);
        actual_str.append(buffer);
        EXPECT_STREQ(expect_str, actual_str.c_str());
    }

    // 使用swprintf_s()
    {
        wchar_t actual_str[BUFFER_MAX];
        swprintf_s(actual_str, BUFFER_MAX, L"true=%u, false=%u", true, false);
        EXPECT_STREQ(expect_str, actual_str);
    }

    // 使用wstringstream
    {
        std::wstringstream ss;
        ss << L"true=" << true << L", false=" << false;
        EXPECT_STREQ(expect_str, ss.str().c_str());
    }

#ifdef _STDINT
    // 使用std::to_wstring()
    {
#if _MSC_VER <= 1600 // vs2010 or previous
        std::wstring actual_str = L"true=";
        actual_str.append(std::to_wstring((uint64_t)true));
        actual_str.append(L", false=");
        actual_str.append(std::to_wstring((uint64_t)false));
        EXPECT_STREQ(expect_str, actual_str.c_str());
#else
        std::wstring actual_str = L"true=";
        actual_str.append(std::to_wstring(true));
        actual_str.append(L", false=");
        actual_str.append(std::to_wstring(false));
        EXPECT_STREQ(expect_str, actual_str.c_str());
#endif
    }
#endif // #ifdef _STDINT
}
