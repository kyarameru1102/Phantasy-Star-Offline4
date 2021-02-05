#pragma once
const enum AttackAnimTime {
	enAttackTime01_blad,
	enAttackTime02_blad,
	enAttackTime03_blad,
	enAttackTime04_blad,
	enAttackTime05_blad,
	enAttackTime06_blad,
	enAttackTime07_blad,
	enAttackTime08_blad,
	enAttackTime09_blad,
	enAttackTime01_sword,
	enAttackTime02_sword,
	enAttackTime03_sword,
	enAttackTime04_sword,
	enAttackTime05_sword,
	enAttackTime06_sword,
	enAttackTime07_sword,
	enAttackTime08_sword,
	enAttackTime09_sword,
	enAttackTimeNum
};
class Player;
class PlayerAnimation;
class EnBase;
class PlayerAttackAnimation : public IGameObject
{
public:
	PlayerAttackAnimation();
	~PlayerAttackAnimation();
	/// <summary>
	/// 攻撃アニメーションの時間を設定。
	/// </summary>
	void SetAttackAnimationTime();
	/// <summary>
	/// 敵を攻撃されていない状態にする。
	/// </summary>
	void MakeTheEnemyUnattacked();
	/// <summary>
	/// 通常攻撃。
	/// </summary>
	void NormalAttack();
	/// <summary>
	/// ブレイド状態の特殊攻撃。
	/// </summary>
	void SpecialAttackStateBlad();
	/// <summary>
	/// ソード状態の特殊攻撃。
	/// </summary>
	void SpecialAttackStateSword();

	void AttackFlag(int attackTime01_blad, int* attackAnimNum, int attackTime01_sword);
	/// 攻撃終了関数。
	/// </summary>
	void AttackEnd();
	/// <summary>
	/// 攻撃。
	/// </summary>
	void Attack();

	bool Start() override;

	void Update() override;

	/// <summary>
	/// 攻撃番号を返す。
	/// </summary>
	/// <returns></returns>
	const int GetAttackNum() const
	{
		return m_attackNum;
	}
	/// <summary>
	/// 元になる攻撃力を設定する。
	/// </summary>
	/// <param name="power"></param>
	void SetBaseAttackPow(const int power)
	{
		m_baseAttackPow = power;
	}
private:
	Player* m_player = nullptr;
	PlayerAnimation* m_playerAnim = nullptr;
	int attackTimer = 0; //攻撃タイマー。
	int m_attackAnimNum = 0; //XボタンかYボタンの攻撃アニメーションの数。
	int m_attackAnimationTimeNum = 0; //攻撃アニメーションの時間を入れた配列の番号。
	int m_totalAttackAnimationTime = 0; //攻撃アニメーションの合計の時間。
	int m_continuousAttackTime = 0;  //連撃する際のアニメーションの合計の時間。
	int m_attackNum = 0; //攻撃番号。
	int m_attackAnimationTime[enAttackTimeNum];//攻撃アニメーションの時間を設定する配列。
	int m_switchAttackTime[enAttackTimeNum];//攻撃の切り替えの時間を設定する配列。
	bool m_specialAttackStartFlag = false;//特殊攻撃のスタートフラグ。
	float m_speed = 50.0f;
	int m_timer = 0;
	int m_accumulateTimer = 0; //溜めるタイマー。
	int m_accumulateTime = 60; //溜める時間。
	int m_magnification = 1; //倍率。
	float m_baseAttackPow = 0.0f;//元になる攻撃力。
	bool m_setPowerFlag = false;//攻撃力設定するとき使うフラグ。
	bool m_swordSpecialAttackAnim2Or3 = false;//ソード状態の特殊攻撃で、
	                                           //2のアニメーションならfalse,
	                                           //3のアニメーションならtrueを返す。


	bool m_soundFlag = false;
};

