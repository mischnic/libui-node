var util = require('util');
var libui = require('../index');
global.gc();
console.log(util.inspect(process.memoryUsage()));

libui.Ui.init();
var win = new libui.UiWindow('UiButton example', 320, 200, true);
var vBox = new libui.UiVerticalBox();
var widgets = [];
var totW = 30;

function close() {

	for (var i = 0; i < totW; i++) {
		vBox.deleteAt(0);
	}

	for (var i2 = 0; i2 < totW; i2++) {
		widgets[i2].destroy();
		widgets[i2].text = 'changed ' + i2;
	}

	win.removeChild();
	vBox.destroy();

	win.close();
	libui.stopLoop();

	widgets = null;
	win = null;
	vBox = null;

	setInterval(() => {
		global.gc();
		console.log(util.inspect(process.memoryUsage()));
	}, 200);
}

for (var i = 0; i < totW; i++) {
	var widget = new libui.UiButton();
	widgets[i] = widget;

	widget.onClicked(close);
	widget.text = 'sample text ' + i;
	vBox.append(widget, true);
}

win.setChild(vBox);

win.show();

libui.startLoop();
