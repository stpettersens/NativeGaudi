/*
NativeGaudi platform agnostic build tool.
Copyright 2012-2013 Sam Saint-Pettersen.

Port of the original Scala/Java application (Gaudi), which ran on the
Java virtual machine, to native C++ code.

Released under the MIT/X11 License.
For dependencies, please see LICENSE file.
*/
#include <iostream>
#include <string>
#include <cstdio>
#include <sstream>
#include <cassert>
#include <vector>
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
using namespace std;
using namespace rapidjson;

class Foreman {
private:
	string m_buildConf;
	string buildJson;
	vector<string> preamble;
	vector<string> commands;
	string target;
	string parseBuildJSON();
	vector<string> getShards(string);
	string getTarget();
	vector<string> getPreamble();
	vector<string> getAction(string);

public:
	Foreman(string buildConf, string action);
};
