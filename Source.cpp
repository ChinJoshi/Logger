#include "Logger.h"
#include <iostream>
int main() {
	Logger log;	//creating object
	log.setFile("C://Users//Chinmaya//Desktop//LoggerTest.csv");	//setting the filepath
	std::string headers[] = { "Error","Part","Fix","Celltest" };	//Array for the headers to log with setHeaders function
	long float row1[] = { 4996,78.99,69,44 };	//An array for a row to log with logBodyRow
	std::string row2[] = { "Segfault","Code","Good Luck With That","what" };	//An array for a row to log with logBodyRow
	char row3[] = { 'a','c','g','t' };		//An array for a row to log with logBodyRow
	log.setHeaders(headers, 4);		//Sets headers with array called headers
	log.logBodyRow(row1, 4);	//Logs a row with an array called row1
	log.logBodyRow(row2, 4);	//Logs a row with an array called row2
	log.logBodyRow(row3, 4);	//Logs a row with an array called row3
	log.logBodyCell("Celltest", "Testing");	//Logs a single cell in the part column 
	return 0;
}