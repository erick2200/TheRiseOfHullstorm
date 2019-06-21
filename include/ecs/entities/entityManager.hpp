#ifndef ECS_ENTITY_MANAGER_H
#define ECS_ENTITY_MANAGER_H

#include "ecs/entities/entity.hpp"

template <typename E>
class EntityManager
{
public:
    explicit EntityManager() {}
    virtual ~EntityManager();

    E* createEntity();
    bool removeEntity(E* entity);
    void clear();

    void printEntities();

private:
    uint32 currentID = 0;
    List<Entity*> entities;
};

#endif // ECS_ENTITY_MANAGER_H
