#include "ROUTE.h"

using std::cout;
using std::cin;
using std::endl;


ROUTE::ROUTE() {
	cout.width(IND);
	cout << "ROUTE()" << endl;
	init();
}
ROUTE::ROUTE(
	const char* s,
	const char* e,
	int n) {
	cout.width(IND);
	cout << "ROUTE(...)" << endl;
	init();
	set_S(s);
	set_E(e);
	set_N(n);
}
ROUTE::ROUTE(const ROUTE &st) {
	cout.width(IND);
	cout << "ROUTE(const ROUTE &r)" << endl;
	init();
	set_S(st.start);
	set_E(st.end);
	set_N(st.num);
}

ROUTE::~ROUTE() {
	cout.width(IND);
	cout << "~ROUTE()" << endl;
	delete[] start;
	delete[] end;
}

void ROUTE::init() {
	start = nullptr;
	end = nullptr;
	num = 0;
}

void ROUTE::set_S(const char* s) {
	int size = strlen(s);
	delete[] start;
	start = nullptr;
	if (size++) {
		start = new char[size];
		strcpy(start, s, size);
	}
}
void ROUTE::set_E(const char* e) {
	int size = strlen(e);
	delete[] end;
	end = nullptr;
	if (size++) {
		end = new char[size];
		strcpy(end, e, size);
	}
}
void ROUTE::set_N(int n) {
	num = n;
}

const char* ROUTE::get_S() {
	return start;
}
const char* ROUTE::get_E() {
	return end;
}
int ROUTE::get_N() const {
	return num;
}

ROUTE& ROUTE::operator=(const ROUTE &r) {
	if (this != &r) {
		set_S(r.start);
		set_E(r.end);
		set_N(r.num);
	}
	return *this;
}

std::istream& operator>>(std::istream& is, ROUTE &st) {
	char *s;
	char *e;
	int n;
	s = read("Enter starting point: ");
	e = read("Enter final point: ");
	cout << "Enter number of route: ";
	is >> n;
	cin.get();
	if (n < 1)
		throw exceptions("route number < 1");
	st.set_S(s);
	st.set_E(e);
	st.set_N(n);
	delete[] s;
	delete[] e;
	return is;
}

std::ostream& operator<<(std::ostream& os, const ROUTE &st) {
	os
		<< "Starting point: " << st.start
		<< ", final point: " << st.end
		<< ", number of route: " << st.num << endl;
	return os;
}
