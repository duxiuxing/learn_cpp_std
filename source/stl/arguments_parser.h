#pragma once

#include "argument.h"

template<class StringType>
class ArgumentsParserT
{
public:
    typedef typename StringType::value_type CharType;
    typedef ArgumentT<StringType> ArgumentType;

    ArgumentsParserT(int argc, CharType** argv)
    {
        if (argc > 0)
        {
            m_argList.reserve(argc);
            for (int i = 0; i < argc; ++i)
            {
                m_argList.emplace_back(ArgumentType(m_argList, i, argv[i]));
            }
        }
    }

    bool Has(const CharType* text)
    {
        return (Get(text) != nullptr);
    }

    ArgumentType* Get(const CharType* text)
    {
        for (auto it = m_argList.begin(); it != m_argList.end(); ++it)
        {
            if ((*it).IsEqualTo(text))
            {
                return &(*it);
            }
        }

        return nullptr;
    }

protected:
    typename ArgumentType::List m_argList;
};

typedef ArgumentsParserT<std::string> ArgumentsParser;
typedef ArgumentsParserT<std::wstring> ArgumentsParserW;
