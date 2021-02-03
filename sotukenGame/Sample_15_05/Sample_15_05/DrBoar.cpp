#include "stdafx.h"
#include "DrBoar.h"
#include "Player.h"
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
	//�v���C���[�̃A�j���[�V�����̃C���X�^���X�쐬�B
	m_boarAnim = NewGO<BoarAnimation>(0, "boarAnim");
	//�z�F�����߂�B
	m_appearcolor = boarcolor[rand() % boarcolor.size()];
	//���f���̏�����
	if (m_appearcolor == 1) {
		m_skinModelRender = NewGO<SkinModelRender>(0);
		m_skinModelRender->Init("Assets/modelData/enemy/DragonBoar/Blue/DrBoarBl.tkm", m_boarAnim->GetAnimationClip(), BoarAnimInfo::enBoarAnimClip_num);
		//m_position = { 300.0f, 0.0f, -100.0f };
	}
	else if (m_appearcolor == 2)
	{
		m_skinModelRender = NewGO<SkinModelRender>(0);
		m_skinModelRender->Init("Assets/modelData/enemy/DragonBoar/Gold/DrBoarGo.tkm", m_boarAnim->GetAnimationClip(), BoarAnimInfo::enBoarAnimClip_num);
		//m_position = { 300.0f, 0.0f, 100.0f };
	}
	else if (m_appearcolor == 3)
	{
		m_skinModelRender = NewGO<SkinModelRender>(0);
		m_skinModelRender->Init("Assets/modelData/enemy/DragonBoar/Green/DrBoarGr.tkm", m_boarAnim->GetAnimationClip(), BoarAnimInfo::enBoarAnimClip_num);
		//m_position = { -300.0f, 0.0f, -100.0f };
	}
	else if (m_appearcolor == 4)
	{
		m_skinModelRender = NewGO<SkinModelRender>(0);
		m_skinModelRender->Init("Assets/modelData/enemy/DragonBoar/Red/DrBoarRe.tkm", m_boarAnim->GetAnimationClip(), BoarAnimInfo::enBoarAnimClip_num);
		//m_position = { -300.0f, 0.0f, 100.0f };
	}
	
	//.SetRotationDegY(90.0f);
	//�L�����R���������B
	m_charaCon.Init(145.0f, 200.0f, m_position);
	Vector3 ghostPos = m_position;
	m_ghostObj.CreateBox(ghostPos, m_rotation, Vector3(50.0f, 50.0f, 50.0f));

	m_player = FindGO<Player>("player");


	//�U���͂��������B
	m_attackPower = 10.0f;
	m_attackPower *= m_magnificationAP;
	//HP���������B
	m_hp = 100.0f;
	m_hp *= m_magnificationHP;


	return true;
}

void DrBoar::Move()
{
	m_status = Walk_state;
	Vector3 playerLen = m_toPlayer;
	playerLen.Normalize();
	m_movespeed = playerLen * 1.4f;
	
	m_movespeed.y = m_speedY;
	m_position = m_charaCon.Execute(1.0f, m_movespeed);
	
}
void DrBoar::AttackMove()
{
	Vector3 playerLen = m_toPlayer;
	playerLen.Normalize();

	if (m_isATKcount == 2 && m_backtimer <= 100)
	{
		m_backtimer++;
		
		m_movespeed = playerLen * -1.4f;
	}
	if (m_backtimer >= 100)
	{
		m_movespeed = playerLen * 1.5f;
		m_jyosoufin = true;
	}
	
	else {
		m_movespeed = playerLen * 1.3f;
	}
	
	m_movespeed.y = m_speedY;
	m_position = m_charaCon.Execute(1.0f, m_movespeed);
}
void DrBoar::Turn()
{
	Vector3 playerLen = m_player->GetPosition() - m_position;
	float angle = atan2(playerLen.x, playerLen.z);
	m_rotation.SetRotation(Vector3::AxisY, angle);
}

void DrBoar::Attack()
{
	if (m_toPlayer.Length() <= 200.0f && m_isATK == true)
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

void DrBoar::HornAttack()
{

	if (m_jyosoufin == true && m_isHornATK == true && m_ishornATKFlag == false)
	{
		m_status = HornAttack_state;
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
	//���t���[�������͂���B
	m_toPlayer = m_player->GetPosition() - m_position;

	//�v���C���[�ɋ߂Â��B
	if (m_status != GetDamage_state) {
		if (m_status != Attack_state && m_status != HornAttack_state && m_status != Die_state) {
			Move();
			Turn();
		}

		//�������߂Â��ƁB
		if ( m_isHornATK ==true )
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
	//�̗͂��[���ɂȂ��
	Die();

	switch (m_status)
	{
	case Idle_state:
		m_animState = BoarAnimInfo::enBo_Idle;
		break;
	case Walk_state:
		m_animState = BoarAnimInfo::enBo_Walk;
		break;
	case Attack_state:
		m_animState = BoarAnimInfo::enBo_Attack;
		m_count++;
		m_isAttack = true;
		if (!m_skinModelRender->GetisAnimationPlaing()) {
			m_status = Idle_state;
			m_isAttack = false;
			m_ATKoff = false;
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
		if (!m_skinModelRender->GetisAnimationPlaing()) {
			m_status = Idle_state;
			m_isAttack = false;
			m_ATKoff = false;
			m_ishornATKFlag = true;
			m_count = 0;
			m_animState = BoarAnimInfo::enBo_Idle;
			m_skinModelRender->PlayAnimation(m_animState, 0.0f);
		}
		break;
	case GetDamage_state:
		m_animState = BoarAnimInfo::enBo_Gethit;
		m_isAttack = false;
		m_ATKoff = false;
		m_count = 0;
		if (!m_skinModelRender->GetisAnimationPlaing()) {
			m_status = Idle_state;
			m_animState = BoarAnimInfo::enBo_Idle;
			m_skinModelRender->PlayAnimation(m_animState, 0.0f);
		}
		break;
	case Die_state:
		m_animState = BoarAnimInfo::enBo_Die;
		break;
	default:
		break;
	}
	
	if (m_movespeed.Length() >= 0.0f) {
		m_dir = m_movespeed;
		m_dir.Normalize();
		m_dir *= 200.0f;
	}
	m_ghostPos = m_position + m_dir;

	m_ghostObj.SetPosition(m_ghostPos);
	m_ghostObj.SetRotation(m_rotation);
	m_skinModelRender->SetScale({ 40.0, 40.0, 40.0 });
	m_skinModelRender->SetRotation(m_rotation);
	m_skinModelRender->SetPosition(m_position);
	m_skinModelRender->PlayAnimation(m_animState, 1.0f / 60.0f);
	//�f�o�b�O�p�B
	printf_s("AnimationState_%d\n", m_animState);
	printf_s("EnemyHP_%d\n", m_hp);
	
}