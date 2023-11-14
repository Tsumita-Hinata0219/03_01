#include "IEnemyDeadState.h"
#include "GameObject/Enemy/Enemy.h"


void IEnemyDeadState::Update(Enemy* pEnemy) {

	if (pEnemy->Respawn()) {

		pEnemy->ChangeState(new IEnemyAliveState());
	}
}

