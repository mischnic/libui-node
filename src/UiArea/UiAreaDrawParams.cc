#include "../../ui.h"
#include "../ui-node.h"


UiAreaDrawParams::UiAreaDrawParams(uiAreaDrawParams *params) {
	p = params;
}

UiDrawContext * UiAreaDrawParams::getContext() {
	return new UiDrawContext(p->Context);
}

// TODO: make readony properties
//

double UiAreaDrawParams::getAreaWidth() {
	return p->AreaWidth;
}

double UiAreaDrawParams::getAreaHeight() {
	return p->AreaHeight;
}

double UiAreaDrawParams::getClipX() {
	return p->ClipX;
}

double UiAreaDrawParams::getClipY() {
	return p->ClipY;
}

double UiAreaDrawParams::getClipWidth() {
	return p->ClipWidth;
}

double UiAreaDrawParams::getClipHeight() {
	return p->ClipHeight;
}



