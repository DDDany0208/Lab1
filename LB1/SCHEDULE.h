#ifndef _SCHEDULE_H_
#define _SCHEDULE_H_

#include "ROUTE.h"

#define STANDART_COUNT 8

class SCHEDULE {
public:
	SCHEDULE();
	SCHEDULE(const ROUTE *r, int l);
	SCHEDULE(const SCHEDULE &s);
	~SCHEDULE();

	void operator+=(const ROUTE &r);
	void operator-(int n);

	bool empty();

	friend std::ostream& operator<<(std::ostream& os, const SCHEDULE &s);
	friend std::istream& operator>>(std::istream& is, SCHEDULE &s);
private:
	ROUTE rt[STANDART_COUNT];
	int len;
	void init(
		const ROUTE *r,
		int l
	);
};

#endif
