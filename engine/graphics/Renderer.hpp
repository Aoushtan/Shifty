#ifndef SFML_GRAPHICS
#define SFML_GRAPHICS
#include <SFML/Graphics.hpp>
#endif

class Renderer {
	private:
		sf::Sprite sprite;
		sf::Texture texture;
	public:
		Renderer();
		sf::Sprite renderSomething();
};

Renderer::Renderer(){
	this->texture.loadFromFile("resources/test_texture.bmp");

	this->sprite.setTexture(this->texture);
	this->sprite.setPosition(100, 100);
}

sf::Sprite Renderer::renderSomething(){
	return this->sprite;
}