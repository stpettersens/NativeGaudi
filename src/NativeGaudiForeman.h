/*
NativeGaudi platform agnostic build tool.
Copyright 2012 Sam Saint-Pettersen.

Port of the original Scala/Java application (Gaudi), which ran on the
Java virtual machine, to native C++ code.

Released under the MIT/X11 License.
For dependencies, please see LICENSE file.
*/
#include <string>
#include <vector>
using namespace std;

class NativeGaudiForeman {
private:
	string m_buildConf;
	string buildJson;
	vector<string> preamble;
	string target;
	string parseBuildJSON();
	vector<string> getShards(string);
	string getTarget();
	vector<string> getPreamble();
	vector<string> getAction(string);

public:
	NativeGaudiForeman(string buildConf, string action);
};
