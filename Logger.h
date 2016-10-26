
#include <fstream>
#include <string>
#include <ctime>

class Logger {
public:

	std::string filePath;

	void setFile(std::string path) {
		filePath = path;
	}

	/**sets the headers of your csv (only accepts a string to label headers) 	Call Example: setHeaders("Error,Part,Solution");*/
	template<typename type>
	void setHeaders(type headers[],int length) {
		std::fstream file;
		file.open(filePath,std::ios::out);
		if (file.is_open() == true) {
            for (int x = 0; x <= (length-1); x++) {
				file <<headers[x] << "," ;
            }
			file << ",Timestamp" <<"\n";
			file.close();
		}
	}

	/**inserts into the next row of the .csv		accepts arrays of any type	Call Example: float exampleArray[] = {float1,float,2float,3float,4}    logBodyRow(exampleArray[]);*/
	template <typename type>
	void logBodyRow(type infoIn[],int length) {
		std::fstream file;
		file.open(filePath,std::ios::out | std::ios::app);
		if (file.is_open() == true) {
			for (int x = 0; x <= (length-1); x++) {
				file <<infoIn[x] << "," ;
			}
		std::time_t time = std::time(0);
		file << (std::asctime(std::localtime(&time)));
		file.close();
		}
	}

	/**inserts info into a singular cell*/
	template <typename type>
	void logBodyCell(type column,type infoIn) {
		std::fstream file;
		file.open(filePath,std::ios::out);

	}

	/**clears a file*/
	void clearFile(){
		std::fstream file;
		file.open(filePath,std::ios::out | std::ios::trunc);
		file << "";
		file.close();
	}
};



