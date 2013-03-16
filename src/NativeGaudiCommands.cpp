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
	string* acommands;
	string* bubbleSort(int poss[], string commands[], int n);
public:
	NativeGaudiCommands();
	string getXString(string buildConf);
	string* getCommands();
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
	vector<int> poss(0);
	string xstring = buildConf;
	for(int i = 0; i < builtins.size(); i++) {
		int pos = xstring.find(builtins[i]);
		if(pos != string::npos) {
			xstring = ireplace_first_copy(xstring, builtins[i], "x");
			commands.push_back(builtins[i]);
			poss.push_back(pos);
		}
	}
	int* aposs = &poss[0];
	acommands = &commands[0];
	acommands = bubbleSort(aposs, acommands, poss.size());
	return xstring;
}

string* NativeGaudiCommands::getCommands() {
	return acommands;
}

string* NativeGaudiCommands::bubbleSort(int poss[], string commands[], int n) {
	bool swapped = true;
	int j = 0;
	int tmp;
	string stmp;
	while(swapped) {
		swapped = false;
		j++;
		for(int i = 0; i < n - j; i++) {
			if(poss[i] > poss[i + 1]) {
				tmp = poss[i];
				poss[i] = poss[i + 1];
				poss[i + 1] = tmp;
				stmp = commands[i];
				commands[i] = commands[i + 1];
				commands[i + 1] = stmp;
				swapped = true;
			}
		}
	}
	return commands;
}
