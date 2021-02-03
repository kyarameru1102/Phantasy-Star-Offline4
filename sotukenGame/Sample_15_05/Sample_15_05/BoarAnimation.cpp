#include "stdafx.h"
#include "BoarAnimation.h"

BoarAnimation::BoarAnimation()
{
	//アニメーションロード。
	//待機
	animClip[BoarAnimInfo::enBo_Idle].Load("Assets/animData/DragonBoar/boar_idle.tka");
	animClip[BoarAnimInfo::enBo_Idle].SetLoopFlag(true);
	//歩き
	animClip[BoarAnimInfo::enBo_Walk].Load("Assets/animData/DragonBoar/boar_walk.tka");
	animClip[BoarAnimInfo::enBo_Walk].SetLoopFlag(true);
	//走り
	animClip[BoarAnimInfo::enBo_Run].Load("Assets/animData/DragonBoar/boar_run.tka");
	animClip[BoarAnimInfo::enBo_Run].SetLoopFlag(true);
	//咆哮
	animClip[BoarAnimInfo::enBo_Scream].Load("Assets/animData/DragonBoar/boar_scream.tka");
	//攻撃
	animClip[BoarAnimInfo::enBo_Attack].Load("Assets/animData/DragonBoar/boar_attack.tka");
	//角攻撃
	animClip[BoarAnimInfo::enBo_Hornattack].Load("Assets/animData/DragonBoar/boar_hornattack.tka");
	//被ダメ
	animClip[BoarAnimInfo::enBo_Gethit].Load("Assets/animData/DragonBoar/boar_gethit.tka");
	//死亡
	animClip[BoarAnimInfo::enBo_Die].Load("Assets/animData/DragonBoar/boar_die.tka");
}

BoarAnimation::~BoarAnimation()
{

}

bool BoarAnimation::Start()
{
	return true;
}

void BoarAnimation::Update()
{

}