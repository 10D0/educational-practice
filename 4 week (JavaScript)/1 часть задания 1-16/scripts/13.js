var number =Math.floor(Math.random() * 10);
var num = prompt("Введите число");
if(number==num){
    alert("Ура победа верно правильное число: "+number);
}
else if(num==null){
    alert("Ну попробовал бы хотя бы что-ли...");
}
else {
    alert(num+" - неверно, правильное число: "+number);
}
