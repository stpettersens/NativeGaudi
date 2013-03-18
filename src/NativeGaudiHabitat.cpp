/*
NativeGaudi platform agnostic build tool.
Copyright 2012 Sam Saint-Pettersen.

Port of the original Scala/Java application (Gaudi), which ran on the
Java virtual machine, to native C++ code.

Released under the MIT/X11 License.
For dependencies, please see LICENSE file.
*/
#include <iostream> // !
#include <string>
#include <cstdlib>
#include <vector>
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
	return 0;
}
