#include "gtest/gtest.h"

#ifndef _ORION_ENTITY
#define _ORION_ENTITY
#include "../../../include/OrionEntity.h"
#endif

#ifndef _CAMERA
#define _CAMERA
#include "../../../include/Camera.h"
#endif

#ifndef _COLLISION_MAP
#define _COLLISION_MAP
#include "../../../include/CollisionMap.h"
#endif

#ifndef _ORB
#define _ORB
#include "../../../include/Orb.h"
#endif

#ifndef _WALL
#define _WALL
#include "../../../include/Wall.h"
#endif

TEST(CollisionMapTest, test1) {
	std::vector<std::string> orbPaths;
	orbPaths.push_back("C:/Users/might/Downloads/orb.png");

	Orb* o = new Orb(700, 700, &orbPaths);

	std::vector<std::string> wallPaths;
	wallPaths.push_back("C:/Users/might/Downloads/wall.png");

	OrionEntity* w4 = new Wall(400, 1075, 800, 40, &wallPaths);

	CollisionMap* collisionMap = new CollisionMap(2000, 2000, 107);

	collisionMap->addHitboxes(o->getHitboxes());
	collisionMap->addHitboxes(w4->getHitboxes());

	o->setPosition(700, 1000);
	o->enactStateChanges();

	collisionMap->updateEntityPosition(o->getHitboxes());

	std::set<Hitbox*>* orbHitbox = o->getHitboxes();

	Hitbox* oHitbox;
	for (Hitbox* h : *orbHitbox) {
		oHitbox = h;
		break;
	}

	

    EXPECT_EQ(collisionMap->getCollidingEntities(oHitbox).size(), 1);
}