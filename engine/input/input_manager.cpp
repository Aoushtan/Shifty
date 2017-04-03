#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Input {
	private:
		Log log; //Using the log module
		//Getting the window from the engine
		sf::RenderWindow window;
		//Creating event
		sf::Event event;
		//Creating a map to hold keys pressed
		unordered_map<int,bool> keys;
		//vector<int> keyReturn;
	public:
		void input_loop(); //Constantly check for input while window is open
		Input();
};
Input::Input() {
	
}

void Input::input_loop()
{
	while(window.pollEvent(event)){
		//If the event is a close event, close the window
		if(event.type == sf::Event::EventType::Closed)
		{
			window.close();
		}
		//Managing held down keys and storing in keys
		//Adds pressed key to map if it does not exist upon press
		if(event.type == sf::Event::EventType::KeyPressed){
				keys[event.key.code] = true;
				//keyReturn.push_back(event.key.code);
				cout << "LOL";
		}
		//Removes pressed key from the map upon release
		if(event.type == sf::Event::EventType::KeyReleased){
				keys.erase(event.key.code);
		}
	}
}
