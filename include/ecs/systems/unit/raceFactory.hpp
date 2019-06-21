#ifndef ABSTRAC_FACTORY_H
#define ABSTRAC_FACTORY_H

#include "ecs/entities/entityManager.hpp"

class RaceFactory
{
public:
    virtual void setUnits(EntityManager<Unit> *units) = 0; 

    virtual Unit* createUnknown(const glm::vec3& pos) = 0 ;
    virtual Unit* createUnknown(const glm::vec3& pos,const glm::vec3& rot, const glm::vec3& sca) = 0;

    virtual Unit* createVillager(const glm::vec3& pos) = 0 ;
    virtual Unit* createVillager(const glm::vec3& pos, const glm::vec3& rot, const glm::vec3& sca) = 0;
    
    virtual Unit* createCattle(const glm::vec3& pos) = 0 ;
    virtual Unit* createCattle(const glm::vec3& pos, const glm::vec3& rot, const glm::vec3& sca) = 0;

    virtual Unit* createSoilder(const glm::vec3& pos) =0 ;
    virtual Unit* createSoilder(const glm::vec3& pos, const glm::vec3& rot, const glm::vec3& sca) = 0;
    
    virtual Unit* createShooter(const glm::vec3& pos) = 0 ;
    virtual Unit* createShooter(const glm::vec3& pos, const glm::vec3& rot, const glm::vec3& sca) = 0;

    virtual Unit* spawnTree(const glm::vec3& pos) = 0;
    virtual Unit* spawnTree(const glm::vec3& pos, const glm::vec3& rot, const glm::vec3& sca) = 0;
};

#endif