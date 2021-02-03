#pragma once
#include "IStage.h"

/// <summary>
/// �X�e�[�W1�N���X
/// </summary>
class RecoveryItem;
class DrBoar;
class DrTerrorBringer;
class Game;
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
	int ENEMY_NUM = 3;		//�G�l�~�[�̐��B
	//enum {
	//	ENEMY_NUM = 3		//�G�l�~�[�̐��B
	//};
	//DrBoar* m_drBoar[ENEMY_NUM] = { nullptr };		//�h���S���{�A(�G)�̃C���X�^���X�B
	RecoveryItem* m_recoveryItem = nullptr;			//�񕜃A�C�e���̃C���X�^���X�B
};

