set PATH=%PATH%;C:\Program Files\7-Zip\

ECHO F|xcopy WinsockErrorCodes\WinsockErrorCodes.h tmp\include\WinsockErrorCodes.h
ECHO F|xcopy Debug\WinsockErrorCodes.lib tmp\lib\WinsockErrorCodes-DEBUG.lib
ECHO F|xcopy Release\WinsockErrorCodes.lib tmp\lib\WinsockErrorCodes.lib
ECHO D|xcopy Docs\* tmp\*

ECHO F|xcopy WinsockErrorCodes\WinsockErrorCodes.h tmp64\include\WinsockErrorCodes.h
ECHO F|xcopy x64\Debug\WinsockErrorCodes.lib tmp64\lib\WinsockErrorCodes-DEBUG.lib
ECHO F|xcopy x64\Release\WinsockErrorCodes.lib tmp64\lib\WinsockErrorCodes.lib
ECHO D|xcopy Docs\* tmp64\*

cd tmp
7za a -tzip tmp.zip *
cd ../

cd tmp64
7za a -tzip tmp64.zip *
cd ../

xcopy tmp\tmp.zip WinsockErrorCodes-x86.zip*
xcopy tmp64\tmp64.zip WinsockErrorCodes-x64.zip*

rmdir /S /Q tmp;
rmdir /S /Q tmp64;