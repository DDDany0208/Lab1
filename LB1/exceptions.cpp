#include "exceptions.h"

using std::cout;
using std::cin;
using std::endl;

exceptions::exceptions() : mesg(nullptr) {
	cout.width(IND);
	cout << "exceptions()" << endl;
}
exceptions::exceptions(const char* s) {
	cout.width(IND);
	cout << "exceptions(...)" << endl;
	int	n = strlen(s);
	mesg = nullptr;
	if (n++) {
		mesg = new char[n];
		strcpy(mesg, s, n);
	}
}
exceptions::exceptions(exceptions &e) {
	cout.width(IND);
	cout << "exceptions(exceptions&)" << endl;
	int	n = strlen(e.mesg) + 1;
	mesg = new char[n];
	strcpy(mesg, e.mesg, n);
}

exceptions::exceptions(exceptions &&e) {
	cout.width(IND);
	cout << "exceptions(exceptions&&)" << endl;
	mesg = e.mesg;
	e.mesg = nullptr;
}
exceptions::~exceptions() {
	cout.width(IND);
	cout << "~exceptions()" << endl;
	delete[] mesg;
}
const char* exceptions::what() {
	return mesg;
}
