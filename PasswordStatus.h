#pragma once
#include <cstring>
class PasswordStatus
{
private:
	const char* password;
	int minLength = 6 ;
public:
	
	char find;

	PasswordStatus(const char* Narray, int minSize) :password(Narray), minLength(minSize) {
		if (minSize < 0) {
			minSize = 6;
		}

	}
	//char getPassword();

	~PasswordStatus();

	bool isValid();
	bool sufficientLength();
	bool hasUpperCase();
	bool hasLowerCase();
	bool hasDigit();
};

