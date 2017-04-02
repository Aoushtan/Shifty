#include <SFML/Graphics.hpp>
#include "../inc/SimpleIni/SimpleIni.hpp"

// Big graphics class
// Manages the window
class Graphics {
    private:
        // variables
        sf::RenderWindow window; // actual window
        CSimpleIniA ini; // ini file for initial values

        // methods
        void createIniHandler(const char *); // creates the ini file for use
        void setTitleIcon(const char *); // sets the icon for the window
    public:
        // methods
        void loop(); // runs a refresh loop
        bool running(); // returns whether the window is open or not

        // constructor
        Graphics(const char *);
};

Graphics::Graphics(const char * iniFilename){
    // create the ini file
    this->createIniHandler(iniFilename);

    // get the needed variables
    int height = atoi(ini.GetValue("main", "WINDOW_HEIGHT", NULL));
    int width = atoi(ini.GetValue("main", "WINDOW_WIDTH", NULL));   
    const char * windowTitle = ini.GetValue("main", "WINDOW_TITLE", NULL);
    const char * iconPath = ini.GetValue("resources", "iconPath", NULL);

    // set up the window
    this->window.create(sf::VideoMode(height, width), windowTitle);
    this->setTitleIcon(iconPath);
}

// this function creates the object for reading from the ini file
void Graphics::createIniHandler(const char * iniFilename){
    SI_Error rc = this->ini.LoadFile(iniFilename);
    if (rc < 0){
        printf("Error with ini file\n");
        exit(-1);
    }
}

// sets the title icon
void Graphics::setTitleIcon(const char * filename){
    // loads an image
    sf::Image image;
    image.loadFromFile(filename);

    // puts them in the window
    this->window.setIcon(image.getSize().x, image.getSize().y, image.getPixelsPtr());
}

// runs a single refresh loop for the window
void Graphics::loop(){
    // make sure the window is open
    if (this->window.isOpen()){
        // event loop
        sf::Event event;
        while (this->window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                this->window.close();
        }

        // display
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