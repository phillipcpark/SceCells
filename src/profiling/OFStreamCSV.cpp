#include "OFStreamCSV.h"

OFStreamCSV::OFStreamCSV() {
	streamCSV.open(OUTPUT_PATH);
}

void OFStreamCSV::write(std::string toWrite) {
	streamCSV << toWrite;
}

void OFStreamCSV::newColumn() {
	streamCSV << COLUMN_DELIMITER_CSV;
}

void OFStreamCSV::newRow() {
	streamCSV << NEWLINE_CSV;
}
