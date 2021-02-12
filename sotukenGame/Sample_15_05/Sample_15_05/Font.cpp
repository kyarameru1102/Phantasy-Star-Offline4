#include "stdafx.h"
#include "Font.h"


Font::Font()
{
	m_spriteBatch = g_graphicsEngine->GetSpriteBatch();
	m_spriteFont = g_graphicsEngine->GetSpriteFont();

	m_scaleMat.MakeScaling(
		{
			FRAME_BUFFER_W / static_cast<float>(FRAME_BUFFER_W),
			FRAME_BUFFER_H / static_cast<float>(FRAME_BUFFER_H),
			1.0f
		}
	);
}


Font::~Font()
{
}
void Font::InitTranslucentBlendState() {

	//例のごとく、作成するブレンドステートの情報を設定する。
	CD3DX12_DEFAULT defaultSettings;
	//デフォルトセッティングで初期化する。
	CD3DX12_BLEND_DESC InitblendDesc(defaultSettings);

	//αブレンディングを有効にする。
	InitblendDesc.RenderTarget[0].BlendEnable = true;

	//ソースカラーのブレンディング方法を指定している。
	//ソースカラーとはピクセルシェーダ―からの出力を指している。
	//この指定では、ソースカラーをSRC(rgba)とすると、
	//最終的なソースカラーは下記のように計算される。
	//最終的なソースカラー = SRC.rgb × SRC.a・・・・・・　①
	InitblendDesc.RenderTarget[0].SrcBlend = D3D12_BLEND_SRC_ALPHA;

	//ディスティネーションカラーのブレンディング方法を指定している。
	//ディスティネーションカラーとは、
	//すでに描き込まれているレンダリングターゲットのカラーを指している。
	//この指定では、ディスティネーションカラーをDEST(rgba)、
	//ソースカラーをSRC(RGBA)とすると、最終的なディスティネーションカラーは
	//下記のように計算される。
	//最終的なディスティネーションカラー = DEST.rgb × (1.0f - SRC.a)・・・・・②
	InitblendDesc.RenderTarget[0].DestBlend = D3D12_BLEND_INV_SRC_ALPHA;

	//最終的にレンダリングターゲットに描き込まれるカラーの計算方法を指定している。
	//この指定だと、①＋②のカラーが書き込まれる。
	//つまり、最終的にレンダリングターゲットに描き込まれるカラーは
	//SRC.rgb × SRC.a + DEST.rgb × (1.0f - SRC.a)
	//となる。
	InitblendDesc.RenderTarget[0].BlendOp = D3D12_BLEND_OP_ADD;

	//この設定で、ブレンドステートを作成すると
	//半透明合成を行えるブレンドステートが作成できる。
	blendDesc= InitblendDesc;
}

void Font::Begin()
{
	//ステートの設定
	//InitTranslucentBlendState();

	m_spriteBatch->Begin(
		g_graphicsEngine->GetCommandList(),
		DirectX::SpriteSortMode_Deferred,
		m_scaleMat
	);
}
void Font::End()
{
	m_spriteBatch->End();
}

void Font::Draw(wchar_t const* text,const Vector2& position,const Vector4& color,float rotation,float scale,Vector2 pivot)
{
	if (text == nullptr) {
		return;
	}
	pivot.y = 1.0f - pivot.y;
	DirectX::XMFLOAT2 tkFloat2Zero(0, 0);
	//座標系をスプライトと合わせる。
	Vector2 pos = position;
	float frameBufferHalfWidth = FRAME_BUFFER_W * 0.5f;
	float frameBufferHalfHeight = FRAME_BUFFER_H * 0.5f;
	pos.x += frameBufferHalfWidth;
	pos.y = -pos.y + frameBufferHalfHeight;


	if (m_isDrawShadow) {
		//影を書く。
		Vector2 offsetTbl[] = {
			{ m_shadowOffset , 0.0f },
		{ -m_shadowOffset , 0.0f },
		{ 0.0f , m_shadowOffset },
		{ 0.0f , -m_shadowOffset },

		{ m_shadowOffset ,  m_shadowOffset },
		{ m_shadowOffset ,  -m_shadowOffset },
		{ -m_shadowOffset , m_shadowOffset },
		{ -m_shadowOffset , -m_shadowOffset },
		};
		for (auto offset : offsetTbl) {
			DirectX::FXMVECTOR xmv = DirectX::XMLoadFloat4(&m_shadowColor.vec);
			Vector2 sPos = pos;
			sPos.x += offset.x;
			sPos.y += offset.y;
			m_spriteFont->DrawString(
				m_spriteBatch,
				text,
				sPos.vec,
				xmv,
				rotation,
				DirectX::XMFLOAT2(pivot.x, pivot.y),
				scale
			);
		}

	}

	End();

	Begin();

	m_spriteFont->DrawString(
		m_spriteBatch,
		text,
		pos.vec,
		color,
		rotation,
		DirectX::XMFLOAT2(pivot.x, pivot.y),
		scale
	);

}

