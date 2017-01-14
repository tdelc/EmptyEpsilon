#ifndef GUI2_SLIDER_H
#define GUI2_SLIDER_H

#include "gui2_element.h"
#include "gui2_label.h"

class GuiSlider : public GuiElement
{
public:
    typedef std::function<void(float value)> func_t;
protected:
    struct TSnapPoint
    {
        float value;
        float range;
    };
    float min_value;
    float max_value;
    float value;
    std::vector<TSnapPoint> snap_points;
    func_t func;
    GuiLabel* overlay_label;
public:
    GuiSlider(GuiContainer* owner, string id, float min_value, float max_value, float start_value, func_t func);

    virtual void onDraw(sf::RenderTarget& window);
    virtual bool onMouseDown(sf::Vector2f position);
    virtual void onMouseDrag(sf::Vector2f position);
    virtual void onMouseUp(sf::Vector2f position);
    
    GuiSlider* clearSnapValues();
    GuiSlider* addSnapValue(float value, float range);
    GuiSlider* setValue(float value);
    GuiSlider* setRange(float min, float max);
    GuiSlider* addOverlay();
    float getValue();
};

class GuiSlider2D : public GuiElement
{
public:
public:
    typedef std::function<void(sf::Vector2f value)> func_t;
protected:
    struct TSnapPoint
    {
        sf::Vector2f value;
        sf::Vector2f range;
    };
    sf::Vector2f min_value;
    sf::Vector2f max_value;
    sf::Vector2f value;
    std::vector<TSnapPoint> snap_points;
    func_t func;
public:
    GuiSlider2D(GuiContainer* owner, string id, sf::Vector2f min_value, sf::Vector2f max_value, sf::Vector2f start_value, func_t func);

    virtual void onDraw(sf::RenderTarget& window);
    virtual bool onMouseDown(sf::Vector2f position);
    virtual void onMouseDrag(sf::Vector2f position);
    virtual void onMouseUp(sf::Vector2f position);
    
    GuiSlider2D* clearSnapValues();
    GuiSlider2D* addSnapValue(sf::Vector2f value, sf::Vector2f range);
    GuiSlider2D* setValue(sf::Vector2f value);
    sf::Vector2f getValue();
};

#endif//GUI2_SLIDER_H
