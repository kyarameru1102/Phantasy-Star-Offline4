#pragma once
#include "FontSpriteRender.h"


/*使い方例
* スタート関数でNewして
	FontNumber*　m_test = NewGO<FontNumber>(0);

* アップデート関数でいろいろ設定してください。
	int num = 100;
	m_test->SetDisplayNum(num);
	m_test->SetPosition(Vector3(450.0f,-210.0f,0.0f));
	m_test->SetScale(Vector3(0.3f, 0.3f, 0.3f));

	numにはHPだったり攻撃力だったりを入れてください。
	これで表示されます。
	消すときはスタート関数でNewしたやつをDeleteしてください。
	*/

/// <summary>
/// フォント(数字専用)クラス。
/// </summary>
class FontNumber : public IGameObject
{
public:
	/// <summary>
	/// コンストラクタ。
	/// </summary>
	FontNumber();
	/// <summary>
	/// デストラクタ。
	/// </summary>
	~FontNumber();
	/// <summary>
	/// スタート関数。
	/// </summary>
	/// <returns></returns>
	bool Start() override;
	/// <summary>
	/// 更新関数。
	/// </summary>
	void Update() override;
	/// <summary>
	/// フォント描画。
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

	void SetAlpha(float alpha) {
		m_alpha = alpha;
	}

private:
	std::vector<int>			m_numberList;
	std::vector<FontSpriteRender*>	m_spriteList;
	Vector3						m_position;		//座標。
	Vector3						m_scale = Vector3(0.5f,0.5f,0.5f);			//サイズ。
	int							m_displayNumber = 0;			//表示したい数字。
	int							m_oldNum = -1;
	float						m_alpha = 1.0f;
	FontSpriteRender* m_spriteRender[10];
	std::string m_filepass[10];
};

