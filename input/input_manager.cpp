#include <SFML\Graphics.hpp>
#include <random>
#include <iostream>
#include <unordered_map>

int main(int argc, char** argv){
	//Change this to window rendered by graphics module
	sf::RenderWindow window(sf::VideoMode(640, 480), "LOL");
	//Event
	sf::Event event;
	//Creating a map to hold keys pressed
	std::unordered_map<int,bool> keys;
	//Creating list to check for if keys change
	//std::list<int> changedKeys;
	
	while(window.isOpen()){
		//Reset changed keys check
		//changedKeys.clear();
		while(window.pollEvent(event)){
			if(event.type == sf::Event::EventType::Closed)
			{
				window.close();
			}
			//Managing held down keys and storing in keys
			//Adds pressed key to map if it does not exist upon press
			if(event.type == sf::Event::EventType::KeyPressed){
				if(keys.count(event.key.code) == 0){
					keys[event.key.code] = true;
					//changedKeys.push_back(event.key.code);
				}
			}
			//Removes pressed key from the map upon release
			if(event.type == sf::Event::EventType::KeyReleased){
				if(keys.count(event.key.code) == 1){
					keys.erase(event.key.code);
					//changedKeys.push_back(event.key.code);
				}
			}
		}
		//Print out enum values of keys
		std::cout << "Currently pressed keys: ";
		for(auto& keyValue : keys)
		{
			std::cout << keyValue.first << " ";
		}
		std::cout << std::endl;
		//if(!changedKeys.empty())
		//{
			//std::cout << "Changed Keys: " << std::endl;
		//}
		window.clear();
		window.display();
	}
}