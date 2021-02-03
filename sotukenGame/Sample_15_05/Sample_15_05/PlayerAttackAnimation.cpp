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
	//�U���A�j���[�V������
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
	//�G�Ƃ̓����蔻����Ƃ�O�ɁA�G�����邩�ǂ����𒲂ׂ�B
	QueryGOs<EnBase>("dragon", [&](EnBase * drBoar)->bool {
		drBoar->SetHit(false);
		return true;
	});
}
void PlayerAttackAnimation::NormalAttack()
{
	m_player->SetAttackAngleFlag(true);
	if (attackTimer >= m_continuousAttackTime) {
		//�U�����Ă��Ȃ��B
		m_player->SetMoveSpeed(Vector3::Zero);
		//�U���t���O��������B
		m_player->SetAttackFlag(false);
	}
	else {
		//�U�����Ă���B
		//�����Ă�������ɓ������B
		Vector3 moveSpeed = m_player->GetDir() * 5.0f;
		m_player->SetMoveSpeed(moveSpeed);
		//�U���t���O�𗧂Ă�B
		m_player->SetAttackFlag(true);


	}
	//�U���^�C�}�[�����Z�B
	attackTimer++;
	//X�{�^����Y�{�^���ŏ����U���A�j���[�V���������߂�B
	if (m_player->GetPressedAttackButton() == attackX) {
		m_player->SetAnimState(enAttack01_blad);
	}
	else if (m_player->GetPressedAttackButton() == attackY) {
		m_player->SetAnimState(enAttack06_blad);
	}
	//m_attackNum�~2�����Z�����ԍ��̃A�j���[�V�����𗬂��B
	int animState = m_player->GetAnimState();
	animState += m_attackNum * 2;
	m_player->SetAnimState(animState);
	if (attackTimer > m_totalAttackAnimationTime) {
		//�U���A�j���[�V�����I���B
		AttackEnd();
	}
}
void PlayerAttackAnimation::SpecialAttackStateBlad()
{
	if (m_player->GetSpecialAttackFlag() != true) {
		if (m_specialAttackStartFlag != true) {
			m_player->SetMoveSpeed(Vector3::Zero);
			//����U���̂͂��߂̃A�j���[�V�����𗬂��B
			m_player->SetAnimState(enSpecialAttack_01_blad);
			if (!m_player->GetPlayerSkinModelRemder().GetisAnimationPlaing()) {
				//�A�j���[�V�������I������B
				m_specialAttackStartFlag = true;
			}
		}
		else {
			if (g_pad[0]->IsPress(enButtonRB2)) {
				//�{�^���������B
				m_player->SetAnimState(enSpecialAttack_02_blad);
				//�ړ����Ȃ��B
				m_player->SetMoveSpeed(Vector3::Zero);
				//�^�C�}�[���Z�B
				m_accumulateTimer++;
				if (m_accumulateTimer >= m_accumulateTime) {
					//��莞�Ԃ��߂�ƒi�K�I�ɍU���͂ƈړ��������オ��B
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
				//�������B
				m_player->SetSpecialAttackFlag(true);
				//�U���͂ɔ{����������B
				m_baseAttackPow = m_player->GetmAtaackPow();
				float attackPower = m_baseAttackPow;
				attackPower *= m_magnification;
				m_player->SetAtaackPow(attackPower);
				//�^�C�}�[�Ƃ��߂鎞�Ԃ����Z�b�g�B
				m_accumulateTimer = 0;
				m_accumulateTime = 60;
			}
		}
		if (m_player->GetSP() <= 0.0f) {
			m_player->SetSpecialAttackFlag(true);
			//�U���͂ɔ{����������B
			m_baseAttackPow = m_player->GetmAtaackPow();
			float attackPower = m_baseAttackPow;
			attackPower *= m_magnification;
			m_player->SetAtaackPow(attackPower);
			//�^�C�}�[�Ƃ��߂鎞�Ԃ����Z�b�g�B
			m_accumulateTimer = 0;
			m_accumulateTime = 60;
		}
		//SP����B
		float sp = m_player->GetSP();
		sp -= 0.5f;
		m_player->SetSP(sp);
	}
	else {
		//�U�����[�V�����B
		m_player->SetAnimState(enSpecialAttack_03_blad);
		m_timer++;
		m_player->SetMoveSpeed(Vector3::Zero);
		if (m_timer > 10 && m_timer < 50) {
			Vector3 v = m_player->GetDir() * m_speed;
			m_player->SetMoveSpeed(v);
			m_speed -= 50.0f / 40.0f;
			if (m_speed <= 0.0f) {
				m_speed = 0.0f;
			}
		}
		if (!m_player->GetPlayerSkinModelRemder().GetisAnimationPlaing()) {
			AttackEnd();
		}
	}
}
void PlayerAttackAnimation::SpecialAttackStateSword()
{
	if (m_setPowerFlag != true) {
		//�U���͂�������B
		m_baseAttackPow = m_player->GetmAtaackPow();
		float attackPower = m_baseAttackPow;
		attackPower /= 10;
		m_player->SetAtaackPow(attackPower);
		m_setPowerFlag = true;
	}
	m_player->SetMoveSpeed(Vector3::Zero);
	if (g_pad[0]->IsPress(enButtonRB2)) {
		//SP����B
		float sp = m_player->GetSP();
		sp -= 0.5f;
		m_player->SetSP(sp);
		m_player->SetSpecialAttackFlag(true);
		if (m_specialAttackStartFlag != true) {
			//����U���̂͂��߂̃A�j���[�V�����𗬂��B
			m_player->SetAnimState(enSpecialAttack_01_sword);
			if (!m_player->GetPlayerSkinModelRemder().GetisAnimationPlaing()) {
				//�A�j���[�V�������I������B
				m_specialAttackStartFlag = true;
				//�A�j���[�V�����ݒ�B
				m_player->SetAnimState(enSpecialAttack_02_sword);
			}
		}//�{�^�����������Ă���Ԃ�2�̍U���A�j���[�V���������݂ɌJ��Ԃ��B
		else if (m_swordSpecialAttackAnim2Or3 != true) {
			//�t���O��false�Ȃ�
			m_player->SetAnimState(enSpecialAttack_02_sword);
			if (!m_player->GetPlayerSkinModelRemder().GetisAnimationPlaing()) {
				//�A�j���[�V�������I������B
				m_player->SetAnimState(enSpecialAttack_03_sword);
				m_swordSpecialAttackAnim2Or3 = true;
				//�G�̍U�������蔻�胊�Z�b�g�B
				MakeTheEnemyUnattacked();
			}
		}
		else if (m_swordSpecialAttackAnim2Or3 != false) {
			//�t���O��true�Ȃ�
			m_player->SetAnimState(enSpecialAttack_03_sword);
			if (!m_player->GetPlayerSkinModelRemder().GetisAnimationPlaing()) {
				//�A�j���[�V�������I������B
				m_player->SetAnimState(enSpecialAttack_02_sword);
				m_swordSpecialAttackAnim2Or3 = false;
				//�G�̍U�������蔻�胊�Z�b�g�B
				MakeTheEnemyUnattacked();
			}
		}
	}
	else {//�{�^���𗣂����B
		//�A�j���[�V�����ݒ�B
		m_player->SetAnimState(enSpecialAttack_04_sword);
		if (!m_player->GetPlayerSkinModelRemder().GetisAnimationPlaing()) {
			//�A�j���[�V�������I������B
			AttackEnd();
		}
	}
	if (m_player->GetSP() <= 0.0f) {
		//�A�j���[�V�����ݒ�B
		m_player->SetAnimState(enSpecialAttack_04_sword);
		if (!m_player->GetPlayerSkinModelRemder().GetisAnimationPlaing()) {
			//�A�j���[�V�������I������B
			AttackEnd();
		}
	}
}
void PlayerAttackAnimation::AttackFlag(int attackTime01_blad, int* attackAnimNum, int attackTime01_sword)
{
	m_player->SetAttackAnimationFlag(true);
	//m_attackAnimationFlag = true;
	if (attackTimer <= 0) {
		//�U���^�C����0�ȉ��B
		m_attackAnimationTimeNum = attackTime01_blad;
		if (m_player->GetWeaponState() == enSwordState) {
			//�\�[�h���
			m_attackAnimationTimeNum = attackTime01_sword;
		}
		//�^�C���ɍŏ��̍U�����Ԃ�����B
		m_totalAttackAnimationTime = m_attackAnimationTime[m_attackAnimationTimeNum];
		//�A���^�C���Ƀ^�C��������B
		m_continuousAttackTime = m_switchAttackTime[m_attackAnimationTimeNum];

		m_player->SetAttackFlag(true);
		//�t���O�𗧂ĂāA���̎��͍U�����ł�������ς����悤�ɂ���B
		m_player->SetAttackAngleFlag(false);
	}
	if (attackTimer >= m_continuousAttackTime && m_attackNum < *attackAnimNum) {
		//�A���^�C���ȍ~
		m_attackNum++;
		m_attackAnimationTimeNum++;
		//�U���A�j���[�V�����̍��v���ԂɎ��̍U���A�j���[�V�����̎��Ԃ����Z����B
		m_totalAttackAnimationTime = attackTimer + m_attackAnimationTime[m_attackAnimationTimeNum];
		m_continuousAttackTime = attackTimer + m_switchAttackTime[m_attackAnimationTimeNum];;
		//�t���O�𗧂ĂāA���̎��͍U�����ł�������ς����悤�ɂ���B
		m_player->SetAttackAngleFlag(false);
		//�G�̍U�������蔻�胊�Z�b�g�B
		MakeTheEnemyUnattacked();
	}
}
void PlayerAttackAnimation::AttackEnd()
{
	if (m_attackAnimationTimeNum == enAttackTime09_blad ||
		m_attackAnimationTimeNum == enAttackTime09_sword) {
		//����`�F���W�̍U���A�j���[�V�����������B
		//����̏�Ԃ�ύX����B
		if (m_player->GetWeaponState() == enBladState) {
			m_player->SetWeaponState(true);
		}
		else if (m_player->GetWeaponState() == enSwordState) {
			m_player->SetWeaponState(false);
		}
	}
	//����U���������ꍇ�A���낢�냊�Z�b�g����B
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
	//�U���A�j���[�V�����t���O��������B
	m_player->SetAttackAnimationFlag(false);
	m_player->SetAttackFlag(false);
	m_attackAnimationTimeNum = enAttackTime01_blad;
	attackTimer = 0;
	m_attackNum = 0;
	m_totalAttackAnimationTime = 0;
	m_player->SetPressedAttackButton(noAttack);
	m_player->SetAttackAngleFlag(false);
	//�G�̍U�������蔻�胊�Z�b�g�B
	MakeTheEnemyUnattacked();

}
void PlayerAttackAnimation::Attack()
{
	if (m_player->GetAttackState() == enBladState) {
		//�u���C�h��Ԃ̓���U���B
		SpecialAttackStateBlad();
	}
	else if (m_player->GetAttackState() == enSwordState) {
		//�\�[�h��Ԃ̓���U���B
		SpecialAttackStateSword();
	}
	else {
		//�ʏ�U���B
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