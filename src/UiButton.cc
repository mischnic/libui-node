#include "../ui.h"
#include "ui-node.h"

UiButton::UiButton(const char* text)
		: UiControl((uiControl*)uiNewButton(text)) {}
UiButton::UiButton() : UiControl((uiControl*)uiNewButton("")) {}

INHERITS_CONTROL_METHODS(UiButton)

void UiButton::setText(const char* text) {
	uiButtonSetText((uiButton*)getHandle(), text);
}

const char* UiButton::getText() {
	return uiButtonText((uiButton*)getHandle());
}

IMPLEMENT_EVENT(UiButton, uiButton, onClicked, uiButtonOnClicked)


