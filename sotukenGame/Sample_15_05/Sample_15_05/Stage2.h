#pragma once
#include "IStage.h"
/// <summary>
/// ステージ2。
/// </summary>
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
	
};

