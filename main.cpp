#include <Novice.h>

#include "Utility/InputManager/InputManager.h"
#include "GameManager/GameManager.h"


// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	GameManager* gameManager = new GameManager();
	gameManager->Run();
	delete gameManager;
	return 0;
}
