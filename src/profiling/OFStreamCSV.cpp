#include "OFStreamCSV.h"

OFStreamCSV::OFStreamCSV() {
	streamCSV.open(OUTPUT_PATH);
}

void OFStreamCSV::write(std::string toWrite) {
	streamCSV << toWrite;
}

void OFStreamCSV::write(float toWrite) {
	std::cout << "\n\n\nSTREAMER CLASS WRITING " << toWrite << "\n\n";
	streamCSV << toWrite;
}

void OFStreamCSV::newColumn() {
	streamCSV << COLUMN_DELIMITER_CSV << " ";
}

void OFStreamCSV::newRow() {
	streamCSV << NEWLINE_CSV;
}

void OFStreamCSV::close() {
	streamCSV.close();
}
