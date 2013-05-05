#ifndef EVENTRENDERTARGET_HPP
#define EVENTRENDERTARGET_HPP

#include <SFML/Graphics.hpp>
#include "../event/BaseEventCallable.hpp"

namespace ev
{

    class EventRenderTarget : public sf::RenderTarget
    {
        public:
            ~EventRenderTarget();

            inline void addEvent(BaseEventCallable* ev,bool hold=false)
            {
                if (hold && (ev->event.type == sf::Event::KeyPressed || ev->event.type == sf::Event::MouseButtonPressed || ev->event.type == sf::Event::JoystickButtonPressed))
                    events.push_back(ev);
                else
                    momentEvents.emplace_back(ev);
            };

            void doEvents();

        private:
            std::vector<BaseEventCallable*> momentEvents;
            std::vector<BaseEventCallable*> events;
    };

};
#endif
