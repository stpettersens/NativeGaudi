/*
NativeGaudi platform agnostic build tool.
Copyright 2012 Sam Saint-Pettersen.

Port of the original Scala/Java application (Gaudi), which ran on the
Java virtual machine, to native C++ code.

Released under the MIT/X11 License.
For dependencies, please see LICENSE file.
*/
#include <string>
using namespace std;

class NativeGaudiBase {

private:

	int caesarOffset[];
	string LogFile;

public:

	void logDump(string, bool);
	void writeToFile(string, string, bool);
	string encodeText(string);
	string decodeText(string);
};
