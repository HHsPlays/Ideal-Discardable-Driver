#pragma once
#include <ntddk.h>

#pragma optimize( "", off ) // Turn off optimisations for this function, otherwise it will get optimised into the INIT section
void TextSectionFunction()
{
	DbgPrintEx(0, 0, "[+] Hello from the .text section\n"); // By default the compiler will put executable code into the .text section
}
#pragma optimize( "", on ) // Turn optimisations back on

__declspec(code_seg("INIT")) NTSTATUS DriverEntry() // Put this function into the INIT section (you can use any discardable section)
{
	DbgPrintEx(0, 0, "[+] Hello from the INIT section\n");

	TextSectionFunction();

	return STATUS_SUCCESS;
}

// You can verify that everything has worked using a disassembler