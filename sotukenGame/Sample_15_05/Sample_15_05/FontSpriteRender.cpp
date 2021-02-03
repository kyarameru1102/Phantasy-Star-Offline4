#include "stdafx.h"
#include "FontSpriteRender.h"

void FontSpriteRender::Init(const char* dds, float height, float width, const char* fx)
{
	m_spriteInitData.m_height = height;
	m_spriteInitData.m_width = width;
	m_spriteInitData.m_fxFilePath = fx;
	m_spriteInitData.m_ddsFilePath[0] = dds;
	m_sprite.Init(m_spriteInitData);
}

bool FontSpriteRender::Start()
{
    return true;
}

void FontSpriteRender::Update()
{
	m_sprite.Update(m_position, m_rotation, m_scale, m_pivot);
}

