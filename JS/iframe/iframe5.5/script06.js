window.onload = initLinks;

var bannerArray = new Array("./../pkq.gif", "./../backimage.gif", "./../car.gif");

function initLinks(){
	for(var i = 0; i < parent.document.links.length; i++){
		parent.document.links[i].onclick = setBanner;
	}
	setBanner();

}

function setBanner(){
	var randomNum = Math.floor(Math.random() * bannerArray.length);
	parent.document.getElementById("adBanner").src = bannerArray[randomNum];
}