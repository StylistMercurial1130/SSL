#include <stdio.h>
#include "include/string.h"

int main(int argc,char **argv) {
	struct STRING *str;
	Init_String(&str);
	Append_Into_String(&str,"helloworld!",11);	
	char buffer[4];
	Get_Sub_String(&str,0,3,3,buffer);
	printf("substring : %s \n",buffer);
	printf("original string : %s \n",Get_String(&str));
	Free_String(&str);
}
