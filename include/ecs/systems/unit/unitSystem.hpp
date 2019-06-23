#ifndef ECS_UNIT_SYSTEM_H
#define ECS_UNIT_SYSTEM_H

#include "ecs/entities/entityManager.hpp"
#include "ecs/systems/unit/factoryRace.hpp"

/* Unit System:
 * ---------------
 * Entities: n
 * Components: 3n
 * --------------- */

class UnitSystem
{
public:
    static void init();
    static void update(float deltaTime);
    static void destroy();

    static void clear();

    static void createUnknown(const glm::vec3& pos,const glm::vec3& rot = glm::vec3(0.0f, 0.0f, 0.0f), const glm::vec3& sca = glm::vec3(1.0f, 1.0f, 1.0f));

    static void createVillager(const glm::vec3& pos, const glm::vec3& rot = glm::vec3(0.0f, 0.0f, 0.0f), const glm::vec3& sca = glm::vec3(1.0f, 1.0f, 1.0f));
    static void createChicken(const glm::vec3& pos, const glm::vec3& rot = glm::vec3(0.0f, 0.0f, 0.0f), const glm::vec3& sca = glm::vec3(1.0f, 1.0f, 1.0f));
    
    static void spawnTree(const glm::vec3& pos, const glm::vec3& rot = glm::vec3(0.0f, 0.0f, 0.0f), const glm::vec3& sca = glm::vec3(1.0f, 1.0f, 1.0f));

    static EntityManager<Unit>& getUnits();

    static void setRace(uint32);

private:
    static RaceFactory *fabrica;
    static EntityManager<Unit> units;
};

#endif // ECS_UNIT_SYSTEM_H
