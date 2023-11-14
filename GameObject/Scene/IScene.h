#pragma once



enum SCENE { TITLE, GAME, RESULT };


/* Isceneクラス */
class IScene {

public:

	/// <summary>
	/// デストラクタ
	/// </summary>
	virtual ~IScene();

	/// <summary>
	/// 初期化処理
	/// </summary>
	virtual void Initialize() = 0;

	/// <summary>
	/// 更新処理
	/// </summary>
	virtual void Update() = 0;

	/// <summary>
	/// 描画処理
	/// </summary>
	virtual void Draw() = 0;


#pragma region Get

	/// <summary>
	/// シーン番号の取得
	/// </summary>
	int GetSceneNo();

#pragma endregion


protected:

	static int sceneNo_;
};