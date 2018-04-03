#include "../ui.h"
#include "ui-node.h"

UiSlider::UiSlider(int min, int max)
    : UiControl((uiControl*)uiNewSlider(min, max)) {}

UiSlider::UiSlider() : UiControl((uiControl*)uiNewSlider(0, 100)) {}

int UiSlider::getValue() {
  return uiSliderValue((uiSlider*)getHandle());
}

void UiSlider::setValue(int value) {
  uiSliderSetValue((uiSlider*)getHandle(), value);
  if (onChangedCallback != NULL) {
    (*onChangedCallback)();
  }
}

IMPLEMENT_EVENT(UiSlider, uiSlider, onChanged, uiSliderOnChanged)

INHERITS_CONTROL_METHODS(UiSlider)


