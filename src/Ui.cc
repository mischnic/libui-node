#include "../ui.h"
#include "ui-node.h"
#include <cstdio>
/* TODO: this has to be removed */

// static int onShouldQuit_cb(void *data) {
//   nbind::cbFunction *cb = (nbind::cbFunction *) data;
//   (*cb)();
//   return 0;
// }

void Ui::main() { uiMain(); }

void Ui::mainSteps() { uiMainSteps(); }

int Ui::mainStep(int wait) { return uiMainStep(wait); }

// static void onShouldQuit(nbind::cbFunction & cb) {
//   // uiOnShouldQuit(onShouldQuit_cb, new nbind::cbFunction(cb));
// }

void Ui::quit() { uiQuit(); }

void Ui::init() {
  uiInitOptions o;
  // memset(&o, 0, sizeof(uiInitOptions));
  const char* err = uiInit(&o);
  if (err != NULL) {
    // NBIND_ERR(err);
    printf("Error: %s\n", err);
    uiFreeInitError(err);
  }
}

