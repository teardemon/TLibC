#ifndef _H_TLIBC_NUMBER
#define _H_TLIBC_NUMBER

#include "platform/tlibc_platform.h"



#define TLIBC_MAX_VARIANT_DECODE_LENGTH 10


#define tlibc_swap16(x) (\
	((x & 0x00ff) << 8) | \
	((x & 0xff00) >> 8)  \
	)


#define tlibc_swap32(x) (\
	((x & 0x000000ff) << 24) | \
	((x & 0x0000ff00) << 8) | \
	((x & 0x00ff0000) >> 8) | \
	((x & 0xff000000) >> 24)  \
	)

#define tlibc_swap64(x) (\
	((x & (tuint64)0x00000000000000ffLL) << 56) | \
	((x & (tuint64)0x000000000000ff00LL) << 40) | \
	((x & (tuint64)0x0000000000ff0000LL) << 24) | \
	((x & (tuint64)0x00000000ff000000LL) << 8) | \
	((x & (tuint64)0x000000ff00000000LL) >> 8) | \
	((x & (tuint64)0x0000ff0000000000LL) >> 24) | \
	((x & (tuint64)0x00ff000000000000LL) >> 40) | \
	((x & (tuint64)0xff00000000000000LL) >> 56)  \
	)

#if TLIBC_BYTE_ORDER == TLIBC_LITTLE_ENDIAN 
	#define tlibc_ntoh16(x) tlibc_swap16(x)
	#define tlibc_ntoh32(x) tlibc_swap32(x)
	#define tlibc_ntoh64(x) tlibc_swap64(x)
	#define tlibc_hton16(x) tlibc_swap16(x)
	#define tlibc_hton32(x) tlibc_swap32(x)
	#define tlibc_hton64(x) tlibc_swap64(x)

	#define tlibc_little_to_host16(x) (x)
	#define tlibc_little_to_host32(x) (x)
	#define tlibc_little_to_host64(x) (x)
	#define tlibc_host16_to_little(x) (x)
	#define tlibc_host32_to_little(x) (x)
	#define tlibc_host64_to_little(x) (x)
#endif

#if TLIBC_BYTE_ORDER == TLIBC_BIG_ENDIAN
	#define tlibc_ntoh16(x) (x) 
	#define tlibc_ntoh32(x) (x)
	#define tlibc_ntoh64(x) (x)
	#define tlibc_hton16(x) (x) 
	#define tlibc_hton32(x) (x)
	#define tlibc_hton64(x) (x)

	#define tlibc_little_to_host16(x) tlibc_swap16(x)
	#define tlibc_little_to_host32(x) tlibc_swap32(x)
	#define tlibc_little_to_host64(x) tlibc_swap64(x)
	#define tlibc_host16_to_little(x) tlibc_swap16(x)
	#define tlibc_host32_to_little(x) tlibc_swap32(x)
	#define tlibc_host64_to_little(x) tlibc_swap64(x)
#endif



#define tlibc_zigzag_encode16(n) ((tuint16)(((tint16)n << 1) ^ ((tint16)n >> 15)))
#define tlibc_zigzag_encode32(n) ((tuint32)(((tint32)n << 1) ^ ((tint32)n >> 31)))
#define tlibc_zigzag_encode64(n) ((tuint64)(((tint64)n << 1) ^ ((tint64)n >> 63)))

#define tlibc_zigzag_decode16(n) ((tint16)((n >> 1) ^ -(tint16)(n & 1)))
#define tlibc_zigzag_decode32(n) ((tint32)((n >> 1) ^ -(tint32)(n & 1)))
#define tlibc_zigzag_decode64(n) ((tint64)((n >> 1) ^ -(tint64)(n & 1)))

#endif

