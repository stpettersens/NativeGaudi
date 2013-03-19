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
#include <cstdlib>
#include <vector>
#include <fstream>
#include "boost/tuple/tuple.hpp"
using namespace std;
using namespace boost;

class NativeGaudiHabitat {

private:
	vector<string> getPaths();

public:
	int getOSFamily();
	tuple<string, string> getExeWithExt(string);

};

vector<string> NativeGaudiHabitat::getPaths() {
	vector<string> paths(0);
	const string PathVar = getenv("PATH");
	paths.push_back(PathVar);
	return paths;
}

int NativeGaudiHabitat::getOSFamily() {
	const string uname[2] = { "uname", "ver" };
	for(int i = 0; i < 2; i++) {
		string command = uname[i] + " > os.tmp";
		int exitCode = system(command.c_str());
		if(exitCode == 0) break; 
	}
	const char* ostmp = "os.tmp";
	string line, osstr;
	ifstream osfile;
	osfile.open(ostmp);
	if(osfile.is_open()) {
		while(getline(osfile, line)) {
			osstr = line;
		}
	}
	osfile.close();
	remove(ostmp);
	return 0;
}
