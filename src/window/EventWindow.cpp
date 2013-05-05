#include <SFML/OpenGL.hpp>

#include "EventWindow.hpp"

#include "../event/EventManager.hpp"

using namespace sf;

namespace event
{

EventWindow::EventWindow(const sf::VideoMode mode, const std::string &title,const unsigned int fps) : RenderWindow(mode,title)
{
    setFramerateLimit(fps);

    // Enable Z-buffer read and write
    //glEnable(GL_DEPTH_TEST);
    glDepthMask(GL_TRUE);
    glClearDepth(1.f);


    // Setup a perspective projection
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //gluPerspective(90.f, 1.f, 1.f, 500.f);

    addCloseEvent();
};

void EventWindow::addCloseEvent()
{
    addEvent(EventManager::createEventObj(*this,&EventWindow::close,sf::Event::Closed));
    addEvent(EventManager::createEventObj(*this,&EventWindow::close,sf::Event::KeyPressed,sf::Keyboard::Escape));
};

void EventWindow::resizeSlot(const sf::Event& event)
{
    sf::View view = getView();
    view.setSize(event.size.width,event.size.height);
    setView(view);
};


};
