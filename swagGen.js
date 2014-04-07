/* ========================================================================
 * Swag Name Generator: v 1.1
 * http://www.swagnamegenerator.com (not live)
 * Designed to satirise the stupid names you find in online gaming (LoL, DotA, CoD etc)
 * ========================================================================
 * Copyright 2014 Laurence Stokes
 * Licensed under MIT 
 * ======================================================================== */

	//Set up Global Variables (the swag name arrays)

	var mySwagArray1 = ["#", "swag","yolo", "420", "blaseit", "fgt", "cool", "hipster", "overload", "2k14", "cunt", "destroyer", "arseface", "XxX", "pimping", "tupac"];
	var mySwagArray2 = ["swag","yolo", "420", "blaseit", "fgt", "cool", "hipster", "overload", "2k14", "cunt", "destroyer", "arseface", "pimping", "tupac"];
	var mySwagArray3 = ["swag","yolo", "420", "blaseit", "fgt", "cool", "hipster", "overload", "2k14", "cunt", "destroyer", "arseface", "XxX", "pimping", "tupac"];
	
	//html element to update the result to
	var elementToUpdate = "header";
	
	//html element to store all the generated names
	var allNames = "allNames";
	
	//html button element
	var button = "clickme";
	
	//html button element
	var favourites = "favourites";
	
	//favourites button element
	var favouriteButton = "favouriteButton"
	
	//array to store the previously generated names
	var nameArray = new Array();

	//array to store favourites
	var favs = new Array();
	
	/**
	function that generates the name.
	**/
	function genName(){

		//result string
		var result = "";
		//curent swag word string
		var swag = "";

		//iterate through the arrays 3 times to construct a random swagName.
		for (var i = 0; i <= 2; i++)
			{	
			if(i === 0){
				//extract a random swag name from array1 to append to result
				swag = mySwagArray1[Math.floor(Math.random()*mySwagArray1.length)];
				//append extracted name to result (result is empty so there can't be a string collision at this point)
				result = result + " " + swag;
			}else if(i===1){
				//extract a random swag name from array2 to append to result
				swag = mySwagArray2[Math.floor(Math.random()*mySwagArray2.length)];
				//append extracted name to result if it's not already in result
				if (result.indexOf(swag) > -1) {
					i--;
				} else {
					result = result + " " + swag;
				}
			}else if(i === 2){
				//extract a random swag name from array3 to append to result
				swag = mySwagArray3[Math.floor(Math.random()*mySwagArray3.length)];
				//append extracted name to result if it's not already in result - XxX can be first and third indice, however.
				if (result.indexOf(swag) > -1 && swag != 'XxX') {
					i--;
				} else {
					result = result + " " + swag;
				}
			}
		}
		setName(result);
		saveName(result, 10)
		updateButton();
		enableButton();
	}
	
	//function to set the desired html element to the generated swagName result.
	function setName(result){
		document.getElementById(elementToUpdate).innerHTML= result;
	}
	
	/**
	Function that saves all the generated names, up to a specified array size
	e.g a size of 5 will allow for 5 elements to be saved at once. specifying no 
	size allows (infinite) elements
	**/
	function saveName(result, size){
		nameArray.unshift(result);
		var output = new Array(size);
		output = (nameArray.slice(0, size)).join(' |');
		document.getElementById(allNames).innerHTML=output;
	}

	//updates the Button after the first click from 'Click me' to 'Another'
	function updateButton(){
		document.getElementById(button).innerHTML= "Another?";
	}
	
	/**
	Adds a generatedName to a list of favourites. Once added, disabled the button
	so the same name cannot be added again.
	Also checks that at least one name has been generated (nameArray[0] is not null).
	**/
	function addFavourite(){
		if(nameArray[0] != null){
			if(favs.indexOf(nameArray[0]) < 0){
				favs.unshift(nameArray[0]);
				document.getElementById(favourites).innerHTML= favs.join(' |');
				document.getElementById(favouriteButton).disabled = true; 
			}
		}else{
			window.alert("You need to create a name before you can save a favourite...");
		}
	}
	
	//enablesButton if it's otherwise disabled
	function enableButton(){
		document.getElementById(favouriteButton).disabled = false;
	}
