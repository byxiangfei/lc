#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

void write(string filepath) {
	ofstream file;
	file.open(filepath);
	file<<"hello\n";
	file.close();
	return ;
}

void read(string filepath) {
	ifstream file;
	file.open(filepath);
	char output[100];
	file>>output;
	file.close();
	// file.getline(file, buffer)
	return;
}

