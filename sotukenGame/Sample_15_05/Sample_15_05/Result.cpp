#include "stdafx.h"
#include "Result.h"

#include "Game.h"
#include "Player.h"
#include "Stage1.h"
#include "Stage2.h"
#include "Stage3.h"

#include "Fade.h"

Result::Result()
{}
Result::~Result() 
{

}

bool Result::Start()
{
	//�S��
	{
		//�w�i�p�Â߂̃e�N�X�`���B
		m_spriteRender[Result_BackGround] = NewGO<SpriteRender>(4);
		m_spriteRender[Result_BackGround]->Init("Assets/image/Result/Result_BackGround.DDS", 780.0f, 1280.0f);
		m_spriteRender[Result_BackGround]->SetPosition(RESULT_BACKGROUND_POS);
		m_spriteRender[Result_BackGround]->SetAlpha(SET_ALPHA);

		//�o�g�����U���g�{�[�h�B
		m_spriteRender[Result_Board] = NewGO<SpriteRender>(4);
		m_spriteRender[Result_Board]->Init("Assets/image/Result/Result_Board.DDS", 150.0f, 620.0f);
		m_spriteRender[Result_Board]->SetPosition({ 300.0f,275.0f,0.0f });
		m_spriteRender[Result_Board]->SetAlpha(SET_ALPHA);

		//���U���g�{�[�h�B
		m_spriteRender[Result_ScoreBoardFrame] = NewGO<SpriteRender>(4);
		m_spriteRender[Result_ScoreBoardFrame]->Init("Assets/image/Result/Result_ScoreBoard.DDS", 530.0f, 800.0f);
		m_spriteRender[Result_ScoreBoardFrame]->SetPosition({ 215.0f,-70.0f,0.0f });
		m_spriteRender[Result_ScoreBoardFrame]->SetAlpha(SET_ALPHA);

		//�����N�B
		m_spriteRender[Result_RankSprite] = NewGO<SpriteRender>(4);
		m_spriteRender[Result_RankSprite]->Init("Assets/image/Result/Result_Rank.DDS", 50.0f, 155.0f);
		m_spriteRender[Result_RankSprite]->SetPosition({ -325.0f,-200.0f,0.0f });
		m_spriteRender[Result_RankSprite]->SetAlpha(SET_ALPHA);


	}

	//�t�H���g�����B
	//�o�g�����U���g
	{
		for (int i = 0; i < Result_BattleResult_Num; i++) {
			m_battleResultSR[i] = NewGO<SpriteRender>(4);
			m_battleResultSR[i]->SetPosition(BATTLERESULT_POS);
			m_battleResultSR[i]->SetAlpha(SET_ALPHA);
		}
		//�������B
		{
			m_battleResultSR[Result_BattleResult_B]->Init("Assets/image/Result/BattleResult/Result_BattleResult_B.DDS", 150.0f, 620.0f);
			m_battleResultSR[Result_BattleResult_a]->Init("Assets/image/Result/BattleResult/Result_BattleResult_a.DDS", 150.0f, 620.0f);
			m_battleResultSR[Result_BattleResult_t]->Init("Assets/image/Result/BattleResult/Result_BattleResult_t.DDS", 150.0f, 620.0f);
			m_battleResultSR[Result_BattleResult_t2]->Init("Assets/image/Result/BattleResult/Result_BattleResult_t2.DDS", 150.0f, 620.0f);
			m_battleResultSR[Result_BattleResult_l]->Init("Assets/image/Result/BattleResult/Result_BattleResult_l.DDS", 150.0f, 620.0f);
			m_battleResultSR[Result_BattleResult_e]->Init("Assets/image/Result/BattleResult/Result_BattleResult_e.DDS", 150.0f, 620.0f);
			m_battleResultSR[Result_BattleResult_R]->Init("Assets/image/Result/BattleResult/Result_BattleResult_R.DDS", 150.0f, 620.0f);
			m_battleResultSR[Result_BattleResult_e2]->Init("Assets/image/Result/BattleResult/Result_BattleResult_e2.DDS", 150.0f, 620.0f);
			m_battleResultSR[Result_BattleResult_s]->Init("Assets/image/Result/BattleResult/Result_BattleResult_s.DDS", 150.0f, 620.0f);
			m_battleResultSR[Result_BattleResult_u]->Init("Assets/image/Result/BattleResult/Result_BattleResult_u.DDS", 150.0f, 620.0f);
			m_battleResultSR[Result_BattleResult_l2]->Init("Assets/image/Result/BattleResult/Result_BattleResult_l2.DDS", 150.0f, 620.0f);
			m_battleResultSR[Result_BattleResult_t3]->Init("Assets/image/Result/BattleResult/Result_BattleResult_t3.DDS", 150.0f, 620.0f);
		}
	}
	//�^�C��
	{
		for (int i = 0; i < Result_TimeScore_Num; i++) {
			m_timeSR[i] = NewGO<SpriteRender>(4);
			m_timeSR[i]->SetPosition(TIME_POS);
			m_timeSR[i]->SetAlpha(SET_ALPHA);
		}
		//�������B
		{
			m_timeSR[Result_TimeScore_Icon]->Init("Assets/image/Result/TimeScore/Result_TimeScore_Icon.DDS", 60.0f, 60.0f);
			m_timeSR[Result_TimeScore_T]->Init("Assets/image/Result/TimeScore/Result_TimeScore_T.DDS", 50.0f, 120.0f);
			m_timeSR[Result_TimeScore_i]->Init("Assets/image/Result/TimeScore/Result_TimeScore_i.DDS", 50.0f, 120.0f);
			m_timeSR[Result_TimeScore_m]->Init("Assets/image/Result/TimeScore/Result_TimeScore_m.DDS", 50.0f, 120.0f);
			m_timeSR[Result_TimeScore_e]->Init("Assets/image/Result/TimeScore/Result_TimeScore_e.DDS", 50.0f, 120.0f);
		}
	}
	//�˔j��
	{
		for (int i = 0; i < Result_ClearFloorScore_Num; i++) {
			m_clearFloorSR[i] = NewGO<SpriteRender>(4);
			m_clearFloorSR[i]->SetPosition(CLEARFLOOR_POS);
			m_clearFloorSR[i]->SetAlpha(SET_ALPHA);
		}
		//�������B
		{
			m_clearFloorSR[Result_ClearFloorScore_Icon]->Init("Assets/image/Result/ClearFloorScore/Result_ClearFloorScore_Icon.DDS", 60.0f, 60.0f);
			m_clearFloorSR[Result_ClearFloorScore_C]->Init("Assets/image/Result/ClearFloorScore/Result_ClearFloorScore_C.DDS", 50.0f, 260.0f);
			m_clearFloorSR[Result_ClearFloorScore_l]->Init("Assets/image/Result/ClearFloorScore/Result_ClearFloorScore_l.DDS", 50.0f, 260.0f);
			m_clearFloorSR[Result_ClearFloorScore_e]->Init("Assets/image/Result/ClearFloorScore/Result_ClearFloorScore_e.DDS", 50.0f, 260.0f);
			m_clearFloorSR[Result_ClearFloorScore_a]->Init("Assets/image/Result/ClearFloorScore/Result_ClearFloorScore_a.DDS", 50.0f, 260.0f);
			m_clearFloorSR[Result_ClearFloorScore_r]->Init("Assets/image/Result/ClearFloorScore/Result_ClearFloorScore_r.DDS", 50.0f, 260.0f);
			m_clearFloorSR[Result_ClearFloorScore_F]->Init("Assets/image/Result/ClearFloorScore/Result_ClearFloorScore_F.DDS", 50.0f, 260.0f);
			m_clearFloorSR[Result_ClearFloorScore_l2]->Init("Assets/image/Result/ClearFloorScore/Result_ClearFloorScore_l2.DDS", 50.0f, 260.0f);
			m_clearFloorSR[Result_ClearFloorScore_o]->Init("Assets/image/Result/ClearFloorScore/Result_ClearFloorScore_o.DDS", 50.0f, 260.0f);
			m_clearFloorSR[Result_ClearFloorScore_o2]->Init("Assets/image/Result/ClearFloorScore/Result_ClearFloorScore_o2.DDS", 50.0f, 260.0f);
			m_clearFloorSR[Result_ClearFloorScore_r2]->Init("Assets/image/Result/ClearFloorScore/Result_ClearFloorScore_r2.DDS", 50.0f, 260.0f);
		}
	}
	//�ŏI���x��
	{
		for (int i = 0; i < Result_LastLevelScore_Num; i++) {
			m_lastLevelSR[i] = NewGO<SpriteRender>(4);
			m_lastLevelSR[i]->SetPosition(LASTLEVEL_POS);
			m_lastLevelSR[i]->SetAlpha(SET_ALPHA);
		}
		//�������B
		{
			m_lastLevelSR[Result_LastLevelScore_Icon]->Init("Assets/image/Result/LastLevelScore/Result_LastLevelScore_Icon.DDS", 60.0f, 60.0f);
			m_lastLevelSR[Result_LastLevelScore_L]->Init("Assets/image/Result/LastLevelScore/Result_LastLevelScore_L.DDS", 50.0f, 250.0f);
			m_lastLevelSR[Result_LastLevelScore_a]->Init("Assets/image/Result/LastLevelScore/Result_LastLevelScore_a.DDS", 50.0f, 250.0f);
			m_lastLevelSR[Result_LastLevelScore_s]->Init("Assets/image/Result/LastLevelScore/Result_LastLevelScore_s.DDS", 50.0f, 250.0f);
			m_lastLevelSR[Result_LastLevelScore_t]->Init("Assets/image/Result/LastLevelScore/Result_LastLevelScore_t.DDS", 50.0f, 250.0f);
			m_lastLevelSR[Result_LastLevelScore_L2]->Init("Assets/image/Result/LastLevelScore/Result_LastLevelScore_L2.DDS", 50.0f, 250.0f);
			m_lastLevelSR[Result_LastLevelScore_e]->Init("Assets/image/Result/LastLevelScore/Result_LastLevelScore_e.DDS", 50.0f, 250.0f);
			m_lastLevelSR[Result_LastLevelScore_v]->Init("Assets/image/Result/LastLevelScore/Result_LastLevelScore_v.DDS", 50.0f, 250.0f);
			m_lastLevelSR[Result_LastLevelScore_e2]->Init("Assets/image/Result/LastLevelScore/Result_LastLevelScore_e2.DDS", 50.0f, 250.0f);
			m_lastLevelSR[Result_LastLevelScore_l3]->Init("Assets/image/Result/LastLevelScore/Result_LastLevelScore_l3.DDS", 50.0f, 250.0f);
		}
	}
	//���j�{�X
	{
		for (int i = 0; i < Result_EnemyScore_Num; i++) {
			m_enemyScoreSR[i] = NewGO<SpriteRender>(4);
			m_enemyScoreSR[i]->SetPosition(ENEMYSCORE_POS);
			m_enemyScoreSR[i]->SetAlpha(SET_ALPHA);
		}
		//�������B
		{
			m_enemyScoreSR[Result_EnemyScore_Icon]->Init("Assets/image/Result/EnemyScore/Result_EnemyScore_Icon.DDS", 60.0f, 60.0f);
			m_enemyScoreSR[Result_EnemyScore_D]->Init("Assets/image/Result/EnemyScore/Result_EnemyScore_D.DDS", 50.0f, 300.0f);
			m_enemyScoreSR[Result_EnemyScore_e]->Init("Assets/image/Result/EnemyScore/Result_EnemyScore_e.DDS", 50.0f, 300.0f);
			m_enemyScoreSR[Result_EnemyScore_f]->Init("Assets/image/Result/EnemyScore/Result_EnemyScore_f.DDS", 50.0f, 300.0f);
			m_enemyScoreSR[Result_EnemyScore_e2]->Init("Assets/image/Result/EnemyScore/Result_EnemyScore_e2.DDS", 50.0f, 300.0f);
			m_enemyScoreSR[Result_EnemyScore_a]->Init("Assets/image/Result/EnemyScore/Result_EnemyScore_a.DDS", 50.0f, 300.0f);
			m_enemyScoreSR[Result_EnemyScore_t]->Init("Assets/image/Result/EnemyScore/Result_EnemyScore_t.DDS", 50.0f, 300.0f);
			m_enemyScoreSR[Result_EnemyScore_E3]->Init("Assets/image/Result/EnemyScore/Result_EnemyScore_E3.DDS", 50.0f, 300.0f);
			m_enemyScoreSR[Result_EnemyScore_n]->Init("Assets/image/Result/EnemyScore/Result_EnemyScore_n.DDS", 50.0f, 300.0f);
			m_enemyScoreSR[Result_EnemyScore_e4]->Init("Assets/image/Result/EnemyScore/Result_EnemyScore_e4.DDS", 50.0f, 300.0f);
			m_enemyScoreSR[Result_EnemyScore_m]->Init("Assets/image/Result/EnemyScore/Result_EnemyScore_m.DDS", 50.0f, 300.0f);
			m_enemyScoreSR[Result_EnemyScore_y]->Init("Assets/image/Result/EnemyScore/Result_EnemyScore_y.DDS", 50.0f, 300.0f);
		}
	}
	//�X�R�A
	{
		for (int i = 0; i < Result_Score_Num; i++) {
			m_scoreSR[i] = NewGO<SpriteRender>(4);
			m_scoreSR[i]->SetPosition(SCORE_POS);
			m_scoreSR[i]->SetAlpha(SET_ALPHA);

		}
		//�������B
		{
			m_scoreSR[Result_Score_S]->Init("Assets/image/Result/Score/Result_Score_S.DDS", 50.0f, 120.0f);
			m_scoreSR[Result_Score_c]->Init("Assets/image/Result/Score/Result_Score_c.DDS", 50.0f, 120.0f);
			m_scoreSR[Result_Score_o]->Init("Assets/image/Result/Score/Result_Score_o.DDS", 50.0f, 120.0f);
			m_scoreSR[Result_Score_r]->Init("Assets/image/Result/Score/Result_Score_r.DDS", 50.0f, 120.0f);
			m_scoreSR[Result_Score_e]->Init("Assets/image/Result/Score/Result_Score_e.DDS", 50.0f, 120.0f);
		}

	}

	//�A�C�R���̍��W�𓮂����܂��B
	{
		m_timeSR[Result_TimeScore_Icon]->SetPosition(TIMEICOM_POS);
		m_clearFloorSR[Result_ClearFloorScore_Icon]->SetPosition(FLOORICOM_POS);
		m_lastLevelSR[Result_LastLevelScore_Icon]->SetPosition(LEVELICOM_POS);
		m_enemyScoreSR[Result_EnemyScore_Icon]->SetPosition(ENEMYICOM_POS);
	}

	//�t�H���g
	{
		//�v���C���[�̃��x���B
		m_fontNumber[Result_ClearFloorScore] = NewGO<FontNumber>(4);
		m_fontNumber[Result_ClearFloorScore]->SetAlpha(0.0f);
		m_fontNumber[Result_LastLevelScore] = NewGO<FontNumber>(4);
		m_fontNumber[Result_LastLevelScore]->SetAlpha(0.0f);
		m_fontNumber[Result_DfeartEnemyScore] = NewGO<FontNumber>(4);
		m_fontNumber[Result_DfeartEnemyScore]->SetAlpha(0.0f);
		m_fontNumber[Result_TotalScore] = NewGO<FontNumber>(4);
		m_fontNumber[Result_TotalScore]->SetAlpha(0.0f);

	}

	//�����N
	{
		for (int i = 0; i < Rank_Num; i++) {
			m_rankSR[i] = NewGO<SpriteRender>(4);
			m_rankSR[i]->SetPosition(RANK_POS);
			m_rankSR[i]->SetScale({ 0.7f,0.7f ,0.7f });
			m_rankSR[i]->SetAlpha(SET_ALPHA);
		}
		//�������B
		{
			m_rankSR[Rank_S]->Init("Assets/image/Result/Rank/S_Runk.DDS", 256.0f, 256.0f);
			m_rankSR[Rank_A]->Init("Assets/image/Result/Rank/A_Runk.DDS", 256.0f, 256.0f);
			m_rankSR[Rank_B]->Init("Assets/image/Result/Rank/B_Runk.DDS", 256.0f, 256.0f);
			m_rankSR[Rank_C]->Init("Assets/image/Result/Rank/C_Runk.DDS", 256.0f, 256.0f);
			m_rankSR[Rank_D]->Init("Assets/image/Result/Rank/D_Runk.DDS", 256.0f, 256.0f);
		}

	}
	return true;
}

///////////////////////////////////////�摜����///////////////////////////////////////

void Result::SpriteMove(SpriteRender* m_sprite)
{
	//�X�v���C�g�̉��~�ړ������B
	//Sprite���~����
	Vector3 m_position = m_sprite->GetPosition();
	if (m_position.y > 275.0f) {
		m_position.y += m_fallMoveSpeed;

	}
	m_sprite->SetAlpha(1.0f);
	m_sprite->SetPosition(m_position);
}
void Result::SpriteIndicate(SpriteRender* m_sprite)
{
	//�X�v���C�g�̕\�������B
	float m_alpha = m_sprite->GetAlpha();
	if (m_alpha < 1.0f) {
		m_alpha += m_Indicate;

	}
	m_sprite->SetAlpha(m_alpha);
}
void Result::SpriteScaleUp(SpriteRender* m_sprite)
{
	//�X�v���C�g�̊g��\�������B
	//�X�v���C�g�̊g��\�������B
	Vector3 m_scale = m_sprite->GetScale();
	float m_alpha = m_sprite->GetAlpha();

	if (m_scale.x < 1.0f && m_scale.y < 1.0f && m_scale.z < 1.0f) {
		m_scale.x += m_Indicate;
		m_scale.y += m_Indicate;
		m_scale.z += m_Indicate;

		if (m_alpha < 1.0f) {
			m_alpha += m_Indicate;

		}

	}
	m_sprite->SetAlpha(m_alpha);
	m_sprite->SetScale(m_scale);

}
/////////////////////////////////////////////////////////////////////////////////////

void Result::BackGroundFade()
{
	//�Q�[����ʂ������Â�����B
	m_spriteRender[Result_BackGround]->DeltaAlpha(FADE_DELTA_ALPHA);
	//���U���g�{�[�h�o���B
	m_spriteRender[Result_Board]->DeltaAlpha(BOARD_DELTA_ALPHA);

	if (m_spriteRender[Result_Board]->GetAlpha() >= 1.0f) {
		//���̏����ցB
		m_resultState = Result_BattleResult;
	}
}
void Result::BattleResult()
{
	//���ԍ��Ő퓬����Sprite�̕\���B
	//���~�ŏo�����܂��B
	m_timer++;
	if (m_timer >= m_timeLag[0]) {
		SpriteMove(m_battleResultSR[0]);
	}
	if (m_timer >= m_timeLag[1]) {
		SpriteMove(m_battleResultSR[1]);
	}
	if (m_timer >= m_timeLag[2]) {
		SpriteMove(m_battleResultSR[2]);
	}
	if (m_timer >= m_timeLag[3]) {
		SpriteMove(m_battleResultSR[3]);
	}
	if (m_timer >= m_timeLag[4]) {
		SpriteMove(m_battleResultSR[4]);
	}
	if (m_timer >= m_timeLag[5]) {
		SpriteMove(m_battleResultSR[5]);
	}
	if (m_timer >= m_timeLag[6]) {
		SpriteMove(m_battleResultSR[6]);
	}
	if (m_timer >= m_timeLag[7]) {
		SpriteMove(m_battleResultSR[7]);
	}
	if (m_timer >= m_timeLag[8]) {
		SpriteMove(m_battleResultSR[8]);
	}
	if (m_timer >= m_timeLag[9]) {
		SpriteMove(m_battleResultSR[9]);
	}
	if (m_timer >= m_timeLag[10]) {
		SpriteMove(m_battleResultSR[10]);
	}
	if (m_timer >= m_timeLag[11]) {
		SpriteMove(m_battleResultSR[11]);
	}

	//���ׂĕ\�����I������̂Ŏ��̏����ֈڍs�B
	if (m_battleResultSR[Result_BattleResult_t3]->GetPosition().y <= 275.0f) {
		m_timer = 0;
		m_resultState = Result_ScoreBoard;
	}
}
void Result::ScoreBoard()
{
	//�X�R�A�{�[�h�̕\���B
	SpriteIndicate(m_spriteRender[Result_ScoreBoardFrame]);

	if (m_spriteRender[Result_ScoreBoardFrame]->GetAlpha() >= 1.0f) {
		m_resultState = Result_ClearFloor_Score;
	}
}
void Result::ClearTimeScore()
{
	//�N���A�^�C���̃X�R�A�\���B
	m_timer++;
	if (m_timer >= m_timeSpriteLag[0]) {
		SpriteIndicate(m_timeSR[0]);
	}
	if (m_timer >= m_timeSpriteLag[1]) {
		SpriteIndicate(m_timeSR[1]);
	}
	if (m_timer >= m_timeSpriteLag[2]) {
		SpriteIndicate(m_timeSR[2]);
	}
	if (m_timer >= m_timeSpriteLag[3]) {
		SpriteIndicate(m_timeSR[3]);
	}
	if (m_timer >= m_timeSpriteLag[4]) {
		SpriteIndicate(m_timeSR[4]);
	}

	if (m_timeSR[Result_TimeScore_e]->GetAlpha() >= 1.0f) {
		m_timer = 0;
		m_resultState = Result_ClearFloor_Score;
	}

}
void Result::ClearTimeScoreCal()
{
	//�N���A�^�C���̃X�R�A�v�Z�B

}
void Result::ClearFloorScore()
{
	//�˔j�K�w�̃X�R�A�\���B
	m_timer++;
	{
		if (m_timer >= m_crearFloorSpriteLag[0]) {
			SpriteIndicate(m_clearFloorSR[0]);
		}
		if (m_timer >= m_crearFloorSpriteLag[1]) {
			SpriteIndicate(m_clearFloorSR[1]);
		}
		if (m_timer >= m_crearFloorSpriteLag[2]) {
			SpriteIndicate(m_clearFloorSR[2]);
		}
		if (m_timer >= m_crearFloorSpriteLag[3]) {
			SpriteIndicate(m_clearFloorSR[3]);
		}
		if (m_timer >= m_crearFloorSpriteLag[4]) {
			SpriteIndicate(m_clearFloorSR[4]);
		}
		if (m_timer >= m_crearFloorSpriteLag[5]) {
			SpriteIndicate(m_clearFloorSR[5]);
		}
		if (m_timer >= m_crearFloorSpriteLag[6]) {
			SpriteIndicate(m_clearFloorSR[6]);
		}
		if (m_timer >= m_crearFloorSpriteLag[7]) {
			SpriteIndicate(m_clearFloorSR[7]);
		}
		if (m_timer >= m_crearFloorSpriteLag[8]) {
			SpriteIndicate(m_clearFloorSR[8]);
		}
		if (m_timer >= m_crearFloorSpriteLag[9]) {
			SpriteIndicate(m_clearFloorSR[9]);
		}
		if (m_timer >= m_crearFloorSpriteLag[10]) {
			SpriteIndicate(m_clearFloorSR[10]);
		}
	}
	if (m_clearFloorSR[Result_ClearFloorScore_r2]->GetAlpha() >= 1.0f) {
		Game* game = FindGO<Game>("Game");
		m_clearFloor = (game->GetClearFloorNumber());
		m_timer = 0;
		m_CFflag = true;
		m_resultState = Result_LastLevel_Score;
	}
}
void Result::ClearFloorScoreCal()
{
	//�˔j�K�w�̃X�R�A�v�Z�B
	m_fontNumber[Result_ClearFloorScore]->SetDisplayNum(m_clearFloor);
	m_fontNumber[Result_ClearFloorScore]->SetAlpha(1.0f);
	m_fontNumber[Result_ClearFloorScore]->SetPosition({ -50.0f, 120.0f, 0.0f });

}
void Result::LastLevelScore()
{
	//�ŏI���x���̃X�R�A�\���B
	m_timer++;
	{
		if (m_timer >= m_laseLevelSpriteLag[0]) {
			SpriteIndicate(m_lastLevelSR[0]);
		}
		if (m_timer >= m_laseLevelSpriteLag[1]) {
			SpriteIndicate(m_lastLevelSR[1]);
		}
		if (m_timer >= m_laseLevelSpriteLag[2]) {
			SpriteIndicate(m_lastLevelSR[2]);
		}
		if (m_timer >= m_laseLevelSpriteLag[3]) {
			SpriteIndicate(m_lastLevelSR[3]);
		}
		if (m_timer >= m_laseLevelSpriteLag[4]) {
			SpriteIndicate(m_lastLevelSR[4]);
		}
		if (m_timer >= m_laseLevelSpriteLag[5]) {
			SpriteIndicate(m_lastLevelSR[5]);
		}
		if (m_timer >= m_laseLevelSpriteLag[6]) {
			SpriteIndicate(m_lastLevelSR[6]);
		}
		if (m_timer >= m_laseLevelSpriteLag[7]) {
			SpriteIndicate(m_lastLevelSR[7]);
		}
		if (m_timer >= m_laseLevelSpriteLag[8]) {
			SpriteIndicate(m_lastLevelSR[8]);
		}
		if (m_timer >= m_laseLevelSpriteLag[9]) {
			SpriteIndicate(m_lastLevelSR[9]);
		}
	}
	if (m_lastLevelSR[Result_LastLevelScore_l3]->GetAlpha() >= 1.0f) {
		Player* player = FindGO<Player>("player");
		m_laseLevel = (player->GetPlayerLevel());
		m_timer = 0;
		m_LLflag = true;
		m_resultState = Result_DefaultBoss_Score;
	}

}
void Result::LastLevelScoreCal()
{
	//�ŏI���x���̃X�R�A�v�Z�B
	m_fontNumber[Result_LastLevelScore]->SetDisplayNum(m_laseLevel);
	m_fontNumber[Result_LastLevelScore]->SetAlpha(1.0f);
	m_fontNumber[Result_LastLevelScore]->SetPosition({ -50.0f, 0.0f, 0.0f });
}
void Result::DefaultBossScore()
{
	//���j�{�X�̃X�R�A�\���B
	m_timer++;
	{
		if (m_timer >= m_EnemyScoreSpriteLag[0]) {
			SpriteIndicate(m_enemyScoreSR[0]);
		}
		if (m_timer >= m_EnemyScoreSpriteLag[1]) {
			SpriteIndicate(m_enemyScoreSR[1]);
		}
		if (m_timer >= m_EnemyScoreSpriteLag[2]) {
			SpriteIndicate(m_enemyScoreSR[2]);
		}
		if (m_timer >= m_EnemyScoreSpriteLag[3]) {
			SpriteIndicate(m_enemyScoreSR[3]);
		}
		if (m_timer >= m_EnemyScoreSpriteLag[4]) {
			SpriteIndicate(m_enemyScoreSR[4]);
		}
		if (m_timer >= m_EnemyScoreSpriteLag[5]) {
			SpriteIndicate(m_enemyScoreSR[5]);
		}
		if (m_timer >= m_EnemyScoreSpriteLag[6]) {
			SpriteIndicate(m_enemyScoreSR[6]);
		}
		if (m_timer >= m_EnemyScoreSpriteLag[7]) {
			SpriteIndicate(m_enemyScoreSR[7]);
		}
		if (m_timer >= m_EnemyScoreSpriteLag[8]) {
			SpriteIndicate(m_enemyScoreSR[8]);
		}
		if (m_timer >= m_EnemyScoreSpriteLag[9]) {
			SpriteIndicate(m_enemyScoreSR[9]);
		}
		if (m_timer >= m_EnemyScoreSpriteLag[10]) {
			SpriteIndicate(m_enemyScoreSR[10]);
		}
		if (m_timer >= m_EnemyScoreSpriteLag[11]) {
			SpriteIndicate(m_enemyScoreSR[11]);
		}
	}
	if (m_enemyScoreSR[Result_EnemyScore_y]->GetAlpha() >= 1.0f) {
		{
			//�G�̃X�R�A�v�Z
			Game* game = FindGO<Game>("Game");
			m_defeatEnemy = (game->GetDfeateEnemyNum());
			Stage1* m_stage1 = FindGO<Stage1>("stage");
			Stage2* m_stage2 = FindGO<Stage2>("stage");
			Stage3* m_stage3 = FindGO<Stage3>("stage");
			if (m_stage1 != nullptr) {
				m_defeatEnemy += (m_stage1->GetDeathEnemyNum());
			}
			if (m_stage2 != nullptr) {
				m_defeatEnemy += (m_stage2->GetDeathEnemyNum());
			}
			if (m_stage3 != nullptr) {
				m_defeatEnemy += (m_stage3->GetDeathEnemyNum());
			}
		}
		m_timer = 0;
		m_DEflag = true;
		m_resultState = Result_Total_Score;
	}
}
void Result::DefaultBossScoreCal()
{
	//���j�G�l�~�[�̃X�R�A�v�Z�B

	m_fontNumber[Result_DfeartEnemyScore]->SetDisplayNum(m_defeatEnemy);
	m_fontNumber[Result_DfeartEnemyScore]->SetAlpha(1.0f);
	m_fontNumber[Result_DfeartEnemyScore]->SetPosition({ -50.0f, -130.0f, 0.0f });
}
void Result::TotalScore()
{
	//�g�[�^���X�R�A�\���B
	m_timer++;
	{
		if (m_timer >= m_scoreSpriteLag[0]) {
			SpriteIndicate(m_scoreSR[0]);
		}
		if (m_timer >= m_scoreSpriteLag[1]) {
			SpriteIndicate(m_scoreSR[1]);
		}
		if (m_timer >= m_scoreSpriteLag[2]) {
			SpriteIndicate(m_scoreSR[2]);
		}
		if (m_timer >= m_scoreSpriteLag[3]) {
			SpriteIndicate(m_scoreSR[3]);
		}
		if (m_timer >= m_scoreSpriteLag[4]) {
			SpriteIndicate(m_scoreSR[4]);
		}
	}
	if (m_scoreSR[Result_Score_e]->GetAlpha() >= 1.0f) {
		//�e�X�R�A����ɂ܂Ƃ߂�B
		m_totalScore =  (m_clearFloor*100) + (m_laseLevel*80) + (m_defeatEnemy*150);
		m_timer = 0;
		m_TSflag = true;
		m_resultState = Result_Rank;
	}

}

void Result::TotalScoreCal()
{
	//�g�[�^���X�R�A�v�Z�B	

	m_fontNumber[Result_TotalScore]->SetDisplayNum(m_totalScore);
	m_fontNumber[Result_TotalScore]->SetAlpha(1.0f);
	m_fontNumber[Result_TotalScore]->SetPosition({ -50.0f, -250.0f, 0.0f });
}
void Result::RankSet()
{
	//�X�R�A���ʂɂ���ă����N�̕\������B

	SpriteIndicate(m_spriteRender[Result_RankSprite]);

	if (m_spriteRender[Result_RankSprite]->GetAlpha() >= 1.0f) {
		m_resultState = Result_Player;
	}
}
void Result::PlayerSet()
{
	//�����N�C���X�g��ύX���ĕ\������B
	//���͉����Ȃ��̂ŃX���[����B
	if (m_totalScore < 1000) {
		SpriteIndicate(m_rankSR[Rank_D]);
	}
	else if (m_totalScore > 1000 && m_totalScore < 2000) {
		SpriteIndicate(m_rankSR[Rank_C]);
	}
	else if (m_totalScore > 2000 && m_totalScore < 3000) {
		SpriteIndicate(m_rankSR[Rank_B]);
	}
	else if (m_totalScore > 3000 && m_totalScore < 6000) {
		SpriteIndicate(m_rankSR[Rank_A]);
	}
	else if (m_totalScore > 6000) {
		SpriteIndicate(m_rankSR[Rank_S]);
	}

}
void Result::Next()
{
	//�Q�[���I���B
}

void Result::Update()
{
	switch (m_resultState)
	{
	case Result::Result_BackGround_Fade:
		BackGroundFade();		//�Q�[����ʂ������Â�����B
		break;
	case Result::Result_BattleResult:
		BattleResult();			//�퓬����Sprite�̕\���B
		break;
	case Result::Result_ScoreBoard:
		ScoreBoard();			//�X�R�A�{�[�h�̕\���B
		break;
	case Result::Result_ClearTime_Score:
		ClearTimeScore();		//�N���A�^�C���̃X�R�A�\���B
		break;
	case Result::Result_ClearFloor_Score:
		ClearFloorScore();		//�˔j�K�w�̃X�R�A�\���B
		break;
	case Result::Result_LastLevel_Score:
		LastLevelScore();		//�ŏI���x���̃X�R�A�\���B
		break;
	case Result::Result_DefaultBoss_Score:
		DefaultBossScore();		//���j�{�X�̃X�R�A�\���B
		break;
	case Result::Result_Total_Score:
		TotalScore();			//�g�[�^���X�R�A�\���B	
		break;
	case Result::Result_Total_ScoreCal:
		TotalScoreCal();		//�g�[�^���X�R�A�v�Z�B	
		break;
	case Result::Result_Rank:
		RankSet();				//�X�R�A���ʂɂ���ă����N�̕\������B
		break;
	case Result::Result_Player:
		PlayerSet();			//�����N�ɂ���ăv���C���[�C���X�g��ύX���ĕ\������B
		break;
	case Result::Result_Next:
		Next();					//���̏����B
		break;
	}

	if (m_CFflag==true) {
		ClearFloorScoreCal();
	}
	if (m_LLflag == true) {
		LastLevelScoreCal();
	}
	if (m_DEflag == true) {
		DefaultBossScoreCal();
	}
	if (m_TSflag == true) {
		TotalScoreCal();
	}

}
