#pragma once
#include "Physics/Character/CharacterController.h"
#include "NightmareAnimation.h"
#include "EnBase.h"
#include "Physics/GhostObject.h"
#include "sound/SoundSource.h"
/// <summary>
/// ドラゴンナイトメアクラス
/// </summary>
class DrNightmare : public EnBase
{
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	DrNightmare();
	/// <summary>
	/// デストラクタ
	/// </summary>
	~DrNightmare();
	/// <summary>
	/// スタート関数。
	/// </summary>
	/// <returns></returns>
	bool Start();
	/// <summary>
	/// 更新関数。
	/// </summary>
	/// <returns></returns>
	void Update();

	/// <summary>
	/// プレイヤーに向かっていく関数。
	/// </summary>
	void Move();
	/// <summary>
	/// プレイヤーの方向に体を向ける関数。
	/// </summary>
	void Turn();
	/// <summary>
	/// 咆哮関数
	/// </summary>
	void Scream();
	/// <summary>
	/// 攻撃関数。
	/// </summary>
	void Attack();
	/// <summary>
	/// 爪攻撃関数。
	/// </summary>
	void ClawAttack();
	/// <summary>
	/// 角攻撃
	/// </summary>
	void HornAttack();
	/// <summary>
	/// 死。
	/// </summary>
	void Die();

	void ReceiveDamage(int damage) override
	{
		m_hp -= damage;
		m_status = GetDamage_state;
	}

	const int& GetDeathCount()const
	{
		return m_deathCount;
	}
private:
	/// <summary>
	/// エネミーのステート。
	/// </summary>
	enum {
		Idle_state,
		Walk_state,
		Run_state,
		Scream_state,
		Attack_state,
		ClawAttack_state,
		HornAttack_state,
		ClowAttack_state,
		GetDamage_state,
		Die_state
	};
	int					m_status = Idle_state;			//状態。
	int					changeTimer = 0;				//アニメーション変更タイマー。
	float				m_speedY = 0.0f;				//Y方向のスピード。
	int					m_animState = NightmAnimInfo::enNi_Idle01;			//アニメーションの状態。
	int					m_appearcolor = 0;				//配色No
	NightmareAnimation* m_nightmAnim = nullptr;           //アニメーションのロード。
	std::vector<int>	nightcolor = { 1,2,3,4 };		//配色決定。
	bool				m_isAttack = false;				//攻撃しているか。
	bool				m_ATKoff = false;				//一回の攻撃でダメージを一回だけ入れるためのフラグ。
	bool                m_isBasicATK = false;           //噛みつき攻撃の判定
	bool                m_isClawATK = false;            //爪攻撃の判定
	bool                m_isHornATK = false;            //角攻撃
	int                 m_isATKcount = 0;               //攻撃した回数のカウント
	int                 m_isClawATKcount = 0;           //爪攻撃のカウント
	int                 m_isHornATKcount = 0;           //角攻撃のカウント

	int					m_count = 0;					//攻撃が入るまでのカウント。
	bool                m_screamflag = true;            //咆哮フラグ
	GhostObject			m_ghostObj;						//ゴースト。
	int					m_deathCount = 0;				//死んだときのカウント。
	CSoundSource* SE_Haul = nullptr;

};

