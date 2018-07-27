var canvas = document.querySelector('canvas');
canvas.width = window.innerWidth;
canvas.height = window.innerHeight;


var ctx = document.getElementById("canvas").getContext("2d");

var cont = 0;


window.addEventListener('click', 
	function(){
	getPosition(event);
});

window.addEventListener('keypress',
	function(){
		reorganize(event);
	})
var pointSize = 3;
var pointsArray = [];
var vectorArray = [];
var aux = [];
var colors = [];
var v1,v2,v3,v4;

function vectorColors(){
	var c = [];
	for (var i = 0; i < 5; i++) {
		c[i] = randomColor();
	}
	return c;
}

colors = vectorColors();

function getPosition(event){
     
     var rect = canvas.getBoundingClientRect();
     var x = event.clientX - rect.left;
     var y = event.clientY - rect.top;
     
    if(cont < 5){
     	drawCoordinates(x,y);
       	cont = cont+1;
     } 

     if(cont ==5){
     	drawPath();
     }   		    	
    
}

function reorganize(event){
	ctx.clearRect(0,0,innerWidth,innerHeight);
	var aux = shuffle(vectorArray);
   	
    o1 = 300;
    o2 = 300;

    for (var i = 0; i < 5; i++) {	
 		v = new Vector(o1,o2,o1+(aux[i].x2-aux[i].x1),o2+(aux[i].y2-aux[i].y1),aux[i].color);
 		v.drawV();
 		o1 = o1+(aux[i].x2-aux[i].x1);
 		o2 = o2+(aux[i].y2-aux[i].y1);
	
	}


    
}
	
function drawVector(x1,y1,x2,y2,color){
	ctx.beginPath();
	ctx.moveTo(x1,y1); 
	ctx.lineTo(x2,y2);
	ctx.strokeStyle = color;
	ctx.stroke();
	ctx.closePath();
	

}

function randomColor() {
 return "#" + 
    Math.floor((1 + Math.random()) * 4096).toString(16).substr(1);
}


function drawCoordinates(x,y){	

    p = new Circle(x,y,pointSize);
  	p.draw();
  	pointsArray.push(p);

}

function Vector(x1,y1,x2,y2,color){
	
	this.x1 = x1;
	this.y1 = y1;
	this.x2 = x2;
	this.y2 = y2;
	this.color = color;
	this.range  = Math.sqrt(Math.pow(x2-x1,2)+Math.pow(y2-y1,2));
	this.drawV = function(){
		drawVector(x1,y1,x2,y2,this.color);
	}
}



function Circle(x,y,raio){//objeto
	this.x = x;
	this.y = y;
	this.raio = raio;

	this.draw = function(){

  		ctx.fillStyle = "#fffff"; // Red color
    	ctx.beginPath();
    	ctx.arc(x, y, pointSize, 0, Math.PI * 2, true);
    	ctx.fill();
	}
}

function drawPath(){
 	for (var i = 0; i < 5; i++) {	
 	
		v = new Vector(pointsArray[i].x,pointsArray[i].y,pointsArray[(i+1)%5].x,pointsArray[(i+1)%5].y,colors[i]);
		v.drawV();
		vectorArray.push(v);
		
	}
}


function shuffle(arra1) {
    var ctr = arra1.length, temp, index;

// While there are elements in the array
    while (ctr > 0) {
// Pick a random index
        index = Math.floor(Math.random() * ctr);
// Decrease ctr by 1
        ctr--;
// And swap the last element with it
        temp = arra1[ctr];
        arra1[ctr] = arra1[index];
        arra1[index] = temp;
    }
    return arra1;
}

