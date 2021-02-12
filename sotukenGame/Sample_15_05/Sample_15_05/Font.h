#pragma once
class Font
{
	/// <summary>
	/// フォント
	/// </summary>
public:
	Font();
	~Font();
	/// <summary>
	/// フォントを設定。
	/// </summary>
	/// <param name="font">差し替えたいフォント</param>
	void SetFont(DirectX::SpriteFont* font) {
		m_spriteFont = font;
	}
	//描画開始。
	void Begin();
	//描画終了。。
	void End();

	/// <summary>
	/// 描画
	/// </summary>
	/// <param name="text">表示したいテキスト</param>
	/// <param name="position">座標</param>
	/// <param name="color">カラー</param>
	/// <param name="rotation">回転</param>
	/// <param name="scale">拡大率</param>
	/// <param name="pivot">ピボット</param>
	void Draw(
		wchar_t const* text,
		const Vector2& position,
		const Vector4& color = { Vector4::White },
		float rotation = 0.0f,
		float scale = 1.0f,
		Vector2 pivot = { 0.5f, 0.5f }
	);
	/*!
	*@brief	影のパラメータを設定。
	*@param[in]	isDrawShadow		影を描く？
	*@param[in]	shadowOffset		影を描くときのピクセルのオフセット量。
	*@param[in]	shadowColor			影の色。
	*/
	void SetShadowParam(bool isDrawShadow, float shadowOffset, const Vector4& shadowColor = { 0.2f,0.2f,0.2f,1.0f })
	{
		m_isDrawShadow = isDrawShadow;
		m_shadowOffset = shadowOffset;
		m_shadowColor = shadowColor;
	}

private:
	void InitTranslucentBlendState();
	ConstantBuffer		m_constantBufferGPU;	//GPU側の定数バッファ。
	CD3DX12_BLEND_DESC	blendDesc;				//ブレンドステートの情報。

	DirectX::SpriteBatch*	m_spriteBatch = nullptr;	//スプライトバッチ。
	DirectX::SpriteFont*	m_spriteFont = nullptr;		//スプライトフォント。

	const Vector4 ShadowColorDef = { 1.0f,1.0f,1.0f,1.0f };	//影の初期色

	bool m_isDrawShadow = false;						//!<影を書く？
	float m_shadowOffset = 0.0f;						//!<影を書くときのピクセルのオフセット量。
	Vector4 m_shadowColor = ShadowColorDef;			//!<影の色。
	Matrix m_scaleMat;

};

