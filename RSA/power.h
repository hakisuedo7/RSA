#pragma once
#include "BigInt.h"

inline bool isodd(BigInt b) {
	string s = b.get();
	return s[s.length() - 1] % 2;
}

// a ^ b % m
inline BigInt power(BigInt a, BigInt b, BigInt m) {
	if (b == BigInt("0"))
		return BigInt("1");
	if (b == BigInt("1"))
		return a % m;
	BigInt hb = half(b);
	BigInt phb = power(a, hb, m);
	BigInt res = (phb * phb) % m;
	if (isodd(b))
		res = (a * res) % m;
	return res;
}