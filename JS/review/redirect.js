window.onload = start;

function start(){
	for(var i = 0; i < document.links.length(); i++){
		document.links[i].onclick = redirect;
	}
}

function redirect(){
	window.location = "newDirect.html";
	return false;
}