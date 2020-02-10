// MathClient.cpp : Client app for MathLibrary DLL.
// #include "pch.h" Uncomment for Visual Studio 2017 and earlier
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#include <iostream>
#include "LogLibrary.h"

int main()
{
	log_open("C:\\Work\\test.log");
	log_write("%s", "テスト");
	log_close(true);

	_CrtDumpMemoryLeaks();
}