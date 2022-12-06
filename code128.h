

#ifndef CODE128_H
#define CODE128_H

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

// Since the FNCn characters are not ASCII, define versions here to
// simplify encoding strings that include them.
#define CODE128_FNC1 '\xf1'
#define CODE128_FNC2 '\xf2'
#define CODE128_FNC3 '\xf3'
#define CODE128_FNC4 '\xf4'

size_t code128_estimate_len(const char *s);
size_t code128_encode_gs1(const char *s, char *out, size_t maxlength);
size_t code128_encode_raw(const char *s, char *out, size_t maxlength);

#ifdef __cplusplus
}
#endif

#endif // CODE128_H
