#include <Novice.h>

#include "Utility/InputManager/InputManager.h"
#include "GameObject/Player/Player.h"


const char kWindowTitle[] = "PG3_03_01";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	const int ScreenWidth = 500;
	const int ScreenHeight = 500;
	Novice::Initialize(kWindowTitle, ScreenWidth, ScreenHeight);


	// 初期化処理
	Player::Initialize();


	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();
		InputManager::BeginFlame();

		
		///
		/// ↓更新処理ここから
		///

		Player::Update();

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		Player::Draw();

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (InputManager::KeysPress(DIK_ESCAPE)) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
