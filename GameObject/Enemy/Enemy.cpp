#include "Enemy.h"



/// <summary>
/// Enemyのインスタンスの取得
/// </summary>
Enemy* Enemy::GetInstance() {
	static Enemy instance;
	return &instance;
}



/// <summary>
/// 初期化処理
/// </summary>
void Enemy::Initialize() {

	Enemy::GetInstance()->position_ = { 250.0f, 100.0f };
	Enemy::GetInstance()->velocity_ = { 8.0f, 8.0f };
	Enemy::GetInstance()->size_ = 30.0f;
	Enemy::GetInstance()->bulVelocity_ = 11.0f;
}



/// <summary>
/// 更新処理
/// </summary>
void Enemy::Update() {

	// 移動処理
	Enemy::GetInstance()->Move();
}



/// <summary>
/// 描画処理
/// </summary>
void Enemy::Draw() {

	Vector2 pos = Enemy::GetInstance()->position_;
	float size = Enemy::GetInstance()->size_;

	// プレイヤーの描画
	Novice::DrawTriangle(
		int(pos.x), int(pos.y),
		int(pos.x - size), int(pos.y - size),
		int(pos.x + size), int(pos.y - size),
		RED, kFillModeSolid);

}


void Enemy::onCollision() {

}



/// <summary>
/// 移動処理
/// </summary>
void Enemy::Move() {

	Vector2 pos = Enemy::GetInstance()->position_;
	Vector2 vel = Enemy::GetInstance()->velocity_;
	float size = Enemy::GetInstance()->size_;
	

	// 移動処理
	pos.x += velocity_.x;

	if (pos.x - size <= 0 || pos.x + size >= 500) {
		vel.x *= -1.0f;
	}


	Enemy::GetInstance()->position_ = pos;
	Enemy::GetInstance()->velocity_ = vel;

}


