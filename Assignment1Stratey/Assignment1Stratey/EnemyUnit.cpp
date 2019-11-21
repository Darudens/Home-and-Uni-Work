#include "EnemyUnit.h"
#include "Units.h"
EnemyUnit::EnemyUnit()
{
	CreateUnitSprite(new olc::Sprite("Skeleton.png"));
	SetStats(5, 4, 4, 5);
	SetPositionX(518);
	SetPositionY(240);
	SetAllianceStatusToEnemy();
}
