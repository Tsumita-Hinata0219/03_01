#include "Player.h"



/// <summary>
/// Playerのインスタンスの取得
/// </summary>
Player* Player::GetInstance() {
	static Player instance;
	return &instance;
}



/// <summary>
/// 初期化処理
/// </summary>
void Player::Initialize() {

	Player::GetInstance()->position_ = { 250.0f, 400 };
	Player::GetInstance()->velocity_ = { 9.0f, 9.0f };
	Player::GetInstance()->size_ = 20.0f;
	Player::GetInstance()->bulVelocity_ = -15.0f;
}


/// <summary>
/// 更新処理
/// </summary>
void Player::Update() {

	// 移動処理
	Player::GetInstance()->Move();

	// 射撃処理
	Player::GetInstance()->Shot();

	// バレットの更新処理
	for (Bullet* bul : Player::GetInstance()->bullets_) {

		bul->Update();
	}

	// バレットの削除
	Player::GetInstance()->DeleteBullet();
}


/// <summary>
/// 描画処理
/// </summary>
void Player::Draw() {

	Vector2 pos = Player::GetInstance()->position_;
	float size = Player::GetInstance()->size_;

	// プレイヤーの描画
	Novice::DrawTriangle(
		int(pos.x), int(pos.y),
		int(pos.x - size), int(pos.y + size),
		int(pos.x + size), int(pos.y + size),
		GREEN, kFillModeSolid);

	// バレットの描画
	for (Bullet* bul : Player::GetInstance()->bullets_) {

		bul->Draw();
	}
}



/// <summary>
/// 移動処理
/// </summary>
void Player::Move() {

	Vector2 pos = Player::GetInstance()->position_;
	Vector2 vel = Player::GetInstance()->velocity_;
	float size = Player::GetInstance()->size_;


	// 移動処理
	if (InputManager::Keys(DIK_A)) {

		if (pos.x - size >= 0) {

			pos.x -= vel.x;
		}
	}
	else if (InputManager::Keys(DIK_D)) {

		if (pos.x + size <= 500) {

			pos.x += vel.x;
		}
	}


	Player::GetInstance()->position_ = pos;
	Player::GetInstance()->velocity_ = vel;
}



/// <summary>
/// 射撃処理
/// </summary>
void Player::Shot() {

	// スペースを押したら
	if (InputManager::KeysPress(DIK_SPACE)) {

		// 球を生成し、初期化
		Bullet* newBullet = new Bullet();
		newBullet->Initialize(Player::GetInstance()->position_, Player::GetInstance()->bulVelocity_);

		bullets_.push_back(newBullet);
	}
}



/// <summary>
/// デスフラグの立った球を削除
/// </summary>
void Player::DeleteBullet() {

	Player::GetInstance()->bullets_.remove_if([](Bullet* bul) {

		if (bul->IsDead()) {
			delete bul;
			return true;
		}
		return false;
	});
}