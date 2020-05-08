#include<iostream> 
#include <JavaScriptCore/JavaScript.h>
#include<string>
#pragma once

using namespace std;


string JSStringToStdString(JSStringRef jsString) {
    size_t maxBufferSize = JSStringGetMaximumUTF8CStringSize(jsString);
    char* utf8Buffer = new char[maxBufferSize];
    size_t bytesWritten = JSStringGetUTF8CString(jsString, utf8Buffer, maxBufferSize);
    std::string utf_string = std::string(utf8Buffer, bytesWritten -1);
    delete [] utf8Buffer;
    return utf_string;
}