#ifndef OF_STREAM_CSV_H
#define OF_STREAM_CSV_H

#include <iostream>
#include <fstream>
#include <string>

#define OUTPUT_PATH "../../dataOutput/profiling_output.txt"
#define COLUMN_DELIMITER_CSV ","
#define NEWLINE_CSV ",,,,,,"

class OFStreamCSV {
	private:
		std::ofstream streamCSV;
	public:
		OFStreamCSV();
		void write(std::string);
		void newColumn();	
		void newRow();	
};

#endif
