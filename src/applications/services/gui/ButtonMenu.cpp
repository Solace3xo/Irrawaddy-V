#include "ButtonMenu.h"
#include <TFT_eSPI.h>

using namespace Applications::Services::GUI;

void ButtonMenu::render(std::shared_ptr<TFT_eSPI> tft)
{
    // Draw button border
    tft->drawRoundRect(this->_x, this->_y, TFT_HEIGHT - 20, 25, 8, this->_borderColor);

    // Draw button fill
    if (this->isSelected())
        tft->fillRoundRect(this->_x, this->_y, TFT_HEIGHT - 20, 25, 8, this->_backgroundColor);

    if (this->isSelected())
        tft->setTextColor(this->_selectedTextColor);
    else
        tft->setTextColor(this->_textColor);

    tft->setTextSize(2);
    tft->setTextDatum(TL_DATUM);

    tft->drawString(this->_text, this->_x + 10, this->_y + 5);
}

void ButtonMenu::setBorderColor(int color)
{
    this->_borderColor = color;
}

void ButtonMenu::setBackgroundColor(int color)
{
    this->_backgroundColor = color;
}

void ButtonMenu::setTextColor(int color)
{
    this->_textColor = color;
}

void ButtonMenu::setSelectedTextColor(int color)
{
    this->_selectedTextColor = color;
}

void ButtonMenu::setSize(int width, int height)
{
    this->_width = width;
    this->_height = height;
}

void ButtonMenu::setPosition(int x, int y)
{
    this->_x = x;
    this->_y = y;
}

void ButtonMenu::setText(String text)
{
    this->_text = text;
}

void ButtonMenu::setSelected(bool selected)
{
    this->_selected = selected;
}

bool ButtonMenu::isSelected()
{
    return this->_selected;
}

void ButtonMenu::click(std::shared_ptr<AppContext> appContext)
{
    if (this->_onClick != nullptr)
        this->_onClick(appContext);
}

void ButtonMenu::setOnClick(Delegates::OnExecute onClick)
{
    this->_onClick = onClick;
}
