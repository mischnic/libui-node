#include "../ui.h"
#include "nbind/api.h"
#include "nbind/nbind.h"
#include "ui-node.h"
#include <map>
#include <nan.h>

std::unordered_map <uiControl *, Nan::Persistent<v8::Object> *> controlsMap;
std::unordered_map <uiControl *, UiControl *> UiControlMap;


uiControl * UiControl::getHandle() {
	return handle;
}

static void onDestroy(uiControl *c) {
	printf("destroy control %p\n", c);
	UiControl * self = UiControlMap[c];
	(*(self->originalDestroy))(c);
	UiControlMap.erase(c);
}

static void onSetParent(uiControl *c, uiControl *p) {
	printf("onSetParent %p=%p\n", c, p);
	UiControl * self = UiControlMap[c];

	if (p != NULL) {
		Nan::Persistent<v8::Object> *pers = nbind::BindWrapper<UiControl>::findInstance(self);
		Nan::Persistent<v8::Object> * other = new Nan::Persistent<v8::Object>(Nan::New(*pers));
		printf("set persistent %p for %p\n", other, c);
		controlsMap[c] = other;
	} else {
		Nan::Persistent<v8::Object> * persy = controlsMap[c];
		printf("remove persy %p for %p\n", persy, c);
		persy->Reset();
		printf("reset done\n");
		controlsMap.erase(c);
		printf("erase done\n");
	}

	(*(self->originalSetParent))(c, p);
	printf("originalSetParent done %p\n",self->originalSetParent);
}

UiControl::UiControl(uiControl* hnd) {
	handle = hnd;
	originalDestroy = hnd->Destroy;
	originalSetParent = hnd->SetParent;
	hnd->Destroy = onDestroy;
	hnd->SetParent = onSetParent;

	UiControlMap[hnd] = this;

	printf("created %p\n", handle);
}

UiControl::~UiControl() {

	printf("destroy c++ %p\n", handle);
}

void UiControl::destroy() {
	uiControlDestroy(handle);
}

void UiControl::setParent (UiControl *parent) {
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
