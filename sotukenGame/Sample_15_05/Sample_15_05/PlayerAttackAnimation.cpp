#include "stdafx.h"
#include "PlayerAttackAnimation.h"
#include "Player.h"
#include "PlayerAnimation.h"
#include "EnBase.h"

PlayerAttackAnimation::PlayerAttackAnimation()
{
}


PlayerAttackAnimation::~PlayerAttackAnimation()
{
}
void PlayerAttackAnimation::SetAttackAnimationTime()
{
	//攻撃アニメーションの
	m_attackAnimationTime[enAttackTime01_blad] = 120;
	m_attackAnimationTime[enAttackTime02_blad] = 100;
	m_attackAnimationTime[enAttackTime03_blad] = 120;
	m_attackAnimationTime[enAttackTime04_blad] = 100;
	m_attackAnimationTime[enAttackTime05_blad] = 106;
	m_attackAnimationTime[enAttackTime06_blad] = 100;
	m_attackAnimationTime[enAttackTime07_blad] = 100;
	m_attackAnimationTime[enAttackTime08_blad] = 130;
	m_attackAnimationTime[enAttackTime09_blad] = 110;
	m_attackAnimationTime[enAttackTime01_sword] = 80;
	m_attackAnimationTime[enAttackTime02_sword] = 80;
	m_attackAnimationTime[enAttackTime03_sword] = 90;
	m_attackAnimationTime[enAttackTime04_sword] = 90;
	m_attackAnimationTime[enAttackTime05_sword] = 90;
	m_attackAnimationTime[enAttackTime06_sword] = 90;
	m_attackAnimationTime[enAttackTime07_sword] = 80;
	m_attackAnimationTime[enAttackTime08_sword] = 110;
	m_attackAnimationTime[enAttackTime09_sword] = 150;

	m_switchAttackTime[enAttackTime01_blad] = 20;
	m_switchAttackTime[enAttackTime02_blad] = 30;
	m_switchAttackTime[enAttackTime03_blad] = 30;
	m_switchAttackTime[enAttackTime04_blad] = 30;
	m_switchAttackTime[enAttackTime05_blad] = 30;
	m_switchAttackTime[enAttackTime06_blad] = 30;
	m_switchAttackTime[enAttackTime07_blad] = 30;
	m_switchAttackTime[enAttackTime08_blad] = 30;
	m_switchAttackTime[enAttackTime09_blad] = 30;
	m_switchAttackTime[enAttackTime01_sword] = 20;
	m_switchAttackTime[enAttackTime02_sword] = 20;
	m_switchAttackTime[enAttackTime03_sword] = 30;
	m_switchAttackTime[enAttackTime04_sword] = 30;
	m_switchAttackTime[enAttackTime05_sword] = 30;
	m_switchAttackTime[enAttackTime06_sword] = 30;
	m_switchAttackTime[enAttackTime07_sword] = 20;
	m_switchAttackTime[enAttackTime08_sword] = 40;
	m_switchAttackTime[enAttackTime09_sword] = 30;
}
void PlayerAttackAnimation::MakeTheEnemyUnattacked()
{
	//敵との当たり判定をとる前に、敵がいるかどうかを調べる。
	QueryGOs<EnBase>("dragon", [&](EnBase * drBoar)->bool {
		drBoar->SetHit(false);
		return true;
	});
}
void PlayerAttackAnimation::NormalAttack()
{
	m_player->SetAttackAngleFlag(true);
	if (attackTimer >= m_continuousAttackTime) {
		//攻撃していない。
		m_player->SetMoveSpeed(Vector3::Zero);
		//攻撃フラグをさげる。
		m_player->SetAttackFlag(false);
	}
	else {
		//攻撃している。
		//向いている方向に動かす。
		Vector3 moveSpeed = m_player->GetDir() * 5.0f;
		m_player->SetMoveSpeed(moveSpeed);
		//攻撃フラグを立てる。
		m_player->SetAttackFlag(true);


	}
	//攻撃タイマーを加算。
	attackTimer++;
	//XボタンかYボタンで初期攻撃アニメーションを決める。
	if (m_player->GetPressedAttackButton() == attackX) {
		m_player->SetAnimState(enAttack01_blad);
	}
	else if (m_player->GetPressedAttackButton() == attackY) {
		m_player->SetAnimState(enAttack06_blad);
	}
	//m_attackNum×2を加算した番号のアニメーションを流す。
	int animState = m_player->GetAnimState();
	animState += m_attackNum * 2;
	m_player->SetAnimState(animState);
	if (attackTimer > m_totalAttackAnimationTime) {
		//攻撃アニメーション終了。
		AttackEnd();
	}
}
void PlayerAttackAnimation::SpecialAttackStateBlad()
{
	if (m_player->GetSpecialAttackFlag() != true) {
		if (m_specialAttackStartFlag != true) {
			m_player->SetMoveSpeed(Vector3::Zero);
			//特殊攻撃のはじめのアニメーションを流す。
			m_player->SetAnimState(enSpecialAttack_01_blad);
			if (!m_player->GetPlayerSkinModelRemder().GetisAnimationPlaing()) {
				//アニメーションが終わった。
				m_specialAttackStartFlag = true;
			}
		}
		else {
			if (g_pad[0]->IsPress(enButtonRB2)) {
				//ボタン長押し。
				m_player->SetAnimState(enSpecialAttack_02_blad);
				//移動しない。
				m_player->SetMoveSpeed(Vector3::Zero);
				//タイマー加算。
				m_accumulateTimer++;
				if (m_accumulateTimer >= m_accumulateTime) {
					//一定時間ためると段階的に攻撃力と移動距離が上がる。
					m_magnification++;
					m_accumulateTime += 60;
					m_speed += 30.0f;
					if (m_magnification >= 3) {
						m_magnification = 3;
						m_speed = 100.0f;
					}
				}
			}
			else {
				//離した。
				m_player->SetSpecialAttackFlag(true);
				//攻撃力に倍率をかける。
				m_baseAttackPow = m_player->GetmAtaackPow();
				float attackPower = m_baseAttackPow;
				attackPower *= m_magnification;
				m_player->SetAtaackPow(attackPower);
				//タイマーとためる時間をリセット。
				m_accumulateTimer = 0;
				m_accumulateTime = 60;
			}
		}
		if (m_player->GetSP() <= 0.0f) {
			m_player->SetSpecialAttackFlag(true);
			//攻撃力に倍率をかける。
			m_baseAttackPow = m_player->GetmAtaackPow();
			float attackPower = m_baseAttackPow;
			attackPower *= m_magnification;
			m_player->SetAtaackPow(attackPower);
			//タイマーとためる時間をリセット。
			m_accumulateTimer = 0;
			m_accumulateTime = 60;
		}
		//SP消費。
		float sp = m_player->GetSP();
		sp -= 0.5f;
		m_player->SetSP(sp);
	}
	else {
		//攻撃モーション。
		m_player->SetAnimState(enSpecialAttack_03_blad);
		m_timer++;
		m_player->SetMoveSpeed(Vector3::Zero);
		if (m_timer > 10 && m_timer < 50) {
			if (m_soundFlag != true) {
				m_player->Sound(L"Assets/sound/SE_PlayerSpecialAttack_Blad.wav");
				m_soundFlag = true;
			}
			Vector3 v = m_player->GetDir() * m_speed;
			m_player->SetMoveSpeed(v);
			m_speed -= 50.0f / 40.0f;
			if (m_speed <= 0.0f) {
				m_speed = 0.0f;
			}
		}
		if (!m_player->GetPlayerSkinModelRemder().GetisAnimationPlaing()) {
			AttackEnd();
			m_soundFlag = false;
		}
	}
}
void PlayerAttackAnimation::SpecialAttackStateSword()
{
	if (m_setPowerFlag != true) {
		//攻撃力をさげる。
		m_baseAttackPow = m_player->GetmAtaackPow();
		float attackPower = m_baseAttackPow;
		attackPower /= 10;
		m_player->SetAtaackPow(attackPower);
		m_setPowerFlag = true;
	}
	m_player->SetMoveSpeed(Vector3::Zero);
	if (g_pad[0]->IsPress(enButtonRB2)) {
		//SP消費。
		float sp = m_player->GetSP();
		sp -= 0.5f;
		m_player->SetSP(sp);
		m_player->SetSpecialAttackFlag(true);
		if (m_specialAttackStartFlag != true) {
			if (m_soundFlag != true) {
				m_player->Sound(L"Assets/sound/SE_PlayerSpecialAttack_Sword.wav");
				m_soundFlag = true;
			}
			//特殊攻撃のはじめのアニメーションを流す。
			m_player->SetAnimState(enSpecialAttack_01_sword);
			if (!m_player->GetPlayerSkinModelRemder().GetisAnimationPlaing()) {
				//アニメーションが終わった。
				m_specialAttackStartFlag = true;

				m_soundFlag = false;

				//アニメーション設定。
				m_player->SetAnimState(enSpecialAttack_02_sword);
			}
		}//ボタン長押ししている間は2つの攻撃アニメーションを交互に繰り返す。
		else if (m_swordSpecialAttackAnim2Or3 != true) {
			if (m_soundFlag != true) {
				m_player->Sound(L"Assets/sound/SE_PlayerSpecialAttack_Sword.wav");
				m_soundFlag = true;
			}
			//フラグがfalseなら
			m_player->SetAnimState(enSpecialAttack_02_sword);
			if (!m_player->GetPlayerSkinModelRemder().GetisAnimationPlaing()) {
				//アニメーションが終わった。
				m_player->SetAnimState(enSpecialAttack_03_sword);

				m_soundFlag = false;

				m_swordSpecialAttackAnim2Or3 = true;
				//敵の攻撃当たり判定リセット。
				MakeTheEnemyUnattacked();
			}
		}
		else if (m_swordSpecialAttackAnim2Or3 != false) {
			if (m_soundFlag != true) {
				m_player->Sound(L"Assets/sound/SE_PlayerSpecialAttack_Sword.wav");
				m_soundFlag = true;
			}
			//フラグがtrueなら
			m_player->SetAnimState(enSpecialAttack_03_sword);
			if (!m_player->GetPlayerSkinModelRemder().GetisAnimationPlaing()) {
				//アニメーションが終わった。
				m_player->SetAnimState(enSpecialAttack_02_sword);

				m_soundFlag = false;

				m_swordSpecialAttackAnim2Or3 = false;
				//敵の攻撃当たり判定リセット。
				MakeTheEnemyUnattacked();
			}
		}
	}
	else {//ボタンを離した。
		//アニメーション設定。
		m_player->SetAnimState(enSpecialAttack_04_sword);
		if (!m_player->GetPlayerSkinModelRemder().GetisAnimationPlaing()) {
			//アニメーションが終わった。
			AttackEnd();
		}
	}
	if (m_player->GetSP() <= 0.0f) {
		//アニメーション設定。
		m_player->SetAnimState(enSpecialAttack_04_sword);
		if (!m_player->GetPlayerSkinModelRemder().GetisAnimationPlaing()) {
			//アニメーションが終わった。
			AttackEnd();
		}
	}
}
void PlayerAttackAnimation::AttackFlag(int attackTime01_blad, int* attackAnimNum, int attackTime01_sword)
{
	m_player->SetAttackAnimationFlag(true);

	//if (m_player->GetAttackFlag() != true) {
	//	m_soundFlag = false;
	//}
	//if (m_player->GetWeaponState() == enBladState && m_soundFlag != true) {
	//	m_player->Sound(L"Assets/sound/SE_PlayerAttack_Blad.wav");
	//	m_soundFlag = true;
	//}
	//else if (m_player->GetWeaponState() == enSwordState && m_soundFlag != true) {
	//	//ソード状態
	//	m_player->Sound(L"Assets/sound/SE_PlayerAttack_Sword.wav");
	//	m_soundFlag = true;
	//}

	//m_attackAnimationFlag = true;
	if (attackTimer <= 0) {
		//攻撃タイムが0以下。
		m_attackAnimationTimeNum = attackTime01_blad;
		if (m_player->GetWeaponState() == enSwordState) {
			//ソード状態
			m_attackAnimationTimeNum = attackTime01_sword;
		}
		//タイムに最初の攻撃時間を入れる。
		m_totalAttackAnimationTime = m_attackAnimationTime[m_attackAnimationTimeNum];
		//連撃タイムにタイムを入れる。
		m_continuousAttackTime = m_switchAttackTime[m_attackAnimationTimeNum];

		m_player->SetAttackFlag(true);
		//フラグを立てて、この時は攻撃中でも方向を変えれるようにする。
		m_player->SetAttackAngleFlag(false);
	}
	if (attackTimer >= m_continuousAttackTime && m_attackNum < *attackAnimNum) {
		//連撃タイム以降
		m_attackNum++;
		m_attackAnimationTimeNum++;
		//攻撃アニメーションの合計時間に次の攻撃アニメーションの時間を加算する。
		m_totalAttackAnimationTime = attackTimer + m_attackAnimationTime[m_attackAnimationTimeNum];
		m_continuousAttackTime = attackTimer + m_switchAttackTime[m_attackAnimationTimeNum];;
		//フラグを立てて、この時は攻撃中でも方向を変えれるようにする。
		m_player->SetAttackAngleFlag(false);
		//敵の攻撃当たり判定リセット。
		MakeTheEnemyUnattacked();

		m_soundFlag = false;
	}
}
void PlayerAttackAnimation::AttackEnd()
{
	if (m_attackAnimationTimeNum == enAttackTime09_blad ||
		m_attackAnimationTimeNum == enAttackTime09_sword) {
		//武器チェンジの攻撃アニメーションだった。
		//武器の状態を変更する。
		if (m_player->GetWeaponState() == enBladState) {
			m_player->SetWeaponState(true);
		}
		else if (m_player->GetWeaponState() == enSwordState) {
			m_player->SetWeaponState(false);
		}
	}
	//特殊攻撃だった場合、いろいろリセットする。
	if (m_player->GetAttackState() == enBladState) {
		m_player->SetSpecialAttackFlag(false);
		m_player->SetAttackState(enNormalState);
		m_specialAttackStartFlag = false;
		m_speed = 50.0f;
		m_timer = 0;
		m_player->SetAtaackPow(m_baseAttackPow);
		m_magnification = 1;
	}
	else if (m_player->GetAttackState() == enSwordState) {
		m_swordSpecialAttackAnim2Or3 = false;
		m_player->SetSpecialAttackFlag(false);
		m_player->SetAttackState(enNormalState);
		m_specialAttackStartFlag = false;
		m_player->SetAtaackPow(m_baseAttackPow);
		m_setPowerFlag = false;
	}
	//攻撃アニメーションフラグをさげる。
	m_player->SetAttackAnimationFlag(false);
	m_player->SetAttackFlag(false);
	m_attackAnimationTimeNum = enAttackTime01_blad;
	attackTimer = 0;
	m_attackNum = 0;
	m_totalAttackAnimationTime = 0;
	m_player->SetPressedAttackButton(noAttack);
	m_player->SetAttackAngleFlag(false);
	//敵の攻撃当たり判定リセット。
	MakeTheEnemyUnattacked();

	m_soundFlag = false;

}
void PlayerAttackAnimation::Attack()
{
	if (m_player->GetAttackState() == enBladState) {
		//ブレイド状態の特殊攻撃。
		SpecialAttackStateBlad();
	}
	else if (m_player->GetAttackState() == enSwordState) {
		//ソード状態の特殊攻撃。
		SpecialAttackStateSword();
	}
	else {
		//通常攻撃。
		NormalAttack();
	}
}
bool PlayerAttackAnimation::Start()
{
	SetAttackAnimationTime();
	m_player = FindGO<Player>("player");
	m_playerAnim = FindGO<PlayerAnimation>("playerAnim");
	return true;
}

void PlayerAttackAnimation::Update()
{

}