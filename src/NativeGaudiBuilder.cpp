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

class NativeGaudiBuilder : NativeGaudiBase {

private: 
	string buildConf;
	bool verbose;
	void substituteVars(string);
	string handleWildcards(string);
	boost::tuple<string, string> extractCommand(string);
	void printError(string);
	void printCommand(string, string);
	void execExtern(string);
	void eraseFile(string, bool);

public:
	NativeGaudiBuilder(string, bool, bool, bool);
	void doCommand(string, string);
	void doAction(string); // Change to a JSON type.
};

// Constructor.
NativeGaudiBuilder::NativeGaudiBuilder(string preamble, bool socket, bool verbose, bool logging) {
	this->verbose = verbose;
}

// Subtitute variables for values.
void NativeGaudiBuilder::substituteVars(string action) {
	// TODO.
}

// Handle wildcards in parameters such as *.scala, *.cpp,
// for example, to compile all Scala or C++ files in the specified directory.
string NativeGaudiBuilder::handleWildcards(string param) {
	return "TODO"; // TODO.
}

// Extract command and parameter for execution.
boost::tuple<string, string> NativeGaudiBuilder::extractCommand(string cmdParam) {
	string x = "x";
	string y = "y";
	return boost::make_tuple(x, y); // TODO.
}

// Print executed command.
void NativeGaudiBuilder::printCommand(string command, string param) {
	if(verbose && command != "echo") {
		cout << "\t" << command << " " << param << endl;
	}
}

// Execute an external program or process.
void NativeGaudiBuilder::execExtern(string param) {
	// TODO.
}

// Execute a command in the action.
void NativeGaudiBuilder::doCommand(string cmd, string param) {
	cout << cmd << ", " << param;
	cout << buildConf;
}

// Execute an action.
void NativeGaudiBuilder::doAction(string action) {
	
}
