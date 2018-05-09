//
//  VisibleRect.cpp
//  CarrotFantasy
//
//  Created by student on 18/5/7.
//
//

#include "VisibleRect.hpp"
USING_NS_CC;
Rect VisibleRect::m_visibleRect;
void VisibleRect::lazyInit()
{
    m_visibleRect = Director::getInstance()->getOpenGLView()->getVisibleRect();
}

Rect VisibleRect::getVisibleRect()
{
    lazyInit();
    return m_visibleRect;
}

Vec2 VisibleRect::left()
{
    lazyInit();
    return Vec2(m_visibleRect.origin.x, m_visibleRect.origin.y+m_visibleRect.size.height/2);
}

Vec2 VisibleRect::right()
{
    lazyInit();
    return Vec2(m_visibleRect.origin.x+m_visibleRect.size.width, m_visibleRect.origin.y+m_visibleRect.size.height/2);
}

Vec2 VisibleRect::top()
{
    lazyInit();
    return Vec2(m_visibleRect.origin.x+m_visibleRect.size.width/2, m_visibleRect.origin.y+m_visibleRect.size.height);
}

Vec2 VisibleRect::bottom()
{
    lazyInit();
    return Vec2(m_visibleRect.origin.x+m_visibleRect.size.width/2, m_visibleRect.origin.y);
}

Vec2 VisibleRect::center()
{
    lazyInit();
    return Vec2(m_visibleRect.origin.x+m_visibleRect.size.width/2, m_visibleRect.origin.y+m_visibleRect.size.height/2);
}

Vec2 VisibleRect::leftTop()
{
    lazyInit();
    return Vec2(m_visibleRect.origin.x, m_visibleRect.origin.y+m_visibleRect.size.height);
}

Vec2 VisibleRect::rightTop()
{
    lazyInit();
    return Vec2(m_visibleRect.origin.x+m_visibleRect.size.width, m_visibleRect.origin.y+m_visibleRect.size.height);
}

Vec2 VisibleRect::leftBottom()
{
    lazyInit();
    return m_visibleRect.origin;
}

Vec2 VisibleRect::rightBottom()
{
    lazyInit();
    return Vec2(m_visibleRect.origin.x+m_visibleRect.size.width, m_visibleRect.origin.y);
}