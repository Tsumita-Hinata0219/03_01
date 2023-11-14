#pragma once

#include <Novice.h>
#include <Vector2.h>



class BackGround {

public:

	static BackGround* GetInstance();

	static void Initialize();

	static void DrawTitle();
	static void DrawGame();
	static void DrawResult();


private:

	int texHD_[3];
};

