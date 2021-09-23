#include "string.h"
using namespace pr;
using namespace std;

String::String() {
	char *str;
	if ((str = (char*) malloc(STR_LEN)) == NULL) return;
	str[0] = '\0';
	this->str = str;
}

String::~String() {
	free(this->str);
}

String::String(const char *s) {
	char *str;
	if ((str = (char*) malloc(100)) == NULL) return;
	
	this->str = str;
	if (s[0] != '\0') {
		int len = 0;
		for (int i = 0; s[i] != '\0'; i++)
			len++;
		memcpy(this->str, s, len*8);
		this->str[len] = '\0';
	} else this->str[0] = '\0';
}

String * String::newcopy () {
	String *str = new String(this->str);
	return str;
}

size_t String::length () {
	size_t count = 0;
	for (; this->str[count] != '\0'; count++);
	
	return count;
}

int String::compare(String &s) {
	int len1 = this->length();
	int len2 = s.length();
	int len = (len1 > len2)? len1:len2;
	for (int i = 0; i < len; i++) {
		if (this->str[i] > s.str[i])
			return len1-i+1;
		if (this->str[i] < s.str[i])
			return len2-i+1;
	}
	
	if (len1 != len2) return len1-len2;
	return 0;
}











