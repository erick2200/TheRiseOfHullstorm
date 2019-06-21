#ifndef HUMAN_FACTORY_H
#define HUMAN_FACTORY_H

#include "ecs/systems/unit/raceFactory.hpp"

class HumanFactory : public RaceFactory
{
private:
    EntityManager<Unit> *units;
public:

    void setUnits(EntityManager<Unit> *_units);

    Unit* createUnknown(const glm::vec3& pos) ;
    Unit* createUnknown(const glm::vec3& pos, const glm::vec3& rot, const glm::vec3& sca) ;

    Unit* createVillager(const glm::vec3& pos) ;
    Unit* createVillager(const glm::vec3& pos, const glm::vec3& rot, const glm::vec3& sca) ;
    
    Unit* createCattle(const glm::vec3& pos) ;
    Unit* createCattle(const glm::vec3& pos, const glm::vec3& rot, const glm::vec3& sca) ;
    
    Unit* createSoilder(const glm::vec3& pos) ;
    Unit* createSoilder(const glm::vec3& pos, const glm::vec3& rot, const glm::vec3& sca) ;
    
    Unit* createShooter(const glm::vec3& pos) ;
    Unit* createShooter(const glm::vec3& pos, const glm::vec3& rot, const glm::vec3& sca) ;

    Unit* spawnTree(const glm::vec3& pos);
    Unit* spawnTree(const glm::vec3& pos, const glm::vec3& rot, const glm::vec3& sca) ;
    
    
};



void HumanFactory::setUnits(EntityManager<Unit> *_units)
{
    units = _units;
}

Unit* HumanFactory::createUnknown(const glm::vec3& pos)
{

    Unit* unit = units->createEntity(); 
    unit->transform->position = pos;

    unit->meshRenderer->index = DEFAULT_MODEL;

    unit->stats->velocity = 10.0;
  
    return unit;
}

Unit* HumanFactory::createUnknown(const glm::vec3& pos, const glm::vec3& rot, const glm::vec3& sca)
{
    Unit* unit = createUnknown(pos);
    unit->transform->rotation = rot;
    unit->transform->scale = sca;
}

Unit* HumanFactory::createVillager(const glm::vec3& pos)
{
    Unit* unit = units->createEntity(); 

    unit->transform->position = pos;

    unit->meshRenderer->index = VILLAGER_MODEL ;

    unit->stats->velocity = 5.0;
  
    return unit;
}

Unit* HumanFactory::createVillager(const glm::vec3& pos, const glm::vec3& rot, const glm::vec3& sca)
{
    Unit* unit = createVillager(pos);
    unit->transform->rotation = rot;
    unit->transform->scale = sca;
}

Unit* HumanFactory::createCattle(const glm::vec3& pos)
{

    Unit* unit = units->createEntity();

    unit->transform->position = pos;

    unit->meshRenderer->index = CHICKEN_MODEL ;

    unit->stats->velocity = 3.0;
  
    return unit;
}

Unit* HumanFactory::createCattle(const glm::vec3& pos, const glm::vec3& rot, const glm::vec3& sca)
{
    Unit* unit = createCattle(pos);
    unit->transform->rotation = rot;
    unit->transform->scale = sca;
}

Unit * HumanFactory::createSoilder(const glm::vec3& pos)
{
    Unit* unit = units->createEntity(); 

    unit->transform->position = pos;

    unit->meshRenderer->index = DEFAULT_MODEL ;

    unit->stats->velocity = 9.0;
  
    return unit;
}

Unit* HumanFactory::createSoilder(const glm::vec3& pos, const glm::vec3& rot, const glm::vec3& sca)
{
    Unit* unit = createSoilder(pos);
    unit->transform->rotation = rot;
    unit->transform->scale = sca;
}

Unit * HumanFactory::createShooter(const glm::vec3& pos)
{
    Unit* unit = units->createEntity(); 

    unit->transform->position = pos;

    unit->meshRenderer->index = DEFAULT_MODEL ;

    unit->stats->velocity = 7.0;
  
    return unit;
}

Unit* HumanFactory::createShooter(const glm::vec3& pos, const glm::vec3& rot, const glm::vec3& sca)
{
    Unit* unit = createShooter(pos);
    unit->transform->rotation = rot;
    unit->transform->scale = sca;
}

Unit* HumanFactory::spawnTree(const glm::vec3& pos)
{
    Unit* unit = units->createEntity();

    unit->meshRenderer->index = TREE_MODEL;
    unit->transform->scale = { 2.5f, 2.5f, 2.5f };
    unit->transform->position = pos;


    unit->stats->velocity = 10.0f;
}
    
Unit* HumanFactory::spawnTree(const glm::vec3& pos, const glm::vec3& rot, const glm::vec3& sca) 
{
    Unit* unit = units->createEntity();

    unit->transform->position = pos;
    unit->transform->rotation = rot;
    unit->transform->scale    = sca;

    unit->meshRenderer->index = TREE_MODEL;

    unit->stats->velocity = 0.0f;
}
    

#endif