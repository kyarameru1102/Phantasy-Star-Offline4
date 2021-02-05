#include "stdafx.h"
#include "Title.h"
#include "Game.h"

#include "Fade.h"

#include "sound/SoundSource.h"

Title::Title()
{

}

Title::~Title()
{
	//Sprite�̍폜�B
	for (int i = 0; i < Title_Num; i++) {
		DeleteGO(m_spriteRender[i]);
	}
	DeleteGO(m_bgmTitle);
	DeleteGOs("FadeIn");
	DeleteGOs("FadeOut");
}

bool Title::Start()
{
	//�^�C�g����BGM���Đ�����B
	m_bgmTitle = NewGO<CSoundSource>(0);
	m_bgmTitle->Init(L"Assets/sound/BGM_Title.wav");
	m_bgmTitle->Play(true);

	//�w�i�B
	{
		//0�ԁ�Title1(�w�i)
		m_spriteRender[Title_BackGround1] = NewGO<SpriteRender>(0);
		m_spriteRender[Title_BackGround1]->Init("Assets/image/title/Title_BackGround.DDS", 780.0f, 1280.0f);
		m_spriteRender[Title_BackGround1]->SetPosition(TITLE_BACKGROUND1_POS);
		m_spriteMulColor[Title_BackGround1] = TITLE_SET_MULCOLOR;
		m_spriteRender[Title_BackGround1]->SetMulColor(m_spriteMulColor[Title_BackGround1]);

		//1�ԁ�Title2(�w�i)
		m_spriteRender[Title_BackGround2] = NewGO<SpriteRender>(0);
		m_spriteRender[Title_BackGround2]->Init("Assets/image/title/Title_BackGround.DDS", 780.0f, 1280.0f);
		m_spriteRender[Title_BackGround2]->SetPosition(TITLE_BACKGROUND2_POS);
		m_spriteMulColor[Title_BackGround2] = TITLE_SET_MULCOLOR;
		m_spriteRender[Title_BackGround2]->SetMulColor(m_spriteMulColor[Title_BackGround2]);
	}
	//2�ԁ�TitlePlayer
	m_spriteRender[Title_Player] = NewGO<SpriteRender>(0);
	m_spriteRender[Title_Player]->Init("Assets/image/title/Title_Player.DDS", 1050.0f, 1050.0f);
	m_spriteRender[Title_Player]->SetPosition(TITLE_PLAYER_POS);
	m_spriteMulColor[Title_Player] = TITLE_SET_MULCOLOR;
	m_spriteRender[Title_Player]->SetMulColor(m_spriteMulColor[Title_Player]);

	//3�ԁ�TitleName
	m_spriteRender[Title_Name] = NewGO<SpriteRender>(0);
	m_spriteRender[Title_Name]->Init("Assets/image/title/Title_Name.DDS", 400.0f, 800.0f);
	m_spriteRender[Title_Name]->SetPosition(TITLE_NAME_POS);
	m_spriteRender[Title_Name]->SetAlpha(SET_ALPHA);

	//�I���{�^���B
	{
		//4�ԁ�StartButton
		m_spriteRender[Title_Start] = NewGO<SpriteRender>(0);
		m_spriteRender[Title_Start]->Init("Assets/image/title/Title_Start.DDS", 100.0f, 175.0f);
		m_spriteRender[Title_Start]->SetPosition(TITLE_STARTBUTTON_POS);
		m_spriteRender[Title_Start]->SetAlpha(SET_ALPHA);

		//5�ԁ�EndButton
		m_spriteRender[Title_End] = NewGO<SpriteRender>(0);
		m_spriteRender[Title_End]->Init("Assets/image/title/Title_End.DDS", 100.0f, 175.0f);
		m_spriteRender[Title_End]->SetPosition(TITLE_ENDBUTTON_POS);
		m_spriteRender[Title_End]->SetAlpha(SET_ALPHA);

		//6�ԁ�SelectIcon
		m_spriteRender[Title_SelectIcon] = NewGO<SpriteRender>(0);
		m_spriteRender[Title_SelectIcon]->Init("Assets/image/title/Title_SelectIcon.DDS", 50.0f, 50.0f);
		m_spriteRender[Title_SelectIcon]->SetPosition(TITLE_SELECTICON_POS);
		m_spriteRender[Title_SelectIcon]->SetAlpha(SET_ALPHA);

		m_iconPos = TITLE_SELECTICON_POS;	//�A�C�R���̍��W�����B
	}

	return true;
}
void Title::TitleMoveBackGround()
{
	//�w�i�̈ړ������B
	m_backTexpos1 = m_spriteRender[Title_BackGround1]->GetPosition();
	m_backTexpos2 = m_spriteRender[Title_BackGround2]->GetPosition();

	m_backTexpos1.x += m_backMove;
	m_backTexpos2.x += m_backMove;

	//���ʒu�ɂȂ�ƈꖇ�ڂ̉E�[�Ɉړ�������B
	//�w�i��Texture���r�؂�Ȃ���I�I
	if (m_backTexpos1.x <= -m_backTexXPos) {
		m_backTexpos1.x = m_backTexXPos;
	}
	else if (m_backTexpos2.x <= -m_backTexXPos) {
		m_backTexpos2.x = m_backTexXPos;
	}

	m_spriteRender[Title_BackGround1]->SetPosition(m_backTexpos1);
	m_spriteRender[Title_BackGround2]->SetPosition(m_backTexpos2);

}

void Title::TitleFadeIn()
{
	//�t�F�[�h�C���B
	if (fadein[0] == nullptr) {
		fadein[0] = NewGO<Fade>(0, "FadeIn");
	}
	fadein[0]->FadeSet(m_spriteRender[Title_BackGround1], Fade::Fade_In, FADEIN_TIME);
	if (fadein[1] == nullptr) {
		fadein[1] = NewGO<Fade>(0, "FadeIn");
	}
	fadein[1]->FadeSet(m_spriteRender[Title_BackGround2], Fade::Fade_In, FADEIN_TIME);
	if (fadein[2] == nullptr) {
		fadein[2] = NewGO<Fade>(0, "FadeIn");
	}
	fadein[2]->FadeSet(m_spriteRender[Title_Player], Fade::Fade_In, FADEIN_TIME);


	m_spriteMulColor[Title_BackGround1] = m_spriteRender[Title_BackGround1]->GetMulColor();
	m_spriteMulColor[Title_BackGround2] = m_spriteRender[Title_BackGround2]->GetMulColor();
	m_spriteMulColor[Title_Player] = m_spriteRender[Title_Player]->GetMulColor();

	//�t�F�[�h�C�������������̂Ŏ��ցB
	if ((m_spriteMulColor[Title_BackGround1].x >= FADEIN_FINISHED.x && m_spriteMulColor[Title_BackGround1].y >= FADEIN_FINISHED.y &&
		m_spriteMulColor[Title_BackGround1].z >= FADEIN_FINISHED.z) && (m_spriteMulColor[Title_BackGround2].x >= FADEIN_FINISHED.x &&
			m_spriteMulColor[Title_BackGround2].y >= FADEIN_FINISHED.y && m_spriteMulColor[Title_BackGround2].z >= FADEIN_FINISHED.z) &&
			(m_spriteMulColor[Title_Player].x >= FADEIN_FINISHED.x && m_spriteMulColor[Title_Player].y >= FADEIN_FINISHED.y &&
				m_spriteMulColor[Title_Player].z >= FADEIN_FINISHED.z))
	{
		//BGM�̍Đ�
		m_titleState = Title_Font;
	}
}
void Title::TitleFont()
{
	//�^�C�g�����A�{�^���̕\���B
	m_spriteFontTimer++;
	if (m_spriteFontTimer <= TITLENAME_FADE_TIME) {
		m_spriteRender[Title_Name]->DeltaAlpha(TITLENAME_FADE_DELTA_ALPHA);		//�^�C�g�����B
	}
	else if (m_spriteFontTimer > TITLENAME_FADE_TIME && m_spriteFontTimer <= TITLENAME_FADE_FONT_TIME) {
		m_spriteRender[Title_Start]->DeltaAlpha(STARTFONT_FADE_DELTA_ALPHA);		//�X�^�[�g�{�^���B
		m_spriteRender[Title_End]->DeltaAlpha(LOADFONT_FADE_DELTA_ALPHA);		//�G���h�{�^���B
		m_spriteRender[Title_SelectIcon]->DeltaAlpha(STARTFONT_FADE_DELTA_ALPHA);		//�I���A�C�R���B
	}
	else if (m_spriteFontTimer > TITLENAME_FADE_FONT_TIME) {
		m_titleState = Title_Select;
	}
}
void Title::TitleSelect()
{
	//�{�^���I���B
	if (g_pad[0]->IsTrigger(enButtonStart)) {
		//�Q�[���X�^�[�g�������̉����Đ�����B
		GameStartSE();
		m_titleState = Title_FadeOut;
	}
	else if (m_buttonState == Button_Load && g_pad[0]->IsTrigger(enButtonUp)) {
		//�I���������̉����Đ�����B
		SelectSE();
		//�u�͂��߂�v��I������B
		m_iconPos.y = SELECTICON_SET_START_POS;		//Y�����W�𓮂����B
		//�I�𒆂̃A�C�R����N���ɂ�����B
		m_spriteRender[Title_Start]->SetAlpha(BUTTON_SELECT);
		m_spriteRender[Title_End]->SetAlpha(BUTTON_NOT_SELECT);
		m_buttonState = Button_Start;
	}
	else if (m_buttonState == Button_Start && g_pad[0]->IsTrigger(enButtonDown)) {
		//�I���������̉����Đ�����B
		SelectSE();
		//�u�Â���v��I������B
		m_iconPos.y = SELECTICON_SET_END_POS;		//Y�����W�𓮂����B
		//�I�𒆂̃A�C�R����N���ɂ�����B
		m_spriteRender[Title_Start]->SetAlpha(BUTTON_NOT_SELECT);
		m_spriteRender[Title_End]->SetAlpha(BUTTON_SELECT);
		m_buttonState = Button_Load;
	}
	m_spriteRender[Title_SelectIcon]->SetPosition(m_iconPos);		//�I���A�C�R���̍��W��ݒ�B

}
void Title::TitleFadeOut()
{
	//�t�F�[�h�A�E�g�B
	if (fadeout[0] == nullptr) {
		fadeout[0] = NewGO<Fade>(0, "FadeOut");
	}
	fadeout[0]->FadeSet(m_spriteRender[Title_BackGround1], Fade::Fade_Out, FADEOUT_TIME);
	if (fadeout[1] == nullptr) {
		fadeout[1] = NewGO<Fade>(0, "FadeOut");
	}
	fadeout[1]->FadeSet(m_spriteRender[Title_BackGround2], Fade::Fade_Out, FADEOUT_TIME);
	if (fadeout[2] == nullptr) {
		fadeout[2] = NewGO<Fade>(0, "FadeOut");
	}
	fadeout[2]->FadeSet(m_spriteRender[Title_Player], Fade::Fade_Out, FADEOUT_TIME);
	if (fadeout[3] == nullptr) {
		fadeout[3] = NewGO<Fade>(0, "FadeOut");
	}
	fadeout[3]->FadeSet(m_spriteRender[Title_Name], Fade::Fade_Out, FADEOUT_TIME);
	if (fadeout[4] == nullptr) {
		fadeout[4] = NewGO<Fade>(0, "FadeOut");
	}
	fadeout[4]->FadeSet(m_spriteRender[Title_Start], Fade::Fade_Out, FADEOUT_TIME);
	if (fadeout[5] == nullptr) {
		fadeout[5] = NewGO<Fade>(0, "FadeOut");
	}
	fadeout[5]->FadeSet(m_spriteRender[Title_End], Fade::Fade_Out, FADEOUT_TIME);
	if (fadeout[6] == nullptr) {
		fadeout[6] = NewGO<Fade>(0, "FadeOut");
	}
	fadeout[6]->FadeSet(m_spriteRender[Title_SelectIcon], Fade::Fade_Out, FADEOUT_TIME);

	m_spriteMulColor[Title_BackGround1] = m_spriteRender[Title_BackGround1]->GetMulColor();
	m_spriteMulColor[Title_BackGround2] = m_spriteRender[Title_BackGround2]->GetMulColor();
	m_spriteMulColor[Title_Player] = m_spriteRender[Title_Player]->GetMulColor();
	m_spriteMulColor[Title_Name] = m_spriteRender[Title_Name]->GetMulColor();
	m_spriteMulColor[Title_Start] = m_spriteRender[Title_Start]->GetMulColor();
	m_spriteMulColor[Title_End] = m_spriteRender[Title_End]->GetMulColor();
	m_spriteMulColor[Title_SelectIcon] = m_spriteRender[Title_SelectIcon]->GetMulColor();


	//�t�F�[�h�A�E�g�����������̂Ŏ��ցB
	if ((m_spriteMulColor[Title_BackGround1].x <= FADEOUT_FINISHED.x && m_spriteMulColor[Title_BackGround1].y <= FADEOUT_FINISHED.y && m_spriteMulColor[Title_BackGround1].z <= FADEOUT_FINISHED.z) &&
		(m_spriteMulColor[Title_BackGround2].x <= FADEOUT_FINISHED.x && m_spriteMulColor[Title_BackGround2].y <= FADEOUT_FINISHED.y && m_spriteMulColor[Title_BackGround2].z <= FADEOUT_FINISHED.z) &&
		(m_spriteMulColor[Title_Player].x <= FADEIN_FINISHED.x && m_spriteMulColor[Title_Player].y <= FADEIN_FINISHED.y && m_spriteMulColor[Title_Player].z <= FADEIN_FINISHED.z) &&
		(m_spriteMulColor[Title_Name].x <= FADEOUT_FINISHED.x && m_spriteMulColor[Title_Name].y <= FADEOUT_FINISHED.y && m_spriteMulColor[Title_Name].z <= FADEOUT_FINISHED.z) &&
		(m_spriteMulColor[Title_Start].x <= FADEOUT_FINISHED.x && m_spriteMulColor[Title_Start].y <= FADEOUT_FINISHED.y && m_spriteMulColor[Title_Start].z <= FADEOUT_FINISHED.z) &&
		(m_spriteMulColor[Title_End].x <= FADEOUT_FINISHED.x && m_spriteMulColor[Title_End].y <= FADEOUT_FINISHED.y && m_spriteMulColor[Title_End].z <= FADEOUT_FINISHED.z) &&
		(m_spriteMulColor[Title_SelectIcon].x <= FADEOUT_FINISHED.x && m_spriteMulColor[Title_SelectIcon].y <= FADEOUT_FINISHED.y && m_spriteMulColor[Title_SelectIcon].z <= FADEOUT_FINISHED.z))
	{
		NewGO<Game>(0, "Game");
		DeleteGO(this);
	}


}
void Title::GameStartSE()
{
	CSoundSource* SE_gameStart = NewGO<CSoundSource>(0);
	SE_gameStart->Init(L"Assets/sound/SE_GameStart.wav");
	SE_gameStart->Play(false);
}
void Title::SelectSE()
{
	CSoundSource* SE_select = NewGO<CSoundSource>(0);
	SE_select->Init(L"Assets/sound/SE_MenuSelect.wav");
	SE_select->Play(false);
}
void Title::Update()
{
	TitleMoveBackGround();
	switch (m_titleState)
	{
	case Title::Title_FadeIn:
		TitleFadeIn();	//�t�F�[�h�C���B
		break;
	case Title::Title_Font:
		TitleFont();	//�^�C�g�����A�{�^���̕\���B
		break;
	case Title::Title_Select:
		TitleSelect();	//�{�^���I���B
		break;
	case Title::Title_FadeOut:
		TitleFadeOut();	//�t�F�[�h�A�E�g�B
		break;
	}


}

