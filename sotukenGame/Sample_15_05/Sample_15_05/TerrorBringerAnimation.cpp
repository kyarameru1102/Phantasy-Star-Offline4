#include "stdafx.h"
#include "TerrorBringerAnimation.h"

TerrorBringerAnimation::TerrorBringerAnimation()
{

}

TerrorBringerAnimation::~TerrorBringerAnimation()
{

}

bool TerrorBringerAnimation::Start()
{
	//�A�j���[�V�������[�h�B
	//�ҋ@�O�P
	animClip[TerrorBringerAnimInfo::enTe_Idle01].Load("Assets/animData/DragonTerrorBringer/TeBr_idle01.tka");
	animClip[TerrorBringerAnimInfo::enTe_Idle01].SetLoopFlag(true);
	//�ҋ@�O�Q
	animClip[TerrorBringerAnimInfo::enTe_Idle02].Load("Assets/animData/DragonTerrorBringer/TeBr_idle02.tka");
	animClip[TerrorBringerAnimInfo::enTe_Idle02].SetLoopFlag(true);
	//���V�ҋ@
	animClip[TerrorBringerAnimInfo::enTe_FlyIdle].Load("Assets/animData/DragonTerrorBringer/TeBr_flyidle.tka");
	animClip[TerrorBringerAnimInfo::enTe_FlyIdle].SetLoopFlag(true);
	//����
	animClip[TerrorBringerAnimInfo::enTe_Walk].Load("Assets/animData/DragonTerrorBringer/TeBr_walk.tka");
	animClip[TerrorBringerAnimInfo::enTe_Walk].SetLoopFlag(true);
	//����
	animClip[TerrorBringerAnimInfo::enTe_Run].Load("Assets/animData/DragonTerrorBringer/TeBr_run.tka");
	animClip[TerrorBringerAnimInfo::enTe_Run].SetLoopFlag(true);

	//�U��
	animClip[TerrorBringerAnimInfo::enTe_BasicAttack].Load("Assets/animData/DragonTerrorBringer/TeBr_basicattack.tka");
	//��s�U��
	animClip[TerrorBringerAnimInfo::enTe_FlyAttack].Load("Assets/animData/DragonTerrorBringer/TeBr_flyattack.tka");
	//�܍U��
	animClip[TerrorBringerAnimInfo::enTe_WingClawAttack].Load("Assets/animData/DragonTerrorBringer/TeBr_attackwingclaw.tka");
	//�Ή��U��
	animClip[TerrorBringerAnimInfo::enTe_FlameAttack].Load("Assets/animData/DragonTerrorBringer/TeBr_flameattack.tka");
	//��s�O�i
	animClip[TerrorBringerAnimInfo::enTe_FlyForward].Load("Assets/animData/DragonTerrorBringer/TeBr_flyforward.tka");
	animClip[TerrorBringerAnimInfo::enTe_FlyForward].SetLoopFlag(true);
	//�΋�
	animClip[TerrorBringerAnimInfo::enTe_FlyGlide].Load("Assets/animData/DragonTerrorBringer/TeBr_flyglide.tka");
	animClip[TerrorBringerAnimInfo::enTe_FlyGlide].SetLoopFlag(true);

	//����
	animClip[TerrorBringerAnimInfo::enTe_Land].Load("Assets/animData/DragonTerrorBringer/TeBr_landing.tka");
	//����
	animClip[TerrorBringerAnimInfo::enTe_Takeoff].Load("Assets/animData/DragonTerrorBringer/TeBr_takeoff.tka");
	//�h��
	animClip[TerrorBringerAnimInfo::enTe_Defend].Load("Assets/animData/DragonTerrorBringer/TeBr_defend.tka");
	//����
	animClip[TerrorBringerAnimInfo::enTe_Sleep].Load("Assets/animData/DragonTerrorBringer/TeBr_sleep.tka");
	//���K
	animClip[TerrorBringerAnimInfo::enTe_Scream].Load("Assets/animData/DragonTerrorBringer/TeBr_scream.tka");
	//��_��
	animClip[TerrorBringerAnimInfo::enTe_Gethit].Load("Assets/animData/DragonTerrorBringer/TeBr_gethit.tka");
	//���S
	animClip[TerrorBringerAnimInfo::enTe_Die].Load("Assets/animData/DragonTerrorBringer/TeBr_die.tka");
	return true;
}

void TerrorBringerAnimation::Update()
{

}