#include "../ui.h"
#include "ui-node.h"

UiColorButton::UiColorButton() : UiControl((uiControl*)uiNewColorButton()) {}

INHERITS_CONTROL_METHODS(UiColorButton)

IMPLEMENT_EVENT(UiColorButton, uiColorButton, onChanged, uiColorButtonOnChanged)

void UiColorButton::setColor(Color color) {
  uiColorButtonSetColor((uiColorButton*)getHandle(), color.getR(), color.getG(),
                        color.getB(), color.getA());
  if (onChangedCallback != NULL) {
    (*onChangedCallback)();
  }
}

Color UiColorButton::getColor() {
  double r = 0.0;
  double g = 0.0;
  double b = 0.0;
  double a = 0.0;

  uiColorButtonColor((uiColorButton*)getHandle(), &r, &g, &b, &a);

  return Color(r, g, b, a);
}


