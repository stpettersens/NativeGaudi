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
	string buildConf;
	string buildJson;
	string parseBuildJSON();
	string getShard(string);
	string getTarget();
	string getPreamble();
	string getAction(string);

public:
	NativeGaudiForeman(string);
};

NativeGaudiForeman::NativeGaudiForeman(string buildConf) {
	// Parse build config into build JSON object on initialization.
	this->buildConf = buildConf;
	buildJson = parseBuildJSON();
}

string NativeGaudiForeman::parseBuildJSON() {
	cout << buildConf << endl;
}

// Get sub-object 'shard' from build JSON object.
string NativeGaudiForeman::getShard(string objectName) {
	// TODO.
}

// Get target from parsed preamble.
string NativeGaudiForeman::getTarget() {
	// TODO.
}

// Get the preamble from build object.
string NativeGaudiForeman::getPreamble() {
	// TODO.
}

// Get an excution action
string getAction(string action) {
	// TODO.
}
