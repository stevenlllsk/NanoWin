#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	string fileName;
	string line;

	int lineCount = 0;

	size_t charCount = 0;

	cout << "Enter your file name: ";
	cin >> fileName;

	ofstream file(fileName);
	if (!file) {
		cout << "Failed to open file.\n";
		return 1;
	}

	cout << "Enter your text (type 'quit' on a new line to finish):\n";

	while (true) {
		getline(cin, line);
		if (line == "quit") break;
		file << line << '\n';
		charCount += line.size() + 1;
		lineCount++;
		cout << lineCount << ": ";
	}

	file.close();

	cout << "Data stored successfully.\n";
	cout << "Total characters written: " << charCount << endl;

	cin.ignore();
	cin.get();

	return 0;
}
