#include "Logger.h"
#include <iostream>
void main() {
	Logger<int> logInt;
	Logger<std::string> logString;
	logInt.setFile("C:\\Users\\Chinmaya\\Documents\\Text Files\\Example.txt");
	logInt.clearFile();
	logInt.setHeaders("Error,Part,Solution");
	int row1[] = { 7,6,398,56,78 };
	logInt.logBodyRow(row1);
	/*std::string row2[] = { "test1","test2","test3","test4" };
	logString.setFile("C:\\Users\\Chinmaya\\Documents\\Text Files\\Example.txt");
	logString.logBodyRow(row2);*/
} 