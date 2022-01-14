#ifndef ASSERT_HPP
#define ASSERT_HPP

#include <stdio.h>
#include <stdlib.h>

#ifdef NO_DEBUG
    #define CORE_ASSERT(EXPR)
    #define CORE_ASSERT_LOG(EXPR, ...)
#else
    #define CORE_ASSERT(EXPR)\
        if(!(EXPR))\
        {\
            printf("Assertion Failed: %s | File %s | Line %d\n", #EXPR, __FILE__, __LINE__);\
            exit(EXIT_FAILURE);\
        }

    #define CORE_ASSERT_LOG(EXPR, ...)\
        if(!(EXPR))\
        {\
            printf("Assertion Failed: %s | File %s | Line %d\n", #EXPR, __FILE__, __LINE__);\
            printf("%s\n", ##__VA_ARGS__);\
            exit(EXIT_FAILURE);\
        }
#endif

#endif