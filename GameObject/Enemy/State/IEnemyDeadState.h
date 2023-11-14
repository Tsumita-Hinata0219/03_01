#pragma once
#include "GameObject/Enemy/IEnemyState.h"


class IEnemyDeadState : public IEnemyState {

public: 

	void Update(Enemy* pEnemy) override;
};