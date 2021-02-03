#include "stdafx.h"
#include "IStage.h"
#include "Player.h"
#include "Random.h"
void IStage::GhostContactCharaCon()
{
	QueryGOs<Player>("player", [&](Player* player)->bool {
		//�v���C���[�̃L�����R�����擾�B
		CharacterController& charaCon = *player->GetCharacterController();
		g_physics.ContactTestCharaCon(charaCon, [&](const btCollisionObject& collisionObject) {
			if (m_ghostObject.IsSelf(collisionObject) == true) {
				//����������X�e�[�W��؂�ւ���B
				m_sceanChangeOK = true;
			}
			});
		return true;
		});
}
Vector3 IStage::InitEnemyPos()
{
	//Random�N���X�������B
	m_rand = FindGO<Random>("rnad");
	//�G��X���W��Z���W��͈͓��Ń����_���Ō��߂�B
	float rand = m_rand->GetRandDouble();
	float posX = m_rand->Lerp(rand, -1969.4f, 1847.9f);
	rand = m_rand->GetRandDouble();
	float posZ = m_rand->Lerp(rand, -1157.0f, 874.5f);
	return { posX , 0.0f, posZ };
}
