window.onload = initAll;
var rowNum = [1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5];
var selectNum = new Array(75);
var winners = [31, 992, 15360, 507904, 541729, 557328, 1083458, 2162820,
	4329736, 8519745, 8659472, 16252928];

function initAll(){
	if (document.getElementById) {
		document.getElementById("reload").onclick = anotherClick;
		newBingo();
	}else {
		alter("浏览器不支持");
	}
}

function newBingo(){
	for(var i = 0; i < 24; i++){
		createNum(i);
	}
}

function createNum(tab){
	var baseNum = rowNum[tab] * 15 + 1;
	var num;
	do{
		num = getNewNum() + baseNum;
	} while(selectNum[num - 1]);
	document.getElementById("square" + tab).innerHTML = num;
	document.getElementById("square" + tab).className = "";
	document.getElementById("square" + tab).onmousedown = selectTd;
}

function getNewNum(){
	return Math.floor(Math.random() * 15);
}

function selectTd(evt){
	if (evt) {
		var thisSquare = evt.target;
	}else {
		var thisSquare = window.event.srcElement;
	}

	if (thisSquare.className == "") {
		thisSquare.className = "pickedBG";
	}else {
		thisSquare.className = "";
	}
	checkWinner();
}

function checkWinner(){
	var selectPosition = 0;
	var select = -1;

	for (var i = 0; i < 24; i++) {
		if (document.getElementById("square" + i).className != "") {
			document.getElementById("square" + i).className = "pickedBG";
			selectPosition = selectPosition | Math.pow(2, i);
		}
	}

	for (var i = 0; i < winners.length; i++) {
		if((selectPosition & winners[i]) == winners[i]){
			select = i;
			break;
		}
	}

	if (select > -1) {
		for(var i = 0; i < 24; i++){
			if (winners[select] & Math.pow(2, i)) {
				document.getElementById("square" + i).className = "winningBG";
			}
		}
	}
}

function anotherClick(){
	for(var i = 0; i < 24; i++){
		selectNum[i] = false;
	}

	newBingo();
	return false;
}