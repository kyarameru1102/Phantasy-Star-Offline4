#include "stdafx.h"
#include "IStage.h"
#include "Player.h"
#include "Random.h"
void IStage::GhostContactCharaCon()
{
	QueryGOs<Player>("player", [&](Player* player)->bool {
		//プレイヤーのキャラコンを取得。
		CharacterController& charaCon = *player->GetCharacterController();
		g_physics.ContactTestCharaCon(charaCon, [&](const btCollisionObject& collisionObject) {
			if (m_ghostObject.IsSelf(collisionObject) == true) {
				//当たったらステージを切り替える。
				m_sceanChangeOK = true;
			}
			});
		return true;
		});
}
Vector3 IStage::InitEnemyPos()
{
	//Randomクラスを検索。
	m_rand = FindGO<Random>("rnad");
	//敵のX座標とZ座標を範囲内でランダムで決める。
	float rand = m_rand->GetRandDouble();
	float posX = m_rand->Lerp(rand, -1969.4f, 1847.9f);
	rand = m_rand->GetRandDouble();
	float posZ = m_rand->Lerp(rand, -1157.0f, 874.5f);
	return { posX , 0.0f, posZ };
}
