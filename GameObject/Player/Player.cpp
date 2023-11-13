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

}


/// <summary>
/// 更新処理
/// </summary>
void Player::Update() {

	Player::GetInstance()->Move();
}


/// <summary>
/// 描画処理
/// </summary>
void Player::Draw() {

	Vector2 pos = Player::GetInstance()->position_;
	float size = Player::GetInstance()->size_;

	Novice::DrawTriangle(
		int(pos.x), int(pos.y),
		int(pos.x - size), int(pos.y + size),
		int(pos.x + size), int(pos.y + size),
		GREEN, kFillModeSolid);
}



/// <summary>
/// 移動処理
/// </summary>
void Player::Move() {

	Vector2 pos = Player::GetInstance()->position_;

	if (InputManager::Keys(DIK_A)) {

		pos.x -= Player::GetInstance()->velocity_.x;
	}



	Player::GetInstance()->position_ = pos;
}