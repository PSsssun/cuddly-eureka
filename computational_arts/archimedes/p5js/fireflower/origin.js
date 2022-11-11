let xoff;
function setup() {
  createCanvas(900,900);
  background(255);
//frameRate(1)

}

function draw() {
background(255)
noLoop()
  
// let wind=map(mouseX,0,width,0,-60)
// rotate(wind)
//loop();

 for(let i=1;i<=50;i++){
    push()
    drawASilk(i*random(width/(2*i))+width/9,i*random(height/(2*i)));
   pop()
  }
}

function drawASilk(posX,posY){  
  push()
  translate(posX,posY)
  scale (random(0.5,2))
  let wind=map(mouseX,0,width,0,-60)
rotate(wind)

  let colorB=(noise(xoff),0,1,200,255)
  stroke(colorB,random(10,200),0)
  strokeWeight(0.1)

  for(let angle=0;angle<20;angle+=0.5){
    push()
    rotate(radians(angle));
    strokeWeight(0.01);
    noFill();
    bezier(0,0,100,150,150,100,250,250)
    pop()
  }
  pop()
}