let f = 0;
let spec;
let numiters;

function setup()
{
    createCanvas(600, 600);

    numiters = 10;
    spec = width/numiters;
    noLoops;
}

function draw()
{
    background(255); // white

    for(let i = 0; i < numiters; i++){
        for(let j = 0; j < numiters; j++){
            //combo of draw in small rects
            push();
            translate(spc/2 + i * spc, j*spc);//tranlation of origins
            drawAMohr(i+1, j+1);
            pop();     // come with push in pairs
        }
    }

    f += 0.01; // to make graphics to animation (based on loop provided from editor)
    noLoop();

}

function drawAMohr(i, j)
{
    beginShape();
    for(let k = 0;k < 15; k++){
        vertex(noise(k*j, i+f)*spc - spc/2, noise(j, i*k+f)*spc - spc/2);
    }
    endShape();


}
