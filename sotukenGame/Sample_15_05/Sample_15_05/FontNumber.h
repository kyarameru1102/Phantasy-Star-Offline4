#pragma once
#include "FontSpriteRender.h"


/*�g������
* �X�^�[�g�֐���New����
	FontNumber*�@m_test = NewGO<FontNumber>(0);

* �A�b�v�f�[�g�֐��ł��낢��ݒ肵�Ă��������B
	int num = 100;
	m_test->SetDisplayNum(num);
	m_test->SetPosition(Vector3(450.0f,-210.0f,0.0f));
	m_test->SetScale(Vector3(0.3f, 0.3f, 0.3f));

	num�ɂ�HP��������U���͂�����������Ă��������B
	����ŕ\������܂��B
	�����Ƃ��̓X�^�[�g�֐���New�������Delete���Ă��������B
	*/

/// <summary>
/// �t�H���g(������p)�N���X�B
/// </summary>
class FontNumber : public IGameObject
{
public:
	/// <summary>
	/// �R���X�g���N�^�B
	/// </summary>
	FontNumber();
	/// <summary>
	/// �f�X�g���N�^�B
	/// </summary>
	~FontNumber();
	/// <summary>
	/// �X�^�[�g�֐��B
	/// </summary>
	/// <returns></returns>
	bool Start() override;
	/// <summary>
	/// �X�V�֐��B
	/// </summary>
	void Update() override;
	/// <summary>
	/// �t�H���g�`��B
	/// </summary>
	void RenderFont() override;

	void InitDisplayNumConfig(float num,Vector3 pos = Vector3::Zero,Vector3 scl = Vector3::One)
	{
		if (num <= 0) {
			m_displayNumber = 0;
		}
		else {
			m_displayNumber = num;
		}
		m_position = pos;
		m_scale = scl;
	}
	void SetDisplayNum(float num) {
		if (num <= 0) {
			m_displayNumber = 0;
		}
		else {
			m_displayNumber = num;
		}
	}
	void SetPosition(Vector3 pos) {
		m_position = pos;
	}
	void SetScale(Vector3 scl) {
		m_scale = scl;
	}
private:
	std::vector<int>			m_numberList;
	std::vector<FontSpriteRender*>	m_spriteList;
	Vector3						m_position;		//���W�B
	Vector3						m_scale = Vector3(0.5f,0.5f,0.5f);			//�T�C�Y�B
	int							m_displayNumber = 0;			//�\�������������B
	int							m_oldNum = -1;
	FontSpriteRender* m_spriteRender[10];
	std::string m_filepass[10];
};

