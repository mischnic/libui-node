#include "../ui.h"
#include "ui-node.h"

UiTab::UiTab() : UiControl((uiControl*)uiNewTab()) {}

INHERITS_CONTROL_METHODS(UiTab)

void UiTab::append(const char* text, UiControl* child) {
  uiTabAppend((uiTab*)getHandle(), text, child->getHandle());
}

void UiTab::insertAt(const char* name, int before, UiControl* child) {
  uiTabInsertAt((uiTab*)getHandle(), name, before, child->getHandle());
}

void UiTab::deleteAt(int index) {
  uiTabDelete((uiTab*)getHandle(), index);
}

int UiTab::numPages() {
  return uiTabNumPages((uiTab*)getHandle());
}

bool UiTab::getMargined(int page) {
  return uiTabMargined((uiTab*)getHandle(), page);
}

void UiTab::setMargined(int page, bool margined) {
  uiTabSetMargined((uiTab*)getHandle(), page, margined);
}


