#include "../ui.h"
#include "ui-node.h"

UiEntryBase::UiEntryBase(uiControl* hnd) : UiControl(hnd) {}

void UiEntryBase::setText(const char* text) {
  uiEntrySetText((uiEntry*)getHandle(), text);
  if (onChangedCallback != NULL) {
    (*onChangedCallback)();
  }
}

std::string UiEntryBase::getText() {
  char *src = uiEntryText((uiEntry*)getHandle());
  std::string string(src);
  uiFreeText(src);
  return string;
}

static void UiEntryBase__call(uiEntry *e, void *data) {
  (*((void (*)())data))();
}

void UiEntryBase::onChanged(void (*cb)()){
  // onChangedCallback = cb;
  uiEntryOnChanged((uiEntry*)getHandle(), UiEntryBase__call, (void*)cb);
}

void UiEntryBase::setReadOnly(bool readOnly) {
  uiEntrySetReadOnly((uiEntry*)getHandle(), readOnly);
}

bool UiEntryBase::getReadOnly() {
  return uiEntryReadOnly((uiEntry*)getHandle());
}

// IMPLEMENT_EVENT(UiEntryBase, uiEntry, onChanged, uiEntryOnChanged)

UiEntry::UiEntry() : UiEntryBase((uiControl*)uiNewEntry()) {}

INHERITS_CONTROL_METHODS(UiEntry)
INHERITS_ENTRY_METHODS(UiEntry)


// UiPasswordEntry::UiPasswordEntry()
//     : UiEntryBase((uiControl*)uiNewPasswordEntry()) {}

// INHERITS_CONTROL_METHODS(UiPasswordEntry)
// INHERITS_ENTRY_METHODS(UiPasswordEntry)

// UiSearchEntry::UiSearchEntry() : UiEntryBase((uiControl*)uiNewSearchEntry()) {}

// INHERITS_CONTROL_METHODS(UiSearchEntry)
// INHERITS_ENTRY_METHODS(UiSearchEntry)







