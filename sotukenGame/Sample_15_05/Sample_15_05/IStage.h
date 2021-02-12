#pragma once
#include "GameObject.h"
#include "EnBase.h"
#include "Game.h" 
enum {
	StageNumber,
	enStageNum1,
	enStageNum2,
	enStageNum3
};
class Random;
class Game;
class BackGround;
class EnBase;
class IStage : public IGameObject
{
public:
	/// <summary>
	/// �X�V�֐����Ă΂��O�ɌĂ΂��J�n�֐��B
	/// </summary>
	/// <returns>true��Ԃ��ƈ�x�����Ă΂��</returns>
	virtual bool Start()override { return 0; };

	/// <summary>
	/// �X�V�֐��B
	/// </summary>
	virtual void Update()override {};

	/// <summary>
	/// �V�[����؂�ւ���B
	/// </summary>
	/// <returns>�V�[���؂�ւ��̃t���O</returns>
	bool GetsceanChangeOK() const
	{
		return m_sceanChangeOK;
	}

protected:
	/// <summary>
	/// DrBoar�𐶐��B
	/// ���̊֐��̑O��m_drBoarNum��ݒ肷�邱�ƂŐ���ݒ�ł���B
	/// </summary>
	/// <param name="stageNum"></param>
	/// <param name="enemyPower"></param>
	void PutOutDrBoar(int enemyPower = en1);
	/// <summary>
	/// DrTerrorBringer�𐶐��B
	/// ���̊֐��̑O��m_drTerrorBringerNum��ݒ肷�邱�ƂŐ���ݒ�ł���B
	/// </summary>
	/// <param name="stageNum"></param>
	/// <param name="enemyPower"></param>
	void PutOutDrTerrorBringer(int enemyPower = en1);
	/// <summary>
	/// DrNightmare�𐶐��B
	/// ���̊֐��̑O��m_drNightmareNum��ݒ肷�邱�ƂŐ���ݒ�ł���B
	/// </summary>
	/// <param name="stageNum"></param>
	/// <param name="enemyPower"></param>
	void PutOutDrNightmare(int enemyPower = en1);
	/// <summary>
	/// DrSoulEater�𐶐��B
	/// ���̊֐��̑O��m_drSoulEaterNum��ݒ肷�邱�ƂŐ���ݒ�ł���B
	/// </summary>
	/// <param name="stageNum"></param>
	/// <param name="enemyPower"></param>
	void PutOutDrSoulEater(int enemyPower = en1);
	/// <summary>
	/// DrUsurper�𐶐��B
	/// ���̊֐��̑O��m_drUsurperNum��ݒ肷�邱�ƂŐ���ݒ�ł���B
	/// </summary>
	/// <param name="stageNum"></param>
	/// <param name="enemyPower"></param>
	void PutOutDrUsurper(int enemyPower = en1);
	/// <summary>
	/// �G���o���֐��B
	/// </summary>
	template<class T>
	void MakeEnemesAppear(int enemyNum, int enemyPower)
	{
		if (enemyNum <= 0) {
			//��������G�̐���0�ȉ��ɂȂ�Ȃ��悤�ɂ���B
			enemyNum = 1;
		}
		for (int i = 0; i < enemyNum; i++) {
			//�G��NewGO����B
			EnBase* drB = NewGO<T>(0, "dragon");
			//���W�ݒ�B
			drB->SetPosition(InitEnemyPos());
			//������ݒ�B
			drB->SetBasicStatusNum(enemyPower);
			//�U���͂̔{����ݒ�B
			float mag = m_game->GetStage3ClearCount() * MAG_AP_INCREASE + 1.0f;
			drB->SetMagnificationAP(mag);
			//HP�̔{����ݒ�B
			drB->SetMagnificationHP(mag);
			//�ǂ�Stage�ɂ��邩��ݒ�B
			drB->SetStageNumber(m_stageNum);
			//�G�̐������Z�B
			ENEMY_NUM++;
			//���X�g�ɓ����B
			m_enemyList.push_back(drB);
		}
	}
	/// <summary>
	/// �G�̏������W
	/// </summary>
	/// <returns></returns>
	Vector3 InitEnemyPos();
protected:
	BackGround* m_backGround = nullptr;		//�X�e�[�W�̃C���X�^���X�B
	std::vector<EnBase*> m_enemyList;       //�G�̉ϒ��z��B
	int m_downEnemy = 0;	//�|�����G�l�~�[�̐��B
	int m_timer = 0;		//�^�C�}�[�B
	const int m_stageChangeTime = 50; //�X�e�[�W�ύX�܂ł̎���
	bool m_sceanChangeOK = false;	//�V�[����؂�ւ��Ă������ǂ����̃t���O�B

	Random* m_rand = nullptr;
	Game* m_game = nullptr;
	const float MAG_AP_INCREASE = 0.2f;//�U���͂̔{���̑����ʁB

	int m_stageNum = 0;
	int ENEMY_NUM = 0;		//�G�l�~�[�̐��B
	int m_drBoarNum = 2;//DrBoar�̐��B
	int m_drTerrorBringerNum = 1;//DrTerrorBringer�̐��B
	int m_drNightmareNum = 2;//DrNightmare�̐��B
	int m_drSoulEaterNum = 1;//DrSoulEater�̐��B
	int m_drUsurperNum = 1;//DrUsurper�̐��B
};

