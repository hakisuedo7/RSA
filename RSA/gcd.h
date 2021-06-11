#pragma once
#include "BigInt.h"

inline BigInt gcd(BigInt a, BigInt b) {
	if (a > b) return gcd(b, a);
	if (a == BigInt("0")) return b;
	return gcd(b % a, a);
}

inline void extendedEuclidean(BigInt a, BigInt b, BigInt& x, BigInt& y, const BigInt& m) {
    if (a == BigInt("0")) {
        x = BigInt("0"), y = BigInt("1");
        return;
    }
    BigInt c = b / a, d = b % a;
    extendedEuclidean(d, a, y, x, m);
    x = (x + m - (c * y) % m) % m;  //to prevent an sub overflow
}

inline BigInt inv(BigInt a, BigInt mod) {
    if (!(gcd(a, mod) == BigInt("1"))) return BigInt("0");
    BigInt x, y;
    a = a % mod;
    extendedEuclidean(a, mod, x, y, mod);
    return x;
}