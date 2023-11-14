#pragma once

#include "Utility/InputManager/InputManager.h"

#include <Novice.h>
#include <Vector2.h>



class Bullet {

public:

	/// <summary>
	/// 初期化処理
	/// </summary>
	void Initialize(Vector2 pos, float vel);

	/// <summary>
	/// 更新処理
	/// </summary>
	void Update();

	/// <summary>
	/// 描画処理
	/// </summary>
	void Draw();

	/// <summary>
	/// 衝突時判定
	/// </summary>
	void onCollision();


#pragma region Get

	Vector2 GetPosition() { return position_; }
	float GetRadius() { return radius_; }

	bool IsDead() const { return isDead_; }

#pragma endregion


private:

	/// <summary>
	/// 移動処理
	/// </summary>
	void Move();

	/// <summary>
	/// 寿命を減らす
	/// </summary>
	void SubtructBulletLife();


private:

	// 座標
	Vector2 position_;

	// 半径
	float radius_;

	// 速度
	float velocity_;

	// 寿命 <5秒>
	static const int32_t kLifeTimer_ = 60 * 5;

	// デスタイマー
	int deathTimer_;

	// デスフラグ
	bool isDead_;

};