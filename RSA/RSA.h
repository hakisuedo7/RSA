#pragma once
#include "BigInt.h"
#include "gcd.h"
#include "power.h"
#include "random.h"
#define KEY_LEN 128

class RSA {
public:
	RSA();
	void Info();
	BigInt Encrypt(BigInt);
	BigInt Decrypt(BigInt);
private:
	BigInt CreatePrime();
	
	BigInt p;	// prime1
	BigInt q;	// prime2
	BigInt N;	// N = p * q
	BigInt r;	// r = £p(n) = (p-1)(q-1);

	BigInt e;	// public key
	BigInt d;	// private key
};
