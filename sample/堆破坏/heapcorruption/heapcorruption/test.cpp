#include "windows.h"

int main()
{
	HANDLE heap_handle = HeapCreate( NULL , 1024 , 0 ) ;
	char *temp = NULL ;

	char *buffer = (char*)HeapAlloc(heap_handle , NULL , 128) ;
	char *buffer1 = (char*)HeapAlloc(heap_handle , NULL , 121) ;
	//temp = buffer ;    //һ����ڴ����������8 bytes����������128 bytes���ڴ�ʱ�ǲ����п�β��䲿�ֵ�
	temp = buffer1;  //buffer1������121 bytes��Ҳ����˵����7 bytes������ֽ�

	for( int i = 0 ; i < 128 ; ++i )   //��ѭ��������Ϊ124����ôwindbg���ж���HeapDestroy( heap_handle)
	{
		*(temp++) = 'a' ;
	}

	HeapFree(heap_handle, 0 , buffer ) ;
	HeapFree(heap_handle, 0 , buffer1 ) ;
	HeapDestroy( heap_handle) ;
	return 0 ;
}