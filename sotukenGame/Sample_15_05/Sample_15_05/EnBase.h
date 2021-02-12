#pragma once
#include "Physics/Character/CharacterController.h"
/// <summary>
/// 敵の強さの段階を示す。
/// 数値が大きくなるほど強くなる。
/// </summary>
enum EnPower {
	en1,
	en2,
	en3,
	en4
};
#include "sound/SoundSource.h"
#include "Player.h"
/// <summary>
/// 敵基底クラス
/// </summary>
class Player;
class Game;
class EnBase : public IGameObject
{
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	EnBase();
	/// <summary>
	/// デストラクタ
	/// </summary>
	~EnBase();
	/// <summary>
	/// 音を出す。
	/// </summary>
	void Sound(const wchar_t* filePath)
	{
		//SEを再生する。
		if (m_soundFlag == false)
		{
			if (m_player->GetDeathFlag() == false)
			{
				CSoundSource* SE_Recovery = NewGO<CSoundSource>(0);
				SE_Recovery->Init(filePath);
				SE_Recovery->Play(false);
			}
			m_soundFlag = true;
		}
	}
	void WalkSound(const wchar_t* filePath)
	{
		//SEを再生する。
		if (m_soundFlag == false)
		{
			CSoundSource* SE_Recovery = NewGO<CSoundSource>(0);
			SE_Recovery->Init(filePath);
			SE_Recovery->Play(true);

			//m_soundFlag = true;
		}
	}
	/// <summary>
	/// 座標を返す。
	/// </summary>
	/// <returns></returns>
	const Vector3& GetPosition() const
	{
		return m_position;
	}
	/// <summary>
	/// HPを返す。
	/// </summary>
	/// <returns></returns>
	const float& GetHP() const
	{
		return m_hp;
	}
	/// <summary>
	/// 攻撃を受けたかの判定を返す。
	/// </summary>
	/// <returns></returns>
	const bool& GetHit() const
	{
		return m_gethit;
	}
	/// <summary>
	/// 攻撃を受けたら切り替える。
	/// </summary>
	/// <returns></returns>
	void SetHit(bool sethit)
	{
		m_gethit = sethit;
	}

	/// <summary>
	/// ダメージを受けてHPを減らす関数。
	/// </summary>
	/// <param name="damage">int ダメージ量</param>
	virtual void ReceiveDamage(int damage)
	{
		m_hp -= damage;
	}
	/// <summary>
	/// HPを与える関数。
	/// 主に回復等で使う。
	/// </summary>
	/// <param name="hp">int 回復量</param>
	void ReceiveHP(float hp)
	{
		m_hp += hp;
	}

	/// <summary>
	/// キャラコンを返す。
	/// </summary>
	CharacterController* GetCharaCon()
	{
		return &m_charaCon;
	}
	/// <summary>
	/// 座標を設定
	/// </summary>
	/// <param name="pos"></param>
	void SetPosition(Vector3 pos)
	{
		m_position = pos;
	}
	/// <summary>
	/// 拡大率を設定
	/// </summary>
	/// <param name="scale"></param>
	void SetScale(Vector3 scale)
	{
		m_scale = scale;
	}
	/// <summary>
	/// HPを設定
	/// </summary>
	/// <param name="hp"></param>
	void SetHp(float hp)
	{
		m_hp = hp;
	}
	bool GetDeath()const
	{
		return m_death;
	}
	Vector3 GetDirection()const
	{
		return m_dir;
	}
	/// <summary>
	/// 攻撃力を設定する。
	/// </summary>
	/// <param name="attackpow"></param>
	void SetAttackPower(const float attackpow)
	{
		m_attackPower = attackpow;
	}
	/// <summary>
	/// 攻撃力を返す。
	/// </summary>
	/// <returns></returns>
	const float GetAttackPower() const
	{
		return m_attackPower;
	}
	/// <summary>
	/// 攻撃力の倍率を設定。
	/// </summary>
	/// <param name="agnificationAP"></param>
	void SetMagnificationAP(const float magnificationAP)
	{
		m_magnificationAP = magnificationAP;
	}
	/// <summary>
	/// 攻撃力の倍率を返す。
	/// </summary>
	/// <returns></returns>
	const float GetMagnificationAP() const
	{
		return m_magnificationAP;
	}
	/// <summary>
	/// HPの倍率を設定。
	/// </summary>
	/// <param name="magnificationHP"></param>
	void SetMagnificationHP(const float magnificationHP)
	{
		m_magnificationHP = magnificationHP;
	}
	/// <summary>
	/// HPの倍率を返す。
	/// </summary>
	/// <returns></returns>
	const float GetMagnificationHP() const
	{
		return m_magnificationHP;
	}
	/// <summary>
	/// 基礎ステータスの数値を設定する。
	/// </summary>
	/// <param name="basicStatusNum"></param>
	void SetBasicStatusNum(const int basicStatusNum)
	{
		m_basicStatusNum = basicStatusNum;
	}
	/// <summary>
	/// 敵のいるステージの番号を設定。
	/// </summary>
	/// <param name="stageNumber"></param>
	void SetStageNumber(const int stageNumber)
	{
		m_stageNumber = stageNumber;
	}
	/// <summary>
	/// 敵のいるステージの番号を返す。
	/// </summary>
	/// <returns></returns>
	const int GetStageNumber() const
	{
		return m_stageNumber;
	}
protected:
	SkinModelRender*	m_skinModelRender = nullptr;			//スキンモデル
	Vector3				m_position = Vector3::Zero;				//座標
	Vector3				m_scale = Vector3::One;					//拡大率
	Quaternion			m_rotation = Quaternion::Identity;		//回転
	Vector3				m_movespeed = Vector3::Zero;			//移動速度
	Vector3             m_oldpos = Vector3::Zero;                //古い座標
	CharacterController m_charaCon;								//キャラコン。
	float				m_hp = 50.0f;						    //HP
	float               m_magnificationHP = 1.0f;               //HPの倍率。
	Player*				m_player = nullptr;						//プレイヤー。
	Game*               m_game = nullptr;                       //Game
	Vector3				m_toPlayer = Vector3::Zero;				//プレイヤーまでのベクトル。
	bool				m_death = false;
	bool                m_gethit = false;                       //プレイヤーからの攻撃判定
	Vector3				m_dir, m_ghostPos;
	float               m_attackPower = 0.0f;                   //攻撃力。Start関数で初期化する。
	float               m_magnificationAP = 1.0f;               //攻撃力の倍率。

	int                 m_basicStatusNum = 0;                   //基礎ステータスの数値。EnPowerの数値のいずれかが入る。
	int                 m_stageNumber = 0;                      //敵のいるステージの番号。

	bool m_soundFlag = false;
	
};


