#pragma once
#include "Physics/Character/CharacterController.h"
#include "TerrorBringerAnimation.h"
#include "EnBase.h"
#include "Physics/GhostObject.h"

/// <summary>
/// �h���S���e���[�u�����K�[�N���X
/// </summary>
class DrTerrorBringer : public EnBase
{
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	DrTerrorBringer();
	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	~DrTerrorBringer();
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
	/// ��s�U���֐�
	/// </summary>
	void FlyAttack();
	/// <summary>
	/// �܍U���֐�
	/// </summary>
	void WingClawAttack();
	/// <summary>
	/// �Ή��U��
	/// </summary>
	void FlameAttack();
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
		Fly_state,
		FlyMove_state,
		FlyLand_state,
		Scream_state,
		Attack_state,
		FlyAttack_state,
		WingClawAttack_state,
		FlameAttack_state,
		GetDamage_state,
		Die_state
	};

	int					m_status = Idle_state;			//��ԁB
	int					changeTimer = 0;				//�A�j���[�V�����ύX�^�C�}�[�B
	float				m_speedY = 0.0f;				//Y�����̃X�s�[�h�B
	int					m_animState = TerrorBringerAnimInfo::enTe_Idle01;			//�A�j���[�V�����̏�ԁB
	int					m_appearcolor = 0;				//�z�FNo
	TerrorBringerAnimation* m_terrorbAnim = nullptr;    //�A�j���[�V�����̃��[�h�B
	std::vector<int>	terrorcolor = { 1,2,3,4 };		//�z�F����B
	bool				m_isAttack = false;				//�U�����Ă��邩�B
	bool				m_ATKoff = false;				//���̍U���Ń_���[�W����񂾂�����邽�߂̃t���O�B
	int					m_count = 0;					//�U��������܂ł̃J�E���g�B
	bool                m_screamflag = true;            //���K�t���O
	bool                m_isFangATK = true;             //���݂��U��������t���O
	bool                m_isClawATK = false;            //�܍U��������t���O
	bool                m_isFlameATK = false;           //�Ή��U��������t���O
	bool                m_FlyFlag = false;              //��s�t���O
	bool                m_SetFly = false;               //��s�ݒ�
	bool                m_LandFlag = false;             //�����t���O
	int                 m_FangATKCount = 0;             //���݂��U���̃J�E���g
	int                 m_ClawATKCont = 0;              //�܍U���̃J�E���g
	int                 m_FlameATKCount = 0;            //�Ή��U���̃J�E���g
	bool                m_ATKOne = true;                //�p�^�[���P
	bool                m_ATKTwe = false;               //�p�^�[���Q
	bool                m_TweStart = false;             //�p�^�[���Q�X�^�[�g
	GhostObject			m_ghostObj;						//�S�[�X�g�B
	int					m_deathCount = 0;				//���񂾂Ƃ��̃J�E���g�B
};

