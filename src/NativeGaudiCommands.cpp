/*
NativeGaudi platform agnostic build tool.
Copyright 2012-2013 Sam Saint-Pettersen.

Port of the original Scala/Java application (Gaudi), which ran on the
Java virtual machine, to native C++ code.

Released under the MIT/X11 License.
For dependencies, please see LICENSE file.
*/
#include <string>
#include <vector>
#include "boost/algorithm/string.hpp"
using namespace std;
using namespace boost;

#define MAX_COMMANDS 100

class NativeGaudiCommands {
private:
	string commands[MAX_COMMANDS];
public:
	NativeGaudiCommands();
	string getXString(string buildConf);
};

NativeGaudiCommands::NativeGaudiCommands() {
	for(int i = 0; i < MAX_COMMANDS; i++) {
		commands[i] = "0";
	}
}

string NativeGaudiCommands::getXString(string buildConf) {
	//vector<string> commands(1);
	vector<string> builtins(1);
	builtins.push_back("echo");
	builtins.push_back("exec");
	builtins.push_back("erase");
	builtins.push_back("xstrip");
	builtins.push_back("xx");
	string xstring = buildConf;
	for(int i = 1; i < builtins.size(); i++) {
		for(int x = 0; x < xstring.length(); x++) {
			xstring = ireplace_first_copy(xstring, builtins[i], "x");
			commands[i] = builtins[i];
		}
	}
	return xstring;
}
