#ifndef CST_STRING
	#define CST_STRING
	
#include <iostream>
#include <cstring>

#define STR_LEN 1024

namespace pr {
	class String {
		public:
		char *str;
		
		String();
		String(const char *s);
		~String();
		size_t length ();
		String * newcopy ();
		int compare(String &s);

		
		friend std::ostream& operator << (std::ostream& Stream, const String& s) {
			Stream << s.str;
			return Stream;
		}
		
		friend std::ostream& operator << (std::ostream& Stream, const String *s) {
			Stream << s->str;
			return Stream;
		}
		
		friend std::istream& operator >> (std::istream& Stream, const String& s) {
			Stream >> s.str;
			return Stream;
		}
		
		friend std::istream& operator >> (std::istream& Stream, const String *s) {
			Stream >> s->str;
			return Stream;
		}
		
		friend & String operator = (const String & other) {
			memcpy(this->str, other.str, other.length());
		}
		
		/*
		friend bool & operator == (const String & other) {
			return (this->compare(other) == 0)? true:false;
		}
		
		friend bool & operator > (const String & other) {
			return (this->compare(other) > 0)? true:false;
		}
		
		friend bool & operator < (const String & other) {
			return (this->compare(other) < 0)? true:false;
		}*/
		
	};
	
}

#endif
