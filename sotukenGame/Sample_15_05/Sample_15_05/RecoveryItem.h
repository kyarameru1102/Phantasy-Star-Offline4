#pragma once
#include "Physics/GhostObject.h"

/// <summary>
/// プレイヤーのHPを回復するアイテムクラス。
/// </summary>
class RecoveryItem : public IGameObject
{
public:
	RecoveryItem();
	~RecoveryItem();

	/// <summary>
	/// 更新関数が呼ばれる前に呼ばれる開始関数。
	/// </summary>
	/// <returns>trueを返すと一度だけ呼ばれる</returns>
	bool Start()override;

	/// <summary>
	/// 更新関数。
	/// </summary>
	void Update()override;

	/// <summary>
	/// 回復アイテムの座標を設定。
	/// </summary>
	/// <param name="pos">設定する座標</param>
	void SetPosition(const Vector3& pos)
	{
		m_position = pos;
	}

	/// <summary>
	/// 回復アイテムの座標を返す。
	/// </summary>
	/// <returns>回復アイテムの座標</returns>
	const Vector3& GetPosition() const
	{
		return m_position;
	}

	/// <summary>
	/// プレイヤーのHPを回復する関数。
	/// </summary>
	void RecoveryPlayerHP();

private:
	SkinModelRender* m_recoveryItemModel = nullptr;		//スキンモデル。
	Vector3 m_position = Vector3::Zero;					//座標。
	Quaternion m_rotation = Quaternion::Identity;		//回転。
	Vector3 m_scale = Vector3::One;						//拡大率。

	GhostObject m_ghostObject;							//ゴーストオブジェクト。
	Vector3 m_ghostScale = { 50.0f, 50.0f, 50.0f };		//ゴーストオブジェクトの拡大率。
};

