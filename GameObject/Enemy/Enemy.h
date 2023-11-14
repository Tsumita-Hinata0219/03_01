#pragma once

#include "Utility/InputManager/InputManager.h"

#include <Novice.h>
#include <Vector2.h>
#include <list>




class Enemy {

public:

	/// <summary>
	/// Playerのインスタンスの取得
	/// </summary>
	static Enemy* GetInstance();

	/// <summary>
	/// 初期化処理
	/// </summary>
	static void Initialize();

	/// <summary>
	/// 更新処理
	/// </summary>
	static void Update();

	/// <summary>
	/// 描画処理
	/// </summary>
	static void Draw();

	/// <summary>
	/// 衝突時判定
	/// </summary>
	static void onCollision();

	/// <summary>
	/// 座標の取得
	/// </summary>
	Vector2 GetPosition() { return Enemy::GetInstance()->position_; }

	
	float GetRadius() { return Enemy::GetInstance()->size_; }


private:

	/// <summary>
	/// 移動処理
	/// </summary>
	void Move();


private:

	// 座標
	Vector2 position_;

	// サイズ
	float size_;

	// 速度
	Vector2 velocity_;

	// 弾速
	float bulVelocity_;

};