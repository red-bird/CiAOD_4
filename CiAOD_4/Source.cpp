#define _CRT_SECURE_NO_WARNINGS
#include "FileAPI.h"

using namespace std;

enum Code
{
	Convert = 1,
	Print,
	Find,
	Update,
	Delete,
	Stop
};

struct Record {
	string key = "";
	string adress = "";
	string fullName = "";
};

int main() {
	setlocale(LC_ALL, "ru");
	FileAPI api;
	Record record;

	cout << "variant 18, input data: telephone(10 nums) - key, adress, fullname\n";
	cout << "------------------------------------------------------------\nEnter code number to do action:\n";
	cout << "1) Convert txt file to binary\n2) Print binary file in ASCII\n3) Search data by key\n4) Update data by key\n";
	cout << "5) Delete binary file\n6) Stop program\n------------------------------------------------------------\n";
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
			cin >> record.key;
			if (record.key.length() < 10) { cout << "wrong key\n"; break; }
			api.findByKey(record.key);
			break;
		case(Update):
			cout << "Enter key(telephone num), adress and fullname (divided by space)\n";
			cin.ignore();
			getline(cin, record.key);
			if (record.key.length() < 10) { cout << "wrong key\n"; break; }
			getline(cin, record.adress);
			getline(cin, record.fullName);
			api.updateByKey(record.key, record.adress, record.fullName);
			break;
		case(Delete):
			if (remove("output.bin")) { cout << "can't remove\n"; }
			else cout << "Deleted!\n";
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