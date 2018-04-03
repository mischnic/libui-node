/* eslint-disable unicorn/filename-case */

var mtrace = require('mtrace');
var filename = mtrace.mtrace();
if (filename) {
  console.log('Saving mtrace to ' + filename);
} else {
  console.log('mtrace not supported');
}

const libui = require('../..');

const win = new libui.UiWindow('UiEntry example', 320, 320, true);
win.margined = true;

const box = new libui.UiVerticalBox();

const entry = new libui.UiEntry();
entry.text = 'sample text sample text sample text sample textsample textv v sample text sample textsample textsample text sample text sample text v sample text sample text';
box.append(entry, true);

const button = new libui.UiButton("Test");
button.onClicked(()=>{
	for(let i = 0; i < 300; i++){
		entry.getText();
	}
})
box.append(button, true);

win.setChild(box);

win.onClosing(() => {
	win.close();
	libui.Ui.quit();
});

win.show();

libui.Ui.main();
