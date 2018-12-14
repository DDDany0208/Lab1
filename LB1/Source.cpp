#include "SCHEDULE.h"

using std::cout;
using std::cin;
using std::endl;

int main() {
	int ch;
	bool flag = true;
	SCHEDULE s;
	while (flag) {
		cout
			<< "1. Add route" << endl
			<< "2. Remove route" << endl
			<< "3. Show route" << endl
			<< "4. Exit" << endl;
		cout << "Enter: ";
		cin >> ch;
		cin.get();
		switch (ch) {
		case 1:
			try {
				cin >> s;
			}
			catch (exceptions &e) {
				cout << "Error: " << e.what() << endl;
			}
			break;
		case 2:
			cout << s;
			if (!s.empty()) {
				cout << "Enter: ";
				cin >> ch;
				cin.get();
				try {
					s - --ch;
					cout << "\tSuccess" << endl;
				}
				catch (exceptions &e) {
					cout << "Error: " << e.what() << endl;
				}
			}
			break;
		case 3:
			cout << s;
			break;
		case 4:
			flag = false;
			break;
		}
	}
	return 0;
}
