/*
NativeGaudi platform agnostic build tool.
Copyright 2012-2013 Sam Saint-Pettersen.

Port of the original Scala/Java application (Gaudi), which ran on the
Java virtual machine, to native C++ code.

Released under the MIT/X11 License.
For dependencies, please see LICENSE file.
*/
#include <iostream>
#include <cstring>
#include <string>
#include <cassert>
#include <vector>
#include "boost/tuple/tuple.hpp"
#include "rapidjson/document.h"
#include "NativeGaudiBase.h"
using namespace std;
using namespace boost;

class NativeGaudiBuilder : NativeGaudiBase {
private: 
	vector<string> m_commands;
	string target;
	vector<string> m_action;
	bool verbose;
	void substituteVars(string);
	string handleWildcards(string);
	tuple<string, string> extractCommand(string);
	void printError(string);
	void printCommand(string, string);
	void execExtern(string);
	void eraseFile(string, bool);

public:
	NativeGaudiBuilder(string* commands, vector<string> preamble, bool socket, bool verbose, bool logging);
	NativeGaudiBuilder(bool socket, bool verbose, bool logging);
	void setTarget(string target);
	void setAction(vector<string> action);
	void doCommand(string command, string param);
	void doAction();
};

// Constructor.
NativeGaudiBuilder::NativeGaudiBuilder(string* commands, vector<string> preamble, bool socket, bool verbose, bool logging) {
	this->verbose = verbose;
	for(int i = 1; i < 100; i++) {
		cout << "constructor >> " << commands[i] << endl;
		m_commands.push_back(commands[i]);
	}
}

// Short constructor.
NativeGaudiBuilder::NativeGaudiBuilder(bool socket, bool verbose, bool logging) {
	
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
tuple<string, string> NativeGaudiBuilder::extractCommand(string cmdParam) {
	string x = "x";
	string y = "y";
	return make_tuple(x, y); // TODO.
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

// Set target for the action.
void NativeGaudiBuilder::setTarget(string target) {
	this->target = target;
}

// Set action.
void NativeGaudiBuilder::setAction(vector<string> action) {
	m_action = action;
}

// Execute a command in the action.
void NativeGaudiBuilder::doCommand(string command, string param) {
	cout << command << " " << param << endl;
}

// Execute an action.
void NativeGaudiBuilder::doAction() {
	for(int i = 1; i < m_action.size(); i++)
		doCommand(m_commands[i], m_action[i]);
}
