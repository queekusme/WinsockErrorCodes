# Winsock Error Codes
C++ library to translate Winsock Error Codes into human readable descriptions.

Currently, the project contains all of the Error Codes listed on the "Windows Sockets Error Codes" which can be found on [MSDN](https://msdn.microsoft.com/en-us/library/windows/desktop/ms740668(v=vs.85).aspx)

## Preparing a release ZIP

Once built, A File "createzip.bat" is provided to build the lib, and documentation files into a release zip file

## Usage

### Includes and Linking

To include the library in your Visual Studio solution, 
- Right click your project and select 'Properties'
- Ensure the drop down at the top left says 'All Configurations', if not, Change it to match
- Open the 'C/C++' group and find 'General'
- At the top of this group will be an area marked 'Additional Include Directories'
- Open the dropdown at the end of this line and select edit
- Add a reference to the includes folder from the extracted build you downloaded. This can be a direct reference e.g. (C:/WinsockErrorCodes/includes) or relative to your solution's root folder e.g. (../WinsockErrorCodes/includes)
- Next navigate to the 'Linker' group and find General
- Part way down this group will be an area marked 'Additional Library Directories'
- Open the dropdown at the end of this line and select edit
- Add a reference to the libs folder from the extracted build you downloaded. This can be a direct reference e.g. (C:/WinsockErrorCodes/libs) or relative to your solution's root folder e.g. (../WinsockErrorCodes/libs)
- Also in the linker group, find 'Input'
- Ensure the drop down at the top left says 'Debug', if not, Change it to match
- At the top of this group will be an area marked 'Additional Dependencies'
- Open the dropdown at the end of this line and select edit
- Add 'WinsockErrorCodes-DEBUG.lib' to this list, 
- After adding this, change the drop down at the top left to say 'Release'
- Again at the top of this group will be an area marked 'Additional Dependencies'
- Open the dropdown at the end of this line and select edit
- Add 'WinsockErrorCodes.lib' to this list
- The project should now have everything included correctly. You can close the properties window.

### Using in a project

Include the provided header file as such,

```cpp
#include <WinsockErrorCodes.h>
```

Once included, you can pass 'WSAGetLastError()' codes into WSEC::getWinsockErrorCode(int), which will return a WSEC::ErrorCode object containing all of the available information about that error.

All objects and functions are namespaced under 'WSEC'

```cpp
WSEC::ErrorCode eCode = WSEC::getWinsockErrorCode(WSAGetLastError());
```