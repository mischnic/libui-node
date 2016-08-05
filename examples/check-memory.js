var humanize = require('humanize');
var procStats = require('proc-stats');
var libui = require('../index.js');

libui.Ui.init();
// var showedWins = [];

function openBigWindow() {
	// console.log(showedWins, winCheckMem);
	var win = new libui.UiWindow('Forms window', 80, 60, false);
	win.margined = 1;
	win.onClosing(function () {
		libui.UiWindow.close(win);
	});

	var vBox = new libui.UiVerticalBox();
	vBox.padded = true;

	var entries = [];
	for (var i = 0; i < 3; i++) {
		entries[i] = new libui.UiEntry();
		entries[i].text = i;
		vBox.append(entries[i], 1);
	}

	win.setChild(vBox);
	libui.UiWindow.show(win);
	// showedWins.push(win);
}

var winCheckMem = new libui.UiWindow('Memory', 200, 100, true);
var label = new libui.UiLabel();
var btn = new libui.UiButton();
btn.text = 'Open';
btn.onClicked(openBigWindow);
var vBox2 = new libui.UiVerticalBox();
vBox2.padded = true;

vBox2.append(label, true);
vBox2.append(btn, false);

winCheckMem.setChild(vBox2);
libui.UiWindow.show(winCheckMem);

var interval = setInterval(function () {
	global.gc();

	procStats.stats(function (err, result) {
		if (err) {
			label.text = err.message;
		} else {
			var text = `
Memory: ${humanize.filesize(result.memory)}
Heap: ${humanize.filesize(result.memoryInfo.heapUsed)}
CPU: ${result.cpu} %
`;
			label.text = text;
		}
	});
}, 1000);

winCheckMem.onClosing(function () {
	clearInterval(interval);
	libui.UiWindow.close(winCheckMem);
	libui.stopLoop();
});

libui.startLoop();

