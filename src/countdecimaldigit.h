#pragma once

inline unsigned CountDecimalDigit32(uint32_t n) {
	static const uint32_t powers_of_10[] = {
		0,
		10,
		100,
		1000,
		10000,
		100000,
		1000000,
		10000000,
		100000000,
		1000000000
	};

	unsigned long i = 0;
	//	uint32_t t = (32 - __builtin_clz(n | 1)) * 1233 >> 12;
	_BitScanReverse(&i, n | 1);
	uint32_t t = (i + 1) * 1233 >> 12;
	return t - (n < powers_of_10[t]) + 1;
}

inline unsigned CountDecimalDigit64(uint64_t n) {
	static const uint64_t powers_of_10[] = {
		0,
		10,
		100,
		1000,
		10000,
		100000,
		1000000,
		10000000,
		100000000,
		1000000000,
		10000000000,
		100000000000,
		1000000000000,
		10000000000000,
		100000000000000,
		1000000000000000,
		10000000000000000,
		100000000000000000,
		1000000000000000000,
		10000000000000000000U
	};

	unsigned long i = 0;
	//	uint32_t t = (32 - __builtin_clz(n | 1)) * 1233 >> 12;

#if _M_IX86
	uint64_t m = n | 1;
	if (_BitScanReverse(&i, m >> 32))
		i += 32;
	else
		_BitScanReverse(&i, m & 0xFFFFFFFF);
#elif _M_X64
	_BitScanReverse64(&i, n | 1);
#else
#error
#endif

	uint32_t t = (i + 1) * 1233 >> 12;
	return t - (n < powers_of_10[t]) + 1;
}
