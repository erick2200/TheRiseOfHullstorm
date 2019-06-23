#ifndef ABSTRAC_FACTORY_H
#define ABSTRAC_FACTORY_H

#include "ecs/entities/entityManager.hpp"

class RaceFactory
{
public:
    virtual void setUnits(EntityManager<Unit> *units) = 0; 

    virtual Unit* createUnknown(const glm::vec3& pos,const glm::vec3& rot = glm::vec3(0.0f, 0.0f, 0.0f) , const glm::vec3& sca = glm::vec3(1.0f, 1.0f, 1.0f)) = 0;

    virtual Unit* createVillager(const glm::vec3& pos,const glm::vec3& rot = glm::vec3(0.0f, 0.0f, 0.0f) , const glm::vec3& sca = glm::vec3(1.0f, 1.0f, 1.0f)) = 0;
    
    virtual Unit* createCattle(const glm::vec3& pos, const glm::vec3& rot = glm::vec3(0.0f, 0.0f, 0.0f) , const glm::vec3& sca = glm::vec3(1.0f, 1.0f, 1.0f)) = 0;

    virtual Unit* createSoilder(const glm::vec3& pos,const glm::vec3& rot = glm::vec3(0.0f, 0.0f, 0.0f) , const glm::vec3& sca = glm::vec3(1.0f, 1.0f, 1.0f)) = 0;
    
    virtual Unit* createShooter(const glm::vec3& pos,const glm::vec3& rot = glm::vec3(0.0f, 0.0f, 0.0f) , const glm::vec3& sca = glm::vec3(1.0f, 1.0f, 1.0f)) = 0;

    virtual Unit* createArchery(const glm::vec3& pos,const glm::vec3& rot = glm::vec3(0.0f, 0.0f, 0.0f) , const glm::vec3& sca = glm::vec3(1.0f, 1.0f, 1.0f)) = 0;
    
    virtual Unit* createCastle(const glm::vec3& pos,const glm::vec3& rot = glm::vec3(0.0f, 0.0f, 0.0f) , const glm::vec3& sca = glm::vec3(1.0f, 1.0f, 1.0f)) = 0;

    virtual Unit* createBarracks(const glm::vec3& pos,const glm::vec3& rot = glm::vec3(0.0f, 0.0f, 0.0f) , const glm::vec3& sca = glm::vec3(1.0f, 1.0f, 1.0f)) = 0;

    virtual Unit* createFarm(const glm::vec3& pos,const glm::vec3& rot = glm::vec3(0.0f, 0.0f, 0.0f) , const glm::vec3& sca = glm::vec3(1.0f, 1.0f, 1.0f)) = 0;

    virtual Unit* createMine(const glm::vec3& pos,const glm::vec3& rot = glm::vec3(0.0f, 0.0f, 0.0f) , const glm::vec3& sca = glm::vec3(1.0f, 1.0f, 1.0f)) = 0;

    virtual Unit* spawnPineTree(const glm::vec3& pos,const glm::vec3& rot = glm::vec3(0.0f, 0.0f, 0.0f) , const glm::vec3& sca = glm::vec3(1.0f, 1.0f, 1.0f)) = 0;    

    virtual Unit* spawnTree(const glm::vec3& pos,const glm::vec3& rot = glm::vec3(0.0f, 0.0f, 0.0f) , const glm::vec3& sca = glm::vec3(1.0f, 1.0f, 1.0f)) = 0;
};

#endif