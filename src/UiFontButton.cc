#include "../ui.h"
#include "ui-node.h"

UiFontButton::UiFontButton() : UiControl((uiControl*)uiNewFontButton()) {}

INHERITS_CONTROL_METHODS(UiFontButton)

IMPLEMENT_EVENT(UiFontButton, uiFontButton, onChanged, uiFontButtonOnChanged)

DrawTextFont* UiFontButton::getFont() {
	return new DrawTextFont(uiFontButtonFont((uiFontButton*)getHandle()));
}


