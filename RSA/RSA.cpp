#include "RSA.h"

string primes[24] = { "3","5","7","11","13","17","19","23","29","31","37","41","43","47","53","59","61","67","71","73","79","83","89","97" };
string randb[10] = { "5","9","21","1227","1357","47","67","89","97","111" };

bool test(BigInt b) {
	if (b == BigInt("2")) return true;
	if (!isodd(b)) return false;
	int j = 0;
	for (int i = 0; i < 24; i++)
		if (b % BigInt(primes[i]) == BigInt("0"))
			return false;
	BigInt m = b - BigInt("1");
	while (!isodd(m)) {
		j++;
		m = half(m);
	}
	for (int i = 0; i < 5; i++)
	{
		BigInt k(randb[i]);
		BigInt v = power(k, m, b);
		if (v == BigInt("1")) continue;
		BigInt testnum = b - BigInt("1");
		int n = 1;
		while (true) {
			if (v == testnum) break;
			if (n == j) return false;
			v = (v * v) % b;
			n++;
		}

	}
	return true;
}

RSA::RSA() {
	clock_t start, finish;
	cout << "Creating RSA...\nGenerating p and q..." << endl;
	start = clock();
	p = CreatePrime();
	do {
		q = CreatePrime();
	} while (p == q);
	finish = clock();
	cout << "Generate p and q cost: " << finish - start << endl;

	N = p * q;
	r = (p - BigInt("1")) * (q - BigInt("1"));

	cout << "Generating d and e..." << endl;
	start = clock();
	d = BigInt("3");
	while (gcd(d, r) != BigInt("1"))
		d = d + BigInt("2");
	e = inv(d, r);
	finish = clock();
	cout << "Generate d and e cost: " << finish - start << endl;
}

void RSA::Info() {
	cout << "p =\t" << p << endl;
	cout << "q =\t" << q << endl;
	cout << "N =\t" << N << endl;
	cout << "£p(n) =\t" << r << endl;
	cout << "e =\t" << e << endl;
	cout << "d =\t " << d << endl;
}

BigInt RSA::Encrypt(BigInt plaintext) {
	return power(plaintext, e, N);
}

BigInt RSA::Decrypt(BigInt ciphertext) {
	return power(ciphertext, d, N);
}

BigInt RSA::CreatePrime() {
	BigInt max("13407807929942597099574024998205846127479365820592393377723561443721764030073546976801874298166903427690031858186486050853753882811946569946433649006084096");
	while (true) {
		BigInt b = random(KEY_LEN);
		for (; b < max; b = b + BigInt("2"))
			if (test(b)) return b;
	}
	return BigInt();
}