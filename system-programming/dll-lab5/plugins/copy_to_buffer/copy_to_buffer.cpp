#include "stdafx.h"

#include "copy_to_buffer.h"

BOOLEAN __stdcall CopyToBuffer(LPSTR buffer, const char* info, DWORD dwBufferSize, DWORD* pdwBytesWritten)
{
	if (strlen(info) + 1 <= dwBufferSize)
	{
		strcpy(buffer, info);

		*pdwBytesWritten = strlen(info) + 1;
		return (TRUE);
	}

	*pdwBytesWritten = 0;
	return (FALSE);
}
