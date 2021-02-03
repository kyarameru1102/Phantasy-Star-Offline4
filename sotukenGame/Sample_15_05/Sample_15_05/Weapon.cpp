#include "stdafx.h"
#include "Weapon.h"
#include "Player.h"
#include "EnBase.h"
#include "PlayerAttackAnimation.h"

Weapon::Weapon()
{
}


Weapon::~Weapon()
{
	DeleteGO(m_skimModelRender);
}
void Weapon::AttackHit()
{
	QueryGOs<EnBase>("dragon", [&](EnBase * drBoar)->bool {
		if (drBoar->GetHit() != true) {
			//�܂��U�����󂯂Ă��Ȃ��B				//�G�̃L�����R�����擾�B
			CharacterController& charaCon = *drBoar->GetCharaCon();
			g_physics.ContactTestCharaCon(charaCon, [&](const btCollisionObject & collisionObject) {
				if (m_ghostObj.IsSelf(collisionObject) == true) {
					//�������Ă�����A�_���[�W��^����B
					drBoar->ReceiveDamage(m_player->GetmAtaackPow());
					//�U�����󂯂��t���O�𗧂Ă�B
					drBoar->SetHit(true);
				}
			});	
		}
		return true;
	});
}
bool Weapon::Start()
{
	//���f���̏������B
	m_skimModelRender = NewGO<SkinModelRender>(0);
	m_skimModelRender->Init(
		"Assets/modelData/player/weapon/weapon01.tkm",
		nullptr,
		0,
		"Assets/shader/model.fx",
		SkinModelRender::YUp
	);
	m_skimModelRender->SetPosition(m_position);
	m_skimModelRender->SetRotation(m_rotation);
	m_player = FindGO<Player>("player");
	m_playerAttackAnim = FindGO<PlayerAttackAnimation>("playerAttackAnimation");
	m_nextAttackNum = m_playerAttackAnim->GetAttackNum();
	//�S�[�X�g�쐬�B
	m_ghostObj.CreateBox(
		m_position,
		m_rotation,
		{ 500.0f, 100.0f, 100.0f }
	);
	return true;
}

void Weapon::Update()
{
	m_player->GetPlayerSkinModelRemder().GetModel().GetSkeleton().GetBone(m_boneNum)->CalcWorldTRS(
		m_position,
		m_rotation,
		m_scale
	);
	Quaternion weaponRot = Quaternion::Identity;
	weaponRot.SetRotationDegX(90.0f);
	weaponRot.Multiply(m_rotation);
	//���W�Ƀ��[�u�X�s�[�h�����Z�B

	m_position += m_player->GetWeaponMoveSpeed();
	//���W�ݒ�B
	m_skimModelRender->SetPosition(m_position);
	//��]�ݒ�B
	m_skimModelRender->SetRotation(weaponRot);

	m_ghostObj.SetPosition(m_position);
	m_ghostObj.SetRotation(weaponRot);

	if (m_player->GetAttackFlag() != false || m_player->GetSpecialAttackFlag() != false) {
		//�v���C���[���U�����Ă���B
		AttackHit();
	}
}
