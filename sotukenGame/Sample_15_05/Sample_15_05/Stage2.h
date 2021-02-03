#pragma once
#include "IStage.h"

/// <summary>
/// ステージ2。
/// </summary>

class DrUsurper;
class Game;
class Stage2 : public IStage
{
public:
	Stage2();
	~Stage2();

	/// <summary>
	/// 更新関数が呼ばれる前に呼ばれる開始関数。
	/// </summary>
	/// <returns>trueを返すと一度だけ呼ばれる</returns>
	bool Start()override;

	/// <summary>
	/// 更新関数。
	/// </summary>
	void Update()override;
private:
	int ENEMY_NUM = 2;		//エネミーの数。
	//enum {
	//	ENEMY_NUM = 2		//エネミーの数。
	//};
	//
	//DrUsurper* m_drUsurper[ENEMY_NUM] = { nullptr }; 
};

