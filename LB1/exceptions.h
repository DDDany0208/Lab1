#ifndef EXCEPTIONS_H_
#define EXCEPTIONS_H_

#include <iostream>
#include "string.h"
#define IND 30

class exceptions {
public:
	exceptions();
	exceptions(const char*);
	exceptions(exceptions&);
	exceptions(exceptions&&);
	~exceptions();
	const char* what();
private:
	char *mesg;
};

#endif
