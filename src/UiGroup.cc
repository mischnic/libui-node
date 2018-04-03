#include "../ui.h"
#include "ui-node.h"

UiGroup::UiGroup(const char* text) : UiControl((uiControl*)uiNewGroup(text)) {}
UiGroup::UiGroup() : UiControl((uiControl*)uiNewGroup("")) {}

void UiGroup::setChild(UiControl* control) {
  uiGroupSetChild((uiGroup*)getHandle(), control->getHandle());
}

bool UiGroup::getMargined() {
  return uiGroupMargined((uiGroup*)getHandle());
}

void UiGroup::setMargined(bool margined) {
  uiGroupSetMargined((uiGroup*)getHandle(), margined);
}

const char* UiGroup::getTitle() {
  return uiGroupTitle((uiGroup*)getHandle());
}

void UiGroup::setTitle(const char* title) {
  uiGroupSetTitle((uiGroup*)getHandle(), title);
}

INHERITS_CONTROL_METHODS(UiGroup)


