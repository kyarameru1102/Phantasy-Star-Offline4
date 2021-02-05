#include "stdafx.h"
#include "DrSoulEater.h"
#include "Player.h"
#include "Game.h"
DrSoulEater::DrSoulEater()
{

}

DrSoulEater::~DrSoulEater()
{

}

bool DrSoulEater::Start()
{
	//ドラゴンソウルイーター
	m_souleAnim = NewGO<SoulEaterAnimation>(0);
	//配色を決める。
	m_appearcolor = soulcolor[rand() % soulcolor.size()];
	//モデルの初期化
	if (m_appearcolor == 1) {
		m_skinModelRender = NewGO<SkinModelRender>(0);
		m_skinModelRender->Init("Assets/modelData/enemy/DragonSoulEater/blue/DrSoEaBl.tkm", m_souleAnim->GetAnimationClip(), SoulEaterAnimInfo::enSoulEAnimClip_num);
	}
	else if (m_appearcolor == 2) {
		m_skinModelRender = NewGO<SkinModelRender>(0);
		m_skinModelRender->Init("Assets/modelData/enemy/DragonSoulEater/green/DrSoEaGr.tkm", m_souleAnim->GetAnimationClip(), SoulEaterAnimInfo::enSoulEAnimClip_num);
	}
	else if (m_appearcolor == 3) {
		m_skinModelRender = NewGO<SkinModelRender>(0);
		m_skinModelRender->Init("Assets/modelData/enemy/DragonSoulEater/purple/DrSoEaPu.tkm", m_souleAnim->GetAnimationClip(), SoulEaterAnimInfo::enSoulEAnimClip_num);
	}
	else if (m_appearcolor == 4) {
		m_skinModelRender = NewGO<SkinModelRender>(0);
		m_skinModelRender->Init("Assets/modelData/enemy/DragonSoulEater/red/DrSoEaRe.tkm", m_souleAnim->GetAnimationClip(), SoulEaterAnimInfo::enSoulEAnimClip_num);
	}
	//キャラコン初期化。
	m_charaCon.Init(145.0f, 200.0f, m_position);
	Vector3 ghostPos = m_position;
	m_ghostObj.CreateBox(ghostPos, m_rotation, Vector3(50.0f, 50.0f, 50.0f));

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

void DrSoulEater::Move()
{
	
	m_status = Walk_state;
	Vector3 playerLen = m_toPlayer;
	playerLen.Normalize();
	m_movespeed = playerLen * 1.2f;
	m_movespeed.y = m_speedY;
	m_position = m_charaCon.Execute(1.0f, m_movespeed);
}

void DrSoulEater::Turn()
{
	Vector3 playerLen = m_player->GetPosition() - m_position;
	float angle = atan2(playerLen.x, playerLen.z);
	m_rotation.SetRotation(Vector3::AxisY, angle);
}
void DrSoulEater::Scream()
{
	if (m_screamflag == true)
	{
		m_status = Scream_state;
	}
}
void DrSoulEater::Attack()
{
	if (m_toPlayer.Length() <= 200.0f)
	{
		m_status = Attack_state;
		CharacterController& charaCon = *m_player->GetCharacterController();
		g_physics.ContactTestCharaCon(charaCon, [&](const btCollisionObject& collisionObject) {
			if (m_ghostObj.IsSelf(collisionObject) == true) {
				if (m_isAttack && !m_ATKoff) {
					if (m_count >= 60 && m_count <= 70) {
						m_player->ReceiveDamage(10);
						m_ATKoff = true;
						printf_s("Enemy_KOUGEKI\n");
					}
				}
			}
			});
	}
}

void DrSoulEater::TailAttack()
{
	if (m_toPlayer.Length() <= 200.0f)
	{
		m_status = TailAttack_state;
		CharacterController& charaCon = *m_player->GetCharacterController();
		g_physics.ContactTestCharaCon(charaCon, [&](const btCollisionObject& collisionObject) {
			if (m_ghostObj.IsSelf(collisionObject) == true) {
				if (m_isAttack && !m_ATKoff) {
					if (m_count >= 60 && m_count <= 70) {
						m_player->ReceiveDamage(10);
						m_ATKoff = true;
						printf_s("Enemy_KOUGEKI\n");
					}
				}
			}
			});
	}
}

void DrSoulEater::FireballShoot()
{
	if (m_toPlayer.Length() <= 400.0f)
	{
		m_status = FireballShoot_state;
		CharacterController& charaCon = *m_player->GetCharacterController();
		g_physics.ContactTestCharaCon(charaCon, [&](const btCollisionObject& collisionObject) {
			if (m_ghostObj.IsSelf(collisionObject) == true) {
				if (m_isAttack && !m_ATKoff) {
					if (m_count >= 60 && m_count <= 70) {
						m_player->ReceiveDamage(10);
						m_ATKoff = true;
						printf_s("Enemy_KOUGEKI\n");
					}
				}
			}
			});
	}
}
void DrSoulEater::Die()
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

void DrSoulEater::Update()
{
	//フェードのフラグがtrueで無い時
	if (m_game->GetIsWave() != true)
	{
		//毎フレーム距離はかる。
		m_toPlayer = m_player->GetPosition() - m_position;

		//プレイヤーに近づく。
		if (m_status != GetDamage_state) {
			Scream();
			if (m_status != Attack_state && m_hp >0) {
				Move();
				Turn();
			}

			if (m_isATK == true)
			{
				Attack();
			}
			if (m_isTailATK == true)
			{
				TailAttack();
			}
			if (m_isFireBallATK == true)
			{
				FireballShoot();
			}

		}
		//体力がゼロになると
		Die();

		switch (m_status)
		{
		case Idle_state:
			m_animState = SoulEaterAnimInfo::enSo_Idle;
			break;
		case Walk_state:
			m_animState = SoulEaterAnimInfo::enSo_Walk;
			break;
		case Scream_state:
			m_animState = SoulEaterAnimInfo::enSo_Scream;

			if (!m_skinModelRender->GetisAnimationPlaing())
			{
				m_screamflag = false;
				m_animState = SoulEaterAnimInfo::enSo_Idle;
				m_skinModelRender->PlayAnimation(m_animState, 0.0f);
			}

			break;
		case Attack_state:
			m_animState = SoulEaterAnimInfo::enSo_BasicAttack;
			m_count++;
			m_isAttack = true;
			if (!m_skinModelRender->GetisAnimationPlaing()) {
				m_status = Idle_state;
				m_isAttack = false;
				m_ATKoff = false;
				m_count = 0;
				m_animState = SoulEaterAnimInfo::enSo_Idle;
				m_skinModelRender->PlayAnimation(m_animState, 0.0f);
			}
			break;
		case TailAttack_state:
			m_animState = SoulEaterAnimInfo::enSo_TailAttack;
			m_count++;
			m_isAttack = true;
			if (!m_skinModelRender->GetisAnimationPlaing()) {
				m_status = Idle_state;
				m_isAttack = false;
				m_ATKoff = false;
				m_count = 0;
				m_animState = SoulEaterAnimInfo::enSo_Idle;
				m_skinModelRender->PlayAnimation(m_animState, 0.0f);
			}
			break;
		case FireballShoot_state:
			m_animState = SoulEaterAnimInfo::enSo_FireballShoot;
			m_count++;
			m_isAttack = true;
			if (!m_skinModelRender->GetisAnimationPlaing()) {
				m_status = Idle_state;
				m_isAttack = false;
				m_ATKoff = false;
				m_count = 0;
				m_animState = SoulEaterAnimInfo::enSo_Idle;
				m_skinModelRender->PlayAnimation(m_animState, 0.0f);
			}
			break;
		case GetDamage_state:
			m_animState = SoulEaterAnimInfo::enSo_Gethit;
			m_isAttack = false;
			m_ATKoff = false;
			m_count = 0;
			if (!m_skinModelRender->GetisAnimationPlaing()) {
				m_status = Idle_state;
				m_animState = SoulEaterAnimInfo::enSo_Idle;
				m_skinModelRender->PlayAnimation(m_animState, 0.0f);
			}
			break;
		case Die_state:
			m_animState = SoulEaterAnimInfo::enSo_Die;
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