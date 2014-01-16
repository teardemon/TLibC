#ifndef _H_TLIBC_ERROR_CODE
#define _H_TLIBC_ERROR_CODE

#include "platform/tlibc_platform.h"

typedef enum _TLIBC_ERROR_CODE
{
    E_TLIBC_NOERROR = 0,
    E_TLIBC_ERROR = -1,
	E_TLIBC_IGNORE = -2,
    E_TLIBC_OUT_OF_MEMORY = -3,
	E_TLIBC_CAN_NOT_OPEN_FILE = -4,
	E_TLIBC_XML_SYNTAX_ERROR = -5,
	E_TLIBC_XML_TAG_MISMATCH = -6,
	E_TLIBC_XML_CONTENT_CONVERT_ERROR = -7,
}TLIBC_ERROR_CODE;

#define TLIBC_ERROR_CODE_NUM 15

#endif
