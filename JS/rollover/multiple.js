window.onload = rolloverInit;

function rolloverInit(){
	for(var i = 0; i < document.links.length; i++){
		var linkobj = document.links[i];
		if (linkobj.className) {
			var imgObj = document.getElementById(linkobj.className);
			if (imgObj) {
				setupRollover(linkobj, imgObj);
			}
		}
	}

	function setupRollover(thisLink, textImage){
		thisLink.imgToChange = new Array;
		thisLink.outImage = new Array;
		thisLink.overImage = new Array;

		thisLink.imgToChange[0] = textImage;

		thisLink.onmouseout = rollOut;
		thisLink.onmouseover = rollOver;

		thisLink.outImage[0] = new Image();
		thisLink.outImage[0].src = textImage.src;

		thisLink.overImage[0] = new Image();
		thisLink.overImage[0].src = "monkey.gif";

		var rolloverObj = document.getElementById(thisLink.id + "Img");
		if (rolloverObj) {
			thisLink.imgToChange[1] = rolloverObj;
			thisLink.outImage[1] = new Image();
			thisLink.outImage[1].src = rolloverObj.src;
			thisLink.overImage[1] = new Image();
			thisLink.overImage[1].src = "pkq.gif";
		}
	}

	function rollOver(){
		for(var i = 0; i < this.imgToChange.length; i++){
			this.imgToChange[i].src = this.overImage[i].src;
		}
	}

	function rollOut(){
		for(var i = 0; i < this.imgToChange.length; i++){
			this.imgToChange[i].src = this.outImage[i].src;
		}
	}
}