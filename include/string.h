#ifndef __STRING_H__
#define __STRING_H__

#include <stdlib.h>
#include <stdio.h>

struct STRING; 

void Init_String(struct STRING **string);
void Append_Char_Into_String(struct STRING **string,char character);
void Append_Into_String(struct STRING **string,const char *str,size_t str_size);
char * Get_String(struct STRING **string);
void Free_String(struct STRING **string);
unsigned int Get_String_Size(struct STRING **string);
void Pop_Back_From_String(struct STRING **string);
void Empty_String(struct STRING **string);
void Get_Sub_String(struct STRING **string,unsigned int start,unsigned end,
	const unsigned int size,char buffer[size + 1]);
void Replace_Sub_String(struct STRING **string,unsigned start,unsigned end,
	const unsigned int size,char buffer[size]);

#endif
