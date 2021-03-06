#include "stdafx.h"

#include "disk_space_info.h"
#include "..\copy_to_buffer\copy_to_buffer.h"

#include <iostream>

const char* author = "Dennis Ritchie";
const char* description = "Prints information about free space on a disk";

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
	// https://docs.microsoft.com/en-us/windows/desktop/api/fileapi/nf-fileapi-getdiskfreespaceexa
	
	ULARGE_INTEGER free_bytes_available_to_caller, total_number_of_bytes, total_number_of_free_bytes;

	if (GetDiskFreeSpaceExA(NULL, &free_bytes_available_to_caller, &total_number_of_bytes, 
		&total_number_of_free_bytes)  == (TRUE))
	{
		std::cout << "The total number of free bytes on a disk that are available to the user: " << free_bytes_available_to_caller.QuadPart << std::endl << 
			"The total number of bytes on a disk that are available to the user: " << total_number_of_bytes.QuadPart << std::endl << 
			"the total number of free bytes on a disk: " << total_number_of_free_bytes.QuadPart;
	}
	else
	{
		std::cout << "An error occured while retrieving information about disk space" << std::endl;
	}

}
