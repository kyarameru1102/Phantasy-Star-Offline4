#include "stdafx.h"
#include "Menu.h"
#include "Game.h"
#include "sound/SoundSource.h"

Menu::Menu()
{
}

Menu::~Menu()
{
	MenuSelectSE();
	for (int i = 0; i < en_menuUINum; i++) {
		DeleteGO(m_spriteRender[i]);
	}
}

bool Menu::Start()
{
	MenuSelectSE();

	//�摜�̏������B
	m_spriteRender[en_menuUIMenu] = NewGO<SpriteRender>(0);
	m_spriteRender[en_menuUIMenu]->Init("Assets/image/menu.DDS", 400, 304);
	m_spriteRender[en_menuUIMenu]->SetPosition(m_spritePosition[en_menuUIMenu]);

	m_spriteRender[en_menuUIArrowButton] = NewGO<SpriteRender>(0);
	m_spriteRender[en_menuUIArrowButton]->Init("Assets/image/arrow.DDS", 20.0f, 20.0f);
	m_spritePosition[en_menuUIArrowButton] = { 90.0f, 50.0f, 0.0f };

	m_spriteRender[en_menuUIReturnTitle] = NewGO<SpriteRender>(0);
	m_spriteRender[en_menuUIReturnTitle]->Init("Assets/image/returnTitle.DDS", 50.0f, 150.0f);
	m_spritePosition[en_menuUIReturnTitle] = { 0.0f, -50.0f, 0.0f };
	m_spriteRender[en_menuUIReturnTitle]->SetPosition(m_spritePosition[en_menuUIReturnTitle]);

	m_spriteRender[en_menuUIStatusMoji] = NewGO<SpriteRender>(0);
	m_spriteRender[en_menuUIStatusMoji]->Init("Assets/image/statusMoji.DDS", 50.0f, 150.0f);
	m_spritePosition[en_menuUIStatusMoji] = { 0.0f, 50.0f, 0.0f };
	m_spriteRender[en_menuUIStatusMoji]->SetPosition(m_spritePosition[en_menuUIStatusMoji]);

	return true;
}

void Menu::Update()
{
	//���̈ړ��B
	ArrowButtonMove();
	//���j���[�̍��ڂ�I������B
	MenuSelect();

	//���W��ݒ�B
	m_spriteRender[en_menuUIArrowButton]->SetPosition(m_spritePosition[en_menuUIArrowButton]);
}

void Menu::ArrowButtonMove()
{
	//�����㉺�œ������B
	if (g_pad[0]->IsTrigger(enButtonUp) && m_spritePosition[en_menuUIArrowButton].y <= 0.0f && m_playerStatus == nullptr) {
		m_spritePosition[en_menuUIArrowButton].y = m_spritePosition[en_menuUIStatusMoji].y;
		MenuSelectSE();
	}
	if (g_pad[0]->IsTrigger(enButtonDown) && m_spritePosition[en_menuUIArrowButton].y >= 0.0f && m_playerStatus == nullptr) {
		m_spritePosition[en_menuUIArrowButton].y = m_spritePosition[en_menuUIReturnTitle].y;
		MenuSelectSE();
	}
}

void Menu::MenuSelect()
{
	if (g_pad[0]->IsTrigger(enButtonA) && m_spritePosition[en_menuUIArrowButton].y == m_spritePosition[en_menuUIReturnTitle].y) {
		MenuSelectSE();
		//�^�C�g���ɖ߂�B
		m_title = NewGO<Title>(0);
		DeleteGO(this);
		m_game = FindGO<Game>("Game");
		DeleteGO(m_game);
	}
	if (g_pad[0]->IsTrigger(enButtonA) && m_spritePosition[en_menuUIArrowButton].y == m_spritePosition[en_menuUIStatusMoji].y && m_playerStatus == nullptr) {
		MenuSelectSE();
		//�v���C���[�̃X�e�[�^�X��\���B
		m_playerStatus = NewGO<PlayerStatus>(0, "playerStatus");
	}
}

void Menu::MenuSelectSE()
{
	CSoundSource* SE_MenuSelect = NewGO<CSoundSource>(0);
	SE_MenuSelect->Init(L"Assets/sound/SE_MenuSelect.wav");
	SE_MenuSelect->Play(false);
}
