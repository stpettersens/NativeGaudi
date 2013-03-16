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
#include "NativeGaudiBase.h"
using namespace std;

class NativeGaudiBuilder : NativeGaudiBase {

private:
	vector<string> m_commands; 
	string target;
	vector<string> m_action;
	void substituteVars(string[]);
	string handleWildcards(string);
	boost::tuple<string, string> extractCommand(string);
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
