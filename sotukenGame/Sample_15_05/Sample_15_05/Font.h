#pragma once
class Font
{
	/// <summary>
	/// �t�H���g
	/// </summary>
public:
	Font();
	~Font();
	/// <summary>
	/// �t�H���g��ݒ�B
	/// </summary>
	/// <param name="font">�����ւ������t�H���g</param>
	void SetFont(DirectX::SpriteFont* font) {
		m_spriteFont = font;
	}
	//�`��J�n�B
	void Begin();
	//�`��I���B�B
	void End();

	/// <summary>
	/// �`��
	/// </summary>
	/// <param name="text">�\���������e�L�X�g</param>
	/// <param name="position">���W</param>
	/// <param name="color">�J���[</param>
	/// <param name="rotation">��]</param>
	/// <param name="scale">�g�嗦</param>
	/// <param name="pivot">�s�{�b�g</param>
	void Draw(
		wchar_t const* text,
		const Vector2& position,
		const Vector4& color = { Vector4::White },
		float rotation = 0.0f,
		float scale = 1.0f,
		Vector2 pivot = { 0.5f, 0.5f }
	);
	/*!
	*@brief	�e�̃p�����[�^��ݒ�B
	*@param[in]	isDrawShadow		�e��`���H
	*@param[in]	shadowOffset		�e��`���Ƃ��̃s�N�Z���̃I�t�Z�b�g�ʁB
	*@param[in]	shadowColor			�e�̐F�B
	*/
	void SetShadowParam(bool isDrawShadow, float shadowOffset, const Vector4& shadowColor = { 0.2f,0.2f,0.2f,1.0f })
	{
		m_isDrawShadow = isDrawShadow;
		m_shadowOffset = shadowOffset;
		m_shadowColor = shadowColor;
	}

private:
	void InitTranslucentBlendState();
	ConstantBuffer		m_constantBufferGPU;	//GPU���̒萔�o�b�t�@�B
	CD3DX12_BLEND_DESC	blendDesc;				//�u�����h�X�e�[�g�̏��B

	DirectX::SpriteBatch*	m_spriteBatch = nullptr;	//�X�v���C�g�o�b�`�B
	DirectX::SpriteFont*	m_spriteFont = nullptr;		//�X�v���C�g�t�H���g�B

	const Vector4 ShadowColorDef = { 1.0f,1.0f,1.0f,1.0f };	//�e�̏����F

	bool m_isDrawShadow = false;						//!<�e�������H
	float m_shadowOffset = 0.0f;						//!<�e�������Ƃ��̃s�N�Z���̃I�t�Z�b�g�ʁB
	Vector4 m_shadowColor = ShadowColorDef;			//!<�e�̐F�B
	Matrix m_scaleMat;

};

