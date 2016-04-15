#include "animatedgraphicelement.h"
#include <SFML/Graphics.hpp>

AnimatedGraphicElement::AnimatedGraphicElement(const std::vector<sf::IntRect>& clipRects, sf::Texture &image, int x, int y, int w, int h)
    :GraphicElement(image, x, y, w, h, false)
{
    m_clipRects = clipRects;
    m_currentClipRect = 0;
    m_nb_steps = 5;
    m_current_step = 0;
    setTextureRect(m_clipRects[m_currentClipRect]);
}
AnimatedGraphicElement::AnimatedGraphicElement(const AnimatedGraphicElement& copy):
    GraphicElement(copy)
{
    m_clipRects = copy.m_clipRects;
    m_currentClipRect = copy.m_currentClipRect;
    m_nb_steps = copy.m_nb_steps;
    m_current_step = copy.m_current_step;
    setTextureRect(m_clipRects[m_currentClipRect]);
}

void AnimatedGraphicElement::draw(sf::RenderWindow *window) {
    m_current_step++;
    if(m_current_step>=m_nb_steps)
    {
        m_current_step=0;
        m_currentClipRect = m_currentClipRect % m_clipRects.size()+1;
        setTextureRect(m_clipRects[m_currentClipRect-1]);
    }
    window->draw(*this);

}

//void resize(int w, int h) {
////    sf::FloatRect dd =
////    float width_factor = w / bb.width;
////    float height_factor = h / bb.height;
////    setScale(width_factor, height_factor);
//}
