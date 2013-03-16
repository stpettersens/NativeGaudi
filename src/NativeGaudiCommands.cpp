/*
NativeGaudi platform agnostic build tool.
Copyright 2012-2013 Sam Saint-Pettersen.

Port of the original Scala/Java application (Gaudi), which ran on the
Java virtual machine, to native C++ code.

Released under the MIT/X11 License.
For dependencies, please see LICENSE file.
*/
#include <iostream> // !
#include <string>
#include <vector>
#include "boost/algorithm/string.hpp"
using namespace std;
using namespace boost;

class NativeGaudiCommands {
private:
	vector<string> builtins;
	vector<string> commands;
public:
	NativeGaudiCommands();
	string getXString(string buildConf);
	vector<string> getCommands();
};

NativeGaudiCommands::NativeGaudiCommands() {
	builtins.push_back("echo");
	builtins.push_back("exec");
	builtins.push_back("erasex");
	builtins.push_back("xstrip");
	builtins.push_back("clobber");
	builtins.push_back("append");
}

string NativeGaudiCommands::getXString(string buildConf) {
	string xstring = buildConf;
	for(int i = 0; i < builtins.size(); i++) {
		if(xstring.find(builtins[i]) != string::npos)
			commands.push_back(builtins[i]);
	}
	for(int i = 0; i < commands.size(); i++) {
		cout << commands[i] << endl;		
	}
	return xstring;
} 
			

vector<string> NativeGaudiCommands::getCommands() {
	return commands;
}
