#pragma once
#include "IStage.h"

/// <summary>
/// �X�e�[�W2�B
/// </summary>

class DrUsurper;
class Game;
class Stage2 : public IStage
{
public:
	Stage2();
	~Stage2();

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
	int ENEMY_NUM = 2;		//�G�l�~�[�̐��B
	//enum {
	//	ENEMY_NUM = 2		//�G�l�~�[�̐��B
	//};
	//
	//DrUsurper* m_drUsurper[ENEMY_NUM] = { nullptr }; 
};

