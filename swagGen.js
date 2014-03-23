/* ========================================================================
 * Swag Name Generator: v 1.1
 * http://www.swagnamegenerator.com (not live)
 * Designed to satirise the stupid names you find in online gaming (LoL, DotA, CoD etc)
 * ========================================================================
 * Copyright 2014 Laurence Stokes
 * Licensed under MIT 
 * ======================================================================== */

	//Set up Global Variables (the swag name arrays)

	var mySwagArray1 = ["swag","yolo", "420", "blaseit", "fgt", "cool", "hipster", "overload", "2k14", "cunt", "destroyer", "arseface", "XxX", "pimping", "tupac"];
	var mySwagArray2 = ["swag","yolo", "420", "blaseit", "fgt", "cool", "hipster", "overload", "2k14", "cunt", "destroyer", "arseface", "XxX", "pimping", "tupac"];
	var mySwagArray3 = ["swag","yolo", "420", "blaseit", "fgt", "cool", "hipster", "overload", "2k14", "cunt", "destroyer", "arseface", "XxX", "pimping", "tupac"];


	
	function genName(){
		
		//html element to update the result to
		var elementToUpdate = "header"
		
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
				//append extracted name to result if it's not already in result
				if (result.indexOf(swag) > -1) {
					i--;
				} else {
					result = result + " " + swag;
				}
			}
		}
		document.getElementById(elementToUpdate).innerHTML= result;
	}
