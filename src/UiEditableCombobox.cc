#include "../ui.h"
#include "ui-node.h"

UiEditableCombobox::UiEditableCombobox()
    : UiControl((uiControl*)uiNewEditableCombobox()) {}

INHERITS_CONTROL_METHODS(UiEditableCombobox)

IMPLEMENT_EVENT(UiEditableCombobox,
                uiEditableCombobox,
                onChanged,
                uiEditableComboboxOnChanged)

void UiEditableCombobox::append(const char* text) {
  uiEditableComboboxAppend((uiEditableCombobox*)getHandle(), text);
}

void UiEditableCombobox::setText(const char* text) {
  uiEditableComboboxSetText((uiEditableCombobox*)getHandle(), text);
  if (onChangedCallback != NULL) {
    (*onChangedCallback)();
  }
}

const char* UiEditableCombobox::getText() {
  return uiEditableComboboxText((uiEditableCombobox*)getHandle());
}


