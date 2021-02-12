#pragma once
#include "FontNumber.h"

class Fade;
class Result : public IGameObject
{	
public:
	/// <summary>
	/// �R���X�g���N�^�B
	/// </summary>
	Result();
	/// <summary>
	/// �f�X�g���N�^�B
	/// </summary>
	~Result();
	/// <summary>
	/// �J�n�֐��B
	/// </summary>
	bool Start()override;
	/// <summary>
	/// �X�V�֐��B
	/// </summary>
	void Update()override;
private:
	//��ԁB
	enum ResultState {
		Result_BackGround_Fade,			//�Q�[����ʂ������Â�����B
		Result_BattleResult,			//�퓬����Sprite�̕\���B
		Result_ScoreBoard,				//�X�R�A�{�[�h�̕\���B
		Result_ClearTime_Score,			//�N���A�^�C���̃X�R�A�\���B
		Result_ClearFloor_Score,		//�˔j�K�w�̃X�R�A�\���B
		Result_LastLevel_Score,			//�ŏI���x���̃X�R�A�\���B
		Result_DefaultBoss_Score,		//���j�{�X�̃X�R�A�\���B
		Result_Total_Score,				//�g�[�^���X�R�A�\���B
		Result_Total_ScoreCal,			//�g�[�^���X�R�A�\���v�Z�B	
		Result_Rank,					//�X�R�A���ʂɂ���ă����N�̕\������B
		Result_Player,					//�����N�ɂ���ăv���C���[�C���X�g��ύX���ĕ\������B
		Result_Next						//���̏����B
	};

private:
	void SpriteMove(SpriteRender* m_sprite);		//�X�v���C�g�̉��~�ړ������B
	void SpriteIndicate(SpriteRender* m_sprite);	//�X�v���C�g�̕\�������B
	void SpriteScaleUp(SpriteRender* m_sprite);		//�X�v���C�g�̊g��\�������B

	void BackGroundFade();		//�Q�[����ʂ������Â�����B
	void BattleResult();		//�퓬����Sprite�̕\���B
	void ScoreBoard();			//�X�R�A�{�[�h�̕\���B
	void ClearTimeScore();		//�N���A�^�C���̃X�R�A�\���B
	void ClearTimeScoreCal();	//�N���A�^�C���̃X�R�A�v�Z�B
	void ClearFloorScore();		//�˔j�K�w�̃X�R�A�\���B
	void ClearFloorScoreCal();	//�˔j�K�w�̃X�R�A�v�Z�B
	void LastLevelScore();		//�ŏI���x���̃X�R�A�\���B
	void LastLevelScoreCal();	//�ŏI���x���̃X�R�A�v�Z�B
	void DefaultBossScore();	//���j�{�X�̃X�R�A�\���B
	void DefaultBossScoreCal();	//���j�{�X�̃X�R�A�v�Z�B
	void TotalScore();			//�g�[�^���X�R�A�\���B	
	void TotalScoreCal();		//�g�[�^���X�R�A�v�Z�B	
	void RankSet();				//�X�R�A���ʂɂ���ă����N�̕\������B
	void PlayerSet();			//�����N�ɂ���ăv���C���[�C���X�g��ύX���ĕ\������B
	void Next();				//���̏����B

private:
	const enum {
		Result_BackGround,		//�w�i�p�e�N�X�`���B
		Result_Board,			//�o�g�����U���g�����{�[�h�B
		Result_ScoreBoardFrame,	//�X�R�A�{�[�h�B
		Result_RankSprite,		//�����N�����B
		Result_Num				//���U���g��Sprite���B
	};

	//���������B
	//�o�g�����U���g
	const enum BattleResult{
		Result_BattleResult_B,			//�o�g�����U���g B
		Result_BattleResult_a,			//�o�g�����U���g a
		Result_BattleResult_t,			//�o�g�����U���g t
		Result_BattleResult_t2,			//�o�g�����U���g t2
		Result_BattleResult_l,			//�o�g�����U���g l
		Result_BattleResult_e,			//�o�g�����U���g e
		Result_BattleResult_R,			//�o�g�����U���g R
		Result_BattleResult_e2,			//�o�g�����U���g e
		Result_BattleResult_s,			//�o�g�����U���g s
		Result_BattleResult_u,			//�o�g�����U���g u
		Result_BattleResult_l2,			//�o�g�����U���g l2
		Result_BattleResult_t3,			//�o�g�����U���g t3
		Result_BattleResult_Num			//�o�g�����U���g��Sprite���B

	};
	//�^�C���B
	const enum TimeScore {
		Result_TimeScore_Icon,		//�^�C���A�C�R��
		Result_TimeScore_T,			//�^�C�� T
		Result_TimeScore_i,			//�^�C�� i
		Result_TimeScore_m,			//�^�C�� m
		Result_TimeScore_e,			//�^�C�� e
		Result_TimeScore_Num		//�^�C����Sprite���B
	};
	//�N���A�t���A�B
	const enum ClearFloorScore {
		Result_ClearFloorScore_Icon,	//�N���A�t���A�A�C�R��
		Result_ClearFloorScore_C,		//�N���A�t���A C
		Result_ClearFloorScore_l,		//�N���A�t���A l
		Result_ClearFloorScore_e,		//�N���A�t���A e
		Result_ClearFloorScore_a,		//�N���A�t���A a
		Result_ClearFloorScore_r,		//�N���A�t���A r
		Result_ClearFloorScore_F,		//�N���A�t���A F
		Result_ClearFloorScore_l2,		//�N���A�t���A l
		Result_ClearFloorScore_o,		//�N���A�t���A o
		Result_ClearFloorScore_o2,		//�N���A�t���A o
		Result_ClearFloorScore_r2,		//�N���A�t���A r
		Result_ClearFloorScore_Num		//�N���A�t���A��Sprite���B

	};
	//�ŏI���x���B
	const enum LastLevelScore {
		Result_LastLevelScore_Icon,	//�N���A�t���A�A�C�R��
		Result_LastLevelScore_L,		//�N���A�t���A L
		Result_LastLevelScore_a,		//�N���A�t���A a
		Result_LastLevelScore_s,		//�N���A�t���A s
		Result_LastLevelScore_t,		//�N���A�t���A t
		Result_LastLevelScore_L2,		//�N���A�t���A L
		Result_LastLevelScore_e,		//�N���A�t���A e
		Result_LastLevelScore_v,		//�N���A�t���A v
		Result_LastLevelScore_e2,		//�N���A�t���A e
		Result_LastLevelScore_l3,		//�N���A�t���A l
		Result_LastLevelScore_Num		//�N���A�t���A��Sprite���B
	};
	const enum EnemyScore {
		Result_EnemyScore_Icon,	//���j�{�X�A�C�R��
		Result_EnemyScore_D,		//���j�{�X D
		Result_EnemyScore_e,		//���j�{�X e
		Result_EnemyScore_f,		//���j�{�X f
		Result_EnemyScore_e2,	//���j�{�X e
		Result_EnemyScore_a,		//���j�{�X r
		Result_EnemyScore_t,		//���j�{�X t
		Result_EnemyScore_E3,	//���j�{�X E
		Result_EnemyScore_n,		//���j�{�X n
		Result_EnemyScore_e4,	//���j�{�X e
		Result_EnemyScore_m,		//���j�{�X m
		Result_EnemyScore_y,		//���j�{�X y
		Result_EnemyScore_Num	//���j�{�X��Sprite���B
	};	//�X�R�A�B
	const enum Score {
		Result_Score_S,		//�X�R�A S
		Result_Score_c,		//�X�R�A c
		Result_Score_o,		//�X�R�A o
		Result_Score_r,		//�X�R�A r
		Result_Score_e,		//�X�R�A e
		Result_Score_Num	//�X�R�A��Sprite���B
	};

	const enum ScoreNum {
		Result_ClearFloorScore,		//�X�R�A S
		Result_LastLevelScore,		//�X�R�A c
		Result_DfeartEnemyScore,		//�X�R�A o
		Result_TotalScore,		//�X�R�A r
		Result_ScoreNum	//�X�R�A��Sprite���B
	};

	const enum Rank {
		Rank_S,
		Rank_A,
		Rank_B,
		Rank_C,
		Rank_D,
		Rank_Num
	};

private:

	SpriteRender* m_spriteRender[Result_Num] = { nullptr };			//�X�v���C�g�����_�[�B
	Vector3 m_position = { Vector3::Zero };							//���W�B
	Vector4 m_spriteMulColor[Result_Num] = { Vector4::White };		//�X�v���C�g�̏�Z�J���[�B
	ResultState m_resultState = Result_BackGround_Fade;				//��ԁB
	FontNumber* m_fontNumber[Result_ScoreNum] = { nullptr };			//�t�H���g�i���o�[�B

	SpriteRender* m_battleResultSR[Result_BattleResult_Num] = { nullptr };							//�X�v���C�g�����_�[�B
	SpriteRender* m_timeSR[Result_TimeScore_Num] = { nullptr };							//�X�v���C�g�����_�[�B
	SpriteRender* m_clearFloorSR[Result_ClearFloorScore_Num] = { nullptr };							//�X�v���C�g�����_�[�B
	SpriteRender* m_lastLevelSR[Result_LastLevelScore_Num] = { nullptr };							//�X�v���C�g�����_�[�B
	SpriteRender* m_enemyScoreSR[Result_EnemyScore_Num] = { nullptr };							//�X�v���C�g�����_�[�B
	SpriteRender* m_scoreSR[Result_Score_Num] = { nullptr };							//�X�v���C�g�����_�[�B
	SpriteRender* m_rankSR[Rank_Num] = { nullptr };							//�X�v���C�g�����_�[�B

	Fade* fadein[1] = { nullptr };
private:
	//�萔�����i�e�������Ƃɕ����Ă܂��B�j
	const Vector3 RESULT_BACKGROUND_POS = { 0.0f,0.0f,0.0f };	//�w�i�p�e�N�X�`���̍��W�B
	const Vector3 RESULT_BOARD_POS = { 0.0f,0.0f,0.0f };	//���U���g�{�[�h�̍��W�B

	const Vector4 SET_MULCOLOR = { 0.0f,0.0f,0.0f,1.0f };	//������Z�J���[�B

	const float FADE_DELTA_ALPHA = 0.92f / 30.0f;		//�E�F�C�u�̓����x��ψʂ�����l�B
	const float BOARD_DELTA_ALPHA = 1.0f / 30.0f;		//�E�F�C�u�̓����x��ψʂ�����l�B
	const float SET_ALPHA = 0.0f;							//���������x�B

	const Vector4 FADEIN_FINISHED = { 1.0f,1.0f,1.0f,1.0f };	//�t�F�[�h�C�����I���l�B
	const Vector4 FADEOUT_FINISHED = { 0.0f,0.0f,0.0f,1.0f };	//�t�F�[�h�A�E�g���I���l�B
	const float FADEIN_TIME = 1.0f;					//�t�F�[�h�C�������鎞�ԁB�P�ʁF�t���[���B

	//��������
	const Vector3 BATTLERESULT_POS = { 300.0f,475.0f,0.0f };
	const Vector3 TIME_POS = { 450.0f,120.0f,0.0f };
	const Vector3 CLEARFLOOR_POS = { 380.0f,150.0f,0.0f };
	const Vector3 LASTLEVEL_POS = { 385.0f,30.0f,0.0f };
	const Vector3 ENEMYSCORE_POS = { 360.0f,-100.0f,0.0f };
	const Vector3 SCORE_POS = { 500.0f,-225.0f,0.0f };
	const Vector3 RANK_POS = { -525.0f,-225.0f,0.0f };


	const Vector3 TIMEICOM_POS = { 560.0f,125.0f,0.0f };
	const Vector3 FLOORICOM_POS = { 560.0f,155.0f,0.0f };
	const Vector3 LEVELICOM_POS = { 560.0f,35.0f,0.0f };
	const Vector3 ENEMYICOM_POS = { 560.0f,-95.0f,0.0f };

	int m_timer = 0;
	const float m_fallMoveSpeed = -25.0f;			//���~���x�B
	const float m_Indicate = 0.1f;				//�\��������l�B
	const int m_timeLag[12] = { 0,5,10,15,20,25,30,35,40,45,50,55 };				//���ԍ��̊e�^�C���B
	const int m_timeSpriteLag[5] = { 0,6,8,10,12 };				//���ԍ��̊e�^�C���B
	const int m_crearFloorSpriteLag[11] = { 0,6,8,10,12,14,16,18,20,22,24 };				//���ԍ��̊e�^�C���B
	const int m_laseLevelSpriteLag[10] = { 0,6,8,10,12,14,16,18,20,22 };				//���ԍ��̊e�^�C���B
	const int m_EnemyScoreSpriteLag[12] = { 0,6,8,10,12,14,16,18,20,22,24,26 };				//���ԍ��̊e�^�C���B
	const int m_scoreSpriteLag[5] = { 0,2,4,6,8 };				//���ԍ��̊e�^�C���B


	//�X�R�A�֌W�ł��B
	int m_clearFloor = 0;		//�N���A�񐔂��X�R�A�v�Z�������̂��i�[�B
	int m_laseLevel = 0;		//�N���A�����X�R�A�v�Z�������̂����x���i�[�B
	int m_defeatEnemy = 0;		//�N���A���̓|�����G�̐����X�R�A�v�Z�������̂��i�[�B
	int m_totalScore = 0;		//�g�[�^���X�R�A���i�[�B

	bool m_CFflag = false;
	bool m_LLflag = false;
	bool m_DEflag = false;
	bool m_TSflag = false;

};

