#pragma once

#include "Utility/InputManager/InputManager.h"

#include <Novice.h>
#include <Vector2.h>




class Player {

public:

	/// <summary>
	/// Playerのインスタンスの取得
	/// </summary>
	static Player* GetInstance();

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

};