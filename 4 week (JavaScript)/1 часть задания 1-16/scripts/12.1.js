var name = prompt("Введите имя:");
var year = prompt("Введите год рождения:");
var age = new Date().getFullYear()-year;
var word;
if(age<9||age>19){
    switch (age%10){
        case 1:
            word=" год";
            break;
        case 2:
        case 3:
        case 4:
            word=" года";
            break;
        case 0:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
            word=" лет";
            break;
    }
}
else{
    word=" лет";
}
document.write(`
    <p>${name}:${age}${word}</p>
    
`);
