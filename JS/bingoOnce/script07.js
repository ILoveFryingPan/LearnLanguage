window.onload = initAll;
function initAll(){
	document.getElementById("redirect").onclick = initRedirect;
}

function initRedirect(){
	window.location = "http://www.baidu.com";
	return false;
}