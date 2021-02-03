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
	//ÉAÉjÉÅÅ[ÉVÉáÉìÉçÅ[ÉhÅB
	//ë“ã@ÇOÇP
	animClip[NightmAnimInfo::enNi_Idle01].Load("Assets/animData/DragonNightmare/Nm_idle01.tka");
	animClip[NightmAnimInfo::enNi_Idle01].SetLoopFlag(true);
	//ë“ã@ÇOÇQ
	animClip[NightmAnimInfo::enNi_Idle02].Load("Assets/animData/DragonNightmare/Nm_idle02.tka");
	animClip[NightmAnimInfo::enNi_Idle02].SetLoopFlag(true);
	//ï‡Ç´
	animClip[NightmAnimInfo::enNi_Walk].Load("Assets/animData/DragonNightmare/Nm_walk.tka");
	animClip[NightmAnimInfo::enNi_Walk].SetLoopFlag(true);
	//å„ÇÎï‡Ç´
	animClip[NightmAnimInfo::enNi_WalkBack].Load("Assets/animData/DragonNightmare/Nm_walkback.tka");
	animClip[NightmAnimInfo::enNi_WalkBack].SetLoopFlag(true);
	//ç∂ï‡Ç´
	animClip[NightmAnimInfo::enNi_WalkLeft].Load("Assets/animData/DragonNightmare/Nm_walkleft.tka");
	animClip[NightmAnimInfo::enNi_WalkLeft].SetLoopFlag(true);
	//âEï‡Ç´
	animClip[NightmAnimInfo::enNi_WalkRight].Load("Assets/animData/DragonNightmare/Nm_walkright.tka");
	animClip[NightmAnimInfo::enNi_WalkRight].SetLoopFlag(true);
	//ëñÇË
	animClip[NightmAnimInfo::enNi_Run].Load("Assets/animData/DragonNightmare/Nm_run.tka");
	animClip[NightmAnimInfo::enNi_Run].SetLoopFlag(true);
	//ôÙöK
	animClip[NightmAnimInfo::enNi_Scream].Load("Assets/animData/DragonNightmare/Nm_scream.tka");
	//çUåÇ
	animClip[NightmAnimInfo::enNi_BasicAttack].Load("Assets/animData/DragonNightmare/Nm_basicattack.tka");
	//í‹çUåÇ
	animClip[NightmAnimInfo::enNi_ClawAttack].Load("Assets/animData/DragonNightmare/Nm_clawattack.tka");
	//äpçUåÇ
	animClip[NightmAnimInfo::enNi_HornAttack].Load("Assets/animData/DragonNightmare/Nm_hornattack.tka");
	//ñhå‰
	animClip[NightmAnimInfo::enNi_Defend].Load("Assets/animData/DragonNightmare/Nm_defend.tka");
	//ñhå‰
	animClip[NightmAnimInfo::enNi_Defend].Load("Assets/animData/DragonNightmare/Nm_sleep.tka");
	//îÌÉ_ÉÅ
	animClip[NightmAnimInfo::enNi_Gethit].Load("Assets/animData/DragonNightmare/Nm_gethit.tka");
	//éÄñS
	animClip[NightmAnimInfo::enNi_Die].Load("Assets/animData/DragonNightmare/Nm_die.tka");
	return true;
}

void NightmareAnimation::Update()
{

}