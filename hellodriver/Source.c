#include<ntddk.h>

VOID Unload(IN PDRIVER_OBJECT DriverObject)
{
	DbgPrint("driver unload\r\n");
}

NTSTATUS DriverEntry(IN PDRIVER_OBJECT DriverObject, IN PUNICODE_STRING RegistryPath) // это типо майн и тут указатель на объект и на строчку 
// IN - empty macro- input argument, Driver treaten like an object , many members driverunload
{
	//DriverUnload member of DriverObject
	DriverObject->DriverUnload = Unload;



	//NO PRINTF IN KERNEL MODE
	//DbgPrint("hello driver\r\n");//printf
	KdPrint(("driver load so hello \n"));
	return STATUS_SUCCESS;// RETURN TO LOAD in windows 


}