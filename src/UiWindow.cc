#include "../ui.h"
#include "ui-node.h"

// static int UiWindow_onClosing(uiWindow *w, void *data) {
//   nbind::cbFunction *cb = (nbind::cbFunction *)data;
//   (*cb)();
//   return 0;
// }

// void UiWindow::onClosing(void(*cb)()) {
//   uiWindowOnClosing((uiWindow *)getHandle(), cb, NULL);
// }

// static void UiWindow_onContentSizeChanged(uiWindow *w, void *data) {
//   nbind::cbFunction *cb = (nbind::cbFunction *)data;
//   (*cb)();
// }

// void UiWindow::onContentSizeChanged(void(*cb)()) {
//   // onContentSizeChangedCallback = new nbind::cbFunction(cb);
//   uiWindowOnContentSizeChanged((uiWindow *)getHandle(), cb, NULL);
// }

UiWindow::UiWindow(const char *title, int width, int height, bool hasMenubar) {
  win = uiNewWindow(title, width, height, hasMenubar);
}

uiWindow *UiWindow::getHandle() { return win; }

void UiWindow::show() { uiControlShow(uiControl(win)); }

void UiWindow::close() { uiControlDestroy(uiControl(win)); }

void UiWindow::setMargined(bool margined) {
  uiWindowSetMargined(win, margined);
}

bool UiWindow::getMargined() { return uiWindowMargined(win); }

void UiWindow::setChild(UiControl *control) {
  uiWindowSetChild(win, control->getHandle());
}

void UiWindow::setTitle(const char *title) { uiWindowSetTitle(win, title); }

const char *UiWindow::getTitle() { return uiWindowTitle(win); }

bool UiWindow::getFullscreen() { return uiWindowFullscreen(win); }

void UiWindow::setFullscreen(bool value) { uiWindowSetFullscreen(win, value); }

void UiWindow::setBorderless(bool value) { uiWindowSetBorderless(win, value); }
bool UiWindow::getBorderless() { return uiWindowBorderless(win); }

void UiWindow::setContentSize(Size value) {
  uiWindowSetContentSize(win, value.getWidth(), value.getHeight());
}

Size UiWindow::getContentSize() {
  int w = 0;
  int h = 0;
  uiWindowContentSize(win, &w, &h);
  return Size(w, h);
}


