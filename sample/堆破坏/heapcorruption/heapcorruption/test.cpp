#include "windows.h"

int main()
{
	HANDLE heap_handle = HeapCreate( NULL , 1024 , 0 ) ;
	char *temp = NULL ;

	char *buffer = (char*)HeapAlloc(heap_handle , NULL , 128) ;
	char *buffer1 = (char*)HeapAlloc(heap_handle , NULL , 121) ;
	//temp = buffer ;    //一般堆内存分配粒度是8 bytes，所以申请128 bytes的内存时是不会有块尾填充部分的
	temp = buffer1;  //buffer1申请了121 bytes，也就是说它有7 bytes的填充字节

	for( int i = 0 ; i < 128 ; ++i )   //当循环次数改为124，那么windbg会中断在HeapDestroy( heap_handle)
	{
		*(temp++) = 'a' ;
	}

	HeapFree(heap_handle, 0 , buffer ) ;
	HeapFree(heap_handle, 0 , buffer1 ) ;
	HeapDestroy( heap_handle) ;
	return 0 ;
}