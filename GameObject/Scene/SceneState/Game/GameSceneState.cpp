#include "GameSceneState.h"
#include "GameObject/BackGround/BackGround.h"



/// <summary>
/// 初期化処理
/// </summary>
void GameSceneState::Initialize() {

	Player::Initialize();
	Enemy::Initialize();
}



/// <summary>
/// 更新処理
/// </summary>
void GameSceneState::Update() {

	Player::Update();
	Enemy::Update();

	if (Enemy::GetInstance()->GetIsDead() != true) {
		CheckCollision();
	}

	if (InputManager::KeysPress(DIK_N)) {
		sceneNo_ = RESULT;
	}
}



/// <summary>
/// 描画処理
/// </summary>
void GameSceneState::Draw() {

	BackGround::Draw(1);

	Player::Draw();
	Enemy::Draw();
}



void GameSceneState::CheckCollision() {

	Vector2 posA{}, posB{};

	// 示談のリスト取得
	const std::list<Bullet*>& bullets = Player::GetInstance()->GetBullet();

	posB = Enemy::GetInstance()->GetPosition();

	for (Bullet* bullet : bullets) {

		posA = bullet->GetPosition();

		float distAB =
			(posB.x - posA.x) * (posB.x - posA.x) +
			(posB.y - posA.y) * (posB.y - posA.y);

		float radiusAB = (bullet->GetRadius() + Enemy::GetInstance()->GetRadius());

  		if (distAB <= radiusAB) {

  			Enemy::GetInstance()->onCollision();
			bullet->onCollision();
		}
	}
}