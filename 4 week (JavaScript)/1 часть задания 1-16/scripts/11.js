    "use strict";
    var name1 = prompt("Введите фамилию и имя:");
    var name2 = prompt("Введите фамилию и имя:");
    var name3 = prompt("Введите фамилию и имя:");
    document.write(
        `
        <h3>Список</h3>
        <ol>
            <li>${name1}</li>
            <li>${name2}</li>
            <li>${name3}</li>
        </ol>
        <h3>Абзацы</h3>
        <p>name1 = "${name1}"</p>
        <p>name2 = '${name2}'</p>
        <p>name1 =\`${name3}\`</p>
        `
    );
