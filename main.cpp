#include "string.h"

using namespace pr;
using namespace std;

int main () {
	String *str = new String("Hello World !");
	size_t len = str->length();
	cout << str << " et taille : " << str->length() << endl;
	String *s = str->newcopy();
	cout << s << endl;
	cout << str->compare(*s) << endl;
	str->~String();
	s->~String();
}
