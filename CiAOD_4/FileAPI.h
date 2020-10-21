#pragma once
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

class FileAPI
{
private:
	char buffer[0];

	bool checkKey(string key, string line) {
		int i = 0;
		for (i; i < 10; ++i)
		{
			if (key[i] != line[i]) { break; }
		}
		return i == 10;
	}

public:
	void convertToBinary() {
		FILE* input, * output;
		input = fopen("input.txt", "r");
		output = fopen("output.bin", "w");
		if ((input != NULL) && (output != NULL))
		{
			while (!feof(input))
			{
				fread(buffer, 1, 1, input);
				fwrite(buffer, 1, 1, output);
			}
			fclose(output);
			fclose(input);
			cout << "Converted!\n";
		}
		else
			cout << "Can't find text file\n";
	}

	void printFileData() {
		FILE* input;
		input = fopen("output.bin", "r");
		if (input != NULL)
		{
			cout << "Binary file:\n";
			while (!feof(input))
			{
				fread(buffer, 1, 1, input);
				cout << buffer[0];
			}
			fclose(input);
			cout << "\nEnd!\n";
		}
		else
			cout << "Can't find binary file\n";
	}

	void findByKey(string key) {
		string line;
		ifstream input("output.bin");
		if (!input.is_open())
			cout << "Can't find binary file\n";
		else
		{
			cout << "Results of search:\n";
			while (!input.eof())
			{
				getline(input, line);
				if (checkKey(key, line)) { cout << line << endl; }
			}
			cout << "End!\n";
			input.close();
		}
	}

	void updateByKey(string key, string adress, string fullName) {
		string line;
		ifstream input("output.bin");
		ofstream output("output2.bin");
		bool checker = false;
		if (!input.is_open())
			cout << "Can't find binary file\n";
		else
		{
			while (!input.eof())
			{
				getline(input, line);
				if (!checkKey(key, line)) { output << line << "\n"; }
				else {
					output << key << " " << adress << " " << fullName << "\n";
					checker = true;
				}
			}
			input.close();
			output.close();

			if (remove("output.bin")) { cout << "can't remove\n"; }
			else if (rename("output2.bin", "output.bin")) { cout << "can't rename\n"; }
			else {
				remove("output2.bin");
				if (checker)
					cout << "Updated!\n";
				else
					cout << "Can't find!\n";
			}
		}
	}
};