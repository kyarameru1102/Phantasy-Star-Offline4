#pragma once
#include "Physics/Character/CharacterController.h"
#include "NightmareAnimation.h"
#include "EnBase.h"
#include "Physics/GhostObject.h"
/// <summary>
/// �h���S���i�C�g���A�N���X
/// </summary>
class DrNightmare : public EnBase
{
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	DrNightmare();
	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	~DrNightmare();
	/// <summary>
	/// �X�^�[�g�֐��B
	/// </summary>
	/// <returns></returns>
	bool Start();
	/// <summary>
	/// �X�V�֐��B
	/// </summary>
	/// <returns></returns>
	void Update();

	/// <summary>
	/// �v���C���[�Ɍ������Ă����֐��B
	/// </summary>
	void Move();
	/// <summary>
	/// �v���C���[�̕����ɑ̂�������֐��B
	/// </summary>
	void Turn();
	/// <summary>
	/// ���K�֐�
	/// </summary>
	void Scream();
	/// <summary>
	/// �U���֐��B
	/// </summary>
	void Attack();
	/// <summary>
	/// �܍U���֐��B
	/// </summary>
	void ClawAttack();
	/// <summary>
	/// �p�U��
	/// </summary>
	void HornAttack();
	/// <summary>
	/// ���B
	/// </summary>
	void Die();

	void ReceiveDamage(int damage) override
	{
		m_hp -= damage;
		m_status = GetDamage_state;
	}

	const int& GetDeathCount()const
	{
		return m_deathCount;
	}
private:
	/// <summary>
	/// �G�l�~�[�̃X�e�[�g�B
	/// </summary>
	enum {
		Idle_state,
		Walk_state,
		Run_state,
		Scream_state,
		Attack_state,
		ClawAttack_state,
		HornAttack_state,
		ClowAttack_state,
		GetDamage_state,
		Die_state
	};
	int					m_status = Idle_state;			//��ԁB
	int					changeTimer = 0;				//�A�j���[�V�����ύX�^�C�}�[�B
	float				m_speedY = 0.0f;				//Y�����̃X�s�[�h�B
	int					m_animState = NightmAnimInfo::enNi_Idle01;			//�A�j���[�V�����̏�ԁB
	int					m_appearcolor = 0;				//�z�FNo
	NightmareAnimation* m_nightmAnim = nullptr;           //�A�j���[�V�����̃��[�h�B
	std::vector<int>	nightcolor = { 1,2,3,4 };		//�z�F����B
	bool				m_isAttack = false;				//�U�����Ă��邩�B
	bool				m_ATKoff = false;				//���̍U���Ń_���[�W����񂾂�����邽�߂̃t���O�B
	bool                m_isBasicATK = true;            //���݂��U���̔���
	bool                m_isClawATK = false;            //�܍U���̔���
	bool                m_isHornATK = false;            //�p�U��
	int                 m_isATKcount = 0;               //�U�������񐔂̃J�E���g
	int					m_count = 0;					//�U��������܂ł̃J�E���g�B
	bool                m_screamflag = true;            //���K�t���O
	GhostObject			m_ghostObj;						//�S�[�X�g�B
	int					m_deathCount = 0;				//���񂾂Ƃ��̃J�E���g�B
	

};

