#include "graphics/Graphics.hpp"
#ifndef INI
#define INI
#include "../inc/SimpleIni/SimpleIni.hpp"
#endif
#ifndef LOG 
#define LOG
#include "../logging/logging.hpp"
#endif

class Engine{
	private:
		// variables
		Log log;
		CSimpleIniA ini; // ini file for initial values
		Graphics graphics;
		sf::Clock gameClock;
		sf::Time lastGraphicsLoop;
		sf::Time lastLogicLoop;

		int logicFramesElapsed;
		int graphicsFramesElapsed;
		int logicFramerate;
		int graphicsFramerate;
		int graphicsUpdatesSkipped;
		int graphicsSkipLimit;

		// methods
		void logicLoop();
		void graphicsUpdate();
		void createIniHandler(const string);
	public:
		Engine();
		void run();
};

Engine::Engine(){
	this->createIniHandler("engine/engine.ini");
	this->logicFramesElapsed = atoi(ini.GetValue("main", "logicFramesElapsed", NULL));;
	this->logicFramerate = atoi(ini.GetValue("main", "logicFramerate", NULL));;
	this->graphicsFramerate = atoi(ini.GetValue("main", "graphicsFramerate", NULL));;
	this->graphicsUpdatesSkipped = atoi(ini.GetValue("main", "graphicsUpdatesSkipped", NULL));;
	this->graphicsSkipLimit = atoi(ini.GetValue("main", "graphicsSkipLimit", NULL));;
}

// this function creates the object for reading from the ini file
void Engine::createIniHandler(const string iniFilename){
    SI_Error rc = this->ini.LoadFile(iniFilename.c_str());
    if (rc < 0){
        log.log("Error opening ini file for Engine");
        exit(-1);
    }
}

void Engine::logicLoop(){
}

void Engine::graphicsUpdate(){
	this->graphics.update();
}

void Engine::run(){
	while (this->graphics.running()){
		// time since game started
		sf::Time elapsed = this->gameClock.getElapsedTime();

		// if a logic loop needs to be ran
		if ((double)(elapsed.asMicroseconds()) * this->logicFramerate / 1000000 
			> this->logicFramesElapsed){
			this->logicLoop();
			this->lastLogicLoop = elapsed;
			this->logicFramesElapsed++;
			if ((double)(elapsed.asMicroseconds()) * this->logicFramerate / 1000000 
				> this->logicFramesElapsed){
				if (this->graphicsUpdatesSkipped > this->graphicsSkipLimit){
					lastGraphicsLoop = elapsed;
					this->graphics.clearDisplay();
					this->graphicsUpdate();

					this->graphicsUpdatesSkipped = 0;
				} else {
					printf("skipped graphics frame\n");
					this->graphicsUpdatesSkipped++;
				}
			}
		} 
		if (elapsed.asMicroseconds() > lastGraphicsLoop.asMicroseconds() + 
			(1.0/this->graphicsFramerate * 1000000)){
			lastGraphicsLoop = elapsed;
			this->graphics.clearDisplay();
			this->graphicsUpdate();
		}
	}
}