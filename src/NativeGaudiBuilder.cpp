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
#include <cstdlib>
#include <string>
#include <cassert>
#include <vector>
#include "boost/tuple/tuple.hpp"
#include "rapidjson/document.h"
#include "NativeGaudiBase.h"
#include "NativeGaudiHabitat.h"
using namespace std;
using namespace boost;

class NativeGaudiBuilder : NativeGaudiBase {
private: 
	string* m_commands;
	string target;
	string action_name;
	vector<string> m_action;
	bool verbose;
	void substituteVars(string);
	string handleWildcards(string);
	void printError(string);
	void printCommand(string, string);
	int execExtern(string);
	void eraseFile(string, bool);

public:
	NativeGaudiBuilder(string* commands, string action); //, vector<string> preamble, bool socket, bool verbose, bool logging);
	NativeGaudiBuilder(bool socket, bool verbose, bool logging);
	void setTarget(string target);
	void setAction(vector<string> action);
	void doCommand(string command, string param);
	void doAction();
};

// Constructor.
NativeGaudiBuilder::NativeGaudiBuilder(string* commands, string action) { //, vector<string> preamble, bool socket, bool verbose, bool logging) {
	this->verbose = verbose;
	m_commands = commands;
	action_name = action;
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

// Print executed command.
void NativeGaudiBuilder::printCommand(string command, string param) {
	if(verbose && command != "echo") {
		cout << "\t:" << command << " " << param << endl;
	}
	else if(command == "echo") {
		cout << "\t# " << param << endl;
	}
}

// Execute an external program or process.
int NativeGaudiBuilder::execExtern(string param) {
	int exitCode = system(param.c_str());
	return exitCode;
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
	NativeGaudiHabitat habitat;
	int os = habitat.getOSFamily();
	printCommand(command, param);
	int exitCode;
	if(command == "exec") {		
		exitCode = execExtern(param);
	}
	else if(command == "xstrip") {
		exitCode = execExtern("strip " + param);
	}
}

// Execute an action.
void NativeGaudiBuilder::doAction() {
	cout << "[ " << target << " => " << action_name << " ]" << endl;
	for(int i = 0; i < m_action.size(); i++)
		doCommand(m_commands[i], m_action[i]);
}
