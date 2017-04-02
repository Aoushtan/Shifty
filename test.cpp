#include <SFML/Graphics.hpp>
#include "audio/Audio.hpp"

int main(){
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    Audio_Module am;
	
	// Displaying the tree
	for(map<string, string>::iterator i = am.audio_files.begin(); i != am.audio_files.end(); ++i){
		cout << i->first << ": " << i->second << endl;
	}
	
	// Playing the first sound in the tree
	am.play_sound("first_song");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}
