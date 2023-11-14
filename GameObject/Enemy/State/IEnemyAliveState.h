#pragma once
#include"GameObject/Enemy/IEnemyState.h"


class IEnemyAliveState : public IEnemyState {

public:

	void Update(Enemy* pEnemy) override;
};