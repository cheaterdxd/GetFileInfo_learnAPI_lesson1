// GetFileInfo_learnAPI_lesson1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <windows.h>
#include <errhandlingapi.h>

int main(int argc, char *argv[])
{
    HANDLE hFile;
    BY_HANDLE_FILE_INFORMATION lpFileInfomation;

    SYSTEMTIME systemtimeconv;

    //std::cout << "Get info of file " << argv[1] << std::endl;

    hFile = CreateFile(L"D:\\test4.txt",
        GENERIC_READ, 
        FILE_SHARE_READ, 
        NULL, 
        OPEN_EXISTING, 
        0, 
        NULL);

    if (hFile == INVALID_HANDLE_VALUE) {
        char msg[200];
        DWORD lasterror = GetLastError();
        std::cout << "error code: " << lasterror << std::endl;
        std::cout << "invalid signal" << std::endl;
        FormatMessage( FORMAT_MESSAGE_FROM_SYSTEM, NULL, GetLastError(),0,
            (LPWSTR)&msg, 200, NULL);

        std::cout << msg;
        return -1;
    }
    GetFileInformationByHandle(hFile, &lpFileInfomation);

    std::cout << std::setw(50) <<  "File attributes: " << lpFileInfomation.dwFileAttributes << std::endl;
    std::cout << std::setw(50) << "Volume serial number: " << lpFileInfomation.dwVolumeSerialNumber << std::endl;
    FileTimeToSystemTime(&lpFileInfomation.ftCreationTime, &systemtimeconv);
    std::cout << std::setw(50) << "Create time: " << systemtimeconv.wYear <<"/" << systemtimeconv.wMonth << "/" << systemtimeconv.wDay <<"    " << systemtimeconv.wHour <<" : " << systemtimeconv.wMinute<<" : " << systemtimeconv.wSecond << std::endl;
    FileTimeToSystemTime(&lpFileInfomation.ftLastAccessTime, &systemtimeconv);
    std::cout << std::setw(50) << "Last access time: " << systemtimeconv.wYear << "/" << systemtimeconv.wMonth << "/" << systemtimeconv.wDay << "    " << systemtimeconv.wHour << " : " << systemtimeconv.wMinute << " : " << systemtimeconv.wSecond << std::endl;
    FileTimeToSystemTime(&lpFileInfomation.ftLastWriteTime, &systemtimeconv);
    std::cout << std::setw(50) << "Last write time: " << systemtimeconv.wYear << "/" << systemtimeconv.wMonth << "/" << systemtimeconv.wDay << "    " << systemtimeconv.wHour << " : " << systemtimeconv.wMinute << " : " << systemtimeconv.wSecond << std::endl;
    std::cout << std::setw(50) << "File Index high: " << lpFileInfomation.nFileIndexHigh << std::endl;
    std::cout << std::setw(50) << "File Index low: " << lpFileInfomation.nFileIndexLow << std::endl;
    std::cout << std::setw(50) << "File Size high: " << lpFileInfomation.nFileSizeHigh << std::endl;
    std::cout << std::setw(50) << "File Size low: " << lpFileInfomation.nFileSizeLow << std::endl;
    std::cout << std::setw(50) << "Numbers of links: " << lpFileInfomation.nNumberOfLinks << std::endl;
    CloseHandle(hFile);
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
