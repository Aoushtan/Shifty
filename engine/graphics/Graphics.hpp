#include <SFML/Graphics.hpp>
#include "../../inc/SimpleIni/SimpleIni.hpp"
#include "../../logging/logging.hpp"

using namespace std;

// Big graphics class
// Manages the window
class Graphics {
    private:
        // variables
        sf::RenderWindow window; // actual window
        CSimpleIniA ini; // ini file for initial values
        Log log;

        // methods
        void createIniHandler(const string); // creates the ini file for use
        void setTitleIcon(const string); // sets the icon for the window
    public:
        // methods
        void loop(); // runs a refresh loop
        bool running(); // returns whether the window is open or not
        sf::RenderWindow* getWindow();

        // constructor
        Graphics();
};

Graphics::Graphics(){
    // create the ini file
    this->createIniHandler("engine/graphics/graphics.ini");

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
void Graphics::createIniHandler(const string iniFilename){
    SI_Error rc = this->ini.LoadFile(iniFilename.c_str());
    if (rc < 0){
        log.log("Error opening ini file for Graphics module");
        exit(-1);
    }
}

// sets the title icon
void Graphics::setTitleIcon(const string filename){
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

sf::RenderWindow* Graphics::getWindow(){
    return &(this->window);
}