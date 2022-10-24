#ifndef __TOKEN_H__
#define __TOKEN_H__

#include "string.h"

enum TOKEN_TYPE {
	NO_INSTRUCTION	
};

struct TOKEN {
	struct STRING *token_value;
	enum TOKEN_TYPE token_type;	
};

#endif
