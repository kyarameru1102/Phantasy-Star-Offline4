#include "stdafx.h"
#include "RecoveryItem.h"
#include "Player.h"

const float RECOVERY_HP = 100.0f;		//HP�̉񕜗ʁB

RecoveryItem::RecoveryItem()
{
}

RecoveryItem::~RecoveryItem()
{
	if (m_recoveryItemModel != nullptr) {
		DeleteGO(m_recoveryItemModel);
	}
}

bool RecoveryItem::Start()
{
	m_recoveryItemModel = NewGO<SkinModelRender>(0);
	m_recoveryItemModel->Init("Assets/modelData/Item/RecoveryItem.tkm", 0, 0, "Assets/shader/model.fx", SkinModelRender::YUp);
	m_recoveryItemModel->SetPosition(m_position);

	m_ghostObject.CreateBox(m_position, m_rotation, m_ghostScale);
	
	return true;
}

void RecoveryItem::Update()
{
	RecoveryPlayerHP();

	//�S�[�X�g�I�u�W�F�N�g�̍��W��ݒ�B
	m_ghostObject.SetPosition(m_position);
}

void RecoveryItem::RecoveryPlayerHP()
{
	QueryGOs<Player>("player", [&](Player* player)->bool {
		//�v���C���[�̃L�����R�����擾�B
		CharacterController& charaCon = *player->GetCharacterController();
		g_physics.ContactTestCharaCon(charaCon, [&](const btCollisionObject& collisionObject) {
			if (m_ghostObject.IsSelf(collisionObject) == true) {
				//����������v���C���[��HP���񕜂���B
				player->SetHP(RECOVERY_HP);
				player->SetBeforeHp(player->GetHP());
				DeleteGO(this);
			}
			});
		return true;
		});
}
