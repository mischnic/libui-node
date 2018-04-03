#include "../ui.h"
#include "ui-node.h"

IMPLEMENT_EVENT(UiCheckbox, uiCheckbox, onToggled, uiCheckboxOnToggled)

UiCheckbox::UiCheckbox(const char* text)
    : UiControl((uiControl*)uiNewCheckbox(text)) {}
UiCheckbox::UiCheckbox() : UiControl((uiControl*)uiNewCheckbox("")) {}

INHERITS_CONTROL_METHODS(UiCheckbox)

void UiCheckbox::setText(const char* text) {
  uiCheckboxSetText((uiCheckbox*)getHandle(), text);
}

const char* UiCheckbox::getText() {
  return uiCheckboxText((uiCheckbox*)getHandle());
}

void UiCheckbox::setChecked(bool checked) {
  uiCheckboxSetChecked((uiCheckbox*)getHandle(), checked);
  if (onToggledCallback != NULL) {
    (*onToggledCallback)();
  }
}

bool UiCheckbox::getChecked() {
  return uiCheckboxChecked((uiCheckbox*)getHandle());
}


