#include "gtest/gtest.h"

#include "arguments_parser.h"

TEST(ArgumentsParserTest, ParseNameOnly)
{
    char* arguments[] = { "Ping.exe", "-t", "192.168.0.1" };
    ArgumentsParser parser(3, arguments);

    EXPECT_TRUE(parser.Has("-t"));
}

TEST(ArgumentsParserTest, ParseNameAndValue)
{
    char* arguments[] = { "Login.exe", "-user_name", "administrator", "-password", "123456" };
    ArgumentsParser parser(5, arguments);

    std::string userName;
    if (parser.Has("-user_name"))
    {
        Argument* arg = parser.Get("-user_name")->Next();
        if (arg)
        {
            userName = arg->Text();
        }
    }
    EXPECT_STREQ("administrator", userName.c_str());

    std::string password;
    if (parser.Has("-password"))
    {
        Argument* arg = parser.Get("-password")->Next();
        if (arg)
        {
            password = arg->Text();
        }
    }
    EXPECT_STREQ("123456", password.c_str());
}

TEST(ArgumentsParserTest, ParseNameAndValues)
{
    char* arguments[] = { "FileManager.exe", "-copy", "src.txt", "dest.txt" };
    ArgumentsParser parser(4, arguments);

    std::string srcFile, destFile;
    if (parser.Has("-copy"))
    {
        Argument* arg = parser.Get("-copy")->Next();
        if (arg)
        {
            srcFile = arg->Text();
            arg = arg->Next();
            if (arg)
            {
                destFile = arg->Text();
            }
        }
    }

    EXPECT_STREQ("src.txt", srcFile.c_str());
    EXPECT_STREQ("dest.txt", destFile.c_str());
}
