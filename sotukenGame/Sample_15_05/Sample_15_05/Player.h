#pragma once
#define _USE_MATH_DEFINES
class GameCamera;
class Weapon;
class PlayerStatusUI;
class PlayerAttackAnimation;
#include <math.h>
#include "Physics/Character/CharacterController.h"
#include "PlayerAnimation.h"

enum {
	//武器の状態。
	enBladState,//ブレイド状態。
	enSwordState,//ソード状態。
	//通常攻撃。攻撃の状態を調べるのに使う。
	enNormalState,
	//何ボタンで攻撃しているか。
	noAttack,//攻撃していない。
	attackX,//Xボタン。
	attackY,//Yボタン。
	attackS,//特殊攻撃。
	
};
/// <summary>
/// プレイヤークラス。
/// </summary>
class Player : public IGameObject
{
public:
	/// <summary>
	/// コンストラクタ。
	/// </summary>
	Player();
	/// <summary>
	/// デストラクタ。
	/// </summary>
	~Player();
	/// <summary>
	/// 音を出す。
	/// </summary>
	void Sound(const wchar_t* filePath);
	/// <summary>
	/// プレイヤーが経験値を取得する。ゲッターじゃないよ！！
	/// </summary>
	/// <param name="experiencePoint">倒した敵の経験値。</param>
	void GetExperiencePoint(const float experiencePoint);
	/// <summary>
	/// Y方向の移動。ジャンプや落下時の処理。
	/// </summary>
	void YDirMove();
	/// <summary>
	/// 武器変更。
	/// </summary>
	void WeaponChange();
	/// <summary>
	/// 移動スピードを設定する。
	/// </summary>
	void SetSpeed();
	/// <summary>
	/// 回避。
	/// </summary>
	void Avoidance();
	/// <summary>
	/// 回転の計算。
	/// </summary>
	void RotationCalculation();
	/// <summary>
	/// 回転。
	/// </summary>
	void Rotation();
	/// <summary>
	/// ダメージを受ける判定と死亡判定。
	/// </summary>
	void ReceiveDamageAndDeath();
	/// <summary>
	/// 死亡。
	/// </summary>
	//void Death();
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
	/// プレイヤーの座標を設定する。
	/// </summary>
	/// <param name="pos">座標。</param>
	void SetPosition(const Vector3& pos)
	{
		m_position = pos;
	}
	/// <summary>
	/// プレイヤーの座標を返す。
	/// </summary>
	/// <returns></returns>
	const Vector3& GetPosition() const
	{
		return m_position;
	}
	/// <summary>
	/// プレイヤーのレベルを返す。
	/// </summary>
	/// <returns></returns>
	const int GetPlayerLevel() const
	{
		return m_playerLevel;
	}
	/// <summary>
	/// HPを減らす。
	/// </summary>
	void ReceiveDamage(int damage)
	{
		m_playerHP -= damage;
	}
	/// <summary>
	/// 最大HPを設定。
	/// </summary>
	/// <param name="maxHp"></param>
	void SetMaxHP(const float maxHp)
	{
		m_maxPlayerHP = maxHp;
	}
	/// <summary>
	/// 最大HPを返す。
	/// </summary>
	/// <returns></returns>
	const float GetMaxHP() const
	{
		return m_maxPlayerHP;
	}
	/// <summary>
	/// HPを設定。
	/// </summary>
	/// <param name="hp">HP</param>
	void SetHP(const float hp)
	{
		m_playerHP = hp;
	}
	/// <summary>
	/// HPを返す。
	/// </summary>
	/// <returns></returns>
	const float GetHP() const
	{
		return m_playerHP;
	}
	/// <summary>
	/// ダメージを受ける前のHPを設定する。
	/// </summary>
	/// <param name="beforeHp"></param>
	void SetBeforeHp(const float beforeHp)
	{
		m_beforeHp = beforeHp;
	}
	/// <summary>
	/// ダメージを受ける前のHPを返す。
	/// </summary>
	/// <returns></returns>
	const float GetBeforeHp() const
	{
		return m_beforeHp;
	}
	/// <summary>
	/// SPを設定する。
	/// </summary>
	/// <param name="sp"></param>
	void SetSP(const float sp)
	{
		m_playerSP = sp;
	}
	/// <summary>
	/// SPを返す。
	/// </summary>
	/// <returns></returns>
	const float GetSP() const
	{
		return m_playerSP;
	}
	/// <summary>
	/// 攻撃力を設定する。
	/// </summary>
	/// <param name="power">攻撃力。</param>
	void SetAtaackPow(const float power)
	{
		m_ataackPow = power;
	}
	/// <summary>
	/// 攻撃力を返す。
	/// </summary>
	/// <returns></returns>
	const float GetmAtaackPow() const
	{
		return m_ataackPow;
	}
	/// <summary>
	/// プレイヤーのスキンモデルレンダーのインスタンスを返す。
	/// </summary>
	/// <returns></returns>
	SkinModelRender& GetPlayerSkinModelRemder()
	{
		return *m_playerSkinModel;
	}
	/// <summary>
	/// 武器のムーブスピードを返す。
	/// </summary>
	/// <returns></returns>
	const Vector3& GetWeaponMoveSpeed() const
	{
		return m_weaponMoveSpeed;
	}
	/// <summary>
	/// 攻撃アニメーションフラグを設定する。
	/// </summary>
	/// <param name="flag">フラグ。</param>
	void SetAttackAnimationFlag(const bool flag)
	{
		m_attackAnimationFlag = flag;
	}
	/// <summary>
	/// 攻撃アニメーションフラグを返す。
	/// </summary>
	/// <returns></returns>
	const bool GetAttackAnimationFlag() const
	{
		return m_attackAnimationFlag;
	}
	/// <summary>
	/// プレイヤーのキャラコンを返す。
	/// </summary>
	/// <returns></returns>
	CharacterController* GetCharacterController()
	{
		return &m_charaCon;
	}
	/// <summary>
	/// 死亡フラグを返す。
	/// </summary>
	/// <returns></returns>
	const bool GetDeathFlag() const
	{
		return m_deathFlag;
	}
	/// <summary>
	/// 武器の状態を設定する。
	/// falseならブレイド状態にする。
	/// trueならソード状態にする。
	/// </summary>
	/// <param name="falseOrTrue"></param>
	void SetWeaponState(const bool falseOrTrue)
	{
		if (falseOrTrue != true) {
			m_weaponState = enBladState;
		}
		else {
			m_weaponState = enSwordState;
		}
	}
	/// <summary>
	/// 武器の状態を返す。
	/// </summary>
	/// <returns></returns>
	const int GetWeaponState() const
	{
		return m_weaponState;
	}
	/// <summary>
	/// 攻撃しているフラグを設定する。
	/// </summary>
	/// <param name="flag"></param>
	void SetAttackFlag(const bool flag)
	{
		m_attackFlag = flag;
	}
	/// <summary>
	/// 攻撃しているフラグを返す。
	/// </summary>
	/// <returns></returns>
	const bool GetAttackFlag() const
	{
		return m_attackFlag;
	}
	/// <summary>
	/// 攻撃中、プレイヤーの向きを変えるフラグを設定する。
	/// </summary>
	/// <param name="flag"></param>
	void SetAttackAngleFlag(const bool flag)
	{
		m_attackAngleFlag = flag;
	}
	/// <summary>
	/// アニメーション番号を設定する。
	/// </summary>
	/// <param name="animState">アニメーション番号。</param>
	void SetAnimState(const int animState)
	{
		m_animState = animState;
	}
	/// <summary>
	/// アニメーション番号を返す。
	/// </summary>
	/// <returns></returns>
	const int GetAnimState() const
	{
		return m_animState;
	}
	/// <summary>
	/// ムーブスピードを設定する。
	/// </summary>
	/// <param name="moveSpeed"></param>
	void SetMoveSpeed(Vector3 moveSpeed)
	{
		m_moveSpeed = moveSpeed;
	}
	/// <summary>
	/// ムーブスピードを返す。
	/// </summary>
	/// <returns></returns>
	const Vector3& GetMoveSpeed() const
	{
		return m_moveSpeed;
	}
	/// <summary>
	/// 方向を返す。
	/// </summary>
	/// <returns></returns>
	const Vector3& GetDir() const
	{
		return m_dir;
	}
	/// <summary>
	/// なんの攻撃ボタンを押したかを設定する。
	/// </summary>
	/// <param name="AXY"></param>
	void SetPressedAttackButton(const int AXY)
	{
		m_pressedAttackButton = AXY;
	}
	/// <summary>
	/// なんの攻撃ボタンを押したかを返す。
	/// </summary>
	/// <returns></returns>
	const int GetPressedAttackButton() const
	{
		return m_pressedAttackButton;
	}
	/// <summary>
	/// 特殊攻撃のフラグを設定する。
	/// </summary>
	/// <param name="flag">フラグ。</param>
	void SetSpecialAttackFlag(const bool flag)
	{
		m_specialAttackFlag = flag;
	}
	/// <summary>
	/// 特殊攻撃のフラグを返す。
	/// </summary>
	/// <returns></returns>
	const bool GetSpecialAttackFlag() const
	{
		return m_specialAttackFlag;
	}
	/// <summary>
	/// 攻撃の状態を設定する。
	/// </summary>
	/// <param name="attackState">状態。</param>
	void SetAttackState(const int attackState)
	{
		m_attackState = attackState;
	}
	/// <summary>
	/// 攻撃の状態を返す。
	/// </summary>
	/// <returns></returns>
	const int GetAttackState() const
	{
		return m_attackState;
	}
private:
	PlayerAnimation* m_playerAnim = nullptr;
	SkinModelRender* m_playerSkinModel = nullptr;
	GameCamera* m_gameCam = nullptr;
	PlayerStatusUI* m_playerStatusUI = nullptr;
	PlayerAttackAnimation* m_playerAttackAnim = nullptr;
	Vector3 m_position = Vector3::Zero;//座標。
	Vector3 m_moveSpeed = Vector3::Zero;//ムーブスピード。
	Quaternion m_rotation = Quaternion::Identity; //回転クォータニオン。
	CharacterController m_charaCon;//キャラコン。
	bool m_changeAnimFlag = false;
	int m_changeAnimTimer = 0;
	int m_changeAnimTime = 35;//武器を変えるのにかかるフレーム。
	int m_animState = enStay_blad; //アニメーションの状態。
	int m_weaponState = enBladState;//武器の状態。
	bool m_jumpFlag = false;//ジャンプしてるかどうかのフラグ。
	float m_speedY = 0.0f;//Y方向のスピード。
	float m_magnificationSpeed = 5.0f; //ムーブスピードの倍率。
	float m_complementaryFlame = 10.0f;//アニメーション補完時間。フレーム数。
	int jumpStartTimer = 40;
	float m_playerHP = 100.0f;      //HP。
	float m_maxPlayerHP = 100.0f; //プレイヤーの最大HP。
	float m_beforeHp = 0.0f; //ダメージを受ける前のHP。
	float m_playerSP = 100.0f;      //SP。
	float m_maxPlayerSP = 100.0f; //プレイヤーの最大SP。
	float m_ataackPow = 10.0f; //攻撃力。
	Weapon* m_weapon[2] = { nullptr, nullptr };
	bool m_attackAnimationFlag = false;
	float m_angle = 0.0f;//回転角度。
	bool m_attackAngleFlag = false; //攻撃から次の行動へうつす時にプレイヤーの向きを決めるフラグ。
	Vector3 m_weaponMoveSpeed = Vector3::Zero; //武器のムーブスピード。
	Vector3 m_oldPosition = Vector3::Zero; //前の座標。
	bool m_kaihiFlag = false; //回避フラグ。
	int m_kaihiTimer = 0;
	int m_playerLevel = 1; //プレイヤーのレベル。
	int m_levelToOpen = 10; //開放するレベル。
	float m_experiencePoint = 10.0f;  //経験値。
	float m_nextExperiencePoint = 10.0f; //次に必要な経験値。
	Vector3 m_dir = Vector3::Zero; //向いている方向。
	int m_attackAnimNumX = 1;//Xボタンの攻撃アニメーションの数。
	int m_attackAnimNumY = 1;//Yボタンの攻撃アニメーションの数。
	bool m_attackFlag = false; //攻撃しているフラグ。
	bool m_doNothingFlag = false; //何もしていないフラグ。
	bool m_deathFlag = false; //死亡フラグ。
	int m_pressedAttackButton = noAttack; //押した攻撃ボタン。
	bool m_specialAttackFlag = false; //特殊攻撃フラグ。
	int m_attackState = enNormalState; //攻撃の状態。

	bool m_soundFlag = false;
	int m_deathSoundTime = 0;
	int m_deathSoundTimer = 0;
};

