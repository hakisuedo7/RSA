#include "RSA.h"

int main() {
	setRandom(time(NULL));
	RSA rsa;
	string input;
	BigInt plaintext, ciphertext;
	clock_t start, finish;
	rsa.Info();

	cout << "Please input the plaintext:(eg.1123)" << endl;
	cin >> input;

	cout << '\n' << "---------------------Encryption--------------------" << endl;
	start = clock();
	ciphertext = rsa.Encrypt(BigInt(input));
	finish = clock();
	cout << "CipherText: " << ciphertext << endl;
	cout << "Encrypt cost: " << finish - start << endl;

	cout << "\n\n" << "--------------------Dencryption--------------------" << endl;
	start = clock();
	plaintext = rsa.Decrypt(ciphertext);
	finish = clock();
	cout << "Plaintext: " << plaintext << endl;
	cout << "Decrypt cost: " << finish - start << endl;

	return 0;
}