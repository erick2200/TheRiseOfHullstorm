#ifndef OXIMORPHOS_FACTORY_H
#define OXIMORPHOS_FACTORY_H

#include "ecs/systems/unit/raceFactory.hpp"

class OximorphosFactory : public RaceFactory
{
private:
    EntityManager<Unit> *units;
public:

    void setUnits(EntityManager<Unit> *_units);

    Unit* createUnknown(const glm::vec3& pos,const glm::vec3& rot = glm::vec3(0.0f, 0.0f, 0.0f) , const glm::vec3& sca = glm::vec3(1.0f, 1.0f, 1.0f)) ;

    Unit* createVillager(const glm::vec3& pos,const glm::vec3& rot = glm::vec3(0.0f, 0.0f, 0.0f) , const glm::vec3& sca = glm::vec3(1.0f, 1.0f, 1.0f)) ;
    
    Unit* createCattle(const glm::vec3& pos,const glm::vec3& rot = glm::vec3(0.0f, 0.0f, 0.0f) , const glm::vec3& sca = glm::vec3(1.0f, 1.0f, 1.0f)) ;
    
    Unit* createSoilder(const glm::vec3& pos,const glm::vec3& rot = glm::vec3(0.0f, 0.0f, 0.0f) , const glm::vec3& sca = glm::vec3(1.0f, 1.0f, 1.0f)) ;
    
    Unit* createShooter(const glm::vec3& pos,const glm::vec3& rot = glm::vec3(0.0f, 0.0f, 0.0f) , const glm::vec3& sca = glm::vec3(1.0f, 1.0f, 1.0f)) ;

    Unit* createArchery(const glm::vec3& pos,const glm::vec3& rot = glm::vec3(0.0f, 0.0f, 0.0f) , const glm::vec3& sca = glm::vec3(1.0f, 1.0f, 1.0f)) ;

    Unit* createCastle(const glm::vec3& pos,const glm::vec3& rot = glm::vec3(0.0f, 0.0f, 0.0f) , const glm::vec3& sca = glm::vec3(1.0f, 1.0f, 1.0f)) ;

    Unit* createBarracks(const glm::vec3& pos,const glm::vec3& rot = glm::vec3(0.0f, 0.0f, 0.0f) , const glm::vec3& sca = glm::vec3(1.0f, 1.0f, 1.0f)) ;

    Unit* createFarm(const glm::vec3& pos,const glm::vec3& rot = glm::vec3(0.0f, 0.0f, 0.0f) , const glm::vec3& sca = glm::vec3(1.0f, 1.0f, 1.0f)) ;

    Unit* createMine(const glm::vec3& pos,const glm::vec3& rot = glm::vec3(0.0f, 0.0f, 0.0f) , const glm::vec3& sca = glm::vec3(1.0f, 1.0f, 1.0f)) ;

    Unit* spawnPineTree(const glm::vec3& pos,const glm::vec3& rot = glm::vec3(0.0f, 0.0f, 0.0f) , const glm::vec3& sca = glm::vec3(1.0f, 1.0f, 1.0f)) ;

    Unit* spawnTree(const glm::vec3& pos,const glm::vec3& rot = glm::vec3(0.0f, 0.0f, 0.0f) , const glm::vec3& sca = glm::vec3(1.0f, 1.0f, 1.0f)) ;
    
};

#include "oximorphosFactory.cpp"

#endif