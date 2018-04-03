#include "../ui.h"
#include "ui-node.h"

UiLabel::UiLabel(const char* text) : UiControl((uiControl*)uiNewLabel(text)) {}
UiLabel::UiLabel() : UiControl((uiControl*)uiNewLabel("")) {}

INHERITS_CONTROL_METHODS(UiLabel)

void UiLabel::setText(const char* text) {
	uiLabelSetText((uiLabel*)getHandle(), text);
}

const char* UiLabel::getText() {
	return uiLabelText((uiLabel*)getHandle());
}


