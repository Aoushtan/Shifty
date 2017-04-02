#include "../inc/json.hpp"
#include <iostream>
#include <fstream>
#include <map>
#include <SFML/Audio.hpp>

using namespace std;
using jSon = nlohmann::json;

class Audio_Module{
	// These need to be defined here so they aren't destroyed after the function's scope is over
	private:
		sf::SoundBuffer sound_buffer;
		sf::Sound sound;
		
	public:
		map<string, string> audio_files; // Key / Value pair of audio files provided by the audio_tree.json file

		Audio_Module();
		void play_sound(string sound_name);
};

Audio_Module::Audio_Module(){
	jSon json;
	ifstream audio_tree("audio/audio_tree.json");
	string directory = "resources/";
	
	audio_tree >> json;
	
	for(jSon::iterator i = json.begin(); i != json.end(); ++i){
		string file_name = i.value();
		audio_files[i.key()] = directory + file_name;
	}
}

// Pass the key of a sound file you want to play from the audio_tree.json
// then the function will load it's associated file and play it.
void Audio_Module::play_sound(string sound_name){
	sound_buffer.loadFromFile(audio_files[sound_name]); // load the file associated to the key passed as a parameter
	sound.setBuffer(sound_buffer);
	sound.play(); // play it
}
