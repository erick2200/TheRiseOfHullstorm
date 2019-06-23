#ifndef SINGLETRON_RACE_H
#define SINGLETRON_RACE_H

#include "ecs/systems/unit/humanFactory.hpp"

class FactoryMethod
{
    private:
        FactoryMethod(){}
        static RaceFactory* race ;
    public:
        static RaceFactory* getRace(uint32 _race);
        static void destroy();
};


RaceFactory* FactoryMethod::race = NULL; 

RaceFactory* FactoryMethod::getRace(uint32 _race)
{
    switch (_race)
    {
    case HUMAN_RACE:
        race =  new HumanFactory();
        break;
    }
    return race;
}

void FactoryMethod::destroy()
{ 
    if(race != NULL)
        delete race;
}

#endif

