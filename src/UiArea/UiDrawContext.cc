#include "../../ui.h"
#include "../ui-node.h"

UiDrawContext::UiDrawContext(uiDrawContext *ctx) {
	c = ctx;
}

void UiDrawContext::stroke(UiDrawPath *path, DrawBrush *b, DrawStrokeParams *p) {
	uiDrawStroke(c, path->getHandle(), b->toStruct(), p->toStruct());
}

void UiDrawContext::fill(UiDrawPath *path, DrawBrush *b) {
	uiDrawFill(c, path->getHandle(), b->toStruct());
}

void UiDrawContext::transform(UiDrawMatrix *m) {
	uiDrawTransform(c, m->getStruct());
}

void UiDrawContext::clip(UiDrawPath *path) {
	uiDrawClip(c, path->getHandle());
}

void UiDrawContext::save() {
	uiDrawSave(c);
}

void UiDrawContext::restore() {
	uiDrawRestore(c);
}

void UiDrawContext::text(double x, double y, DrawTextLayout *layout) {
	uiDrawText(c, x, y, layout->getHandle());
}




