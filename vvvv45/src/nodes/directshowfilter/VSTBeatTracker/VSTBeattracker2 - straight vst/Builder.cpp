//Builder.cpp - VSTGUI editor file, automatically generated by VSTGUI Builder

#include <stdio.h>
#include "Builder.h"

//****remember to include your plugin's header file here****

enum
{
    kBack = 128,
    kbutton00,
};

//--------------------------------
Builder::Builder(AudioEffect *effect) : AEffGUIEditor(effect)
{
    Signal = 0;
    Adjust = 0;
    Reset = 0;

    hbutton00 = 0;

    hBack  = new CBitmap(kBack);

    rect.left   = 0;
    rect.top    = 0;
    rect.right  = (short)hBack->getWidth();
    rect.bottom = (short)hBack->getHeight();
}

//--------------------------------
Builder::~Builder()
{
    if(hBack)
    {
        if(hBack->getNbReference()<=1)
        {
            hBack->forget();
            hBack = 0;
        }
        else
            hBack->forget();
    }
}

//--------------------------------
long Builder::open(void *ptr)
{
    CRect size, temp;
    CPoint point;

    AEffGUIEditor::open(ptr);

    hbutton00 = new CBitmap(kbutton00);

    size(0, 0, hBack->getWidth(), hBack->getHeight());
    frame = new CFrame(size, ptr, this);
    frame->setBackground(hBack);

    //--Signal--------
    size(6, 14, (6+16), (14+16));
    Signal = new COnOffButton(size, this, 0, hbutton00);
    Signal->setValue(effect->getParameter(0));
    Signal->setTransparency(0);
    frame->addView(Signal);

    //--Adjust--------
    size(26, 14, (26+16), (14+16));
    Adjust = new COnOffButton(size, this, 0, hbutton00);
    Adjust->setValue(effect->getParameter(0));
    Adjust->setTransparency(0);
    frame->addView(Adjust);

    //--Reset--------
    size(46, 14, (46+16), (14+16));
    Reset = new COnOffButton(size, this, 0, hbutton00);
    Reset->setValue(effect->getParameter(0));
    Reset->setTransparency(0);
    frame->addView(Reset);

    setKnobMode(kLinearMode);

    if(hbutton00)
        hbutton00->forget();

    return true;
}

//--------------------------------
void Builder::close()
{
    delete frame;
    frame = 0;

}

//--------------------------------
void Builder::setParameter(long index, float value)
{
    if(!frame)
        return;

    switch(index)
    {
    case 0:
        if(Signal)
            Signal->setValue(effect->getParameter(index));
        break;
    case 0:
        if(Adjust)
            Adjust->setValue(effect->getParameter(index));
        break;
    case 0:
        if(Reset)
            Reset->setValue(effect->getParameter(index));
        break;
    }
    postUpdate();
}

//--------------------------------
void Builder::valueChanged(CDrawContext* context, CControl* control)
{
    char tempch[64];
				    long tag = control->getTag();

    switch(tag)
    {
    case 0:
        effect->setParameterAutomated(tag, control->getValue());
        break;
    case 0:
        effect->setParameterAutomated(tag, control->getValue());
        break;
    case 0:
        effect->setParameterAutomated(tag, control->getValue());
        break;
    }
}

//--------------------------------
void Builder::idle()
{
    AEffGUIEditor::idle();

}
			