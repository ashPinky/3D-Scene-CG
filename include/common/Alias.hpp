#ifndef ALIAS_HPP
#define ALIAS_HPP

#include <memory>

typedef char                CHAR;
typedef unsigned char       BYTE;
typedef const unsigned char CBYTE;
typedef char*               PSTR;
typedef const char*         PCSTR;

typedef void*               PVOID;
typedef const void*         PCVOID;

typedef unsigned char       UI8;
typedef unsigned short      UI16;
typedef unsigned int        UI32;
typedef unsigned long long  UI64;

typedef signed char         SI8;
typedef signed short        SI16;
typedef signed int          SI32;
typedef signed long long    SI64;

typedef float               F32;
typedef double              F64;
typedef long double         F128;

typedef UI64                SIZE;

namespace re
{
    template<typename T>
    using Scope = std::unique_ptr<T>;

    template<typename T>
    using Ref = std::shared_ptr<T>;

    template<typename T>
    using WeakRef = std::weak_ptr<T>;
}

#endif