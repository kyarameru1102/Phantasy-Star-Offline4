#include "stdafx.h"
#include "UsurperAnimation.h"

UsurperAnimation::UsurperAnimation()
{

}

UsurperAnimation::~UsurperAnimation()
{

}

bool UsurperAnimation::Start()
{
	//�ҋ@�O�P
	animClip[UsurperAnimInfo::enUs_Idle01].Load("Assets/animData/DragonUsurper/Us_idle01.tka");
	animClip[UsurperAnimInfo::enUs_Idle01].SetLoopFlag(true);
	//�ҋ@�O�Q
	animClip[UsurperAnimInfo::enUs_Idle02].Load("Assets/animData/DragonUsurper/Us_idle02.tka");
	animClip[UsurperAnimInfo::enUs_Idle02].SetLoopFlag(true);

	//���V�ҋ@
	animClip[UsurperAnimInfo::enUs_FlyIdle].Load("Assets/animData/DragonUsurper/Us_flyidle.tka");
	animClip[UsurperAnimInfo::enUs_FlyIdle].SetLoopFlag(true);
	//����
	animClip[UsurperAnimInfo::enUs_Walk].Load("Assets/animData/DragonUsurper/Us_walk.tka");
	animClip[UsurperAnimInfo::enUs_Walk].SetLoopFlag(true);
	//����
	animClip[UsurperAnimInfo::enUs_Run].Load("Assets/animData/DragonUsurper/Us_run.tka");
	animClip[UsurperAnimInfo::enUs_Run].SetLoopFlag(true);

	//�r�U��
	animClip[UsurperAnimInfo::enUs_HandAttack].Load("Assets/animData/DragonUsurper/Us_attackhand.tka");
	//���݂��U��
	animClip[UsurperAnimInfo::enUs_MouthAttack].Load("Assets/animData/DragonUsurper/Us_attackmouth.tka");
	//�Ή��U��
	animClip[UsurperAnimInfo::enUs_FlameAttack].Load("Assets/animData/DragonUsurper/Us_attackflame.tka");
	//���V�Ή��U��
	animClip[UsurperAnimInfo::enUs_FlyFlame].Load("Assets/animData/DragonUsurper/Us_flyflame.tka");

	//��s�O�i
	animClip[UsurperAnimInfo::enUs_FlyForward].Load("Assets/animData/DragonUsurper/Us_flyforward.tka");
	//�΋�
	animClip[UsurperAnimInfo::enUs_FlyGlide].Load("Assets/animData/DragonUsurper/Us_flyglide.tka");
	//����
	animClip[UsurperAnimInfo::enUs_Land].Load("Assets/animData/DragonUsurper/Us_land.tka");
	//����
	animClip[UsurperAnimInfo::enUs_Takeoff].Load("Assets/animData/DragonUsurper/Us_takeoff.tka");
	//�h��
	animClip[UsurperAnimInfo::enUs_Defend].Load("Assets/animData/DragonUsurper/Us_defend.tka");
	//����
	animClip[UsurperAnimInfo::enUs_Sleep].Load("Assets/animData/DragonUsurper/Us_sleep.tka");
	//���K
	animClip[UsurperAnimInfo::enUs_Scream].Load("Assets/animData/DragonUsurper/Us_scream.tka");
	//��_��
	animClip[UsurperAnimInfo::enUs_Gethit].Load("Assets/animData/DragonUsurper/Us_gethit.tka");
	//���S
	animClip[UsurperAnimInfo::enUs_Die].Load("Assets/animData/DragonUsurper/Us_die.tka");
	return true;
}

void UsurperAnimation::Update()
{

}