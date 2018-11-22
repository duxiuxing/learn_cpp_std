#pragma once

#include "argument.h"

class ArgumentsParser
{
public:
    ArgumentsParser(int argc, char** argv);
    virtual ~ArgumentsParser();

    bool Has(const char* text);
    Argument* Get(const char* text);

protected:
    ArgumentList m_argList;
};
