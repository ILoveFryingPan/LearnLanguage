window.onload = newWinLinks;

function newWinLinks(){
	for(var i = 0; i < document.links.length; i++){
		if (document.links[i].className == "newWin") {
			document.links[i].onclick = newWindow;
		}
	}
}

function newWindow(){
	var catWindow = window.open("./../threeCatimg.gif","catWin","resizable=no,width = 700,height = 260");
	catWindow.focus();
	return false;
}