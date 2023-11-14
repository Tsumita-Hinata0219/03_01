#include "TitleSceneState.h"
#include "GameObject/BackGround/BackGround.h"



/// <summary>
/// 初期化処理
/// </summary>
void TitleSceneState::Initialize() {


}



/// <summary>
/// 更新処理
/// </summary>
void TitleSceneState::Update() {


	if (InputManager::KeysPress(DIK_N)) {
		sceneNo_ = GAME;
	}
}



/// <summary>
/// 描画処理
/// </summary>
void TitleSceneState::Draw() {

	BackGround::Draw(0);
}