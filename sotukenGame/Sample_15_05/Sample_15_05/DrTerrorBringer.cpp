#include "stdafx.h"
#include "DrTerrorBringer.h"
#include "Player.h"
#include "Game.h"
DrTerrorBringer::DrTerrorBringer()
{

}

DrTerrorBringer::~DrTerrorBringer()
{
	DeleteGO(m_skinModelRender);
	DeleteGO(m_terrorbAnim);
}

bool DrTerrorBringer::Start()
{
	//ドラゴンテラーブリンガー
	m_terrorbAnim = NewGO<TerrorBringerAnimation>(0);
	//配色を決める。
	m_appearcolor = terrorcolor[rand() % terrorcolor.size()];
	//モデルの初期化
	if (m_appearcolor == 1) {
		m_skinModelRender = NewGO<SkinModelRender>(0);
		m_skinModelRender->Init("Assets/modelData/enemy/DragonTerrorBringer/blue/DrTeBrBl.tkm", m_terrorbAnim->GetAnimationClip(), TerrorBringerAnimInfo::enTerrorBringerAnimClip_num);
	}
	else if (m_appearcolor == 2) {
		m_skinModelRender = NewGO<SkinModelRender>(0);
		m_skinModelRender->Init("Assets/modelData/enemy/DragonTerrorBringer/green/DrTeBrGr.tkm", m_terrorbAnim->GetAnimationClip(), TerrorBringerAnimInfo::enTerrorBringerAnimClip_num);
	}
	else if (m_appearcolor == 3) {
		m_skinModelRender = NewGO<SkinModelRender>(0);
		m_skinModelRender->Init("Assets/modelData/enemy/DragonTerrorBringer/purple/DrTeBrPu.tkm", m_terrorbAnim->GetAnimationClip(), TerrorBringerAnimInfo::enTerrorBringerAnimClip_num);
	}
	else if (m_appearcolor == 4) {
		m_skinModelRender = NewGO<SkinModelRender>(0);
		m_skinModelRender->Init("Assets/modelData/enemy/DragonTerrorBringer/red/DrTeBrRe.tkm", m_terrorbAnim->GetAnimationClip(), TerrorBringerAnimInfo::enTerrorBringerAnimClip_num);
	}
	//キャラコン初期化。
	m_charaCon.Init(120.0f, 200.0f, m_position);
	Vector3 ghostPos = m_position;
	m_ghostObj.CreateBox(ghostPos, m_rotation, Vector3(120.0f, 200.0f, 120.0f));

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

void DrTerrorBringer::Move()
{
	Vector3 playerLen = m_toPlayer;
	playerLen.Normalize();
	if (m_FangATKCount >= 2 || m_ClawATKCont >= 2)
	{
		m_isFlameATK = true;
		m_isFangATK = false;
		m_isClawATK = false;
	}
	if (m_toPlayer.Length() <= 400.0f && m_isClawATK == false && m_isFlameATK == false)
	{
		m_isFangATK = true;
	}
	if (m_toPlayer.Length() <= 400.0f && m_isFangATK == false && m_isFlameATK == false)
	{
		m_isClawATK = true;
	}
	if (m_toPlayer.Length() <= 800.0f && m_isClawATK == false && m_isFangATK == false && m_isFlameATK == false && m_FlameATKCount != 1)
	{
		m_status = Walk_state;
		m_movespeed = playerLen * 1.4;
		m_isFlameATK = true;
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
	
}
void DrTerrorBringer::Turn()
{
	Vector3 playerLen = m_player->GetPosition() - m_position;
	float angle = atan2(playerLen.x, playerLen.z);
	m_rotation.SetRotation(Vector3::AxisY, angle);
}
void DrTerrorBringer::Scream()
{
	m_status = Scream_state;
}
void DrTerrorBringer::Attack()
{
	
		m_status = Attack_state;
		m_jawboneNum = m_skinModelRender->GetModel().GetSkeleton().FindBoneID(L"UpperHead2");
		m_skinModelRender->GetModel().GetSkeleton().GetBone(m_jawboneNum)->CalcWorldTRS(
			m_jawpos,
			m_jawrot,
			m_jawscale
		);
		m_toJawPlayer = m_player->GetPosition() - m_jawpos;

		
		if (m_toJawPlayer.Length() <= 200)
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

void DrTerrorBringer::FlyAttack()
{
	m_status = FlyAttack_state;
	CharacterController& charaCon = *m_player->GetCharacterController();
	g_physics.ContactTestCharaCon(charaCon, [&](const btCollisionObject& collisionObject) {
		if (m_ghostObj.IsSelf(collisionObject) == true) {
			if (m_isAttack && !m_ATKoff) {
				if (m_count >= 60 && m_count <= 70) {
					m_player->ReceiveDamage(m_attackPower);
					m_ATKoff = true;
					printf_s("Enemy_KOUGEKI\n");
				}
			}
		}
		});
}

void DrTerrorBringer::WingClawAttack()
{
	m_status = WingClawAttack_state;
	m_armboneNum = m_skinModelRender->GetModel().GetSkeleton().FindBoneID(L"Wing3_L");
	m_skinModelRender->GetModel().GetSkeleton().GetBone(m_armboneNum)->CalcWorldTRS(
		m_armpos,
		m_armrot,
		m_armscale
	);
	m_toArmPlayer = m_player->GetPosition() - m_armpos;
	if (m_toArmPlayer.Length() <= 200)
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

void DrTerrorBringer::FlameAttack()
{
	m_status = FlameAttack_state;
	m_jawboneNum = m_skinModelRender->GetModel().GetSkeleton().FindBoneID(L"UpperHead2");
	m_skinModelRender->GetModel().GetSkeleton().GetBone(m_jawboneNum)->CalcWorldTRS(
		m_jawpos,
		m_jawrot,
		m_jawscale
	);
	m_toJawPlayer = m_player->GetPosition() - m_jawpos;
	if (m_toJawPlayer.Length() <= 1200)
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
void DrTerrorBringer::Die()
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
void DrTerrorBringer::Update()
{
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

			if (m_screamflag == false && m_status != Attack_state && m_status != WingClawAttack_state && m_status != FlameAttack_state && m_hp > 0) {
				Move();
				Turn();
			}
			//距離が近づくと。
			if (m_isFangATK == true && m_isClawATK == false && m_isFlameATK == false)
			{
				Attack();
			}
			if (m_FangATKCount == 2)
			{
				m_isClawATK = true;
				m_isFangATK = false;
				m_isFlameATK = false;
			}
			if (m_ClawATKCont == 1)
			{
				m_isFangATK = true;
				m_isClawATK = false;
				m_isFlameATK = false;
				m_FlameATKCount = 0;
				m_FangATKCount = 0;
				m_ClawATKCont = 0;
			}
			if (m_isClawATK == true && m_isFangATK == false && m_isFlameATK == false)
			{
				WingClawAttack();
			}

			if(m_isFlameATK == true && m_isClawATK == false && m_isFangATK == false && m_toPlayer.Length() <= 300.0f)
			{
				FlameAttack();
			}
		}
			//体力がゼロになると
			Die();
		
			switch (m_status)
			{
			case Idle_state:
				m_animState = TerrorBringerAnimInfo::enTe_Idle01;
				break;
			case Walk_state:
				m_animState = TerrorBringerAnimInfo::enTe_Walk;
				break;
			case Run_state:
				m_animState = TerrorBringerAnimInfo::enTe_Run;
				break;
			case Fly_state:
				//離陸
				m_animState = TerrorBringerAnimInfo::enTe_Takeoff;
				if (!m_skinModelRender->GetisAnimationPlaing())
				{
					m_SetFly = true;
					m_FlyFlag = false;
				}
				break;
			case FlyMove_state:
				m_animState = TerrorBringerAnimInfo::enTe_FlyForward;
				if (!m_skinModelRender->GetisAnimationPlaing())
				{
					m_LandFlag = true;
					m_SetFly = false;
				}
				break;
			case FlyLand_state:
				m_animState = TerrorBringerAnimInfo::enTe_Land;
				if (!m_skinModelRender->GetisAnimationPlaing())
				{
					//m_TweStart = true;
					m_FlyFlag = false;
					m_SetFly = false;
					m_LandFlag = false;
					m_Flametotal = 0;
					m_animState = TerrorBringerAnimInfo::enTe_Idle01;
					m_skinModelRender->PlayAnimation(m_animState, 0.0f);
				}
				break;

			case Scream_state:
				m_animState = TerrorBringerAnimInfo::enTe_Scream;
				Sound(L"Assets/sound/SE_Dragon_Haul.wav");
				if (!m_skinModelRender->GetisAnimationPlaing())
				{
					m_soundFlag = false;
					m_screamflag = false;
					m_animState = TerrorBringerAnimInfo::enTe_Idle01;
					m_skinModelRender->PlayAnimation(m_animState, 0.0f);
				}
				break;
			case Attack_state:
				m_animState = TerrorBringerAnimInfo::enTe_BasicAttack;
				m_count++;
				m_isAttack = true;
				Sound(L"Assets/sound/SE_Dragon_Fang.wav");
				if (!m_skinModelRender->GetisAnimationPlaing()) {
					m_status = Idle_state;
					m_isAttack = false;
					m_ATKoff = false;
					m_soundFlag = false;
					m_count = 0;
					m_FangATKCount++;
					m_isFangATK = false;
					m_animState = TerrorBringerAnimInfo::enTe_Idle01;
					m_skinModelRender->PlayAnimation(m_animState, 0.0f);
					
				}
				break;
			case FlyAttack_state:
				m_animState = TerrorBringerAnimInfo::enTe_FlyAttack;
				m_count++;
				m_isAttack = true;
				if (!m_skinModelRender->GetisAnimationPlaing()) {
					m_status = Idle_state;
					m_isAttack = false;
					m_ATKoff = false;
					m_count = 0;
					m_animState = TerrorBringerAnimInfo::enTe_Idle01;
					m_skinModelRender->PlayAnimation(m_animState, 0.0f);
				}
				break;
			case  WingClawAttack_state:
				m_animState = TerrorBringerAnimInfo::enTe_WingClawAttack;
				m_count++;
				m_isAttack = true;
				Sound(L"Assets/sound/SE_Dragon_Claw.wav");
				if (!m_skinModelRender->GetisAnimationPlaing()) {
					m_status = Idle_state;
					m_isAttack = false;
					m_ATKoff = false;
					m_soundFlag = false;
					m_count = 0;
					m_ClawATKCont++;
					m_isClawATK = false;
					m_animState = TerrorBringerAnimInfo::enTe_Idle01;
					m_skinModelRender->PlayAnimation(m_animState, 0.0f);
					
				}
				break;
			case FlameAttack_state:
				m_animState = TerrorBringerAnimInfo::enTe_FlameAttack;
				m_count++;
				m_isAttack = true;
				Sound(L"Assets/sound/SE_Dragon_Haul2.wav");
				if (!m_skinModelRender->GetisAnimationPlaing()) {
					m_status = Idle_state;
					m_isAttack = false;
					m_ATKoff = false;
					m_soundFlag = false;
					m_count = 0;
					m_FlameATKCount++;
					m_Flametotal++;
					m_isFlameATK = false;
					m_animState = TerrorBringerAnimInfo::enTe_Idle01;
					m_skinModelRender->PlayAnimation(m_animState, 0.0f);
					m_isFlameATK = false;
				}
				break;
			case GetDamage_state:
				m_animState = TerrorBringerAnimInfo::enTe_Gethit;
				Sound(L"Assets/sound/SE_Dragon_Damage.wav");
				m_isAttack = false;
				m_ATKoff = false;
				m_count = 0;
				if (!m_skinModelRender->GetisAnimationPlaing()) {
					m_soundFlag = false;
					m_status = Idle_state;
					m_animState = TerrorBringerAnimInfo::enTe_Idle01;
					m_skinModelRender->PlayAnimation(m_animState, 0.0f);
				}
				break;
			case Die_state:
				m_animState = TerrorBringerAnimInfo::enTe_Die;
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
	m_skinModelRender->SetScale({ 60.0f, 60.0f, 60.0f });
	m_skinModelRender->SetRotation(m_rotation);
	m_skinModelRender->SetPosition(m_position);
	m_skinModelRender->PlayAnimation(m_animState, 1.0f / 60.0f);
	//デバッグ用。
	printf_s("AnimationState_%d\n", m_animState);
	printf_s("EnemyHP_%d\n", m_hp);
}