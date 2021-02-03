#pragma once
#include "Physics/Character/CharacterController.h"

/// <summary>
/// �G���N���X
/// </summary>
class Player;
class EnBase : public IGameObject
{
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	EnBase();
	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	~EnBase();
	/// <summary>
	/// ���W��Ԃ��B
	/// </summary>
	/// <returns></returns>
	const Vector3& GetPosition() const
	{
		return m_position;
	}
	/// <summary>
	/// HP��Ԃ��B
	/// </summary>
	/// <returns></returns>
	const float& GetHP() const
	{
		return m_hp;
	}
	/// <summary>
	/// �U�����󂯂����̔����Ԃ��B
	/// </summary>
	/// <returns></returns>
	const bool& GetHit() const
	{
		return m_gethit;
	}
	/// <summary>
	/// �U�����󂯂���؂�ւ���B
	/// </summary>
	/// <returns></returns>
	void SetHit(bool sethit)
	{
		m_gethit = sethit;
	}

	/// <summary>
	/// �_���[�W���󂯂�HP�����炷�֐��B
	/// </summary>
	/// <param name="damage">int �_���[�W��</param>
	virtual void ReceiveDamage(int damage)
	{
		m_hp -= damage;
	}
	/// <summary>
	/// HP��^����֐��B
	/// ��ɉ񕜓��Ŏg���B
	/// </summary>
	/// <param name="hp">int �񕜗�</param>
	void ReceiveHP(float hp)
	{
		m_hp += hp;
	}

	/// <summary>
	/// �L�����R����Ԃ��B
	/// </summary>
	CharacterController* GetCharaCon()
	{
		return &m_charaCon;
	}
	/// <summary>
	/// ���W��ݒ�
	/// </summary>
	/// <param name="pos"></param>
	void SetPosition(Vector3 pos)
	{
		m_position = pos;
	}
	/// <summary>
	/// �g�嗦��ݒ�
	/// </summary>
	/// <param name="scale"></param>
	void SetScale(Vector3 scale)
	{
		m_scale = scale;
	}
	/// <summary>
	/// HP��ݒ�
	/// </summary>
	/// <param name="hp"></param>
	void SetHp(float hp)
	{
		m_hp = hp;
	}
	bool GetDeath()const
	{
		return m_death;
	}
	Vector3 GetDirection()const
	{
		return m_dir;
	}
	/// <summary>
	/// �U���͂�ݒ肷��B
	/// </summary>
	/// <param name="attackpow"></param>
	void SetAttackPower(const float attackpow)
	{
		m_attackPower = attackpow;
	}
	/// <summary>
	/// �U���͂�Ԃ��B
	/// </summary>
	/// <returns></returns>
	const float GetAttackPower() const
	{
		return m_attackPower;
	}
	/// <summary>
	/// �U���͂̔{����ݒ�B
	/// </summary>
	/// <param name="agnificationAP"></param>
	void SetMagnificationAP(const float magnificationAP)
	{
		m_magnificationAP = magnificationAP;
	}
	/// <summary>
	/// �U���͂̔{����Ԃ��B
	/// </summary>
	/// <returns></returns>
	const float GetMagnificationAP() const
	{
		return m_magnificationAP;
	}
	/// <summary>
	/// HP�̔{����ݒ�B
	/// </summary>
	/// <param name="magnificationHP"></param>
	void SetMagnificationHP(const float magnificationHP)
	{
		m_magnificationHP = magnificationHP;
	}
	/// <summary>
	/// HP�̔{����Ԃ��B
	/// </summary>
	/// <returns></returns>
	const float GetMagnificationHP() const
	{
		return m_magnificationHP;
	}
protected:
	SkinModelRender*	m_skinModelRender = nullptr;			//�X�L�����f��
	Vector3				m_position = Vector3::Zero;				//���W
	Vector3				m_scale = Vector3::One;					//�g�嗦
	Quaternion			m_rotation = Quaternion::Identity;		//��]
	Vector3				m_movespeed = Vector3::Zero;			//�ړ����x
	CharacterController m_charaCon;								//�L�����R���B
	float				m_hp = 50.0f;						//HP
	float               m_magnificationHP = 1.0f;               //HP�̔{���B
	Player*				m_player = nullptr;						//�v���C���[�B
	Vector3				m_toPlayer = Vector3::Zero;				//�v���C���[�܂ł̃x�N�g���B
	bool				m_death = false;
	bool                m_gethit = false;                       //�v���C���[����̍U������
	Vector3				m_dir, m_ghostPos;
	float               m_attackPower = 0.0f;                   //�U���́BStart�֐��ŏ���������B
	float               m_magnificationAP = 1.0f;               //�U���͂̔{���B
};


