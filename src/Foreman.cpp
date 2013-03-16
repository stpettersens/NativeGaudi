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

Foreman::Foreman(string buildConf, string action) {
	// Parse build config into build JSON object on initialization.
	m_buildConf = buildConf;
	buildJson = parseBuildJSON();
	preamble = getPreamble();
	target = getTarget();

	cout << "Action to execute = " << action << endl;
	commands = getAction(action);
}

string Foreman::parseBuildJSON() {
	Document document;
	if(document.Parse<0>(m_buildConf.c_str()).HasParseError()) {
		cout << "Error parsing build file (Bad JSON)." << endl;
	}
	StringBuffer json;
	Writer<StringBuffer> writer(json);
	document.Accept(writer);
	return json.GetString();
}

// Get sub-object 'shard's from build object.
vector<string> Foreman::getShards(string objectName) {
	Document document;
	document.Parse<0>(this->buildJson.c_str()).HasParseError();
	const Value& object = document[objectName.c_str()];
	vector<string> shards(2); // 200?
	if(objectName == "preamble") {
		assert(object.IsObject());
		shards[0] = object["source"].GetString();
		shards[1] = object["target"].GetString();
	}
	else {
		assert(object.IsArray());
		for(SizeType i = 0; i < object.Size(); i++) {
			const Value& a = object[i];
			cout << a["x"].GetString() << endl;
		}
	}
	return shards;
}

// Get target from parsed preamble.
string Foreman::getTarget() {
	return preamble[1];
}

// Get the preamble from build object.
vector<string> Foreman::getPreamble() {
	return getShards("preamble");
}

// Get an excution action.
vector<string> Foreman::getAction(string action) {
	return getShards(action);
}
