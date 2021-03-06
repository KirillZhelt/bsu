#include "stdafx.h"

#include "processor_info.h"
#include "..\copy_to_buffer\copy_to_buffer.h"

#include <iostream>

const char* author = "Bjarne Stroustrup";
const char* description = "Prints information about the processor";

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

	const char* processor_architecture;

	switch (system_info.wProcessorArchitecture)
	{
	case PROCESSOR_ARCHITECTURE_AMD64:
		processor_architecture = "x64 (AMD or Intel)";
		break;
	case PROCESSOR_ARCHITECTURE_ARM:
		processor_architecture = "ARM";
		break;
	case PROCESSOR_ARCHITECTURE_ARM64:
		processor_architecture = "ARM64";
		break;
	case PROCESSOR_ARCHITECTURE_IA64:
		processor_architecture = "Intel Itanium-based";
		break;
	case PROCESSOR_ARCHITECTURE_INTEL:
		processor_architecture = "x86";
		break;
	default:
		processor_architecture = "Unknown architecture";
	}

	std::cout << "processor architecture: " << processor_architecture << std::endl <<
		"number of processors: " << 
		system_info.dwNumberOfProcessors;
}
