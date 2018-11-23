#include "gtest/gtest.h"

#include "arguments_parser.h"

TEST(ArgumentsParserTest, ParseNameOnly)
{
    {
        char* argv[] = { "Ping.exe", "-t" };
        ArgumentsParser parser(sizeof(argv) / sizeof(argv[0]), argv);

        EXPECT_TRUE(parser.Has("-t"));
    }

    {
        wchar_t* wargv[] = { L"Ping.exe", L"-t" };
        ArgumentsParserW parser(sizeof(wargv) / sizeof(wargv[0]), wargv);

        EXPECT_TRUE(parser.Has(L"-t"));
    }
}

TEST(ArgumentsParserTest, ParseNameAndValue)
{
    char* argv[] = { "Login.exe", "-user_name", "administrator", "-password", "123456" };
    ArgumentsParser parser(sizeof(argv) / sizeof(argv[0]), argv);

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
    char* argv[] = { "FileManager.exe", "-copy", "src.txt", "dest.txt" };
    ArgumentsParser parser(sizeof(argv) / sizeof(argv[0]), argv);

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
