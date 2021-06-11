#pragma once
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
const double PI = acos(-1.0);

class BigInt {
public:
	// �غc���
	BigInt();
	BigInt(string);
	BigInt(const BigInt&);
	
	// �򥻾ާ@
	string get() const;
	bool set(string);
	void print() const;

	// �B��
	BigInt operator + (const BigInt&) const;
	BigInt operator - (const BigInt&) const;
	BigInt operator * (const BigInt&) const;
	BigInt operator / (const BigInt&) const;
	BigInt operator % (const BigInt&) const;
	
	// �޿�
	bool operator == (const BigInt&) const;
	bool operator != (const BigInt&) const;
	bool operator > (const BigInt&) const;
	bool operator < (const BigInt&) const;
	bool operator >= (const BigInt&) const;
	bool operator <= (const BigInt&) const;
	
	// ���
	BigInt& operator = (const BigInt&);
	
	// ��X/�J
	friend ostream& operator << (ostream&, const BigInt&);
	friend istream& operator >> (istream&, BigInt&);
private:
	string num;
};

string toHex(string);
string toDec(string);
BigInt half(BigInt);