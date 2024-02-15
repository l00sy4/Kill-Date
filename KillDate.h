#ifndef FILE_H
#define FILE_H

#include <Windows.h>

#define HAS_TIME_PASSED(epoch) (GetUnixTimestamp() > epoch)

SIZE_T GetUnixTimestamp();
void SelfDelete();

extern const wchar_t NewStream[];

#endif // FILE_H