#ifndef EVENTTARGET_HPP
#define EVENTTARGET_HPP

#include "../event/BaseEventCallable.hpp"

#include <vector>

namespace event
{

    class EventTarget
    {
        public:
            ~EventTarget();

            inline void addEvent(BaseEventCallable* ev,bool hold=false)
            {
                if (hold && (ev->event.type == sf::Event::KeyPressed || ev->event.type == sf::Event::MouseButtonPressed || ev->event.type == sf::Event::JoystickButtonPressed))
                    events.push_back(ev);
                else
                    momentEvents.emplace_back(ev);
            };

            void doEvents();

            virtual bool pollEvent(sf::Event &event) = 0;

        private:
            std::vector<BaseEventCallable*> momentEvents;
            std::vector<BaseEventCallable*> events;
    };

};
#endif
