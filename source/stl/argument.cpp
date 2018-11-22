#include "argument.h"

Argument::Argument(ArgumentList& argList, int index, const char* text)
    : m_argList(argList)
    , m_index(index)
    , m_text(text)
{}

Argument* Argument::Next()
{
    int nextIndex = m_index + 1;

    if (nextIndex > 0 && nextIndex < static_cast<int>(m_argList.size()))
    {
        return m_argList[nextIndex];
    }
    else
    {
        return NULL;
    }
}

Argument* Argument::Previous()
{
    int prevIndex = m_index - 1;

    if (prevIndex > 0 && prevIndex < static_cast<int>(m_argList.size()))
    {
        return m_argList[prevIndex];
    }
    else
    {
        return NULL;
    }
}

const char* Argument::Text()
{
    return m_text.c_str();
}

bool Argument::IsEqualTo(const char* text)
{
    return (0 == m_text.compare(text));
}
