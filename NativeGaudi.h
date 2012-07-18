/*
NativeGaudi platform agnostic build tool.
Copyright 2012 Sam Saint-Pettersen.

Port of the original Scala/Java application (Gaudi), which ran on the
Java virtual machine, to native C++ code.

Released under the MIT/X11 License.
For dependencies, please see LICENSE file.
*/
#include <string>
#include "NativeGaudiBase.h"
using namespace std;

class NativeGaudiBuilder : public NativeGaudiBase {

private: 

	void substituteVars(string[]);
	string handleWildcards(string);
	string extractCommand(string); // Change return type to tuple.
	void printError(string);
	void printCommand(string, string);
	void execExtern(string);
	void eraseFile(string, bool);

public:

	NativeGaudiBuilder(string, bool, bool, bool)
	{
		
	}

	void doCommand(string command, string param);
	void doAction(string action); // Change to a JSON type.
};
