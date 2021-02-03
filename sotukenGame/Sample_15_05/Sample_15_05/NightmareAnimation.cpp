#include "stdafx.h"
#include "NightmareAnimation.h"

NightmareAnimation::NightmareAnimation()
{

}

NightmareAnimation::~NightmareAnimation()
{

}

bool NightmareAnimation::Start()
{
	//�A�j���[�V�������[�h�B
	//�ҋ@�O�P
	animClip[NightmAnimInfo::enNi_Idle01].Load("Assets/animData/DragonNightmare/Nm_idle01.tka");
	animClip[NightmAnimInfo::enNi_Idle01].SetLoopFlag(true);
	//�ҋ@�O�Q
	animClip[NightmAnimInfo::enNi_Idle02].Load("Assets/animData/DragonNightmare/Nm_idle02.tka");
	animClip[NightmAnimInfo::enNi_Idle02].SetLoopFlag(true);
	//����
	animClip[NightmAnimInfo::enNi_Walk].Load("Assets/animData/DragonNightmare/Nm_walk.tka");
	animClip[NightmAnimInfo::enNi_Walk].SetLoopFlag(true);
	//������
	animClip[NightmAnimInfo::enNi_WalkBack].Load("Assets/animData/DragonNightmare/Nm_walkback.tka");
	animClip[NightmAnimInfo::enNi_WalkBack].SetLoopFlag(true);
	//������
	animClip[NightmAnimInfo::enNi_WalkLeft].Load("Assets/animData/DragonNightmare/Nm_walkleft.tka");
	animClip[NightmAnimInfo::enNi_WalkLeft].SetLoopFlag(true);
	//�E����
	animClip[NightmAnimInfo::enNi_WalkRight].Load("Assets/animData/DragonNightmare/Nm_walkright.tka");
	animClip[NightmAnimInfo::enNi_WalkRight].SetLoopFlag(true);
	//����
	animClip[NightmAnimInfo::enNi_Run].Load("Assets/animData/DragonNightmare/Nm_run.tka");
	animClip[NightmAnimInfo::enNi_Run].SetLoopFlag(true);
	//���K
	animClip[NightmAnimInfo::enNi_Scream].Load("Assets/animData/DragonNightmare/Nm_scream.tka");
	//�U��
	animClip[NightmAnimInfo::enNi_BasicAttack].Load("Assets/animData/DragonNightmare/Nm_basicattack.tka");
	//�܍U��
	animClip[NightmAnimInfo::enNi_ClawAttack].Load("Assets/animData/DragonNightmare/Nm_clawattack.tka");
	//�p�U��
	animClip[NightmAnimInfo::enNi_HornAttack].Load("Assets/animData/DragonNightmare/Nm_hornattack.tka");
	//�h��
	animClip[NightmAnimInfo::enNi_Defend].Load("Assets/animData/DragonNightmare/Nm_defend.tka");
	//�h��
	animClip[NightmAnimInfo::enNi_Defend].Load("Assets/animData/DragonNightmare/Nm_sleep.tka");
	//��_��
	animClip[NightmAnimInfo::enNi_Gethit].Load("Assets/animData/DragonNightmare/Nm_gethit.tka");
	//���S
	animClip[NightmAnimInfo::enNi_Die].Load("Assets/animData/DragonNightmare/Nm_die.tka");
	return true;
}

void NightmareAnimation::Update()
{

}