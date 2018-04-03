#include "../../ui.h"
#include "../ui-node.h"


void Draw (UiAreaHandler *self, uiArea *area, uiAreaDrawParams *params) {
	UiAreaDrawParams *pp = new UiAreaDrawParams(params);
	(*self->draw)(areasMap[area], pp);
}

void MouseEvent (UiAreaHandler *self, uiArea *area, uiAreaMouseEvent *event) {
	UiAreaMouseEvent *ev = new UiAreaMouseEvent(event);
	(*(self->mouseEvent))(areasMap[area], ev);
}

void MouseCrossed (UiAreaHandler *self, uiArea *area, int left) {
	(*(self->mouseCrossed))(areasMap[area], left);
}

void DragBroken (UiAreaHandler *self, uiArea *area) {
	(*(self->dragBroken))(areasMap[area]);
}

int KeyEvent (UiAreaHandler *self, uiArea *area, uiAreaKeyEvent *event) {
	UiAreaKeyEvent * ev = new UiAreaKeyEvent(event);
	return (self->keyEvent)(areasMap[area], ev);
}

UiAreaHandler * UiAreaHandlerFactory::build(
	void(*drawCb)(uiArea*, uiAreaDrawParams*), void(*mouseEventCb)(uiArea*, uiAreaMouseEvent*),
         void(*mouseCrossedCb)(uiArea*, int), void(*dragBrokenCb)(uiArea*),
         int(*keyEventCb)(uiArea*, uiAreaKeyEvent*)
) {
	UiAreaHandler *handler = new UiAreaHandler();
	handler->draw = (drawCb);
	handler->mouseEvent = (mouseEventCb);
	handler->mouseCrossed = (mouseCrossedCb);
	handler->dragBroken = (dragBrokenCb);
	handler->keyEvent = (keyEventCb);

	handler->Draw = Draw;
	handler->MouseEvent = MouseEvent;
	handler->MouseCrossed = MouseCrossed;
	handler->DragBroken = DragBroken;
	handler->KeyEvent = KeyEvent;

	return handler;
}
