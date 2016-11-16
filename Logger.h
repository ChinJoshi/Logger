#include <string>
#include <ctime>
#include <fstream>


class Logger {
public:
	std::string filePath;	//string that will hold the file path tot write to
	int length;		//int that holds the number of elements in the header array
	/**sets the filepath that you want to write to (only accepts a string)
	Call Example:
	setFile("C://hello//dumb//test.csv");**/
	void setFile(std::string path) {
		filePath = path;
	}
	/**sets the headers of your csv (accepts an array of any type as the first argumetn and the number of elements in the array as the second argument)
	Call Example: 
	std::string headers[] = {"test1","test2","test3","test4"};
	setHeaders(headers,4);**/
	template<typename type>
	void setHeaders(type headers[], int arrayLength) {
		std::ofstream file;
		file.open(filePath, std::ios::out);
		if (file.is_open() == true) {
			for (int x = 0; x <= (arrayLength - 1); x++) {
				file << headers[x] << ",";
			}
			file << "Timestamp";
			file << "\n";
			file.close();
			length = arrayLength;
		}
	}
	/**inserts into the next row of the .csva
	ccepts arrays of any type
	Call Example: float exampleArray[] = {float1,float,2float,3float,4}
	logBodyRow(exampleArray[]);**/
	template <typename type>
	void logBodyRow(type infoIn[], int lengthy) {
		std::ofstream file;		
		file.open(filePath, std::ios::out | std::ios::app);		//opening file for writing and appednign to the end of it
		if (file.is_open() == true) {		//checks if file is open
			for (int x = 0; x <= (lengthy - 1); x++) {	//writes alll elements of the array to 
				file << infoIn[x] << ",";
			}
			std::time_t time = std::time(0);
			file << (std::asctime(std::localtime(&time)));
			file.close();
		}
	}

	/**inserts info into a singular cell*/
	template<typename type>
	void logBodyCell(std::string column,type infoIn) {
		std::string currentColumn;
		std::fstream file;
		file.open(filePath);
		int counter = 0;
		while (counter <= length) {
			counter++;
			getline(file, currentColumn, ',');
			if (column == currentColumn) {
				break;
			}
		}
		file.close();
		file.open(filePath, std::ios::out| std::ios::app);
		for (int x = 0; x < (counter-1); x++) {
			file << ",";
		}
		file << infoIn;
		file .close();
	}

	/**clears a file*/
	void clearFile() {
		std::ofstream file;
		file.open(filePath, std::ios::out | std::ios::trunc);
		file << "";
		file.close();
	}
};
