#include "../ui.h"
#include "ui-node.h"
#include "nbind/api.h"
#include "nbind/nbind.h"

std::vector<std::shared_ptr<UiWindow>> visibleWindows;

Point UiWindow::getPosition() {
	int x = 0;
	int y = 0;
	uiWindowPosition(
		(uiWindow *) getHandle(),
		&x,
		&y
	);
	return Point(x, y);
}


UiWindow::~UiWindow() {
	printf("destroy UiWindow c++ %p\n", win);
}

void UiWindow::setPosition(Point position) {
	uiWindowSetPosition(
		(uiWindow *) getHandle(),
		position.getX(),
		position.getY()
	);
}

void UiWindow::center() {
	uiWindowCenter((uiWindow *) getHandle());
}



static int UiWindow_onClosing(uiWindow *w, void *data) {
	UiWindow * win = (UiWindow *) data;
	visibleWindows[win->visibleWindowsIdx].reset();
	visibleWindows[win->visibleWindowsIdx] = nullptr;

	nbind::cbFunction *cb = win->onClosingCallback;
	(*cb)();

	printf("resetting child\n");
	win->child.reset();

	return 0;
}

void UiWindow::onClosing(nbind::cbFunction & cb) {

	onClosingCallback = new nbind::cbFunction(cb);
	uiWindowOnClosing(
		(uiWindow *) getHandle(),
		UiWindow_onClosing,
		this
	);
}

static void UiWindow_onContentSizeChanged(uiWindow *w, void *data) {
	nbind::cbFunction *cb = (nbind::cbFunction *) data;
	(*cb)();
}

void UiWindow::onContentSizeChanged(nbind::cbFunction & cb) {
	onContentSizeChangedCallback = new nbind::cbFunction(cb);
	uiWindowOnContentSizeChanged(
		(uiWindow *) getHandle(),
		UiWindow_onContentSizeChanged,
		onContentSizeChangedCallback
	);
}


static void UiWindow_onPositionChanged(uiWindow *w, void *data) {
	nbind::cbFunction *cb = (nbind::cbFunction *) data;
	(*cb)();
}

void UiWindow::onPositionChanged(nbind::cbFunction & cb) {
	onPositionChangedCallback = new nbind::cbFunction(cb);
	uiWindowOnPositionChanged(
		(uiWindow *) getHandle(),
		UiWindow_onPositionChanged,
		onPositionChangedCallback
	);
}

UiWindow::UiWindow(const char* title, int width, int height, bool hasMenubar) {
	win = uiNewWindow(title, width, height, hasMenubar);
}

uiWindow * UiWindow::getHandle() {
	return win;
}


void UiWindow::show(std::shared_ptr<UiWindow> window) {
	window->visibleWindowsIdx = visibleWindows.size();
	visibleWindows.push_back(window);
	uiControlShow(uiControl(window->win));
}

void UiWindow::close(std::shared_ptr<UiWindow> window) {
	uiControlDestroy(uiControl(window->win));
}

void UiWindow::setMargined(bool margined) {
	uiWindowSetMargined(win, margined);
}

bool UiWindow::getMargined() {
	return uiWindowMargined(win);
}

void UiWindow::setChild(std::shared_ptr<UiControl> control) {
	uiWindowSetChild(win, control->getHandle());
	child = control;
}

void UiWindow::setTitle(const char * title) {
	uiWindowSetTitle(win, title);
}

const char * UiWindow::getTitle() {
	return uiWindowTitle(win);
}

bool UiWindow::getFullscreen() {
	return uiWindowFullscreen(win);
}

void UiWindow::setFullscreen(bool value) {
	uiWindowSetFullscreen(win, value);
}

void UiWindow::setBorderless(bool value) {
	uiWindowSetBorderless(win, value);
}
bool UiWindow::getBorderless() {
	return uiWindowBorderless(win);
}


void UiWindow::setContentSize(Size value) {
//	printf("setting content to (%d x %d)\n", value.getWidth(), value.getHeight());
	uiWindowSetContentSize(win, value.getWidth(), value.getHeight());
}

Size UiWindow::getContentSize() {
	int w = 0;
	int h = 0;
	uiWindowContentSize(win, &w, &h);
	return Size(w, h);
}



NBIND_CLASS(UiWindow) {
  construct<const char *, int, int, bool>();
  method(show);
  method(close);
  method(setChild);
  method(onClosing);
  method(onContentSizeChanged);
  getset(getMargined, setMargined);
  getset(getTitle, setTitle);
  getset(getPosition, setPosition);
  method(getPosition);
  method(setPosition);
  method(onPositionChanged);
  method(center);

  getset(getContentSize, setContentSize);
  method(getContentSize);
  method(setContentSize);
  method(onContentSizeChanged);

  getset(getFullscreen, setFullscreen);
  method(getFullscreen);
  method(setFullscreen);
  getset(getBorderless, setBorderless);
  method(getBorderless);
  method(setBorderless);
}

