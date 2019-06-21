EntityManager<Unit> UnitSystem::units;
RaceFactory* UnitSystem::fabrica;

void UnitSystem::init()
{
    Unit* unit;
    fabrica = FactoryMethod::getRace(HUMAN_RACE) ;
    fabrica->setUnits(&units);
    
    // VILLAGERS
    for(size_t i = 0; i < 5; ++i)
    {
        glm::vec3 pos;
        pos.x = 4.0f * i - 8.0f;
        pos.y = 64.0f * i;
        pos.z = 8.0f;

        fabrica->createVillager(pos);
    }

    // CHICKENS
    for(size_t i = 0; i < 5; ++i)
    {
        glm::vec3 pos;
        pos.x = 4.0f * i - 8.0f;
        pos.y = 64.0f * i;
        pos.z = 8.0f;

        fabrica->createCattle(pos);
    }

    // TREES
    for(size_t i = 0; i < 5; ++i)
    {
        glm::vec3 pos;
        pos.x = 4.0f * i - 8.0f;
        pos.y = 64.0f * i;
        pos.z = 8.0f;

        fabrica->spawnTree(pos);
    }

}

void UnitSystem::createUnknown(const glm::vec3& pos, const glm::vec3& rot, const glm::vec3& sca)
{
    fabrica->createUnknown(pos,rot,sca);
}

void UnitSystem::createVillager(const glm::vec3& pos, const glm::vec3& rot, const glm::vec3& sca)
{
    fabrica->createVillager(pos,rot,sca);
}

void UnitSystem::createChicken(const glm::vec3& pos, const glm::vec3& rot, const glm::vec3& sca)
{
    fabrica->createCattle(pos,rot,sca);
}

void UnitSystem::spawnTree(const glm::vec3& pos, const glm::vec3& rot, const glm::vec3& sca)
{
    fabrica->spawnTree(pos,rot,sca);
}

void UnitSystem::clear()
{
    units.clear();
}

void UnitSystem::update(float deltaTime)
{
    //
}

void UnitSystem::destroy()
{
    FactoryMethod::destroy();
    units.clear();
}

EntityManager<Unit>& UnitSystem::getUnits()
{
    return units;
}
