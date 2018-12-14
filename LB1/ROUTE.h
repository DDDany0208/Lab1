#ifndef _ROUTE_H_
#define _ROUTE_H_

#include <iostream>
#include "string.h"
#include "exceptions.h"

class ROUTE {
public:
	ROUTE();
	ROUTE(
		const char* s,
		const char* e,
		int n);
	ROUTE(const ROUTE &r);
	~ROUTE();

	void set_S(const char* s);
	void set_E(const char* e);
	void set_N(int n);

	const char* get_S();
	const char* get_E();
	int get_N() const;

	ROUTE& operator=(const ROUTE &r);
	friend std::ostream& operator<<(std::ostream& os, const ROUTE &st);
	friend std::istream& operator>>(std::istream& is, ROUTE &st);
private:
	char *start;
	char *end;
	int num;
	void init();
};

#endif
