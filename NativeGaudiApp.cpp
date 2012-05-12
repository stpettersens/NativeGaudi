/*
NativeGaudi platform agnostic build tool.
Copyright 2012 Sam Saint-Pettersen.

Port of the original Scala/Java application (Gaudi), which ran on the
Java virtual machine, to native C++ code.

Released under the MIT/X11 License.
For dependencies, please see LICENSE file.
*/
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <exception>
#include "NativeGaudi.h"
using namespace std;

class NativeGaudiApp : protected NativeGaudiBase {

private:

	char* program;
	string appVersion;
	int errCode;
	string buildFile;
	bool beVerbose;
	bool logging;

	void displayError(exception);
	void displayError(string);

public:

	NativeGaudiApp() {

		appVersion = "0.1";
		errCode = -2;
		buildFile = "build.json";
		beVerbose = true;
		logging = false;
	}

	void displayUsage(char*, int);
	void displayVersion();
	void runCommand(string, string);
	void loadBuild(string);
};

// Display version information and exit.
void NativeGaudiApp::displayVersion() {

	cout << "NativeGaudi v. " << appVersion << ".\n";
	exit(0);
}

// Display an error.
void NativeGaudiApp::displayError(exception ex) {

	cout << "\nError with: " << ex.what() << ".";
	displayUsage(program, errCode);
}

// Display an error. Overloaded for a string parameter.
void NativeGaudiApp::displayError(string ex) {

	cout << "\nError with: " << ex << ".";
	displayUsage(program, errCode);
}

// Display usage information and exit.
void NativeGaudiApp::displayUsage(char* program, int exitCode) {

	program = program;
	cout << "\nNativeGaudi platform agnostic build tool";
	cout << "\nCopyright (c) 2012 Sam Saint-Pettersen";
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
void NativeGaudiApp::runCommand(string cmd, string param) {

	// Create a new builder to run a command.
	NativeGaudiBuilder builder("", false, beVerbose, logging);
	builder.doCommand(cmd, param);
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
	// Shrink string by replacing tabs with spaces;
	// Gaudi build files should be written using tabs.
	//buildConf.replace() // TODO!
	infile.close();
}

int main(int argc, char* argv[]) {

	NativeGaudiApp app;
	string action = "build";

	/* Default beavior is to build project following
	build file in the current working directory. */
	if(argc == 1) app.loadBuild(action);

	// Handle command line arguments.
	else if(argc > 1 && argc < 7) {
		if(strcmp(argv[1], "-i") == 0) app.displayUsage(argv[0], 0);
		else if(strcmp(argv[1], "-v") == 0) app.displayVersion();
	}

	return 0;
}
	