#ifndef ECS_PLAYER_SYSTEM_H
#define ECS_PLAYER_SYSTEM_H

#include "ecs/component/componentManager.hpp"
#include "ecs/entities/entityManager.hpp"

/* Input System:
 * --------------
 * Entities: 1
 * Components: 3
 * -------------- */
class PlayerSystem
{
public:
    static void init();
    static void update(float deltaTime);
    static void  destroy();
    static void setRace(uint32 race);

    static void createVillager(const glm::vec3& pos);
    static void createChicken(const glm::vec3& pos);

    static uint32 race;
    static Unit* dummy;
};

#endif // ECS_PLAYER_SYSTEM_H
