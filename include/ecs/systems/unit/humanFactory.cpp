void HumanFactory::setUnits(EntityManager<Unit> *_units)
{
    units = _units;
}


Unit* HumanFactory::createUnknown(const glm::vec3& pos, const glm::vec3& rot, const glm::vec3& sca)
{
    Unit* unit = units->createEntity(); 
    unit->transform->position = pos;

    unit->meshRenderer->index = DEFAULT_MODEL;

    unit->stats->velocity = 10.0;

    unit->transform->rotation = rot;
    unit->transform->scale = sca;
}


Unit* HumanFactory::createVillager(const glm::vec3& pos, const glm::vec3& rot, const glm::vec3& sca)
{
    Unit* unit = units->createEntity(); 

    unit->transform->position = pos;

    unit->meshRenderer->index = VILLAGER_MODEL ;


    unit->stats->velocity = 5.0;
    unit->transform->rotation = rot;
    unit->transform->scale = sca;
}



Unit* HumanFactory::createCattle(const glm::vec3& pos, const glm::vec3& rot, const glm::vec3& sca)
{
    Unit* unit = units->createEntity();

    unit->transform->position = pos;

    unit->meshRenderer->index = CHICKEN_MODEL;

    unit->stats->velocity = 3.0;

    unit->transform->rotation = rot;
    unit->transform->scale = sca;
}


Unit* HumanFactory::createSoilder(const glm::vec3& pos, const glm::vec3& rot, const glm::vec3& sca)
{
    Unit* unit = units->createEntity(); 

    unit->transform->position = pos;

    unit->meshRenderer->index = DEFAULT_MODEL ;

    unit->stats->velocity = 9.0;

    unit->transform->rotation = rot;
    unit->transform->scale = sca;
}



Unit* HumanFactory::createShooter(const glm::vec3& pos, const glm::vec3& rot, const glm::vec3& sca)
{
    Unit* unit = units->createEntity(); 

    unit->transform->position = pos;

    unit->meshRenderer->index = DEFAULT_MODEL ;

    unit->stats->velocity = 7.0;

    unit->transform->rotation = rot;
    unit->transform->scale = sca;
}


////////// STRUCTS "MOTIONLESS" XD

Unit* HumanFactory::createArchery(const glm::vec3& pos, const glm::vec3& rot, const glm::vec3& sca) 
{
    Unit* unit = units->createEntity();

    unit->meshRenderer->index = DEFAULT_MODEL;    //ARCHERY_MODEL ;
    unit->transform->scale = { 2.5f, 2.5f, 2.5f };
    unit->transform->position = pos;
    unit->transform->rotation = rot;
    unit->transform->scale    = sca;

    unit->stats->velocity = 0.0f;

}

Unit* HumanFactory::createCastle(const glm::vec3& pos, const glm::vec3& rot, const glm::vec3& sca) 
{
    Unit* unit = units->createEntity();

    unit->meshRenderer->index = DEFAULT_MODEL;        //CASTLE_MODEL ;
    unit->transform->scale = { 2.5f, 2.5f, 2.5f };
    unit->transform->position = pos;
    unit->transform->rotation = rot;
    unit->transform->scale    = sca;

    unit->stats->velocity = 0.0f;

}

Unit* HumanFactory::createBarracks(const glm::vec3& pos, const glm::vec3& rot, const glm::vec3& sca)
{
    Unit* unit = units->createEntity();

    unit->meshRenderer->index = DEFAULT_MODEL;      //  BARRACKS_MODEL;
    unit->transform->scale = { 2.5f, 2.5f, 2.5f };
    unit->transform->position = pos;
    unit->transform->rotation = rot;
    unit->transform->scale    = sca;


    unit->stats->velocity = 0.0f;

}

Unit* HumanFactory::createFarm(const glm::vec3& pos, const glm::vec3& rot, const glm::vec3& sca)
{
    Unit* unit = units->createEntity();

    unit->meshRenderer->index = DEFAULT_MODEL;      // FARM_MODEL;
    unit->transform->scale = { 2.5f, 2.5f, 2.5f };
    unit->transform->position = pos;
    unit->transform->rotation = rot;
    unit->transform->scale    = sca;

    unit->stats->velocity = 0.0f;

}

Unit* HumanFactory::createMine(const glm::vec3& pos, const glm::vec3& rot, const glm::vec3& sca)
{
    Unit* unit = units->createEntity();

    unit->meshRenderer->index = DEFAULT_MODEL;      // MINE_MODEL;
    unit->transform->scale = { 2.5f, 2.5f, 2.5f };
    unit->transform->position = pos;
    unit->transform->rotation = rot;
    unit->transform->scale    = sca;

    unit->stats->velocity = 0.0f;

}

Unit* HumanFactory::spawnPineTree(const glm::vec3& pos, const glm::vec3& rot, const glm::vec3& sca) 
{
    Unit* unit = units->createEntity();

    unit->meshRenderer->index = DEFAULT_MODEL;      // PINE_TREE_MODEL;
    unit->transform->scale = { 2.5f, 2.5f, 2.5f };
    unit->transform->position = pos;
    unit->transform->rotation = rot;
    unit->transform->scale    = sca;

    unit->stats->velocity = 0.0f;

}
    
Unit* HumanFactory::spawnTree(const glm::vec3& pos, const glm::vec3& rot, const glm::vec3& sca) 
{
    Unit* unit = units->createEntity();

    unit->meshRenderer->index = TREE_MODEL;
    unit->transform->scale = { 2.5f, 2.5f, 2.5f };
    unit->transform->position = pos;
    unit->transform->rotation = rot;
    unit->transform->scale    = sca;

    unit->stats->velocity = 0.0f;
}
 