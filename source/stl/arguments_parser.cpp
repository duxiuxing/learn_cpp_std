#include "arguments_parser.h"

ArgumentsParser::ArgumentsParser(int argc, char** argv)
{
    if (argc > 0)
    {
        m_argList.reserve(argc);
    }

    for (int i = 0; i < argc; ++i)
    {
        m_argList.push_back(new Argument(m_argList, i, argv[i]));
    }
}

ArgumentsParser::~ArgumentsParser()
{
    ArgumentList::iterator it = m_argList.begin();
    while (it != m_argList.end())
    {
        delete (*it);
        ++it;
    }

    m_argList.clear();
}

bool ArgumentsParser::Has(const char* text)
{
    ArgumentList::iterator it = m_argList.begin();
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

Argument* ArgumentsParser::Get(const char* text)
{
    ArgumentList::iterator it = m_argList.begin();
    while (it != m_argList.end())
    {
        if ((*it)->IsEqualTo(text))
        {
            return (*it);
        }
        ++it;
    }

    return NULL;
}