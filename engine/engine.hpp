#include "graphics/Graphics.hpp"

class Engine{
	private:
		Graphics gfx;
		void logicLoop();
		void graphicsLoop();
	public:
		Engine();
		void run();
};

Engine::Engine(){

}

void Engine::logicLoop(){

}

void Engine::graphicsLoop(){
	gfx.loop();
}

void Engine::run(){
	while (this->gfx.running()){
		this->graphicsLoop();
	}
}