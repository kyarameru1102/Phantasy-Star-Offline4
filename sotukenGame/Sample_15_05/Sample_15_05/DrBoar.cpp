#include "stdafx.h"
#include "DrBoar.h"
#include "Player.h"
#include "Game.h"
DrBoar::DrBoar()
{
}

DrBoar::~DrBoar()
{
	DeleteGO(m_skinModelRender);
	DeleteGO(m_boarAnim);
}

bool DrBoar::Start()
{
	//プレイヤーのアニメーションのインスタンス作成。
	m_boarAnim = NewGO<BoarAnimation>(0, "boarAnim");
	//配色を決める。
	//m_appearcolor = boarcolor[rand() % boarcolor.size()];
	//モデルの初期化
	if (m_basicStatusNum == en1) {
		m_skinModelRender = NewGO<SkinModelRender>(0);
		m_skinModelRender->Init("Assets/modelData/enemy/DragonBoar/Blue/DrBoarBl.tkm", m_boarAnim->GetAnimationClip(), BoarAnimInfo::enBoarAnimClip_num);
		//攻撃力を初期化。
		m_attackPower = 20.0f;
		//HPを初期化。
		m_hp = 100.0f;
		m_fullhp = m_hp;
	}
	else if (m_basicStatusNum == en2)
	{
		m_skinModelRender = NewGO<SkinModelRender>(0);
		m_skinModelRender->Init("Assets/modelData/enemy/DragonBoar/Gold/DrBoarGo.tkm", m_boarAnim->GetAnimationClip(), BoarAnimInfo::enBoarAnimClip_num);
		//攻撃力を初期化。
		m_attackPower = 20.0f;
		//HPを初期化。
		m_hp = 150.0f;
		m_fullhp = m_hp;
	}
	else if (m_basicStatusNum == en3)
	{
		m_skinModelRender = NewGO<SkinModelRender>(0);
		m_skinModelRender->Init("Assets/modelData/enemy/DragonBoar/Green/DrBoarGr.tkm", m_boarAnim->GetAnimationClip(), BoarAnimInfo::enBoarAnimClip_num);
		//攻撃力を初期化。
		m_attackPower = 25.0f;
		//HPを初期化。a
		m_hp = 200.0f;
		m_fullhp = m_hp;
	}
	else if (m_basicStatusNum == en4)
	{
		m_skinModelRender = NewGO<SkinModelRender>(0);
		m_skinModelRender->Init("Assets/modelData/enemy/DragonBoar/Red/DrBoarRe.tkm", m_boarAnim->GetAnimationClip(), BoarAnimInfo::enBoarAnimClip_num);
		//攻撃力を初期化。
		m_attackPower = 25.0f;
		//HPを初期化。
		m_hp = 250.0f;
		m_fullhp = m_hp;
	}

	//.SetRotationDegY(90.0f);
	//キャラコン初期化。
	m_charaCon.Init(145.0f, 200.0f, m_position);
	Vector3 ghostPos = m_position;
	m_ghostObj.CreateBox(ghostPos, m_rotation, Vector3(50.0f, 80.0f, 63.0f));

	m_player = FindGO<Player>("player");
	m_game = FindGO<Game>("Game");

	//攻撃力を初期化。
	
	//攻撃力に倍率をかける。
	m_attackPower *= m_magnificationAP;
	//HPを初期化。
	
	//HPに倍率をかける。
	m_hp *= m_magnificationHP;

	return true;
}

void DrBoar::Move()
{
	m_status = Walk_state;
	Vector3 playerLen = m_toPlayer;
	playerLen.Normalize();
	m_movespeed = playerLen * 1.6f;
	if (m_toPlayer.Length() <= 160.0f)
	{
		m_movespeed = { 0.0f, 0.0f, 0.0f };
		m_position = m_charaCon.Execute(1.0f, m_movespeed);
	}
	else {
		m_movespeed.y = m_speedY;
		m_position = m_charaCon.Execute(1.0f, m_movespeed);
	}
	
	
}
void DrBoar::AttackMove()
{
	Vector3 playerLen = m_toPlayer;
	playerLen.Normalize();


	m_movespeed = playerLen * 1.3f;

	
	if (m_toPlayer.Length() <= 160.0f)
	{
		m_movespeed = { 0.0f, 0.0f, 0.0f };
		m_position = m_charaCon.Execute(1.0f, m_movespeed);
	}
	else {
		m_movespeed.y = m_speedY;
		m_position = m_charaCon.Execute(1.0f, m_movespeed);
		m_oldpos = m_position;
	}
	
	
}
void DrBoar::Turn()
{
	Vector3 playerLen = m_player->GetPosition() - m_position;
	float angle = atan2(playerLen.x, playerLen.z);
	m_rotation.SetRotation(Vector3::AxisY, angle);
}

void DrBoar::Attack()
{

	
	if (m_toPlayer.Length() <= 180.0f && m_isATK == true)
	{
		m_status = Attack_state;
		if (m_skinModelRender->GetisAnimationPlaing() == true && m_toPlayer.Length() >= 500)
		{
			m_hedboneNum = m_skinModelRender->GetModel().GetSkeleton().FindBoneID(L"UpperMouth2");
			m_skinModelRender->GetModel().GetSkeleton().GetBone(m_hedboneNum)->CalcWorldTRS(
				m_hedpos,
				m_hedrot,
				m_hedscale
			);

			m_jawboneNum = m_skinModelRender->GetModel().GetSkeleton().FindBoneID(L"Jaw3");
			m_skinModelRender->GetModel().GetSkeleton().GetBone(m_jawboneNum)->CalcWorldTRS(
				m_jawpos,
				m_jawrot,
				m_jawscale
			);

			m_toHedPlayer = m_player->GetPosition() - m_hedpos;
			m_toJawPlayer = m_player->GetPosition() - m_jawpos;
		}
		if (m_toHedPlayer.Length() <= 100 && m_toJawPlayer.Length() <= 100)
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
}

void DrBoar::HornAttack()
{


	if ( m_isHornATK == true && m_ishornATKFlag == false)
	{
		m_status = HornAttack_state;
		if (m_skinModelRender->GetisAnimationPlaing() == true && m_toPlayer.Length() >= 100)
		{
			m_hedboneNum = m_skinModelRender->GetModel().GetSkeleton().FindBoneID(L"UpperMouth2");
			m_skinModelRender->GetModel().GetSkeleton().GetBone(m_hedboneNum)->CalcWorldTRS(
				m_hedpos,
				m_hedrot,
				m_hedscale
			);

			m_toHedPlayer = m_player->GetPosition() - m_hedpos;
		}
		if (m_toHedPlayer.Length() <= 100)
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
}

void DrBoar::Die()
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

void DrBoar::Update()
{
	//フェードフラグがtrueで無い時
	if (m_game->GetIsWave() != true)
	{
		//毎フレーム距離はかる。
		m_toPlayer = m_player->GetPosition() - m_position;

		//プレイヤーに近づく。
		if (m_status != GetDamage_state) {
			if (m_status != Attack_state && m_status != HornAttack_state && m_status != Die_state) {
				Move();
				Turn();
			}

			//距離が近づくと。
			if (m_isHornATK == true)
			{
				AttackMove();
			}
			if (m_isATKcount != 2)
			{
				Attack();
			}

			//Attack();
			if (m_isATKcount == 2)
			{
				m_isATK = false;
				m_isHornATK = true;
			}
			if (m_ishornATKFlag == true)
			{
				m_isATKcount = 0;
				m_isATK = true;
				m_isHornATK = false;
				m_ishornATKFlag = false;
			}
			HornAttack();
		}
		//体力がゼロになると
		Die();

		switch (m_status)
		{
		case Idle_state:
			m_animState = BoarAnimInfo::enBo_Idle;
			break;
		case Walk_state:
			m_animState = BoarAnimInfo::enBo_Walk;
			//WalkSound(L"Assets/sound/SE_Dragon_Walk.wav");
			if (!m_skinModelRender->GetisAnimationPlaing()) {
				m_soundFlag = false;
			}
			break;
		case Attack_state:
			m_animState = BoarAnimInfo::enBo_Attack;
			m_count++;
			m_isAttack = true;
		    Sound(L"Assets/sound/SE_Dragon_Fang.wav");
			if (!m_skinModelRender->GetisAnimationPlaing()) {
				m_status = Idle_state;
				m_isAttack = false;
				m_ATKoff = false;
				m_soundFlag = false;
				m_isATKcount += 1;
				m_count = 0;
				m_animState = BoarAnimInfo::enBo_Idle;
				m_skinModelRender->PlayAnimation(m_animState, 0.0f);
			}
			break;
		case HornAttack_state:
			m_animState = BoarAnimInfo::enBo_Hornattack;
			m_count++;
			m_isAttack = true;
			Sound(L"Assets/sound/SE_Dragon_Fang.wav");
			if (!m_skinModelRender->GetisAnimationPlaing()) {
				m_status = Idle_state;
				m_isAttack = false;
				m_ATKoff = false;
				m_soundFlag = false;
				m_ishornATKFlag = true;
				m_count = 0;
				m_animState = BoarAnimInfo::enBo_Idle;
				m_skinModelRender->PlayAnimation(m_animState, 0.0f);
			}
			break;
		case GetDamage_state:
			m_animState = BoarAnimInfo::enBo_Gethit;
			Sound(L"Assets/sound/SE_Dragon_Damage.wav");
			m_isAttack = false;
			m_ATKoff = false;
			m_count = 0;
			if (!m_skinModelRender->GetisAnimationPlaing()) {
				m_soundFlag = false;
				m_status = Idle_state;
				m_animState = BoarAnimInfo::enBo_Idle;
				m_skinModelRender->PlayAnimation(m_animState, 0.0f);
			}
			break;
		case Die_state:
			m_animState = BoarAnimInfo::enBo_Die;
			Sound(L"Assets/sound/SE_Dragon_Die.wav");
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
	m_skinModelRender->SetScale({ 40.0, 40.0, 40.0 });
	m_skinModelRender->SetRotation(m_rotation);
	m_skinModelRender->SetPosition(m_position);
	m_skinModelRender->PlayAnimation(m_animState, 1.0f / 60.0f);
	//デバッグ用。
	printf_s("AnimationState_%d\n", m_animState);
	printf_s("EnemyHP_%d\n", m_hp);
	
}