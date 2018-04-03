#include "../ui.h"
#include "ui-node.h"

UiProgressBar::UiProgressBar() : UiControl((uiControl*)uiNewProgressBar()) {}

INHERITS_CONTROL_METHODS(UiProgressBar)

void UiProgressBar::setValue(int val) {
  value = val;
  uiProgressBarSetValue((uiProgressBar*)getHandle(), value);
}

int UiProgressBar::getValue() {
  return value;
}


