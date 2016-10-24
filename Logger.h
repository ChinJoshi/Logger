#include <fstream>
#include <string>
#include <sstream>

template <typename type>
class Logger {
public:
	std::string filePath;
	void setFile(std::string path) { 
		filePath = path;
	}
	void setHeaders(std::string headers) {		//sets the headers of your csv (only accepts a string to label headers) 	//Call Example: setHeaders("Error,Part,Solution");				
		std::fstream file;						
		file.open(filePath,std::ios::out);
		if (file.is_open() == true) {
			file << "Timestamp"<<","<<headers << "\n"; 
			file.close();
		}
	}
	void logBodyRow(type infoIn[]) {	//inserts into the next row of the .csv		//accepts arrays of any type	//Call Example: float exampleArray[] = {float1,float,2float,3float,4}    logBodyRow(exampleArray[]);
		std::fstream file;
		file.open(filePath,std::ios::out | std::ios::app);
		int length = sizeof(infoIn);
		if (file.is_open() == true) {
			file << __TIMESTAMP__<<",";
			for (int x = 0; x <= length; x++) {
				file << infoIn[x] << "," ;
			}
			file << "\n";
		file.close();
		}
	}
	void logBodyCell() {	//inserts info into a singular cell

		}
	void clearFile(){	//clears a file
		std::fstream file;
		file.open(filePath,std::ios::trunc);
		file << "";
		file.close();
	}
};



