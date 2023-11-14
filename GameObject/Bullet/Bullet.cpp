#include "Bullet.h"



/// <summary>
/// 初期化処理
/// </summary>
void Bullet::Initialize(Vector2 pos, float vel) {

	position_ = pos;
	velocity_ = vel;
	radius_ = 8.0f;
	deathTimer_ = kLifeTimer_;
	isDead_ = false;
}



/// <summary>
/// 更新処理
/// </summary>
void Bullet::Update() {

	// 移動処理
	Move();

	// 寿命を減らす
	SubtructBulletLife();
}



/// <summary>
/// 描画処理
/// </summary>
void Bullet::Draw() {

	Novice::DrawEllipse(
		int(position_.x), int(position_.y),
		int(radius_), int(radius_),
		0.0f, BLACK, kFillModeSolid);
}



/// <summary>
/// 移動処理
/// </summary>
void Bullet::Move() {

	position_.y += velocity_;
}



/// <summary>
/// 寿命を減らす
/// </summary>
void Bullet::SubtructBulletLife() {

	if (--deathTimer_ <= 0) {

		isDead_ = true;
	}
}



/// <summary>
/// 衝突時判定
/// </summary>
void Bullet::onCollision() {
	isDead_ = true;
}