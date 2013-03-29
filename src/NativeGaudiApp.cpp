/*
NativeGaudi platform agnostic build tool.
Copyright 2012-2013 Sam Saint-Pettersen.

Port of the original Scala/Java application (Gaudi), which ran on the
Java virtual machine, to native C++ code.

Released under the MIT/X11 License.
For dependencies, please see LICENSE file.
*/
#include <iostream>
#include <algorithm>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include "boost/version.hpp"
#include "NativeGaudiForeman.h"
#include "NativeGaudiBuilder.h"
#include "NativeGaudiCommands.h"
using namespace std;

class NativeGaudiApp : NativeGaudiBase {

private:
	string appVersion;
	int errorCode;

public:
	char* program;
	string buildFile;
	bool beVerbose;
	bool logging;
	bool uSocket;

	NativeGaudiApp() {
		appVersion = "0.1";
		errorCode = -1;
		buildFile = "build.json";
		beVerbose = true;
		logging = false;
		uSocket = false;
	}

	void displayError(string);
	void displayUsage(int);
	void displayVersion();
	void runCommand(char*, char*);
	void loadBuild(string);
};

// Display version information and exit.
void NativeGaudiApp::displayVersion() {
	cout << "NativeGaudi v. " << appVersion 
	<< " (using Boost "
	<< BOOST_VERSION / 100000 << "." // Major version.
	<< BOOST_VERSION / 100 % 1000 << "." // Minor version.
	<< BOOST_VERSION % 100 // Patch level.
	<< ")." << endl;
	exit(0);
}

// Display an error.
void NativeGaudiApp::displayError(string error) {
	cout << "\nError with: " << error << "." << endl;
	displayUsage(errorCode);
}

// Display usage information and exit.
void NativeGaudiApp::displayUsage(int exitCode) {
	cout << "\nNativeGaudi platform agnostic build tool";
	cout << "\nCopyright (c) 2012-2013 Sam Saint-Pettersen";
	cout << "\n\nReleased under the MIT/X11 License.";
	cout << "\n\nUsage: " << program <<  " [-s <port>][-l][-i|-v|-n|-m][-q]";
	cout << "\n[-p <plug-in>][-f <build file>][<action>|\"<:command>\"]";
	cout << "\n\n-s: Enable listen on socket (Default: TCP/3082).";
	cout << "\n-l: Enable logging of certain events.";
	cout << "\n-i: Display usage information and quit.";
	cout << "\n-v: Display version information and quit.";
	cout << "\n-b: Generate a Gaudi build file (build.json).";
	cout << "\n-p: Invoke <plug-in> action.";
	cout << "\n-q: Mute console output, except for :echo and errors (Quiet mode).";
	cout << "\n-f: Use <build file> instead of build.json.\n";
	exit(exitCode);
}

// Just perform a stdin command; really just for testing implemented
// commands. E.g. argument ":move a->b".
void NativeGaudiApp::runCommand(char* command, char* param) {
	// Create a new builder to run a command.
	//NativeGaudiBuilder builder(false, beVerbose, logging);
	//builder.doCommand(command, param);
	exit(0);
}

// Load and delegate parse and execution of build file.
void NativeGaudiApp::loadBuild(string action) {
	string buildConf, line;
	ifstream infile;
	infile.open(buildFile.c_str());
	if(infile.is_open()) {
		while(getline(infile, line)) {
			buildConf += line;
		}
	}
	else {
		displayError("Build file (" + buildFile + "). Cannot be found/opened");
	}
	infile.close();

	// Shrink string by replacing tabs with spaces;
	// Gaudi build files should be written using tabs.
	replace(buildConf.begin(), buildConf.end(), '\t', ' ');
	
	// Peform key swapping for JSON array parsing (Hackish).
	NativeGaudiCommands ocommands;
	buildConf = ocommands.getXString(buildConf);
	string* commands = ocommands.getCommands();

	// Delegate to the foreman and builder.
	NativeGaudiForeman foreman(buildConf, action);
	NativeGaudiBuilder builder(commands, action); //, foreman.getPreamble(), false, false, false);
	builder.setTarget(foreman.getTarget());
	builder.setAction(foreman.getAction());
	builder.doAction();
	exit(0);
}

int main(int argc, char* argv[]) {
	NativeGaudiApp app;
	app.program = argv[0];
	string action = "build";

	/* Default behavior is to build a project following
	the build file in the current working directory. */
	if(argc == 1) app.loadBuild(action);

	// Handle command line arguments.
	else if(argc > 1 && argc < 7) {
		for (int i = 1; i < argc; i++)
		{
			if(strcmp(argv[i], "-i") == 0) app.displayUsage(0);
			else if(strcmp(argv[i], "-v") == 0) app.displayVersion();
			else if(strcmp(argv[i], "-l") == 0) app.logging = true;
			else if(strcmp(argv[i], "-s") == 0) app.uSocket = true;
			else if(strcmp(argv[i], "-f") == 0) {
				if(argv[i + 1] == NULL) {
					app.displayError("Build file. Filename not provided");
				}
				else {
					app.buildFile = argv[i + 1];
					if(argv[i + 2] != NULL) action = argv[i + 2];
					app.loadBuild(action);
				}
			}
			else app.loadBuild(argv[i]);
			//else if(strcmp(argv[1], "-b")) app.generateBuildFile();
			//else app.runCommand(argv[1], argv[2]);
		}
	}
	return 0;
}
