#define SWAP_NIBBLE(a) ((((a) >> 4) & 0x0f) | (((a) << 4) & 0xf0))

#define max(a,b)           \
({                         \
	__typeof__ (a) _a = (a); \
	__typeof__ (b) _b = (b); \
	_a > _b ? _a : _b;       \
})

#define min(a,b)           \
({                         \
	__typeof__ (a) _a = (a); \
	__typeof__ (b) _b = (b); \
	_a < _b ? _a : _b;       \
})

#define xchange(a, b, tmp) \
({                         \
	tmp = a;                 \
	a = b;                   \
	b = tmp;                 \
})

#define ROUND_TO_2(a) (((a) / 2) * 2)

extern void debug_string(char *s, int max_string);
