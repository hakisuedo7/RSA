#pragma once
#include <ctime>
#include <random>
#include "BigInt.h"

inline void setRandom(unsigned seed) {
	srand(seed);
}

inline BigInt random(int len) {
	if (len == 0) return BigInt("0");
	if (len == 1) return BigInt("1");
	BigInt x("1");
	for (int i = 1; i < len; i++)
		x = x * BigInt("2");
	string s(len, '0');
	for (int i = 0; i < s.length(); i++)
		s[i] += rand() % 10;
	BigInt res = BigInt(s) % x + x;
	if (res % BigInt("2") == BigInt("0"))
		return res + BigInt("1");
	else
		return res;
}