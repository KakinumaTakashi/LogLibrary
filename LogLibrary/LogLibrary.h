#pragma once
#include <string>

#ifdef LOGLIBRARY_EXPORTS
#define LOGLIBRARY_API __declspec(dllexport)
#else
#define LOGLIBRARY_API __declspec(dllimport)
#endif

extern "C" LOGLIBRARY_API int log_open(std::string file_path);
extern "C" LOGLIBRARY_API void log_close(bool flush);
extern "C" LOGLIBRARY_API void log_flush();
extern "C" LOGLIBRARY_API void log_write(std::string format, ...);


