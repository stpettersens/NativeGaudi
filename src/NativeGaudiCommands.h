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

class NativeGaudiCommands {
private:
	string commands[100];
public:
	NativeGaudiCommands();
	string getXString(string buildConf);
};
