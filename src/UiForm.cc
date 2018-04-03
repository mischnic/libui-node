#include "../ui.h"
#include "ui-node.h"

UiForm::UiForm() : UiControl((uiControl*)uiNewForm()) {}

void UiForm::append(const char* label, UiControl* c, bool stretchy) {
  uiFormAppend((uiForm*)getHandle(), label, c->getHandle(), stretchy);
}

void UiForm::deleteAt(int index) {
  uiFormDelete((uiForm*)getHandle(), index);
}

bool UiForm::getPadded() {
  return uiFormPadded((uiForm*)getHandle());
}

void UiForm::setPadded(bool padded) {
  uiFormSetPadded((uiForm*)getHandle(), padded);
}

INHERITS_CONTROL_METHODS(UiForm)


