#include "IEnemyAliveState.h"
#include "GameObject/Enemy/Enemy.h"


void IEnemyAliveState::Update(Enemy* pEnemy) {

	pEnemy->Move();

	if (pEnemy->GetIsDead()) {

		pEnemy->ChangeState(new IEnemyDeadState());
	}
}

