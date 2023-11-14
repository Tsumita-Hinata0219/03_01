#include "ResultSceneState.h"
#include "GameObject/BackGround/BackGround.h"



/// <summary>
/// 初期化処理
/// </summary>
void ResultSceneState::Initialize() {


}



/// <summary>
/// 更新処理
/// </summary>
void ResultSceneState::Update() {

	if (InputManager::KeysPress(DIK_N)) {
		sceneNo_ = TITLE;
	}
}



/// <summary>
/// 描画処理
/// </summary>
void ResultSceneState::Draw() {

	BackGround::DrawResult();
}