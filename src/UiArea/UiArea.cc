#include "../../ui.h"
#include "../ui-node.h"

std::map<uiArea*, UiArea*> areasMap;

INHERITS_CONTROL_METHODS(UiArea)

void UiArea::setSize(int width, int height) {
  uiAreaSetSize((uiArea*)getHandle(), width, height);
}

void UiArea::queueRedrawAll() {
  uiAreaQueueRedrawAll((uiArea*)getHandle());
}

void UiArea::scrollTo(double x, double y, double width, double height) {
  uiAreaScrollTo((uiArea*)getHandle(), x, y, width, height);
}

UiArea::UiArea(void(*drawCb)(UiArea*, UiAreaDrawParams*), void(*mouseEventCb)(UiArea*, UiAreaMouseEvent*),
         void(*mouseCrossedCb)(UiArea*, int), void(*dragBrokenCb)(UiArea*),
         int(*keyEventCb)(UiArea*, UiAreaKeyEvent*))
    : UiControl((uiControl*)uiNewArea(
          (uiAreaHandler*)UiAreaHandlerFactory::build(drawCb,
                                                      mouseEventCb,
                                                      mouseCrossedCb,
                                                      dragBrokenCb,
                                                      keyEventCb))) {
  areasMap[(uiArea*)getHandle()] = this;
}

UiArea::UiArea(void(*drawCb)(UiArea*, UiAreaDrawParams*), void(*mouseEventCb)(UiArea*, UiAreaMouseEvent*),
         void(*mouseCrossedCb)(UiArea*, int), void(*dragBrokenCb)(UiArea*),
         int(*keyEventCb)(UiArea*, UiAreaKeyEvent*),
               int width,
               int height)
    : UiControl((uiControl*)uiNewScrollingArea(
          (uiAreaHandler*)UiAreaHandlerFactory::build(drawCb,
                                                      mouseEventCb,
                                                      mouseCrossedCb,
                                                      dragBrokenCb,
                                                      keyEventCb),
          width,
          height)) {
  areasMap[(uiArea*)getHandle()] = this;
}

// Workaround for nbind bug solved in 0.3
UiArea::UiArea(int dummy) : UiControl(NULL) {}



