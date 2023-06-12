document.write(`<table >`); 
for(var i=1;i<10;i++){
    document.write(`<tr>`); 
    for(var j=1;j<10;j++){
        if(i==1||j==1){
            document.write(`<td style="background-color:orange;">${i*j}</td>`);
        }
        else{
            document.write(`<td style="background-color:white;">${i*j}</td>`);  
        }
    }
    document.write(`</tr>`); 
}
document.write(`</table>`); 
