#include "stdafx.h"
#include "DrNightmare.h"
#include "Player.h"
#include "Game.h"
#include "sound/SoundSource.h"
DrNightmare::DrNightmare()
{
}

DrNightmare::~DrNightmare()
{
	DeleteGO(m_skinModelRender);
	DeleteGO(m_nightmAnim);
	
}

bool DrNightmare::Start()
{
	//ドラゴンナイトメアのアニメーションをロード。
	m_nightmAnim = NewGO<NightmareAnimation>(0);
	
	if (m_basicStatusNum == en1) {
		m_skinModelRender = NewGO<SkinModelRender>(0);
		m_skinModelRender->Init("Assets/modelData/enemy/DragonNightmare/albino/DrNmAl.tkm", m_nightmAnim->GetAnimationClip(), NightmAnimInfo::enNightmAnimClip_num);
		//攻撃力を初期化。
		m_attackPower = 15.0f;
		//HPを初期化。
		m_hp = 130.0f;
	}
	else if (m_basicStatusNum == en2)
	{
		m_skinModelRender = NewGO<SkinModelRender>(0);
		m_skinModelRender->Init("Assets/modelData/enemy/DragonNightmare/blue/DrNmBl.tkm", m_nightmAnim->GetAnimationClip(), NightmAnimInfo::enNightmAnimClip_num);
		//攻撃力を初期化。
		m_attackPower = 20.0f;
		//HPを初期化。
		m_hp = 180.0f;
	}
	else if (m_basicStatusNum == en3)
	{
		m_skinModelRender = NewGO<SkinModelRender>(0);
		m_skinModelRender->Init("Assets/modelData/enemy/DragonNightmare/darkblue/DrNmDp.tkm", m_nightmAnim->GetAnimationClip(), NightmAnimInfo::enNightmAnimClip_num);
		//攻撃力を初期化。
		m_attackPower = 25.0f;
		//HPを初期化。
		m_hp = 220.0f;
	}
	else if (m_basicStatusNum == en4)
	{
		m_skinModelRender = NewGO<SkinModelRender>(0);
		m_skinModelRender->Init("Assets/modelData/enemy/DragonNightmare/green/DrNmGr.tkm", m_nightmAnim->GetAnimationClip(), NightmAnimInfo::enNightmAnimClip_num);
		//攻撃力を初期化。
		m_attackPower = 25.0f;
		//HPを初期化。
		m_hp = 270.0f;
	}

	//キャラコン初期化。
	m_charaCon.Init(240.0f, 200.0f, m_position);
	Vector3 ghostPos = m_position;
	m_ghostObj.CreateBox(ghostPos, m_rotation, Vector3(100.0f, 100.0f, 180.0f));

	m_game = FindGO<Game>("Game");
	m_player = FindGO<Player>("player");

	//攻撃力を初期化。
	m_attackPower = 10.0f;
	m_attackPower *= m_magnificationAP;
	//HPを初期化。
	m_hp = 200.0f;
	m_hp *= m_magnificationHP;
	
	
	return true;
}

void DrNightmare::Move()
{
	
	Vector3 playerLen = m_toPlayer;
	playerLen.Normalize();
	if (m_isATKcount >= 2 || m_isClawATKcount >= 2)
	{
		m_isHornATK = true;
		m_isBasicATK = false;
		m_isClawATK = false;
	}
	if (m_toPlayer.Length() <= 400.0f && m_isClawATK == false && m_isHornATK == false)
	{
		m_isBasicATK = true;
	}
	if (m_toPlayer.Length() <= 400.0f && m_isBasicATK == false && m_isHornATK == false)
	{
		m_isClawATK = true;
	}
	if (m_toPlayer.Length() <= 800.0f && m_isClawATK == false && m_isBasicATK == false && m_isHornATK ==false && m_isHornATKcount != 1)
	{
		m_status = Walk_state;
		m_movespeed = playerLen * 1.4;
		m_isHornATK = true;
	}
	
	else {
		m_status = Run_state;
		m_movespeed = playerLen * 1.6f;
		
	}
	
	if (m_toPlayer.Length() <= 500.0f)
	{
		m_movespeed = { 0.0f, 0.0f, 0.0f };
		m_position = m_charaCon.Execute(1.0f, m_movespeed);
	}
	else {
		m_movespeed.y = m_speedY;
		m_position = m_charaCon.Execute(1.0f, m_movespeed);
		
	}
	//m_movespeed.y = m_speedY;
	//m_position = m_charaCon.Execute(1.0f, m_movespeed);
}

void DrNightmare::Turn()
{
	Vector3 playerLen = m_player->GetPosition() - m_position;
	float angle = atan2(playerLen.x, playerLen.z);
	m_rotation.SetRotation(Vector3::AxisY, angle);
}
void DrNightmare::Scream()
{
		m_status = Scream_state;
}
void DrNightmare::Attack()
{
	m_status = Attack_state;
	m_jawboneNum = m_skinModelRender->GetModel().GetSkeleton().FindBoneID(L"Jaw02");
	m_skinModelRender->GetModel().GetSkeleton().GetBone(m_jawboneNum)->CalcWorldTRS(
		m_jawpos,
		m_jawrot,
		m_jawscale
	);
	m_toJawPlayer = m_player->GetPosition() - m_jawpos;
	
	if (m_toJawPlayer.Length() <= 150)
	{
		if (m_isAttack && !m_ATKoff) {
			if (m_count >= 60 && m_count <= 70) {
				m_player->ReceiveDamage(m_attackPower);
				m_ATKoff = true;
				printf_s("Enemy_KOUGEKI\n");
			}
		}
	}
	
}

void DrNightmare::ClawAttack()
{
	m_status = ClawAttack_state;
	m_armboneNum = m_skinModelRender->GetModel().GetSkeleton().FindBoneID(L"R_Hand");
	m_skinModelRender->GetModel().GetSkeleton().GetBone(m_armboneNum)->CalcWorldTRS(
		m_armpos,
		m_armrot,
		m_armscale
	);
	m_toArmPlayer = m_player->GetPosition() - m_armpos;
	if (m_toArmPlayer.Length() <= 300)
	{
		if (m_isAttack && !m_ATKoff) {
			if (m_count >= 60 && m_count <= 70) {
				m_player->ReceiveDamage(m_attackPower);
				m_ATKoff = true;
				printf_s("Enemy_KOUGEKI\n");
			}
		}
	}
	
	
}

void DrNightmare::HornAttack()
{
	m_status = HornAttack_state;
	m_hedboneNum = m_skinModelRender->GetModel().GetSkeleton().FindBoneID(L"UpperHead01");
	m_skinModelRender->GetModel().GetSkeleton().GetBone(m_hedboneNum)->CalcWorldTRS(
		m_hedpos,
		m_hedrot,
		m_hedscale
	);
	m_toHedPlayer = m_player->GetPosition() - m_hedpos;
	if (m_toHedPlayer.Length() <= 300)
	{
		if (m_isAttack && !m_ATKoff) {
			if (m_count >= 60 && m_count <= 1000) {
				m_player->ReceiveDamage(m_attackPower);
				m_ATKoff = true;
				printf_s("Enemy_KOUGEKI\n");
			}
		}
	}
}

void DrNightmare::Die()
{
	if (m_hp <= 0)
	{
		m_status = Die_state;
		m_charaCon.RemoveRigidBoby();
		if (!m_skinModelRender->GetisAnimationPlaing()) {
			m_deathCount++;
			m_player->GetExperiencePoint(10);
			SetIsDead();
			m_death = true;
		}
	}
}
void DrNightmare::Update()
{
	//フェードのフラグがtrueで無い時
	if (m_game->GetIsWave() != true)
	{
		//毎フレーム距離はかる。
		m_toPlayer = m_player->GetPosition() - m_position;
		
		
		//プレイヤーに近づく。
		if (m_status != GetDamage_state) {
			if (m_screamflag == true)
			{
				Scream();
			}
			
			if (m_screamflag == false && m_status != Attack_state && m_status != ClawAttack_state && m_status != HornAttack_state && m_hp >0) {
				Move();
				Turn();
			}

			//距離が近づくと。
			if (m_isBasicATK == true && m_isClawATK == false && m_isHornATK == false)
			{
				Attack();
			}

			if (m_isATKcount == 2)
			{
				m_isClawATK = true;
				m_isBasicATK = false;
				m_isHornATK = false;
			}
			if (m_isClawATKcount == 1)
			{
				m_isBasicATK = true;
				m_isClawATK = false;
				m_isHornATK = false;
				m_isHornATKcount = 0;
				m_isATKcount = 0;
				m_isClawATKcount = 0;
			}
			if (m_isClawATK == true && m_isBasicATK == false && m_isHornATK == false)
			{
				ClawAttack();
			}

			if (m_isHornATK == true && m_isClawATK == false && m_isBasicATK == false && m_toPlayer.Length() <= 300.0f)
			{
				HornAttack();
			}

		}
		//体力がゼロになると
		Die();

		switch (m_status)
		{
		case Idle_state:
			m_animState = NightmAnimInfo::enNi_Idle01;
			break;
		case Walk_state:
			m_animState = NightmAnimInfo::enNi_Walk;
			break;
		case Run_state:
			m_animState = NightmAnimInfo::enNi_Run;
			break;
		case Scream_state:
			m_animState = NightmAnimInfo::enNi_Scream;
			Sound(L"Assets/sound/SE_Dragon_Haul.wav");
			
			if (!m_skinModelRender->GetisAnimationPlaing())
			{
				m_soundFlag = false;
				m_screamflag = false;
				m_animState = NightmAnimInfo::enNi_Idle01;
				m_skinModelRender->PlayAnimation(m_animState, 0.0f);
			}
			break;
		case Attack_state:
			m_animState = NightmAnimInfo::enNi_BasicAttack;
			m_count++;
			m_isAttack = true;
			Sound(L"Assets/sound/SE_Dragon_Fang.wav");
			if (!m_skinModelRender->GetisAnimationPlaing()) {
				m_status = Idle_state;
				m_isAttack = false;
				m_ATKoff = false;
				m_soundFlag = false;
				m_count = 0;
				m_isATKcount++;
				m_isBasicATK = false;
				m_animState = NightmAnimInfo::enNi_Idle01;
				m_skinModelRender->PlayAnimation(m_animState, 0.0f);
			}
			break;
		case ClawAttack_state:
			m_animState = NightmAnimInfo::enNi_ClawAttack;
			m_count++;
			m_isAttack = true;
			Sound(L"Assets/sound/SE_Dragon_Claw.wav");
			if (!m_skinModelRender->GetisAnimationPlaing()) {
				m_status = Idle_state;
				m_isAttack = false;
				m_ATKoff = false;
				m_soundFlag = false;
				m_count = 0;
				m_isClawATKcount++;
				m_isClawATK = false;
				m_animState = NightmAnimInfo::enNi_Idle01;
				m_skinModelRender->PlayAnimation(m_animState, 0.0f);
			}
			break;
		case HornAttack_state:
			m_animState = NightmAnimInfo::enNi_HornAttack;
			m_count++;
			m_isAttack = true;
			Sound(L"Assets/sound/SE_Dragon_Fang.wav");
			if (!m_skinModelRender->GetisAnimationPlaing()) {
				m_status = Idle_state;
				m_isAttack = false;
				m_ATKoff = false;
				m_soundFlag = false;
				m_count = 0;
				m_isHornATKcount++;
				m_isHornATK = false;
				m_isATKcount = 0;
				m_isClawATK = 0;
				m_animState = NightmAnimInfo::enNi_Idle01;
				m_skinModelRender->PlayAnimation(m_animState, 0.0f);
			}
			break;
		case GetDamage_state:
			m_animState = NightmAnimInfo::enNi_Gethit;
			Sound(L"Assets/sound/SE_Dragon_Damage.wav");
			m_isAttack = false;
			m_ATKoff = false;
			m_count = 0;
			if (!m_skinModelRender->GetisAnimationPlaing()) {
				m_soundFlag = false;
				m_status = Idle_state;
				m_animState = NightmAnimInfo::enNi_Idle01;
				m_skinModelRender->PlayAnimation(m_animState, 0.0f);
			}
			break;
		case Die_state:
			m_animState = NightmAnimInfo::enNi_Die;
			Sound(L"Assets/sound/SE_Dragon_Die2.wav");
			break;
		default:
			break;
		}

		if (m_movespeed.Length() >= 0.0f) {
			m_dir = m_movespeed;
			m_dir.Normalize();
			m_dir *= 200.0f;
		}
	}
	
	m_ghostPos = m_position + m_dir;

	m_ghostObj.SetPosition(m_ghostPos);
	m_ghostObj.SetRotation(m_rotation);
	m_skinModelRender->SetScale({ 75.0, 75.0, 75.0 });
	m_skinModelRender->SetRotation(m_rotation);
	m_skinModelRender->SetPosition(m_position);
	m_skinModelRender->PlayAnimation(m_animState, 1.0f / 60.0f);
	//デバッグ用。
	printf_s("AnimationState_%d\n", m_animState);
	printf_s("EnemyHP_%d\n", m_hp);
}