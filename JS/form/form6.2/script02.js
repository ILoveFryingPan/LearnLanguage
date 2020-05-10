window.onload = initForm;
var monthDays = new Array(31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31);

function initForm(){
	document.getElementById("months").selectedIndex = 0;
	document.getElementById("months").onchange = populateDays;
}

function populateDays(){
	document.getElementById("days").options.length = 0;
	var monthStr = this.options[this.selectedIndex].value;
	if (monthStr != "") {
		var theMonth = parseInt(monthStr);
		for(var i = 0; i < monthDays[theMonth]; i++) {
			document.getElementById("days").options[i] = new Option(i + 1);
		}
	}else{
		document.getElementById("days").options[0] = new Option("Day");
	}
	
}