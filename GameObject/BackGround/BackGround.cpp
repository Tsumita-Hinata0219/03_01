#include "BackGround.h"



BackGround* BackGround::GetInstance() {
	static BackGround instance;
	return &instance;
}


void BackGround::Initialize() {

	BackGround::GetInstance()->texHD_[0] = Novice::LoadTexture("./Resources/Title.png");
	BackGround::GetInstance()->texHD_[1] = Novice::LoadTexture("./Resources/Game.png");
	BackGround::GetInstance()->texHD_[2] = Novice::LoadTexture("./Resources/Result.png");
	BackGround::GetInstance()->nextTexHD_ = Novice::LoadTexture("./Resources/next.png");
	BackGround::GetInstance()->UITexHD_ = Novice::LoadTexture("./Resources/UI.png");

}


void BackGround::Draw(int num) {

	Novice::DrawSprite(
		0, 0,
		BackGround::GetInstance()->texHD_[num],
		1, 1, 0, 0xffffffff);
	Novice::DrawSprite(
		0, 0,
		BackGround::GetInstance()->nextTexHD_,
		1, 1, 0, 0xffffffff);

	if (num == 1) {
		Novice::DrawSprite(
			0, 0,
			BackGround::GetInstance()->UITexHD_,
			1, 1, 0, 0xffffffff);
	}
}
