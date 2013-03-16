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

class NativeGaudiForeman {
private:
	string m_buildConf;
	string buildJson;
	string m_action;
	vector<string> preamble;
	vector<string> commands;
	string target;
	string parseBuildJSON();
	vector<string> getShards(string);
public:
	NativeGaudiForeman(string buildConf, string action);
	string getTarget();
	vector<string> getPreamble();
	vector<string> getAction();
};

NativeGaudiForeman::NativeGaudiForeman(string buildConf, string action) {
	// Parse build config into build JSON object on initialization.
	m_buildConf = buildConf;
	m_action = action;
	buildJson = parseBuildJSON();
}

string NativeGaudiForeman::parseBuildJSON() {
	Document document;
	if(document.Parse<0>(m_buildConf.c_str()).HasParseError()) {
		cout << "Error parsing build file (Bad JSON)." << endl;
		exit(1);
	}
	StringBuffer json;
	Writer<StringBuffer> writer(json);
	document.Accept(writer);
	return json.GetString();
}

// Get sub-object 'shard's from build object.
vector<string> NativeGaudiForeman::getShards(string objectName) {
	Document document;
	document.Parse<0>(this->buildJson.c_str()).HasParseError();
	const Value& object = document[objectName.c_str()];
	vector<string> shards(0);
	if(objectName == "preamble") {
		assert(object.IsObject());
		shards.push_back(object["source"].GetString());
		shards.push_back(object["target"].GetString());
	}
	else {
		assert(object.IsArray());
		for(SizeType i = 0; i < object.Size(); i++) {
			const Value& a = object[i];
			shards.push_back(a["x"].GetString());
		}
	}	
	return shards;
}

// Get target from parsed preamble.
string NativeGaudiForeman::getTarget() {
	vector<string> preamble = getPreamble();
	return preamble[1];
}

// Get the preamble from build object.
vector<string> NativeGaudiForeman::getPreamble() {
	return getShards("preamble");
}

// Get an excution action.
vector<string> NativeGaudiForeman::getAction() {
 	return getShards(m_action);
}
