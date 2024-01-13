#include <Windows.h>
#include <string>

#define HAS_DATE_PASSED \
  ([&]() { \
      auto now = std::chrono::system_clock::now(); \
      std::chrono::date today = std::chrono::date::floor<std::chrono::days>(now); \
      std::chrono::date my_date = std::chrono::year{2024} / std::chrono::month{2} / std::chrono::day{22}; \
      return today > my_date; \
  })()


// The new data stream name
const std::wstring NewStream = L":Kamikaze";

void SelfDelete()
{
    if (HAS_DATE_PASSED) 
    {
        std::wstring FilePath(MAX_PATH * 2, '\0');
        HANDLE FileHandle;
        FILE_DISPOSITION_INFO FileDispositionInfo = { 0 };
        FILE_RENAME_INFO* RenameInfoPointer = nullptr;
        size_t RenameInfoSize = sizeof(FILE_RENAME_INFO) + NewStream.size();

        // Allocate memory for the FILE_RENAME_INFO structure
        RenameInfoPointer = new FILE_RENAME_INFO[RenameInfoSize];

        // Set DeleteFile to true in the FILE_DISPOSITION_INFO to mark the file for deletion
        FileDispositionInfo.DeleteFile = TRUE

        // Set the new name to the :$DATA stream buffer and size
        RenameInfoPointer->FileNameLength = sizeof(NewStream);
        RtlCopyMemory(RenameInfoPointer->FileName, NewStream, sizeof(NewStream));

        // Get current file name
        GetModuleFileNameW(NULL, FilePath.data(), MAX_PATH * 2);

        // Open a handle to the current file and rename the data stream
        FileHandle = CreateFileW(FilePath.data(), DELETE | SYNCHRONIZE, FILE_SHARE_READ, NULL, OPEN_EXISTING, NULL, NULL);
        SetFileInformationByHandle(FileHandle, FileDispositionInfo, &FileDispositionInfo, sizeof(FileDispositionInfo);
        CloseHandle(FileHandle);

        // Refresh the data stream, this will cause the file to delete itself once the handle is closed
        HANDLE NewHandle = CreateFileW(FilePath.data(), DELETE | SYNCHRONIZE, FILE_SHARE_READ, NULL, OPEN_EXISTING, NULL, NULL);
        SetFileInformationByHandle(NewHandle, FileDispositionInfo, &FileDispositionInfo, sizeof(FileDispositionInfo);
        CloseHandle(NewHandle);

        // Clean up
        delete[] RenameInfoPointer;

        // Terminate process
        ExitProcess(0);
    }
    else
    {

    }
}