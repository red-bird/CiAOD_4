#define _CRT_SECURE_NO_WARNINGS
#include "FileAPI.h"

using namespace std;

enum Code
{
	Convert = 1,
	Print,
	Find,
	Update,
	Stop
};

int main() {
	setlocale(LC_ALL, "ru");
	FileAPI api;
	string key, adress, fullName;

	cout << "variant 18, input data: telephone(10 nums) - key, adress, fullname\n";
	cout << "------------------------------------------------------------\nEnter code number to do action:\n1) Convert txt file to binary\n2) Print binary file in ASCII\n3) Search data by key\n4) Update data by key\n5) Stop program\n------------------------------------------------------------\n";
	int code;
	while (true)
	{
		cin >> code;
		switch (code)
		{
		case(Convert):
			api.convertToBinary();
			break;
		case(Print):
			api.printFileData();
			break;
		case(Find):
			cout << "Enter key(telephone num)\n";
			cin >> key;
			if (key.length() < 10) { cout << "wrong key\n"; break; }
			api.findByKey(key);
			break;
		case(Update):
			cout << "Enter key(telephone num), adress and fullname (divided by space)\n";
			cin >> key;
			if (key.length() < 10) { cout << "wrong key\n"; break; }
			cin >> adress >> fullName;
			api.updateByKey(key, adress, fullName);
			break;
		case(Stop):
			cout << "Stop program\n";
			return 0;
		default:
			cout << "something gone wrong.. stop\n";
			return -1;
		}
	}
}