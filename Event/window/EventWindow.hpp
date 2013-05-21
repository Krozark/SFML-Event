#ifndef EVENTWINDOW_HPP
#define EVENTWINDOW_HPP

#include <SFML/Graphics.hpp>
#include "EventTarget.hpp"


namespace event
{

    class EventWindow : public sf::RenderWindow, public EventTarget
    {
        public:
            EventWindow(const sf::VideoMode mode, const std::string &title,const unsigned int max_fps=60);

            void addCloseEvent();
            void resizeSlot(const sf::Event& ev);
            bool pollEvent(sf::Event& event) {return RenderWindow::pollEvent(event);}
           /* void doEvents();


        private:
            sf::Clock LoopClock;
            int elapsedTime;*/
    };
};
#endif
