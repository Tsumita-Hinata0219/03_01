#pragma once

#include<Novice.h>
#include<format>



class InputManager {

public:

	/// <summary>
	/// Inputanagerのインスタンスの取得
	/// </summary>
	static InputManager* GetInstance();

	/// <summary>
	/// キーの状態を更新して次のフレームに備える
	/// </summary>
	static void BeginFlame();

	/// <summary>
	/// 押した瞬間
	/// </summary>
	static bool KeysPress(uint32_t key);

	/// <summary>
	/// 押し続ける
	/// </summary>
	static bool Keys(uint32_t key);

private:

	char keys[256] = { 0 };
	char preKeys[256] = { 0 };
};