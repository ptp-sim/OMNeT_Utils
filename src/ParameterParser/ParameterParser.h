
#ifndef PARAMETER_PARSER_H_
#define PARAMETER_PARSER_H_

// ======================================================
// Includes
// ======================================================

#include <cexception.h>

// ======================================================
// Definitions
// ======================================================

#define     MAX_PARSE_STRING_LEN    50

#define     ArrayLen(A)             (sizeof(A)/sizeof(A[0]))

// ======================================================
// Constants
// ======================================================

// ======================================================
// Types
// ======================================================

template <typename T>
struct ParseType
{
    T       Value;
    char    Name[MAX_PARSE_STRING_LEN];
};

// ======================================================
// Declarations
// ======================================================

// ------------------------------------------------------
// Template search function
// ------------------------------------------------------
template <class T>
T Parse( ParseType<T> *pParse, size_t size, const char *Str)
{
    for(size_t i = 0; i < size; i++)
    {
        if( 0 == strcmp(pParse[i].Name, Str))
        {
            return  pParse[i].Value;
        }
    }

    // No match could be found --> Throw exception
    throw cRuntimeError("Parsing exception: Failed to parse value '%s'", Str );
}

#endif

