#include "BackGround.h"



BackGround* BackGround::GetInstance() {
	static BackGround instance;
	return &instance;
}


void BackGround::Initialize() {

	BackGround::GetInstance()->texHD_[0] = Novice::LoadTexture("./Resources/Title.png");
	BackGround::GetInstance()->texHD_[1] = Novice::LoadTexture("./Resources/Game.png");
	BackGround::GetInstance()->texHD_[2] = Novice::LoadTexture("./Resources/Result.png");
}


void BackGround::DrawTitle() {

	Novice::DrawSprite(
		0, 0,
		BackGround::GetInstance()->texHD_[0],
		1, 1, 0, 0xffffffff);
}

void BackGround::DrawGame() {

	Novice::DrawSprite(
		0, 0,
		BackGround::GetInstance()->texHD_[1],
		1, 1, 0, 0xffffffff);
}

void BackGround::DrawResult() {

	Novice::DrawSprite(
		0, 0,
		BackGround::GetInstance()->texHD_[2],
		1, 1, 0, 0xffffffff);
}