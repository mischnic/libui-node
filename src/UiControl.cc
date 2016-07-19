#include "../ui.h"
#include "nbind/api.h"
#include "nbind/nbind.h"
#include "ui-node.h"
#include <map>
#include <nan.h>

std::unordered_map <uiControl *, UiControl *> controlsMap;

uiControl * UiControl::getHandle() {
	return handle;
}

static void onDestroy(uiControl *c) {
	UiControl * self = controlsMap[c];
	(*(self->originalDestroy))(c);
	controlsMap.erase(c);
	printf("destroy control %p\n", c);
}

UiControl::UiControl(uiControl* hnd) {
	handle = hnd;
	originalDestroy = hnd->Destroy;
	hnd->Destroy = onDestroy;
	controlsMap[hnd] = this;
	printf("created %p\n", handle);
}

UiControl::~UiControl() {

	printf("destroy c++ %p\n", handle);
}

void UiControl::destroy() {
	uiControlDestroy(handle);
}

void UiControl::setParent (UiControl *parent) {

	Nan::Persistent<v8::Object> *pers = nbind::BindWrapper<UiControl>::findInstance(this);
	printf("pers %p\n", pers);
	if (parent != NULL) {
		printf("set Parent\n");
		pers->ClearWeak(); //new Nan::Persistent<v8::Object>(Nan::New(*pers));
	} else {
		printf("clear Parent\n");
		pers->SetWeak(pers, nbind::BindWrapper<UiControl>::weakCallback, Nan::WeakCallbackType::kParameter);
	}

	uiControlSetParent(handle, parent->getHandle());
}

bool UiControl::toplevel() {
	return uiControlToplevel(handle);
}

bool UiControl::getVisible() {
	return uiControlVisible(handle);
}

void UiControl::setVisible(bool visible) {
	if (visible == 1) {
		uiControlShow(handle);
	} else {
		uiControlHide(handle);
	}
}

bool UiControl::getEnabled() {
	return uiControlEnabled(handle);
}

void UiControl::setEnabled(bool enabled) {
	if (enabled == 1) {
		uiControlEnable(handle);
	} else {
		uiControlDisable(handle);
	}
}
