#include "SCHEDULE.h"

using std::cout;
using std::cin;
using std::endl;

SCHEDULE::SCHEDULE() {
	cout.width(IND);
	cout << "SCHEDULE()" << endl;
	init(nullptr, 0);
}
SCHEDULE::SCHEDULE(const ROUTE *r, int l) {
	cout.width(IND);
	cout << "SCHEDULE(...)" << endl;
	init(r, l);
}
SCHEDULE::SCHEDULE(const SCHEDULE &s) {
	cout.width(IND);
	cout << "SCHEDULE(const SCHEDULE &s)" << endl;
	init(s.rt, s.len);
}
SCHEDULE::~SCHEDULE() {
	cout.width(IND);
	cout << "~SCHEDULE()" << endl;
}

void SCHEDULE::init(
	const ROUTE *r,
	int l
) {
	len = min(l, STANDART_COUNT);
	for (int i = 0; i < len; ++i)
		rt[i] = r[i];
}

void SCHEDULE::operator+=(const ROUTE &r) {
	int i;
	int tmp = 0;
	int n = r.get_N();

	if (len == STANDART_COUNT)
		throw exceptions("the list of routes is full");
	if (!len) {
		rt[len++] = r;
		return;
	}
	for (i = 0; i < len; ++i) {
		if (rt[i].get_N() < n)
			tmp = i;
		if (rt[i].get_N() == n)
			break;
	}
	if (i < len) {
		while (rt[i].get_N() == n) i++;
		for (int j = len - 1; j >= i; --j)
			rt[j + 1] = rt[j];
		rt[i] = r;
	}
	else {
		int j = len - 1;
		do {
			rt[j + 1] = rt[j];
		} while (--j > tmp);
		rt[tmp + 1] = r;
	}
	++len;
}
void SCHEDULE::operator-(int n) {
	if (n < 0 || n >= len)
		throw exceptions("number < \"0\" or number > \"number of ROUTE\"");
	for (int j = n + 1; j < len; ++j)
		rt[j - 1] = rt[j];
	--len;
}

bool SCHEDULE::empty() {
	return ((len) ? false : true);
}
std::ostream& operator<<(std::ostream& os, const SCHEDULE &s) {
	os << "ROUTES:\n";
	for (int i = 0; i < s.len; ++i) {
		os << '\t' << i + 1 << ')' << s.rt[i];
	}
	if (!s.len) os << "\t\tempty!" << endl;
	return os;
}
std::istream& operator>>(std::istream& is, SCHEDULE &s) {
	ROUTE r;
	cin >> r;
	s += r;
	return is;
}
