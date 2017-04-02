#include "graphics/Graphics.hpp"
#include "input/input_manager.cpp"

class Engine{
	private:
		Graphics gfx;
		Input input;
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
		input.input_loop();
	}
}