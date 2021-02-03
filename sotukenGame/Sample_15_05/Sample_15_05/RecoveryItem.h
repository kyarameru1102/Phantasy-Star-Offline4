#pragma once
#include "Physics/GhostObject.h"

/// <summary>
/// �v���C���[��HP���񕜂���A�C�e���N���X�B
/// </summary>
class RecoveryItem : public IGameObject
{
public:
	RecoveryItem();
	~RecoveryItem();

	/// <summary>
	/// �X�V�֐����Ă΂��O�ɌĂ΂��J�n�֐��B
	/// </summary>
	/// <returns>true��Ԃ��ƈ�x�����Ă΂��</returns>
	bool Start()override;

	/// <summary>
	/// �X�V�֐��B
	/// </summary>
	void Update()override;

	/// <summary>
	/// �񕜃A�C�e���̍��W��ݒ�B
	/// </summary>
	/// <param name="pos">�ݒ肷����W</param>
	void SetPosition(const Vector3& pos)
	{
		m_position = pos;
	}

	/// <summary>
	/// �񕜃A�C�e���̍��W��Ԃ��B
	/// </summary>
	/// <returns>�񕜃A�C�e���̍��W</returns>
	const Vector3& GetPosition() const
	{
		return m_position;
	}

	/// <summary>
	/// �v���C���[��HP���񕜂���֐��B
	/// </summary>
	void RecoveryPlayerHP();

private:
	SkinModelRender* m_recoveryItemModel = nullptr;		//�X�L�����f���B
	Vector3 m_position = Vector3::Zero;					//���W�B
	Quaternion m_rotation = Quaternion::Identity;		//��]�B
	Vector3 m_scale = Vector3::One;						//�g�嗦�B

	GhostObject m_ghostObject;							//�S�[�X�g�I�u�W�F�N�g�B
	Vector3 m_ghostScale = { 50.0f, 50.0f, 50.0f };		//�S�[�X�g�I�u�W�F�N�g�̊g�嗦�B
};

