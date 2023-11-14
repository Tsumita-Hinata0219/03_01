#include "GameManager.h"
#include "GameObject/BackGround/BackGround.h"

const char kWindowTitle[] = "PG3_03_01";


/// <summary>
/// コンストラクタ
/// </summary>
GameManager::GameManager() {

	// ライブラリの初期化
	const int ScreenWidth = 500;
	const int ScreenHeight = 500;
	Novice::Initialize(kWindowTitle, ScreenWidth, ScreenHeight);

	BackGround::Initialize();


	// 各シーンの配列
	sceneArr_[TITLE] = std::make_unique<TitleSceneState>();
	sceneArr_[GAME] = std::make_unique<GameSceneState>();
	sceneArr_[RESULT] = std::make_unique<ResultSceneState>();

	// 初期シーンの設定
	currentSceneNo_ = TITLE;
	sceneArr_[currentSceneNo_]->Initialize();
}



/// <summary>
/// デストラクタ
/// </summary>
GameManager::~GameManager() {

	// ライブラリの終了
	Novice::Finalize();
}



/// <summary>
/// この関数でゲームループを呼び出す
/// </summary>
int GameManager::Run() {

	while (Novice::ProcessMessage() == 0) {

		Novice::BeginFrame(); // フレームの開始
		InputManager::BeginFlame();

		// シーンのチェック
		preSceneNo_ = currentSceneNo_;
		currentSceneNo_ = sceneArr_[currentSceneNo_]->GetSceneNo();

		// シーンの変更チェック
		if (preSceneNo_ != currentSceneNo_) {

			////// 初期化処理
			sceneArr_[currentSceneNo_]->Initialize();
		}

		///// 更新処理
		sceneArr_[currentSceneNo_]->Update();

		///// 描画処理
		sceneArr_[currentSceneNo_]->Draw();


		Novice::EndFrame(); // フレームの終了


		// ESCキーが押されたらループを抜ける
		if (InputManager::KeysPress(DIK_ESCAPE)) {
			break;
		}
	}

	return 0;
}