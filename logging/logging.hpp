#include <stdio.h>
#include <ctime>
#include <string>
#include <iostream>
#include <fstream>

#include "../inc/SimpleIni/SimpleIni.hpp"

using namespace std;

// simple logging class
class Log {
	private:
		string logFilepath;
		CSimpleIniA ini;
	public:
		Log();
		void log(const string);
		void createIniHandler(const string);
};

Log::Log(){
	this->createIniHandler("logging/logging.ini");

	this->logFilepath = ini.GetValue("main", "logpath", NULL);
}

void Log::createIniHandler(const string iniFilename){
    SI_Error rc = this->ini.LoadFile(iniFilename.c_str());
    if (rc < 0){
        printf("Error with ini file\n");
        exit(-1);
    }
}

void Log::log(const string str){
	// get timestamp for error
	time_t rawtime;
	struct tm * timeinfo;
	char buffer[80];
	time (&rawtime);
	timeinfo = localtime(&rawtime);
	strftime(buffer,sizeof(buffer),"[%d-%m-%Y %I:%M:%S] ",timeinfo);
	string timestamp(buffer);

	// log error
	ofstream logfile;
	logfile.open(logFilepath);
	logfile << timestamp << str << endl;
	logfile.close();
}