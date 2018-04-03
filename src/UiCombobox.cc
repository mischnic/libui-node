#include "../ui.h"
#include "ui-node.h"

UiCombobox::UiCombobox() : UiControl((uiControl*)uiNewCombobox()) {}

INHERITS_CONTROL_METHODS(UiCombobox)

IMPLEMENT_EVENT(UiCombobox, uiCombobox, onSelected, uiComboboxOnSelected)

void UiCombobox::append(const char* text) {
  uiComboboxAppend((uiCombobox*)getHandle(), text);
}

int UiCombobox::getSelected() {
  return uiComboboxSelected((uiCombobox*)getHandle());
}

void UiCombobox::setSelected(int n) {
  uiComboboxSetSelected((uiCombobox*)getHandle(), n);
  if (onSelectedCallback != NULL) {
    (*onSelectedCallback)();
  }
}


