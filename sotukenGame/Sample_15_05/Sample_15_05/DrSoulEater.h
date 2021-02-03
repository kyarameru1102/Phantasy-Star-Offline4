#pragma once
#include "Physics/Character/CharacterController.h"
#include "SoulEaterAnimation.h"
#include "EnBase.h"
#include "Physics/GhostObject.h"

/// <summary>
/// �h���S���\�E���C�[�^�[�N���X
/// </summary>
class DrSoulEater : public EnBase
{
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	DrSoulEater();
	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	~DrSoulEater();
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
	/// �K���U���֐�
	/// </summary>
	void TailAttack();
	/// <summary>
	/// �Ή��e�U���֐��B
	/// </summary>
	void FireballShoot();
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
		TailAttack_state,
		FireballShoot_state,
		GetDamage_state,
		Die_state
	};

	int					m_status = Idle_state;			//��ԁB
	int					changeTimer = 0;				//�A�j���[�V�����ύX�^�C�}�[�B
	float				m_speedY = 0.0f;				//Y�����̃X�s�[�h�B
	int					m_animState = SoulEaterAnimInfo::enSo_Idle;			//�A�j���[�V�����̏�ԁB
	int					m_appearcolor = 0;				//�z�FNo
	SoulEaterAnimation* m_souleAnim = nullptr;           //�A�j���[�V�����̃��[�h�B
	std::vector<int>	soulcolor = { 1,2,3,4 };		//�z�F����B
	bool				m_isAttack = false;				//�U�����Ă��邩�B

	bool				m_ATKoff = false;				//���̍U���Ń_���[�W����񂾂�����邽�߂̃t���O�B
	int					m_count = 0;					//�U��������܂ł̃J�E���g�B
	bool                m_screamflag = true;            //���K�t���O
	bool                m_isATK = true;                 //���݂��U��������t���O
	bool                m_isTailATK = false;            //�܍U��������t���O
	bool                m_isFireBallATK = false;           //�Ή��U��������t���O
	GhostObject			m_ghostObj;						//�S�[�X�g�B
	int					m_deathCount = 0;				//���񂾂Ƃ��̃J�E���g�B
};

