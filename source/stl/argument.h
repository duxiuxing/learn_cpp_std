#pragma once

#include <string>
#include <vector>

template<class StringType>
class ArgumentT
{
public:
    typedef typename StringType::value_type CharType;
    typedef std::vector<ArgumentT<StringType>*> List;

    ArgumentT(List& argList, int index, const CharType* text)
        : m_argList(argList), m_index(index), m_text(text)
    {}

    ArgumentT<StringType>* Next();
    ArgumentT<StringType>* Previous();

    const CharType* Text();
    bool IsEqualTo(const CharType* text);

protected:
    List& m_argList;
    int m_index;
    StringType m_text;
};

template<class StringType>
ArgumentT<StringType>* ArgumentT<StringType>::Next()
{
    int nextIndex = m_index + 1;

    if (nextIndex > 0 && nextIndex < static_cast<int>(m_argList.size()))
    {
        return m_argList[nextIndex];
    }
    else
    {
        return nullptr;
    }
}

template<class StringType>
ArgumentT<StringType>* ArgumentT<StringType>::Previous()
{
    int prevIndex = m_index - 1;

    if (prevIndex > 0 && prevIndex < static_cast<int>(m_argList.size()))
    {
        return m_argList[prevIndex];
    }
    else
    {
        return nullptr;
    }
}

template<class StringType>
typename const ArgumentT<StringType>::CharType* ArgumentT<StringType>::Text()
{
    return m_text.c_str();
}

template<class StringType>
bool ArgumentT<StringType>::IsEqualTo(typename const CharType* text)
{
    return (0 == m_text.compare(text));
}

typedef ArgumentT<std::string> Argument;
typedef ArgumentT<std::wstring> ArgumentW;
