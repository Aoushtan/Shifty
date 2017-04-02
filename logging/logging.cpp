#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class Log {
	private:
		string logFilepath;
	public:
		Log(const string);
		void log(const string);
};

Log::Log(const string filepath){
	this->logFilepath = filepath;
}

void Log::log(const string str){
	time_t rawtime;
	struct tm * timeinfo;
	char buffer[80];

	time (&rawtime);
	timeinfo = localtime(&rawtime);

	strftime(buffer,sizeof(buffer),"[%d-%m-%Y %I:%M:%S] ",timeinfo);

	string timestamp(buffer);

	ofstream logfile;
	logfile.open(logFilepath);
	logfile << timestamp << str << endl;
	logfile.close();
}

int main(){
	Log log();

	log.log("garbo");

	return 0;
}