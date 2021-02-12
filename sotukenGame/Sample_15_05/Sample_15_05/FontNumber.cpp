#include "stdafx.h"
#include "FontNumber.h"

FontNumber::FontNumber()
{

}
FontNumber::~FontNumber()
{
    for (int i = 0; i <= 9; i++) {
        if (m_spriteRender[i] != nullptr) {
            DeleteGO(m_spriteRender[i]);
            m_spriteRender[i] = nullptr;
        }
    }
}

bool FontNumber::Start()
{
    for (int i = 0; i <= 9; i++) {
        m_spriteRender[i] = nullptr;
    }
	return true;
}

void FontNumber::Update()
{
    int nm = m_displayNumber;
    //受け取った数字の桁数を求める
    int digit = (int)log10((double)m_displayNumber) + 1;
    //桁数分だけ各桁の数字を求める
    if (m_displayNumber != m_oldNum) {
        m_numberList.clear();
        m_spriteList.clear();
        for (int i = 0; i <= 9; i++) {
            if (m_spriteRender[i] != nullptr) {
                DeleteGO(m_spriteRender[i]);
                m_spriteRender[i] = nullptr;
            }
        }
        if (m_displayNumber <= 0) {
            m_spriteRender[0] = NewGO<FontSpriteRender>(0);
            m_filepass[0] = "Assets/image/Number/number0";
            m_filepass[0] += std::to_string(0);
            m_filepass[0] += ".DDS";
            m_spriteRender[0]->Init(m_filepass[0].c_str(), 100, 100);
            m_spriteList.push_back(m_spriteRender[0]);
        }
        else {
            for (int i = 0; i < digit; i++) {
                int Divide = std::pow(10, (i + 1));
                int Divide2 = std::pow(10, i);
                int remainder = nm % Divide / Divide2;
                nm = nm - remainder * Divide2;
                m_numberList.push_back(remainder);
            }
            for (int i = 0; i < m_numberList.size(); i++) {
                //表示するSpriteRender型のリストにプッシュバック。
                m_spriteRender[i] = NewGO<FontSpriteRender>(0);
                m_filepass[i] = "Assets/image/Number/number0";
                m_filepass[i] += std::to_string(m_numberList[i]);
                m_filepass[i] += ".DDS";
                m_spriteRender[i]->Init(m_filepass[i].c_str(), 100, 100);
                m_spriteList.push_back(m_spriteRender[i]);
            }
        }
    }
    m_oldNum = m_displayNumber;
   

}

void FontNumber::RenderFont()
{
    for (int i = 0; i < m_spriteList.size(); i++) {
        m_spriteList[i]->SetPosition(m_position);
        m_position.x += (50.0 * m_scale.Length());
        m_spriteList[i]->SetScale(m_scale);
		m_spriteList[i]->SetAlpha(m_alpha);
        m_spriteList[i]->Drow();
    }
}
