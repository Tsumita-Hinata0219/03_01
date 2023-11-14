#pragma once

#include "Utility/InputManager/InputManager.h"
#include "GameObject/Enemy/IEnemyState.h"
#include "GameObject/Enemy/State/IEnemyAliveState.h"
#include"GameObject/Enemy/State/IEnemyDeadState.h"

#include <Novice.h>
#include <Vector2.h>
#include <list>

#include "imgui.h"




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
	/// 移動処理
	/// </summary>
	void Move();

	/// <summary>
	/// リスポーン処理
	/// </summary>
	bool Respawn();

	/// <summary>
	/// ステートの変更
	/// </summary>
	void ChangeState(IEnemyState* newState);

	/// <summary>
	/// 衝突時判定
	/// </summary>
	static void onCollision();

	/// <summary>
	/// 取得
	/// </summary>
	Vector2 GetPosition() { return Enemy::GetInstance()->position_; }
	Vector2 GetVelocity() { return Enemy::GetInstance()->velocity_; }
	float GetRadius() { return Enemy::GetInstance()->size_; }
	bool GetIsDead() { return Enemy::GetInstance()->isDead_; }

	/// <summary>
	/// 設定
	/// </summary>
	void SetPosition(Vector2 pos) { Enemy::GetInstance()->position_ = pos; }
	void SetVelocity(Vector2 vel) { Enemy::GetInstance()->velocity_ = vel; }


private:

	// 座標
	Vector2 position_;

	// サイズ
	float size_;

	// 速度
	Vector2 velocity_;

	// 死亡フラグ
	bool isDead_;

	// リスポーンタイマー
	int reswawnTimer_;

	// ステートパターン
	IEnemyState* state_;
};