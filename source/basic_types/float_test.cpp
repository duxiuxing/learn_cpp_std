#include <gtest/gtest.h>
#include <sstream>
#include <stdlib.h>

#define BUFFER_MAX UINT8_MAX
float32_t
float64_t
float_t
//
///*
//输入：float32和字符串互转。
//预期输出：值域内的数值能正确转换。
//*/
//TEST(XPTypes, test_float32) {
//    EXPECT_EQ(sizeof(float32), 4);
//
//    float32 value1 = 0.25f;
//    float32 value2 = 4294.967295f;
//
//    xp::strutf8 str;
//    str.format("%f~%f", value1, value2);
//    EXPECT_STREQ(str.c_str(), "0.250000~4294.967285");
//
//  //字符串转float64
//  xp::strutf8 test_str;
//  test_str.format("%f", value1);
//
//  float32 test_float32 = atof(test_str.c_str());
//  EXPECT_EQ(test_float32, value1);//test_str还保留着max的值
//
//  test_str.format("%f", value2);
//  test_float32 = atof(test_str.c_str());
//  EXPECT_EQ(test_float32, value2);
//}
//
///*
//输入：float64和字符串互转。
//预期输出：值域内的数值能正确转换。
//*/
//TEST(XPTypes, test_float64) {
//    EXPECT_EQ(sizeof(float64), 8);
//
//    float64 value1 = 0.25l;
//    float64 value2 = 4294.967295l;
//
//    xp::strutf8 str;
//    str.format("%lf~%lf", value1, value2);
//    EXPECT_STREQ(str.c_str(), "0.250000~4294.967295");
//
////字符串转float64
//  xp::strutf8 test_str;
//  test_str.format("%lf", value1);
//
//  float64 test_float64 = atof(test_str.c_str());
//  EXPECT_EQ(test_float64, value1);//test_str还保留着max的值
//
//  test_str.format("%lf", value2);
//  test_float64 = atof(test_str.c_str());
//  EXPECT_EQ(test_float64, value2);
//
//}
//