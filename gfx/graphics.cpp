#include <SFML/Graphics.hpp>
#include "../SimpleIni/SimpleIni.hpp"
#include "stdio.h"



int setTitleIcon(const char * filename, sf::RenderWindow* window){
    sf::Image image;
    image.loadFromFile(filename);
    window->setIcon(image.getSize().x, image.getSize().y, image.getPixelsPtr());
}

int main(){
    CSimpleIniA ini;
    SI_Error rc = ini.LoadFile("gfx/graphics.ini");
    if (rc < 0){
        printf("error with file\n");
    }

    int height = atoi(ini.GetValue("main", "WINDOW_HEIGHT", NULL));
    int width = atoi(ini.GetValue("main", "WINDOW_WIDTH", NULL));   
    const char * iconPath = ini.GetValue("resources", "iconPath", NULL);

    sf::RenderWindow window(sf::VideoMode(height, width), "Shifty");
    setTitleIcon(iconPath, &window);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.display();
    }

    return 0;
}