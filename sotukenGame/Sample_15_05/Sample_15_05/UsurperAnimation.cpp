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
	//‘Ò‹@‚O‚P
	animClip[UsurperAnimInfo::enUs_Idle01].Load("Assets/animData/DragonUsurper/Us_idle01.tka");
	animClip[UsurperAnimInfo::enUs_Idle01].SetLoopFlag(true);
	//‘Ò‹@‚O‚Q
	animClip[UsurperAnimInfo::enUs_Idle02].Load("Assets/animData/DragonUsurper/Us_idle02.tka");
	animClip[UsurperAnimInfo::enUs_Idle02].SetLoopFlag(true);

	//•‚—V‘Ò‹@
	animClip[UsurperAnimInfo::enUs_FlyIdle].Load("Assets/animData/DragonUsurper/Us_flyidle.tka");
	animClip[UsurperAnimInfo::enUs_FlyIdle].SetLoopFlag(true);
	//•à‚«
	animClip[UsurperAnimInfo::enUs_Walk].Load("Assets/animData/DragonUsurper/Us_walk.tka");
	animClip[UsurperAnimInfo::enUs_Walk].SetLoopFlag(true);
	//‘–‚è
	animClip[UsurperAnimInfo::enUs_Run].Load("Assets/animData/DragonUsurper/Us_run.tka");
	animClip[UsurperAnimInfo::enUs_Run].SetLoopFlag(true);

	//˜rUŒ‚
	animClip[UsurperAnimInfo::enUs_HandAttack].Load("Assets/animData/DragonUsurper/Us_attackhand.tka");
	//Šš‚İ‚Â‚«UŒ‚
	animClip[UsurperAnimInfo::enUs_MouthAttack].Load("Assets/animData/DragonUsurper/Us_attackmouth.tka");
	//‰Î‰ŠUŒ‚
	animClip[UsurperAnimInfo::enUs_FlameAttack].Load("Assets/animData/DragonUsurper/Us_attackflame.tka");
	//•‚—V‰Î‰ŠUŒ‚
	animClip[UsurperAnimInfo::enUs_FlyFlame].Load("Assets/animData/DragonUsurper/Us_flyflame.tka");

	//”òs‘Oi
	animClip[UsurperAnimInfo::enUs_FlyForward].Load("Assets/animData/DragonUsurper/Us_flyforward.tka");
	//‘Î‹ó
	animClip[UsurperAnimInfo::enUs_FlyGlide].Load("Assets/animData/DragonUsurper/Us_flyglide.tka");
	//’…—¤
	animClip[UsurperAnimInfo::enUs_Land].Load("Assets/animData/DragonUsurper/Us_land.tka");
	//—£—¤
	animClip[UsurperAnimInfo::enUs_Takeoff].Load("Assets/animData/DragonUsurper/Us_takeoff.tka");
	//–hŒä
	animClip[UsurperAnimInfo::enUs_Defend].Load("Assets/animData/DragonUsurper/Us_defend.tka");
	//‡–°
	animClip[UsurperAnimInfo::enUs_Sleep].Load("Assets/animData/DragonUsurper/Us_sleep.tka");
	//™ôšK
	animClip[UsurperAnimInfo::enUs_Scream].Load("Assets/animData/DragonUsurper/Us_scream.tka");
	//”íƒ_ƒ
	animClip[UsurperAnimInfo::enUs_Gethit].Load("Assets/animData/DragonUsurper/Us_gethit.tka");
	//€–S
	animClip[UsurperAnimInfo::enUs_Die].Load("Assets/animData/DragonUsurper/Us_die.tka");
	return true;
}

void UsurperAnimation::Update()
{

}