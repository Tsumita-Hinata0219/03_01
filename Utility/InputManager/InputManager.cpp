#include "InputManager.h"



/// <summary>
/// Inputanagerのインスタンスの取得
/// </summary>
InputManager* InputManager::GetInstance()
{
	static InputManager instance;
	return &instance;
}



/// <summary>
/// キーの状態を更新して次のフレームに備える
/// </summary>
void InputManager::BeginFlame()
{
	memcpy(InputManager::GetInstance()->preKeys, InputManager::GetInstance()->keys, 256);
	Novice::GetHitKeyStateAll(InputManager::GetInstance()->keys);
}



/// <summary>
/// 押した瞬間
/// </summary>
bool InputManager::KeysPress(uint32_t preKeys)
{
	if (InputManager::GetInstance()->keys[preKeys] == 0 && InputManager::GetInstance()->preKeys[preKeys] != 0)
	{
		return true;
	}
	return false;
}



/// <summary>
/// 押し続ける
/// </summary>
bool InputManager::Keys(uint32_t key)
{
	if (InputManager::GetInstance()->keys[key] == 0x80)
	{
		return true;
	}
	return false;
}