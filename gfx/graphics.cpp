#include <SFML/Graphics.hpp>
#include "../SimpleIni/SimpleIni.hpp"
#include <stdio.h>

using namespace std;

class Graphics {
    private:
        sf::RenderWindow window;
        CSimpleIniA ini;
        void createIniHandler(const char *);
        void setTitleIcon(const char *);
    public:
        Graphics(const char *);
        void loop();
        bool running();
};

Graphics::Graphics(const char * iniFilename){
    this->createIniHandler(iniFilename);

    int height = atoi(ini.GetValue("main", "WINDOW_HEIGHT", NULL));
    int width = atoi(ini.GetValue("main", "WINDOW_WIDTH", NULL));   
    const char * windowTitle = ini.GetValue("main", "WINDOW_TITLE", NULL);
    const char * iconPath = ini.GetValue("resources", "iconPath", NULL);


    this->window.create(sf::VideoMode(height, width), "test");
    this->setTitleIcon(iconPath);
}

void Graphics::createIniHandler(const char * iniFilename){
    SI_Error rc = this->ini.LoadFile(iniFilename);
    if (rc < 0){
        printf("Error with ini file\n");
    }
}

void Graphics::setTitleIcon(const char * filename){
    sf::Image image;
    image.loadFromFile(filename);
    this->window.setIcon(image.getSize().x, image.getSize().y, image.getPixelsPtr());
}

void Graphics::loop(){
    if (this->window.isOpen()){
        sf::Event event;
        while (this->window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                this->window.close();
        }

        this->window.clear();
        this->window.display();
    }
} 

bool Graphics::running(){
    return this->window.isOpen();
}

int main(){
    Graphics gfx("gfx/graphics.ini");

    while (gfx.running()){
        gfx.loop();
    }

    return 0;
}