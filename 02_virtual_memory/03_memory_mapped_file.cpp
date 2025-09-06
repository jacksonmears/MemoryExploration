#include <iostream>
#include <fstream>
#include <windows.h>
using namespace std;

int main() {
    cout << "Demonstrating Memory-Mapped Files (Windows):\n\n";

    const char* filename = "demo.txt";
    const char* message = "Hello, memory mapping!";
    DWORD size = strlen(message);

    // Step 1: Create or open the file
    HANDLE hFile = CreateFileA(
        filename,
        GENERIC_READ | GENERIC_WRITE,
        0,              // no sharing
        NULL,           // default security
        OPEN_ALWAYS,    // create if not exists
        FILE_ATTRIBUTE_NORMAL,
        NULL);

    if (hFile == INVALID_HANDLE_VALUE) {
        cerr << "Error creating/opening file.\n";
        return 1;
    }

    // Ensure file is large enough
    DWORD written;
    WriteFile(hFile, message, size, &written, NULL);

    // Step 2: Create a file mapping object
    HANDLE hMapFile = CreateFileMappingA(
        hFile,
        NULL,           // default security
        PAGE_READWRITE, // read/write access
        0,
        size,
        NULL);

    if (hMapFile == NULL) {
        cerr << "Error creating file mapping.\n";
        CloseHandle(hFile);
        return 1;
    }

    // Step 3: Map the file into memory
    char* mapped = (char*)MapViewOfFile(
        hMapFile,
        FILE_MAP_ALL_ACCESS,
        0, 0,
        size);

    if (mapped == NULL) {
        cerr << "Error mapping view of file.\n";
        CloseHandle(hMapFile);
        CloseHandle(hFile);
        return 1;
    }

    // Step 4: Use memory like normal
    cout << "Mapped file contents: " << mapped << "\n";

    mapped[0] = 'h'; // modify directly in memory
    cout << "After modification: " << mapped << "\n";

    // Step 5: Cleanup
    UnmapViewOfFile(mapped);
    CloseHandle(hMapFile);
    CloseHandle(hFile);

    /*
    -----------------------------------------------------
    Explanation:
    -----------------------------------------------------
    - On Windows, memory mapping is done with:
        CreateFile      -> open file
        CreateFileMapping -> create mapping object
        MapViewOfFile   -> get pointer into virtual memory
    - Reads/writes go directly to the file through virtual memory.
    - Demonstrates virtual memory abstraction beyond RAM.
    */
    return 0;
}
