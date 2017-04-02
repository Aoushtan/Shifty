#include "graphics/Graphics.hpp"
#include "input/input_manager.cpp"
<<<<<<< HEAD

class Engine{
	private:
		Graphics gfx;
		Input input;
		void logicLoop();
		void graphicsLoop();
=======
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
		Graphics graphics; // graphics for display
		sf::Clock gameClock; // counts the time since the game started

		/* 
		graphics and logic can run at different rates,
		or the same rate, but the tracking variables
		have been separated as such
		*/
		sf::Time lastGraphicsUpdate; // last time a graphics update happened
		sf::Time lastLogicUpdate; // last time a logic update happened

		// how many logic frames have happened since the game started
		int logicFramesElapsed; 
		int logicFramerate;

		// how many graphics frames have happened since the game started
		int graphicsFramesElapsed;
		int graphicsFramerate;
		// how many graphics frames have been skipped
		int graphicsUpdatesSkipped;
		// how many frames can be skipped before we must update
		int graphicsSkipLimit;

		// methods
		void logicUpdate();
		void graphicsUpdate();
		void createIniHandler(const string);
>>>>>>> origin/engine
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

void Engine::logicUpdate(){
}

void Engine::graphicsUpdate(){
	this->graphics.update();
}

void Engine::run(){
<<<<<<< HEAD
	while (this->gfx.running()){
		this->graphicsLoop();
		input.input_loop();
=======
	while (this->graphics.running()){
		// time since game started
		sf::Time elapsed = this->gameClock.getElapsedTime();

		// if a logic loop needs to be ran
		// (expected # of frames that have been completed > actual frames completed)
		if ((double)(elapsed.asMicroseconds()) * this->logicFramerate / 1000000 
			> this->logicFramesElapsed){

			// run a logic loop
			this->logicUpdate();
			this->lastLogicUpdate = elapsed;
			this->logicFramesElapsed++;

			// if we are still behind
			// (same condition as above)
			if ((double)(elapsed.asMicroseconds()) * this->logicFramerate / 1000000 
				> this->logicFramesElapsed){
				// if we can skip a frame
				if (this->graphicsUpdatesSkipped > this->graphicsSkipLimit){
					lastGraphicsUpdate = elapsed;
					this->graphics.clearDisplay();
					this->graphicsUpdate();

					this->graphicsUpdatesSkipped = 0;
				// skip a frame
				} else {
					// debugging red flag
					printf("skipped graphics frame\n");
					this->graphicsUpdatesSkipped++;
				}
			}
		} 
		// if we need to run a graphics update
		// (elapsed microseconds > elapsed microseconds + frame time)
		if (elapsed.asMicroseconds() > lastGraphicsUpdate.asMicroseconds() + 
			(1.0/this->graphicsFramerate * 1000000)){
			lastGraphicsUpdate = elapsed;
			this->graphics.clearDisplay();
			this->graphicsUpdate();
		}
>>>>>>> origin/engine
	}
}