#pragma once
/// <summary>
/// �^�C�g���V�[���B
/// </summary>
class Fade;
class Title : public IGameObject
{
public:
	/// <summary>
	/// �R���X�g���N�^�B
	/// </summary>
	Title();
	/// <summary>
	/// �f�X�g���N�^�B
	/// </summary>
	~Title();
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
	enum TitleState {
		Title_FadeIn,		//�t�F�[�h�C���B
		Title_Font,			//�^�C�g�����A�{�^���̕\���B
		Title_Select,		//�{�^���I���B
		Title_FadeOut,		//�t�F�[�h�A�E�g�B
	};

	//�I���{�^��
	enum EButton {
		Button_Start,
		Button_Load
	};

private:
	void TitleMoveBackGround();		//�w�i�̈ړ������B

	void TitleFadeIn();				//�t�F�[�h�C���B
	void TitleFont();				//�^�C�g�����A�{�^���̕\���B
	void TitleSelect();				//�{�^���I���B
	void TitleFadeOut();			//�t�F�[�h�A�E�g�B

private:
	const enum {
		Title_BackGround1,				//�w�i1�B
		Title_BackGround2,				//�w�i2�B		
		Title_Player,					//�v���C���[�C���X�g�B
		Title_Name,						//�^�C�g�����B
		Title_Start,					//�X�^�[�g�{�^���B
		Title_End,						//�G���h�{�^���B
		Title_SelectIcon,				//�I�𒆃A�C�R���B
		Title_Num						//�^�C�g����Sprite���B
	};

	SpriteRender* m_spriteRender[Title_Num] = { nullptr };		//�X�v���C�g�����_�[�B
	Vector4 m_spriteMulColor[Title_Num] = { Vector4::White };		//�X�v���C�g�̏�Z�J���[�B

	TitleState m_titleState = Title_FadeIn;			//��ԁB
	EButton m_buttonState = Button_Start;			//�I�𒆂̃{�^����ԁB
private:

	//Sprite�ݒ���W�B
	const Vector3 TITLE_BACKGROUND1_POS = { 0.0f,0.0f,0.0f };		//�w�i1�̏����ݒ���W�B
	const Vector3 TITLE_BACKGROUND2_POS = { 1280.0f,0.0f,0.0f };	//�w�i2�̏����ݒ���W�B
	const Vector3 TITLE_PLAYER_POS = { -450.0f,0.0f,0.0f };	//�v���C���[�̏����ݒ���W�B
	const Vector3 TITLE_NAME_POS = { 300.0f,200.0f,0.0f };			//�^�C�g�����̏����ݒ���W�B
	const Vector3 TITLE_STARTBUTTON_POS = { 315.0f,-125.0f,0.0f };	//�X�^�[�g�{�^���̏����ݒ���W�B
	const Vector3 TITLE_ENDBUTTON_POS = { 325.0f,-225.0f,0.0f };	//�G���h�{�^���̏����ݒ���W�B
	const Vector3 TITLE_SELECTICON_POS = { 425.0f,-130.0f,0.0f };	//�Z���N�g�A�C�R���̏����ݒ���W�B

	//����
	const Vector4 FADEIN_FINISHED = { 1.0f,1.0f,1.0f,1.0f };	//�t�F�[�h�C�����I���l�B
	const Vector4 FADEOUT_FINISHED = { 0.0f,0.0f,0.0f,1.0f };	//�t�F�[�h�A�E�g���I���l�B
	const Vector4 TITLE_SET_MULCOLOR = { 0.0f,0.0f,0.0f,1.0f };	//������Z�J���[�B
	const float SET_ALPHA = 0.0f;								//���������x�B

	//background�֘A
	const float FADEIN_TIME = 1.0f;					//�t�F�[�h�C�������鎞�ԁB�P�ʁF�t���[���B
	const float m_backTexXPos = 1280.0f;				//�񖇖ڂ�X���W�̈ʒu�B
	Vector3 m_backTexpos1 = Vector3::Zero;				//�w�i�̍��W1�B
	Vector3 m_backTexpos2 = Vector3::Zero;				//�w�i�̍��W2�B
	const float m_backMove = -0.1f;						//�w�i�̈ړ����x�B

	//�{�^���֘A
	Vector3	m_iconPos = Vector3::Zero;		//���W�B
	int m_spriteFontTimer = 0;			//�����p�^�C�}�[�B
	const float TITLENAME_FADE_TIME = 120.0f;					//�^�C�g�������t�F�[�h�����鎞�ԁB
	const float TITLENAME_FADE_FONT_TIME = 180.0f;				//�t�H���g���t�F�[�h�����鎞�ԁB
	const float TITLENAME_FADE_DELTA_ALPHA = 1.0f / 120.0f;		//�^�C�g�����̓����x��ψʂ�����l�B
	const float STARTFONT_FADE_DELTA_ALPHA = 1.0f / 60.0f;		//�u�͂��߂�v�̓����x��ψʂ�����l�B
	const float LOADFONT_FADE_DELTA_ALPHA = 0.3f / 46.0f;		//�u�Â���v�̓����x��ψʂ�����l�B
	const float SELECTICON_SET_START_POS = -130.0f;				//�Z���N�g�A�C�R���̃X�^�[�g�{�^���I�𒆂�Y���̍��W�B
	const float SELECTICON_SET_END_POS = -230.0f;				//�Z���N�g�A�C�R���̃G���h�{�^���I�𒆂�Y���̍��W�B
	const float BUTTON_SELECT = 1.0f;							//�I�𒆂̃{�^���B
	const float BUTTON_NOT_SELECT = 0.3f;						//�I���O�̃{�^���B

	//�t�F�[�h�A�E�g�֘A�B
	const float FADEOUT_TIME = 1.0f;							//�t�F�[�h�A�E�g�����鎞�ԁB�P�ʁF�t���[���B
	Fade* fadein[3] = { nullptr };
	Fade* fadeout[7] = { nullptr };
};