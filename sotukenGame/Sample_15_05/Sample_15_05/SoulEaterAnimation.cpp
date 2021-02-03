#include "stdafx.h"
#include "SoulEaterAnimation.h"
#include "Player.h"
SoulEaterAnimation::SoulEaterAnimation()
{

}

SoulEaterAnimation::~SoulEaterAnimation()
{

}

bool SoulEaterAnimation::Start()
{
	//ƒAƒjƒ[ƒVƒ‡ƒ“ƒ[ƒhB
	//‘Ò‹@
	animClip[SoulEaterAnimInfo::enSo_Idle].Load("Assets/animData/DragonSoulEater/SoEa_idle.tka");
	animClip[SoulEaterAnimInfo::enSo_Idle].SetLoopFlag(true);

	//•à‚«
	animClip[SoulEaterAnimInfo::enSo_Walk].Load("Assets/animData/DragonSoulEater/SoEa_walk.tka");
	animClip[SoulEaterAnimInfo::enSo_Walk].SetLoopFlag(true);

	//‘–‚è
	animClip[SoulEaterAnimInfo::enSo_Run].Load("Assets/animData/DragonSoulEater/SoEa_run.tka");
	animClip[SoulEaterAnimInfo::enSo_Run].SetLoopFlag(true);

	//•‚—V
	animClip[SoulEaterAnimInfo::enSo_FlyFloat].Load("Assets/animData/DragonSoulEater/SoEa_flyfloat.tka");
	animClip[SoulEaterAnimInfo::enSo_FlyFloat].SetLoopFlag(true);
	//”òs‘Oi
	animClip[SoulEaterAnimInfo::enSo_FlyForward].Load("Assets/animData/DragonSoulEater/SoEa_flyforward.tka");
	animClip[SoulEaterAnimInfo::enSo_FlyForward].SetLoopFlag(true);
	//‘Î‹ó
	animClip[SoulEaterAnimInfo::enSo_FlyGlide].Load("Assets/animData/DragonSoulEater/SoEa_flyglide.tka");
	animClip[SoulEaterAnimInfo::enSo_FlyGlide].SetLoopFlag(true);
	//™ôšK
	animClip[SoulEaterAnimInfo::enSo_Scream].Load("Assets/animData/DragonSoulEater/SoEa_scream.tka");
	//UŒ‚
	animClip[SoulEaterAnimInfo::enSo_BasicAttack].Load("Assets/animData/DragonSoulEater/SoEa_basic_attack.tka");
	//K”öUŒ‚
	animClip[SoulEaterAnimInfo::enSo_TailAttack].Load("Assets/animData/DragonSoulEater/SoEa_tail_attack.tka");
	//‰Î‰ŠUŒ‚
	animClip[SoulEaterAnimInfo::enSo_FireballShoot].Load("Assets/animData/DragonSoulEater/SoEa_fireball shoot.tka");
	//’…—¤
	animClip[SoulEaterAnimInfo::enSo_FlyLand].Load("Assets/animData/DragonSoulEater/SoEa_flyland.tka");
	//—£—¤
	animClip[SoulEaterAnimInfo::enSo_Takeoff].Load("Assets/animData/DragonSoulEater/SoEa_takeoff.tka");
	//–hŒä
	animClip[SoulEaterAnimInfo::enSo_Defend].Load("Assets/animData/DragonSoulEater/SoEa_defend.tka");
	//‡–°
	animClip[SoulEaterAnimInfo::enSo_Defend].Load("Assets/animData/DragonSoulEater/SoEa_sleep.tka");
	//”íƒ_ƒ
	animClip[SoulEaterAnimInfo::enSo_Gethit].Load("Assets/animData/DragonSoulEater/SoEa_gethit.tka");
	//€–S
	animClip[SoulEaterAnimInfo::enSo_Die].Load("Assets/animData/DragonSoulEater/SoEa_die.tka");
	return true;
}

void SoulEaterAnimation::Update()
{

}