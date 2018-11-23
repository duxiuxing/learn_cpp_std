#pragma once

#include "argument.h"

template<class StringType>
class ArgumentsParserT
{
public:
    typedef typename StringType::value_type CharType;

    ArgumentsParserT(int argc, CharType** argv);
    virtual ~ArgumentsParserT();

    bool Has(const CharType* text);
    ArgumentT<StringType>* Get(const CharType* text);

protected:
    typename ArgumentT<StringType>::List m_argList;
};

template<class StringType>
ArgumentsParserT<StringType>::ArgumentsParserT(int argc, typename CharType** argv)
{
    if (argc > 0)
    {
        m_argList.reserve(argc);
    }

    for (int i = 0; i < argc; ++i)
    {
        m_argList.push_back(new ArgumentT<StringType>(m_argList, i, argv[i]));
    }
}

template<class StringType>
ArgumentsParserT<StringType>::~ArgumentsParserT()
{
    ArgumentT<StringType>::List::iterator it = m_argList.begin();
    while (it != m_argList.end())
    {
        delete (*it);
        ++it;
    }

    m_argList.clear();
}

template<class StringType>
bool ArgumentsParserT<StringType>::Has(typename const CharType* text)
{
    ArgumentT<StringType>::List::iterator it = m_argList.begin();
    while (it != m_argList.end())
    {
        if ((*it)->IsEqualTo(text))
        {
            return true;
        }
        ++it;
    }

    return false;
}

template<class StringType>
ArgumentT<StringType>* ArgumentsParserT<StringType>::Get(typename const CharType* text)
{
    Argument::List::iterator it = m_argList.begin();
    while (it != m_argList.end())
    {
        if ((*it)->IsEqualTo(text))
        {
            return (*it);
        }
        ++it;
    }

    return nullptr;
}

typedef ArgumentsParserT<std::string> ArgumentsParser;
typedef ArgumentsParserT<std::wstring> ArgumentsParserW;
