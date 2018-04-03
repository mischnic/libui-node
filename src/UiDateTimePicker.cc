#include "../ui.h"
#include "ui-node.h"

UiDateTimePicker::UiDateTimePicker()
		: UiControl((uiControl*)uiNewDateTimePicker()) {}

INHERITS_CONTROL_METHODS(UiDateTimePicker)



UiTimePicker::UiTimePicker() : UiControl((uiControl*)uiNewTimePicker()) {}

INHERITS_CONTROL_METHODS(UiTimePicker)



UiDatePicker::UiDatePicker() : UiControl((uiControl*)uiNewDatePicker()) {}

INHERITS_CONTROL_METHODS(UiDatePicker)


