window.onload = initAll;
var colPlace = new Array(0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4);
var useNums = new Array(76);

function initAll(){
	if (document.getElementById) {
		document.getElementById("reload").onclick = anotherCard;
		newCard();
	}else {
		alert("Sorry, your browser doesn't support this script");
	}

	function newCard(){
		for(var i = 0; i < 24; i++){
			setSquare(i);
		}
	}

	function setSquare(thisSquare){
		var currSquare = "square" + thisSquare;
		var colBasis = colPlace[thisSquare] * 15;
		var newNum;
		do{
			newNum = colBasis + getNewNum() + 1;
		}while(useNums[newNum]);

		useNums[newNum] = true;
		document.getElementById(currSquare).innerHTML = newNum;
		document.getElementById(currSquare).className = "";
		document.getElementById(currSquare).onmousedown = toggleColor;
	}

	function getNewNum() {
		return Math.floor(Math.random() * 15);
	}

	function anotherCard(){
		for(var i = 1; i < useNums.length; i++){
			useNums[i] = false;
		}

		newCard();
		return false;
	}

	function toggleColor(evt) {
		if (evt) {
			var thisSquare = evt.target;
		} else {
			var thisSquare = window.event.srcElement;
		}

		if (thisSquare.className == "") {
			thisSquare.className = "pickedBG";
		} else {
			thisSquare.className = "";
		}

		checkWin();
	}

	function checkWin(){
		var winningOption = -1;
		var setSquares = 0;
		var winners = new Array(31, 992, 15360, 507904, 541729, 557328,
			1083458, 2162820, 4329736, 8519745, 8659472, 16252928);
		for(var i = 0; i < 24; i++){
			if (document.getElementById("square" + i).className != "") {
				document.getElementById("square" + i).className = "pickedBG";
				setSquares = setSquares | Math.pow(2, i);
			}
		}

		for(var i = 0; i < winners.length; i++){
			if ((setSquares & winners[i]) == winners[i]) {
				winningOption = i;
				break;
			}
		}

		if (winningOption > -1) {
			for(var i = 0; i < 24; i++){
				if (winners[winningOption] & Math.pow(2, i)) {
					document.getElementById("square" + i).className = "winningBG";
				}
			}
		}
	}
}
