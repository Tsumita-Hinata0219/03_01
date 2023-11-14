#pragma once


// Enemyの前方宣言
class Enemy;

class IEnemyState {

public:

	virtual void Update(Enemy* pEnemy) = 0;
};

