window.onload = circulInit;
var ad = 0;
var adImage = ["./../hot_fly.gif", "./../car.gif", "./../timg.gif", "./../tianxinmao.gif"];
var url = ["baidu.com", "github.com", "tudou.com", "youku.com"];

function circulInit(){

	if (top.location != self.location) {
		top.location.replace(self.location);
	}

	var cirImage = document.getElementById("adBanner");
	if (cirImage.parentNode.tagName == "A") {
		cirImage.parentNode.onclick = hrefUrl;
	}

	document.getElementById("prevLink").onclick = privious;
	document.getElementById("nextLink").onclick = next;

	// circle();
}

function circle(){
	var cirImage = document.getElementById("adBanner");
	ad++;
	if (ad == adImage.length) {
		ad = 0;
	}

	cirImage.src = adImage[ad];
	setTimeout(circulInit, 3 * 1000);
}

function hrefUrl(){
	// console.log("执行了一次");
	this.href = "http://www." + url[ad];
	return false;
}

function privious(){
	if (ad == 0) {
		ad = adImage.length;
	}

	ad--;
	document.getElementById("adBanner").src = adImage[ad];
	return false;
}

function next(){
	ad++;
	if (ad == adImage.length) {
		ad = 0;
	}

	document.getElementById("adBanner").src = adImage[ad];
	return false;
}