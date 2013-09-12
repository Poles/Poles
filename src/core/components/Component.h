#include <Artemis/Artemis.h>

class Component : public artemis::Component{
public:
        Component() { }
        virtual ~Component() { }

        virtual const char * toString() = 0;

};