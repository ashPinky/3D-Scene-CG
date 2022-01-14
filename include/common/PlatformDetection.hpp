#ifndef PLATFORM_DETECTION
#define PLATFORM_DETECTION

    #ifdef _WIN32
        #ifdef _WIN64
            #define RE_WINDOWS_PLATFORM
        #elif   
            #error "x86 builds are not supported"
        #endif

    #elif defined(__MACH__)
        #include <TargetConditionals.h>

        #ifdef defined(TARGET_OS_MAC)
            #define RE_MACOS_PLATFORM
            #error "MacOS is not supported"
        #endif
        
    #elif defined(__linux__)
        #define RE_LINUX_PLATFORM
        #error "Linux is not supported"
        
    #else
        #error "Unknown platform"

    #endif

#endif