#include "Logger.h"
#include <iostream>
int main() {
	Logger log;
	log.setFile("//home//chinmaya//Desktop//test.csv");
	log.clearFile();
	std::string headers[]={"Error","Part","Propose"};
	log.setHeaders(headers,3);
	double row1[] = { 1478,6.7,9567 };
	log.logBodyRow(row1,3);
	std::string row2[] = { "Segfault","Code","Have fun with that"};
	log.logBodyRow(row2,3);
	int row3[] = {1,2,3};
	log.logBodyRow(row3,3);
	return 0;
}



