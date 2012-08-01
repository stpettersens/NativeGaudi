/*
NativeGaudi platform agnostic build tool.
Copyright 2012 Sam Saint-Pettersen.

Port of the original Scala/Java application (Gaudi), which ran on the
Java virtual machine, to native C++ code.

Released under the MIT/X11 License.
For dependencies, please see LICENSE file.
*/
#include <string>
#include "json_spirit.h"
using namespace std;

class NativeGaudiForeman {
private:
	string buildJson;
	string parseBuildJSON();

public:
	NativeGaudiForeman(string);
};
