document.write(`<table >`); 
for(var i=1;i<=8;i++){
    document.write(`<tr>`); 
    for(var j=1;j<=8;j++){
        if((i+j)%2==0){
            document.write(`<td style="background-color:white;"></td>`); 
        }
        else{
            document.write(`<td style="background-color:black;"></td>`);  
        }
    }
    document.write(`</tr>`); 
}
document.write(`</table>`); 
