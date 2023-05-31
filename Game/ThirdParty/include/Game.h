#pragma once

#ifdef MEDIEVELHOTLINE_EXPORTS
#define MEDIEVELHOTLINE_API __declspec(dllexport)
#else 
#define MEDIEVELHOTLINE_API __declspec(dllimport)
#endif

extern "C" MEDIEVELHOTLINE_API void bebra();