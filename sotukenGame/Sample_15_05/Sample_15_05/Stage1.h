#pragma once
#include "IStage.h"
/// <summary>
/// �X�e�[�W1�N���X
/// </summary>
class RecoveryItem;
class Stage1 : public IStage
{
public:
	Stage1();
	~Stage1();

	/// <summary>
	/// �X�V�֐����Ă΂��O�ɌĂ΂��J�n�֐��B
	/// </summary>
	/// <returns>true��Ԃ��ƈ�x�����Ă΂��</returns>
	bool Start()override;

	/// <summary>
	/// �X�V�֐��B
	/// </summary>
	void Update()override;
private:
	RecoveryItem* m_recoveryItem = nullptr;			//�񕜃A�C�e���̃C���X�^���X�B
};

