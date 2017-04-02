#include <SFML\Graphics.hpp>
#include <random>
#include <iostream>
#include <unordered_map>

int main(){
	//Change this to window rendered by graphics module
	sf::RenderWindow window(sf::VideoMode(640, 480), "LOL");
	//Event
	sf::Event event;
	//Creating a map to hold keys pressed
	std::unordered_map<int,bool> keys;
	
	while(window.isOpen()){
		while(window.pollEvent(event)){
			if(event.type == sf::Event::EventType::Closed)
			{
				window.close();
			}
			//Managing held down keys and storing in keys
			//Adds pressed key to map if it does not exist upon press
			if(event.type == sf::Event::EventType::KeyPressed){
					keys[event.key.code] = true;
			}
			//Removes pressed key from the map upon release
			if(event.type == sf::Event::EventType::KeyReleased){
					keys.erase(event.key.code);
			}
			//About to work on this so it isn't trash
			//if(event.type == sf::Event::EventType::)
		}
		//Print out enum values of keys
		std::cout << "Currently pressed keys: ";
		for(auto& keyValue : keys)
		{
			std::cout << keyValue.first << " ";
		}
		std::cout << std::endl;
		window.clear();
		window.display();
	}
}