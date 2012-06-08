//
// Author: Micke Prag <micke.prag@telldus.se>, (C) 2009
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef TELLDUS_CORE_COMMON_COMMON_H_
#define TELLDUS_CORE_COMMON_COMMON_H_

#ifdef _WINDOWS
#include <windows.h>
#include <ole2.h>
#define strcasecmp _stricmp
#define strncasecmp _strnicmp
#else
#include <unistd.h>
#endif
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <string>
#include "common/Strings.h"

inline void msleep( const int msec) {
#ifdef _WINDOWS
	Sleep(msec);
#else
	usleep(msec*1000);
#endif
}

inline void dlog(const char *fmt, ...) {
	va_list ap;
	va_start(ap, fmt);
	vprintf(fmt, ap);
	va_end(ap);
	printf("\n");
	fflush(stdout);
}

inline void debuglog(const int intMessage, const std::string strMessage) {
#ifdef _WINDOWS
	static bool firstRun = true;
	std::ofstream file;
	std::string filename("C:/log_locks.txt");
	if (firstRun) {
		file.open(filename.c_str(), std::ios::out);
		firstRun = false;
	} else {
		file.open(filename.c_str(), std::ios::out | std::ios::app);
	}

	file << "[" << GetCurrentThreadId() << "] " << intMessage << " - " << strMessage << "\n";
	file.flush();
	file.close();

#elif !defined(_MACOSX) && !defined(__FreeBSD__)
	pthread_t thread = pthread_self();
	printf("[%i] %i - %s\n", static_cast<int>(thread), intMessage, strMessage.c_str());
	fflush(stdout);
#else
	printf("%i - %s\n", intMessage, strMessage.c_str());
#endif
}

inline char *wrapStdString( const std::string &string) {
#ifdef _WINDOWS
	return reinterpret_cast<char *>(SysAllocStringByteLen(string.c_str(), (unsigned int)string.size()));
#else
	char *returnVal;
	returnVal = reinterpret_cast<char *>(malloc(sizeof(*returnVal) * (string.size()+1)));
	strcpy(returnVal, string.c_str());
	return returnVal;
#endif
}

inline char *wrapStdWstring( const std::wstring &wstring) {
	return wrapStdString(TelldusCore::wideToString(wstring));
}

#endif  // TELLDUS_CORE_COMMON_COMMON_H_
