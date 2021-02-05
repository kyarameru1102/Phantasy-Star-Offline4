#include "stdafx.h"
#include "DrUsurper.h"
#include "Player.h"
#include "Game.h"
DrUsurper::DrUsurper()
{

}

DrUsurper::~DrUsurper()
{
	DeleteGO(m_skinModelRender);
	DeleteGO(m_usurperAnim);
}

bool DrUsurper::Start()
{
	//ドラゴンユーサープ
	m_usurperAnim = NewGO<UsurperAnimation>(0);
	//配色を決める。
	m_appearcolor = usurpercolor[rand() % usurpercolor.size()];
	//モデルの初期化
	if (m_appearcolor == 1) {
		m_skinModelRender = NewGO<SkinModelRender>(0);
		m_skinModelRender->Init("Assets/modelData/enemy/DragonUsurper/blue/DrUsBl.tkm", m_usurperAnim->GetAnimationClip(), UsurperAnimInfo::enUsurperAnimClip_num);
	}
	else if (m_appearcolor == 2) {
		m_skinModelRender = NewGO<SkinModelRender>(0);
		m_skinModelRender->Init("Assets/modelData/enemy/DragonUsurper/green/DrUsGr.tkm", m_usurperAnim->GetAnimationClip(), UsurperAnimInfo::enUsurperAnimClip_num);
	}
	else if (m_appearcolor == 3) {
		m_skinModelRender = NewGO<SkinModelRender>(0);
		m_skinModelRender->Init("Assets/modelData/enemy/DragonUsurper/purple/DrUsPu.tkm", m_usurperAnim->GetAnimationClip(), UsurperAnimInfo::enUsurperAnimClip_num);
	}
	else if (m_appearcolor == 4) {
		m_skinModelRender = NewGO<SkinModelRender>(0);
		m_skinModelRender->Init("Assets/modelData/enemy/DragonUsurper/red/DrUsRe.tkm", m_usurperAnim->GetAnimationClip(), UsurperAnimInfo::enUsurperAnimClip_num);
	}
	//キャラコン初期化。
	m_charaCon.Init(145.0f, 200.0f, m_position);
	Vector3 ghostPos = m_position;
	m_ghostObj.CreateBox(ghostPos, m_rotation, Vector3(80.0f, 50.0f, 80.0f));

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

void DrUsurper::Move()
{
	Vector3 playerLen = m_toPlayer;
	playerLen.Normalize();
	if (m_toPlayer.Length() <= 800.0f && m_isMouthATK == false && m_isFlameATK == false)
	{
		
		m_movespeed = playerLen * 2.5;
		m_movespeed.y = m_speedY;
		m_isHandATK = true;

	}
	if (m_HandATKCount == 1)
	{
		m_isHandATK = false;
	}
	if (m_toPlayer.Length() <= 500.0f && m_isHandATK == false && m_isFlameATK == false)
	{
		m_isMouthATK = true;
		m_movespeed = { 0.0f, 0.0f, 0.0f };
	}
	if (m_toPlayer.Length() <= 1000.0f && m_HandATKCount >= 1 && m_MouthATKCont >= 2)
	{
		m_isFlameATK = true;
		m_movespeed = { 0.0f, 0.0f, 0.0f };
		
	}
	else if ( m_isHandATK == false && m_isMouthATK == false && m_isFlameATK == false)
	{
		m_status = Run_state;

		m_movespeed = playerLen * 1.7f;
		m_movespeed.y = m_speedY;
	}
	
	m_position = m_charaCon.Execute(1.0f, m_movespeed);
	
}

void DrUsurper::Turn()
{
	
		Vector3 playerLen = m_player->GetPosition() - m_position;
		float angle = atan2(playerLen.x, playerLen.z);
		m_rotation.SetRotation(Vector3::AxisY, angle);
	
	
}
void DrUsurper::Scream()
{
	if (m_screamflag == true)
	{
		m_status = Scream_state;
	}
}
void DrUsurper::HandAttack()
{
	m_status = HandAttack_state;
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

void DrUsurper::MouthAttack()
{
	
	
		m_status = MouthAttack_state;
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

void DrUsurper::FlameAttack()
{
		m_status = FlameAttack_state;
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

void DrUsurper::FlyFlame()
{
	if (m_toPlayer.Length() <= 200.0f)
	{
		m_status = FlyFlame_state;
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
}

void DrUsurper::Die()
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
void DrUsurper::Update()
{
	//フェードのフラグがtrueでないとき
	if (m_game->GetIsWave() != true)
	{
		//毎フレーム距離はかる。
		m_toPlayer = m_player->GetPosition() - m_position;

		//プレイヤーに近づく。
		if (m_status != GetDamage_state) {
			Scream();
			if (m_status != MouthAttack_state && m_status != FlameAttack_state && m_status != HandAttack_state && m_hp >0) {
				Move();
				Turn();
			}

			//距離が近づくと。
			//走りからの腕攻撃　１回
			if (m_isHandATK == true)
			{
				HandAttack();
			}
			//	噛みつき２回
			if (m_isMouthATK == true)
			{
				MouthAttack();
			}
			

			//	火炎攻撃　１回
			if (m_isFlameATK == true)
			{
				FlameAttack();
			}
			//	前ジャンからの腕攻撃　1回

		}
		//体力がゼロになると
		Die();

		switch (m_status)
		{
		case Idle_state:
			m_animState = UsurperAnimInfo::enUs_Idle01;
			break;
		case Walk_state:
			m_animState = UsurperAnimInfo::enUs_Walk;
			break;
		case Run_state:
			m_animState = UsurperAnimInfo::enUs_Run;
			break;
		case Scream_state:
			m_animState = UsurperAnimInfo::enUs_Scream;

			if (!m_skinModelRender->GetisAnimationPlaing())
			{
				m_screamflag = false;
				m_animState = UsurperAnimInfo::enUs_Idle01;
				m_skinModelRender->PlayAnimation(m_animState, 0.0f);
			}
			break;
		case HandAttack_state:
			m_animState = UsurperAnimInfo::enUs_HandAttack;
			m_count++;
			m_isAttack = true;
			if (!m_skinModelRender->GetisAnimationPlaing()) {
				m_status = Idle_state;
				m_isAttack = false;
				m_ATKoff = false;
				m_count = 0;
				m_HandATKCount++;
				m_isHandATK = false;
				m_animState = UsurperAnimInfo::enUs_Idle01;
				m_skinModelRender->PlayAnimation(m_animState, 0.0f);
			}
			break;
		case MouthAttack_state:
			m_animState = UsurperAnimInfo::enUs_MouthAttack;
			m_count++;
			m_isAttack = true;
			if (!m_skinModelRender->GetisAnimationPlaing()) {
				m_status = Idle_state;
				m_isAttack = false;
				m_ATKoff = false;
				m_count = 0;
				m_MouthATKCont++;
				m_isMouthATK = false;
				m_animState = UsurperAnimInfo::enUs_Idle01;
				m_skinModelRender->PlayAnimation(m_animState, 0.0f);
			}
			break;
		case FlameAttack_state:
			m_animState = UsurperAnimInfo::enUs_FlameAttack;
			m_count++;
			m_isAttack = true;
			if (!m_skinModelRender->GetisAnimationPlaing()) {
				m_status = Idle_state;
				m_isAttack = false;
				m_ATKoff = false;
				m_count = 0;
				m_FlameATKCount++;
				m_HandATKCount = 0;
				m_MouthATKCont = 0;
				m_isFlameATK = false;
				m_animState = UsurperAnimInfo::enUs_Idle01;
				m_skinModelRender->PlayAnimation(m_animState, 0.0f);
			}
			break;
		case FlyFlame_state:
			m_animState = UsurperAnimInfo::enUs_FlyFlame;
			m_count++;
			m_isAttack = true;
			if (!m_skinModelRender->GetisAnimationPlaing()) {
				m_status = Idle_state;
				m_isAttack = false;
				m_ATKoff = false;
				m_count = 0;
				m_animState = UsurperAnimInfo::enUs_Idle01;
				m_skinModelRender->PlayAnimation(m_animState, 0.0f);
			}
			break;
		case GetDamage_state:
			m_animState = UsurperAnimInfo::enUs_Gethit;
			m_isAttack = false;
			m_ATKoff = false;
			m_count = 0;
			if (!m_skinModelRender->GetisAnimationPlaing()) {
				m_status = Idle_state;
				m_animState = UsurperAnimInfo::enUs_Idle01;
				m_skinModelRender->PlayAnimation(m_animState, 0.0f);
			}
			break;
		case Die_state:
			m_animState = UsurperAnimInfo::enUs_Die;
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