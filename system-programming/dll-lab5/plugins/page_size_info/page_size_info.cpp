#include "stdafx.h"

#include "page_size_info.h"
#include "..\copy_to_buffer\copy_to_buffer.h"

#include <iostream>

const char* author = "Guido van Rossum";
const char* description = "Prints system page size";

BOOLEAN __stdcall GetAuthor(LPSTR buffer, DWORD dwBufferSize, DWORD* pdwBytesWritten)
{
	return CopyToBuffer(buffer, author, dwBufferSize, pdwBytesWritten);
}

BOOLEAN __stdcall GetDescription(LPSTR buffer, DWORD dwBufferSize, DWORD* pdwBytesWritten)
{
	return CopyToBuffer(buffer, description, dwBufferSize, pdwBytesWritten);
}

VOID __stdcall Execute()
{
	// https://docs.microsoft.com/en-us/windows/desktop/api/sysinfoapi/nf-sysinfoapi-getsysteminfo
	SYSTEM_INFO system_info;
	GetSystemInfo(&system_info);

	std::cout << "page size: " << system_info.dwPageSize;
}
