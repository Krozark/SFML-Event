#include <SFML/OpenGL.hpp>

#include "EventRenderTarget.hpp"
#include "../event/EventManager.hpp"


using namespace sf;

namespace ev
{

    EventRenderTarget::~EventRenderTarget()
    {
        int size = events.size();
        for (int i=0;i<size;++i)
        delete events[i];
    };

    void EventRenderTarget::doEvents()
    {

        Event event; // gestion des évenements
        elapsedTime =  LoopClock.restart().asMilliseconds();

        int size = events.size();
        for (int i=0;i<size;++i)
        if (events[i]->test())
        events[i]->execute(event);

        size = momentEvents.size();
        while(this->pollEvent(event))
        {
            for (int i=0;i<size;++i)
            if (*momentEvents[i] == event)
            {
                momentEvents[i]->execute(event);
                //break;
            }
        }
    };

};
