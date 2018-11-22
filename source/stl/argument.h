#pragma once

#include <string>
#include <vector>

class Argument;
typedef std::vector<Argument*> ArgumentList;

class Argument
{
public:
    Argument(ArgumentList& argList, int index, const char* text);

    Argument* Next();
    Argument* Previous();

    const char* Text();
    bool IsEqualTo(const char* text);

protected:
    ArgumentList& m_argList;
    int m_index;
    std::string m_text;
};
