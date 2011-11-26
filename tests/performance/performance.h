#define REPEAT 40

#define repeat(code) \
	do \
	{ \
		int __repeat_i; \
		for (__repeat_i = 0; __repeat_i != REPEAT; ++__repeat_i) \
		{ \
			code; \
		} \
	} while (0)
