var name = prompt("Введите имя:");
var year = prompt("Введите год рождения:");
var age = new Date().getFullYear()-year;
document.write(`
    <p>${name}:${age}</p>В
`);
