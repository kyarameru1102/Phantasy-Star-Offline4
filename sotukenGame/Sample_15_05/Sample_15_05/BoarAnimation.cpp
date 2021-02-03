#include "stdafx.h"
#include "BoarAnimation.h"

BoarAnimation::BoarAnimation()
{
	//�A�j���[�V�������[�h�B
	//�ҋ@
	animClip[BoarAnimInfo::enBo_Idle].Load("Assets/animData/DragonBoar/boar_idle.tka");
	animClip[BoarAnimInfo::enBo_Idle].SetLoopFlag(true);
	//����
	animClip[BoarAnimInfo::enBo_Walk].Load("Assets/animData/DragonBoar/boar_walk.tka");
	animClip[BoarAnimInfo::enBo_Walk].SetLoopFlag(true);
	//����
	animClip[BoarAnimInfo::enBo_Run].Load("Assets/animData/DragonBoar/boar_run.tka");
	animClip[BoarAnimInfo::enBo_Run].SetLoopFlag(true);
	//���K
	animClip[BoarAnimInfo::enBo_Scream].Load("Assets/animData/DragonBoar/boar_scream.tka");
	//�U��
	animClip[BoarAnimInfo::enBo_Attack].Load("Assets/animData/DragonBoar/boar_attack.tka");
	//�p�U��
	animClip[BoarAnimInfo::enBo_Hornattack].Load("Assets/animData/DragonBoar/boar_hornattack.tka");
	//��_��
	animClip[BoarAnimInfo::enBo_Gethit].Load("Assets/animData/DragonBoar/boar_gethit.tka");
	//���S
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