/*
NativeGaudi platform agnostic build tool.
Copyright 2012 Sam Saint-Pettersen.

Port of the original Scala/Java application (Gaudi), which ran on the
Java virtual machine, to native C++ code.

Released under the MIT/X11 License.
For dependencies, please see LICENSE file.
*/
#include <iostream>
#include <cstring>
#include <string>
using namespace std;

class NativeGaudiBase  {

private:

	int caesarOffset[12];
	string LogFile;

public:

	void logDump(string, bool);
	void writeToFile(string, string, bool);
	string encodeText(string);
	string decodeText(string);

	NativeGaudiBase() {

		caesarOffset[0] = 0x22; 
		caesarOffset[1] = 0x1C;
		caesarOffset[2] = 0xA;
		caesarOffset[3] = 0x1F;
		caesarOffset[4] = 0x8;
		caesarOffset[5] = 0x2;
		caesarOffset[6] = 0x24;
		caesarOffset[7] = 0xF;
		caesarOffset[8] = 0x13;
		caesarOffset[9] = 0x25;
		caesarOffset[10] = 0x40;
		caesarOffset[11] = 0x10;
		LogFile = "gaudi.log";
	}
};

// Dump output to log file.
void NativeGaudiBase::logDump(string message, bool isLogging) {

}

// File writing operations.
void NativeGaudiBase::writeToFile(string file, string message, bool append) {

}

// Encode a message in a simple Caesar cipher.
string NativeGaudiBase::encodeText(string message) {

	string emessage;
	int x = 0;
	for(int i = 0; i < message.length(); i++) {

		if(x == 12) x = 0;
		int cv = (int)message[x] - caesarOffset[x];
		char ca = (char)cv;
		emessage += ca;
		x++;
	}
	return emessage;
}

// Decode a message in a simple Caesar cipher.
string NativeGaudiBase::decodeText(string message) {

	string umessage;
	int x = 0;
	for(int i = 0; i < message.length(); i++) {

		if(x == 12) x = 0;
		int cv = (int)message[x] + caesarOffset[x];
		char ca = (char)cv;
		umessage += ca;
		x++;
	}
	return umessage;
}
