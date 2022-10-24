#include "include/string.h"

#define __DEFAULT_MAX_STRING_SIZE__ 10
#define __INCREAMENTAL_BUFFER_SIZE__ 10
#define __STRING_INTERNAL_MIN_SIZE__ 1
#define __EOF_CHAR__ '\0'

struct STRING {
	unsigned int pos;
	unsigned int max_size;
	char *buffer;
	size_t size;
};

void Init_String(struct STRING **string) {
	*string = (struct STRING *)malloc(sizeof(struct STRING));
	(*string)->buffer = (char *)malloc(sizeof(char) * __DEFAULT_MAX_STRING_SIZE__);	
	(*string)->buffer[0] = __EOF_CHAR__;
	(*string)->size = __STRING_INTERNAL_MIN_SIZE__ , (*string)->pos = 0;
	(*string)->max_size = __DEFAULT_MAX_STRING_SIZE__;
}

void Append_Char_Into_String(struct STRING **string,char character) {
	if((*string)->size == (*string)->max_size)
		realloc((*string)->buffer,
			sizeof(char) * ((*string)->size + __INCREAMENTAL_BUFFER_SIZE__));
	(*string)->buffer[(*string)->pos] = character;
	++(*string)->pos;
	++(*string)->size;
	(*string)->buffer[(*string)->pos] = __EOF_CHAR__;		
}

char * Get_String(struct STRING **string) {
	return (*string)->buffer;
}

void Free_String(struct STRING **string) {
	free((*string)->buffer);
	free((*string));
}

void Append_Into_String(struct STRING **string,const char *str,size_t str_size) {
	for(size_t index = 0;index < str_size;index++) {
		Append_Char_Into_String(&(*string),str[index]);
	}	
}

unsigned int Get_String_Size(struct STRING **string) {
	return (*string)->pos;
}

void Pop_Back_From_String(struct STRING **string) {
	if((*string)->size > __STRING_INTERNAL_MIN_SIZE__) {
		(*string)->buffer[(*string)->pos - 1] = __EOF_CHAR__;
		--(*string)->pos;
		--(*string)->size;	
	}
}

void Empty_String(struct STRING **string) {
	realloc((*string)->buffer,__DEFAULT_MAX_STRING_SIZE__);
	(*string)->buffer[0] = __EOF_CHAR__;
	(*string)->size = __STRING_INTERNAL_MIN_SIZE__;
	(*string)->pos = 0;
	(*string)->max_size = __DEFAULT_MAX_STRING_SIZE__;	
}

void Get_Sub_String(struct STRING **string,unsigned int start,unsigned int end,
	const unsigned int size,char buffer[size + 1]) {
	if(end - start == size) {
		unsigned int _index = 0;
		for(unsigned int index = start;index < end;index++) {
			buffer[_index++] = (*string)->buffer[index];	
		}
		buffer[_index] = __EOF_CHAR__;
	}
}

void Replace_Sub_String(struct STRING **string,unsigned int start, 
	unsigned int end,const unsigned int size,char buffer[size]) {
	if(end - start== size && end <= (*string)->pos) {	
		for(unsigned int index = 0;index < size;index++) {
			(*string)->buffer[start++] = buffer[index];	
		}		
	}
}
