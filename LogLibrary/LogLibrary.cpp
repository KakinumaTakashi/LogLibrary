// プリコンパイル済みヘッダー ファイル
#include "pch.h"

#include <fstream>
#include "LogLibrary.h"


#ifdef _DEBUG
#define DEBUG_LOG(fmt, ...) {char b[1024];sprintf_s(b, 1024, fmt, __VA_ARGS__);strcat_s(b, 1024, "\n");OutputDebugString(b);}
#else
#define DEBUG_LOG(fmt, ...) {}
#endif // DEBUG


static std::string log_file_path;
static std::ofstream log_output_stream;

int log_open(std::string file_path)
{
    // ログファイルのオープン
    log_output_stream.open(file_path, std::ios::app);

    if (!log_output_stream) {
        // ファイルオープン失敗
        return ERROR_OPEN_FAILED;
    }
    // ファイル名保存
    log_file_path = file_path;

    return ERROR_SUCCESS;
}

void log_flush()
{
    if (!log_output_stream) return;
    log_output_stream.flush();
}

void log_close(bool flush)
{
    if (!log_output_stream) return;

    if (flush) {
        log_flush();
    }

    log_output_stream.close();
}

std::string get_current_time_string()
{
    SYSTEMTIME system_time;
    GetLocalTime(&system_time);

    char buffer[24];
    sprintf_s(buffer, 24, "%04d/%02d/%02d %02d:%02d:%02d.%03d",
        system_time.wYear, system_time.wMonth, system_time.wDay,
        system_time.wHour, system_time.wMinute, system_time.wSecond, system_time.wMilliseconds);

    return std::string(buffer);
}

void log_write(std::string format, ...)
{
    va_list args;
    va_start(args, format);

    char arg_format_buffer[4096];
    vsnprintf(arg_format_buffer, 4096, format.c_str(), args);

    char write_format_buffer[4096];
    snprintf(write_format_buffer, 4096, "%s\n", get_current_time_string().c_str());
    DEBUG_LOG("len=%d", strlen(write_format_buffer));

    log_output_stream.write(write_format_buffer, strlen(write_format_buffer));

    va_end(args);
}


std::string get_current_thread_id_string()
{
    return "";
}
