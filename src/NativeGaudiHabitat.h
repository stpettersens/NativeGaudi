/*
NativeGaudi platform agnostic build tool.
Copyright 2012 Sam Saint-Pettersen.

Port of the original Scala/Java application (Gaudi), which ran on the
Java virtual machine, to native C++ code.

Released under the MIT/X11 License.
For dependencies, please see LICENSE file.
*/
#include <string>
#include <cstdlib>
#include <vector>
#include "boost/tuple/tuple.hpp"
using namespace std;
using namespace boost;

class NativeGaudiHabitat {

private:

	static vector<string> getPaths();

public:

	static unsigned int getOSFamily();
	static tuple<string, string> getExeWithExt(string);

};
