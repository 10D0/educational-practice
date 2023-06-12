var min=200;
var max=600;
var count=5;
var stroke=1;
for(var i=min;i<max;i+=(max-min)/count){
    document.write(
        `
        <p style="width:${i};">абзац ${stroke}</p>
        `
        )
        stroke++;
    }
