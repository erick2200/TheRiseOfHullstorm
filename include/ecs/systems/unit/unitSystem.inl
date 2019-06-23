EntityManager<Unit> UnitSystem::units;
RaceFactory* UnitSystem::fabrica;

void UnitSystem::init()
{
    Unit* unit;
    fabrica = FactoryMethod::getRace(HUMAN_RACE) ;
    fabrica->setUnits(&units);
    
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

void UnitSystem::createSoilder(const glm::vec3& pos, const glm::vec3& rot, const glm::vec3& sca)
{
    fabrica->createSoilder(pos,rot,sca);
}

void UnitSystem::createShooter(const glm::vec3& pos, const glm::vec3& rot, const glm::vec3& sca)
{
    fabrica->createShooter(pos,rot,sca);
}

void UnitSystem::createArchery(const glm::vec3& pos, const glm::vec3& rot, const glm::vec3& sca)
{
    fabrica->createArchery(pos,rot,sca);
}

void UnitSystem::createCastle(const glm::vec3& pos, const glm::vec3& rot, const glm::vec3& sca)
{
    fabrica->createCastle(pos,rot,sca);
}

void UnitSystem::createBarracks(const glm::vec3& pos, const glm::vec3& rot, const glm::vec3& sca)  
{
    fabrica->createBarracks(pos,rot,sca);
}

void UnitSystem::createFarm(const glm::vec3& pos, const glm::vec3& rot, const glm::vec3& sca)
{
    fabrica->createFarm(pos,rot,sca);
}

void UnitSystem::createMine(const glm::vec3& pos, const glm::vec3& rot, const glm::vec3& sca)
{
    fabrica->createMine(pos,rot,sca);
}

void UnitSystem::spawnPineTree(const glm::vec3& pos, const glm::vec3& rot, const glm::vec3& sca)
{
    fabrica->spawnPineTree(pos,rot,sca);
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
