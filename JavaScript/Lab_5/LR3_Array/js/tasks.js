function getRandomIntInclusive(min, max) {
    min = Math.ceil(min);
    max = Math.floor(max);
    return Math.floor(Math.random() * (max - min + 1)) + min;
}
function createArray10() {
    let arr = [];
    for (let i = 0; i < 10; ++i) {
        arr[i] = getRandomIntInclusive(1, 100);
    }
    return arr;
}
function createArray5() {
    let arr = [];
    for (let i = 0; i < 5; ++i) {
        arr[i] = getRandomIntInclusive(1, 10);
    }
    return arr;
}
let arr = createArray10();
let arr1 = createArray5();
let arr2 = createArray5();
let arrFruits = ["Яблуко", "Груша", "Слива", "Персик", "Гранат", "Ківі", "Маракуя", "Хурма", "Папая", "Абрикос"];
function task1(arr) {
    let arrStr = [];
    for (let i = 0; i < 10; ++i) {
        arrStr[i] = " " + arr[i];
    }
    alert("Масив чисел: " + arrStr);
}
function task2(arr) {
    let evenArr = [];
    let arrStr = [];
    let k = 0;
    for (let i = 0; i < 10; ++i) {
        arrStr[i] = " " + arr[i];
        if (arr[i] % 2 == 0) {
            evenArr[k] = " " + arr[i];
            ++k;
        }
    }
    alert("Масив: " + arrStr + "\nПарні: " + evenArr);
}
function task3(arr) {
    let sum = 0;
    let arrStr = [];
    for (let i = 0; i < 10; ++i) {
        arrStr[i] = " " + arr[i];
        sum += arr[i];
    }
    alert("Масив чисел: " + arrStr + "\nСума: " + sum);
}
function task4(arr) {
    let max = 0;
    let arrStr = [];
    for (let i = 0; i < 10; ++i) {
        if (arr[i] > max) max = arr[i];
        arrStr[i] = " " + arr[i];
    }
    alert("Масив чисел: " + arrStr + "\nМаксимальний елемент: " + max);
}
function task5(arr) {
    let arrPlusOne = [];
    let arrStr = [];
    let k = 0;
    let index = parseInt(prompt("Будь ласка, введіть індекс від 0 до 10 [0 початок масиву]:", "0"));
    while (index < 0 || index > 10) {
        index = parseInt(prompt("Не вірний індекс. Будь ласка, введіть індекс від 0 до 10 [0 початок масиву]:", "0"));
    }
    for (let i = 0; i < 10; ++i) {
        arrStr[i] = " " + arr[i];
    }
    for (let i = 0; i < 11; ++i) {
        if (i == index) arrPlusOne[i] = " " + getRandomIntInclusive(1, 100);
        else {
            arrPlusOne[i] = " " + arr[k];
            k++;
        }
    }
    alert("Масив чисел: " + arrStr + "\nНовий масив: " + arrPlusOne);
}
function task6(arr) {
    let arrMinusOne = [];
    let arrStr = [];
    let k = 0;
    let index = parseInt(prompt("Будь ласка, введіть індекс від 1 до 10:", "1"));
    while (index < 1 || index > 10) {
        index = parseInt(prompt("Не вірний індекс. Будь ласка, введіть індекс від 1 до 10:", "1"));
    }
    for (let i = 0; i < 10; ++i) {
        arrStr[i] = " " + arr[i];
    }
    for (let i = 0; i < 10; ++i) {
        if (i == index - 1) continue;
        else {
            arrMinusOne[k] = " " + arr[i];
            k++;
        }
    }
    alert("Масив чисел: " + arrStr + "\nНовий масив: " + arrMinusOne);
}
function task7(arr1, arr2) {
    let arrStr1 = [];
    let arrStr2 = [];
    let arrDouble = [];
    for (let i = 0; i < 5; ++i) {
        arrStr1[i] = " " + arr1[i];
    }
    for (let i = 0; i < 5; ++i) {
        arrStr2[i] = " " + arr2[i];
    }
    let check;
    let count = 0;
    for (let i = 0; i < 5; ++i) {
        check = 0;
        for (let k = i + 1; k < 5; ++k) {
            if (arr1[i] == arr1[k]) check++;
        }
        if (check == 0) { arrDouble[count] = " " + arr1[i]; count++; }
    }
    for (let i = 0; i < 5; ++i) {
        check = 0;
        for (let k = 0; k < arrDouble.length; ++k) {
            if (arr2[i] == arrDouble[k]) check++;
        }
        if (check == 0) { arrDouble[count] = " " + arr2[i]; count++; }
    }
    alert("Перший масив: " + arrStr1 + "\nДругий масив: " + arrStr2 + "\nОб'єднаний масив без повторень: " + arrDouble);
}
function task8(arr1, arr2) {
    let arrStr1 = [];
    let arrStr2 = [];
    let arrDouble = [];
    for (let i = 0; i < 5; ++i) {
        arrStr1[i] = " " + arr1[i];
    }
    for (let i = 0; i < 5; ++i) {
        arrStr2[i] = " " + arr2[i];
    }
    let check;
    let count = 0;
    for (let i = 0; i < 5; ++i) {
        for (let k = 0; k < 5; ++k) {
            if (arr1[i] == arr2[k]) {
                check = 0;
                for (let j = 0; j < arrDouble.length; ++j) {
                    if (arr1[i] == arrDouble[j]) check++;
                }
                if (check == 0) {
                    arrDouble[count] = " " + arr1[i];
                    count++;
                }
                break;
            }
        }
    }
    if (count == 0) arrDouble[0] = "відсутні";
    alert("Перший масив: " + arrStr1 + "\nДругий масив: " + arrStr2 + "\nСпільні елементи масивів: " + arrDouble);
}
function task9(arr1, arr2) {
    let arrStr1 = [];
    let arrStr2 = [];
    let arrDouble = [];
    for (let i = 0; i < 5; ++i) {
        arrStr1[i] = " " + arr1[i];
    }
    for (let i = 0; i < 5; ++i) {
        arrStr2[i] = " " + arr2[i];
    }
    let check;
    let count = 0;
    for (let i = 0; i < 5; ++i) {
        check = 0;
        for (let k = 0; k < 5; ++k) {
            if (arr1[i] == arr2[k]) {
                check++;
                break;
            }
        }
        if (check == 0) {
            for (let j = 0; j < arrDouble.length; ++j) {
                if (arr1[i] == arrDouble[j]) check++;
            }
            if (check == 0) {
                arrDouble[count] = " " + arr1[i];
                count++;
            }
        }
    }
    if (count == 0) arrDouble[0] = "відсутні";
    alert("Перший масив: " + arrStr1 + "\nДругий масив: " + arrStr2 + "\nЕлементи першого масиву яких немає в другому: " + arrDouble);

}
function task10(arrFruits) {
    let arrFruitsSort = [];
    let arrFruitsStr = [];
    for (let i = 0; i < arrFruits.length; ++i) {
        arrFruitsSort[i] = arrFruits[i] + "\n";
    }
    arrFruitsSort.sort();
    for (let i = 0; i < arrFruitsSort.length; ++i) {
        arrFruitsStr = arrFruitsStr + arrFruitsSort[i];
    }
    alert("Відсортований по алфавіту:\n" + arrFruitsStr);
}
function task11(arrFruits) {
    let arrFruitsLower = [];
    for (let i = 0; i < arrFruits.length; ++i) {
        arrFruitsLower[i] = arrFruits[i].toLowerCase();
    }
    let fruits = prompt("Будь ласка, введіть фрукт:", "Яблуко").toLowerCase();
    let check = 0;
    for (let i = 0; i < arrFruitsLower.length; ++i) {
        if (fruits == arrFruitsLower[i]) {
            alert("Фрукт присутній в масиві під номером: " + (i + 1));
            check++;
            break;
        }
    }
    if (check == 0) alert("Фрукт відсутній в масиві!");
}


