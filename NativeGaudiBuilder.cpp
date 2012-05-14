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
#include "boost/tuple/tuple.hpp"
#include "json_spirit.h"
#include "NativeGaudiBase.h"
using namespace std;

class NativeGaudiBuilder : protected NativeGaudiBase {

private: 

	string buildConf;

	void substituteVars(string[]);
	string handleWildcards(string);
	boost::tuple<string, string> extractCommand(string);
	void printError(string);
	void printCommand(string, string);
	void execExtern(string);
	void eraseFile(string, bool);

public:

	NativeGaudiBuilder(string preamble, bool sSwitch, bool beVerbose, bool logging)
	{
		buildConf = preamble;
	}
	void doCommand(string, string);
	void doAction(string); // Change to a JSON type.
};

void NativeGaudiBuilder::doCommand(string cmd, string param) {

	cout << buildConf;
}
