#include "EventTarget.hpp"
#include "../event/EventManager.hpp"


using namespace sf;

namespace event
{

    EventTarget::~EventTarget()
    {
        int size = events.size();
        for (int i=0;i<size;++i)
        delete events[i];
    };

    void EventTarget::doEvents()
    {

        Event event; // gestion des évenements

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
