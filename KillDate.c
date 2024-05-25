#include <Windows.h>

#define HAS_TIME_PASSED(epoch) (GetUnixTimestamp() > epoch)

// Credit to @0xLegacyy for helping me with this function :hug:
SIZE_T GetUnixTimestamp()
{   
    const SIZE_T UNIX_TIME_START = 0x019DB1DED53E8000;
    
    const SIZE_T TICKS_PER_MILLISECOND = 10000; 
    LARGE_INTEGER Time;

    Time.LowPart = *(DWORD*)(0x7FFE0000 + 0x14);

    Time.HighPart = *(LONG*)(0x7FFE0000 + 0x1c); 
    
    // Calculate the Unix timestamp in milliseconds by subtracting the start of the Unix epoch from the current time(Time.QuadPart)
    return (SIZE_T)((Time.QuadPart - UNIX_TIME_START) / TICKS_PER_MILLISECOND);
}

// The new data stream name
const wchar_t NewStream[] = L":Kamikaze";

void SelfDelete()
{
    WCHAR FilePath(MAX_PATH * 2, '\0');
    HANDLE FileHandle;
    FILE_DISPOSITION_INFO FileDispositionInfo = { 0 };
    FILE_RENAME_INFO* RenameInfoPointer = nullptr;
    size_t RenameInfoSize = sizeof(FILE_RENAME_INFO) + NewStream.size();

    RenameInfoPointer = malloc(RenameInfoSize);
    if (RenameInfoPointer != NULL) 
    {
       memset(RenameInfoPointer, 0, RenameInfoSize);
    }

    FileDispositionInfo.DeleteFile = TRUE

    RenameInfoPointer->FileNameLength = sizeof(NewStream);
    RtlCopyMemory(RenameInfoPointer->FileName, NewStream, sizeof(NewStream));
    GetModuleFileNameW(NULL, FilePath.data(), MAX_PATH * 2);

    FileHandle = CreateFileW(FilePath.data(), DELETE | SYNCHRONIZE, FILE_SHARE_READ, NULL, OPEN_EXISTING, NULL, NULL);
    SetFileInformationByHandle(FileHandle, FileDispositionInfo, &FileDispositionInfo, sizeof(FileDispositionInfo);
    CloseHandle(FileHandle);

    HANDLE NewHandle = CreateFileW(FilePath.data(), DELETE | SYNCHRONIZE, FILE_SHARE_READ, NULL, OPEN_EXISTING, NULL, NULL);
    SetFileInformationByHandle(NewHandle, FileDispositionInfo, &FileDispositionInfo, sizeof(FileDispositionInfo);
    CloseHandle(NewHandle);

    free(RenameInfoPointer);
    RenameInfoPointer = NULL;
    
    exit();
}
