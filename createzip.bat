set PATH=%PATH%;C:\Program Files\7-Zip\

ECHO F|xcopy WinsockErrorCodes\WinsockErrorCodes.h tmp\include\WinsockErrorCodes.h
ECHO F|xcopy Debug\WinsockErrorCodes.lib tmp\lib\WinsockErrorCodes-DEBUG.lib
ECHO F|xcopy Release\WinsockErrorCodes.lib tmp\lib\WinsockErrorCodes.lib
ECHO D|xcopy Docs\* tmp\*

cd tmp
7za a -tzip tmp.zip *
cd ../

xcopy tmp\tmp.zip WinsockErrorCodes.zip*

rmdir /S /Q tmp;