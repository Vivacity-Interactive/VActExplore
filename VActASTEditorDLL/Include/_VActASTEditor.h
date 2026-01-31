#pragma once

#if defined(_WIN32)
    #if defined(EDITOR_BUILD_DLL)
        #define VACTASTEDITOR_API __declspec(dllexport)
    #else
        #define VACTASTEDITOR_API __declspec(dllimport)
    #endif
#else
    #define VACTASTEDITOR_API
#endif