#pragma once

#include <Novice.h>
#include <Vector2.h>



class BackGround {

public:

	static BackGround* GetInstance();

	static void Initialize();

	static void Draw(int num);


private:

	int texHD_[3];
	int nextTexHD_;
	int UITexHD_;
};

