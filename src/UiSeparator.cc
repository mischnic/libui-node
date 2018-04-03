#include "../ui.h"
#include "ui-node.h"

UiHorizontalSeparator::UiHorizontalSeparator()
		: UiControl((uiControl*)uiNewHorizontalSeparator()) {}

INHERITS_CONTROL_METHODS(UiHorizontalSeparator)



UiVerticalSeparator::UiVerticalSeparator()
		: UiControl((uiControl*)uiNewVerticalSeparator()) {}

INHERITS_CONTROL_METHODS(UiVerticalSeparator)


