#pragma once
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
const double PI = acos(-1.0);

class BigInt {
public:
	// 建構函數
	BigInt();
	BigInt(string);
	BigInt(const BigInt&);
	
	// 基本操作
	string get() const;
	bool set(string);
	void print() const;

	// 運算
	BigInt operator + (const BigInt&) const;
	BigInt operator - (const BigInt&) const;
	BigInt operator * (const BigInt&) const;
	BigInt operator / (const BigInt&) const;
	BigInt operator % (const BigInt&) const;
	
	// 邏輯
	bool operator == (const BigInt&) const;
	bool operator != (const BigInt&) const;
	bool operator > (const BigInt&) const;
	bool operator < (const BigInt&) const;
	bool operator >= (const BigInt&) const;
	bool operator <= (const BigInt&) const;
	
	// 賦值
	BigInt& operator = (const BigInt&);
	
	// 輸出/入
	friend ostream& operator << (ostream&, const BigInt&);
	friend istream& operator >> (istream&, BigInt&);
private:
	string num;
};

string toHex(string);
string toDec(string);
BigInt half(BigInt);