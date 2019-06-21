uint32 PlayerSystem::race = HUMAN_RACE ;
Unit* PlayerSystem::dummy;



void PlayerSystem::init()
{
    dummy = new Unit;
    dummy->init(0);
    race = HUMAN_RACE;

    dummy->meshRenderer->alpha = 0.25f;
    dummy->meshRenderer->isVisible = false;
}

void PlayerSystem::update(float deltaTime)
{
    //
}

void PlayerSystem::destroy()
{
    dummy->destroy();
    delete dummy;
}

void PlayerSystem::setRace(uint32 _race)
{
    race = _race;
}

void PlayerSystem::createVillager(const glm::vec3& pos)
{
    UnitSystem::createVillager(pos);
}

void PlayerSystem::createChicken(const glm::vec3& pos)
{
    UnitSystem::createChicken(pos);
}
