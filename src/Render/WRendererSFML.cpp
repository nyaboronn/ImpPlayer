#include <WRendererSFML.hpp>
#include <spdlog/spdlog.h>
#include <iostream>
#include <Log.hpp>
#include <InputController.hpp>
using namespace std;
using namespace sf;
using namespace impvm;

void WRendererSFML::init()
{


this->_window = new RenderWindow(sf::VideoMode(800, 600), "SFML window");
if(_window != nullptr){
    Log::info("SFML Renderer is UP");
     _window->setFramerateLimit(60);
     _font = new sf::Font();
     _event = new sf::Event();
     InputController* Input = InputController::getInstance();
     Input->init(_window);
    if (!_font->loadFromFile("game.ttf"))
    {
        Log::error("Error loading font");
    }
}else{
    Log::error("Error initializing SFML Renderer");

}
    
    
}


void WRendererSFML::close()
{
    

    _ready = false;
    _window->close();     
        

    
}



void WRendererSFML::update()
{
    
    while (_window->pollEvent(*_event))
    {
        // Close window: exit
        if (_event->type == sf::Event::Closed){
            _ready = false;
            _window->close();     
        }

    }
}

void WRendererSFML::flush(){
    
            _window->display();

}


void WRendererSFML::clear(){
            _window->clear();

}

void WRendererSFML::destroy()
{
    
    
}

void WRendererSFML::drawObject(Object* str){
     //   Log::console->info("Drawing {:p}", (void*)str );
    //    Log::console->info("Rect {:p}", (void*)str->_rect );

   // Log::console->info("x {}",str->x );
   sf::IntRect rectangulo = sf::IntRect(str->_rect->x, str->_rect->y, str->_rect->w, str->_rect->h);

    str->getSheet()->_baseSheet->setTextureRect(rectangulo);
    str->getSheet()->_baseSheet->setPosition((float)str->x  - 72, (float)str->y -95 ); //change place, very slow
  // Log::console->info("position x {}", str->x );
 //  Log::console->info("position y {}", str->y );
    _window->draw( *str->getSheet()->_baseSheet);


}


void WRendererSFML::drawText(std::string str){
    
    sf::Text text = sf::Text(str, *_font, 25);
    text.setFillColor(sf::Color::Red);

    _window->draw( text);


}


bool WRendererSFML::ready(){
    return _ready;    
}