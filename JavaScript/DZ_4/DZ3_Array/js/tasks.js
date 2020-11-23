let car = {
    developer: "Toyota",
    model: "RAV4",
    year: 2019,
    average: 120
}
function fraction(num, den) {
    this.num = num;
    this.den = den;
}
function time(hour, minute, second) {
    this.hour = hour;
    this.minute = minute;
    this.second = second;
}
function task1(car) {
    alert("Інформація про автомобіль:\nВиробник: " + car.developer + "\nМодель: " + car.model + "\nРік випуску: " + car.year + " рік\nСередня швидкість: " + car.average + " км/год");
}
function task2(car) {
    let distance = parseInt(prompt("Будь ласка, введіть відстань:", 660));
    let hours = distance / car.average;
    if (parseInt((hours - parseInt(hours)) * 60) == 0) alert("Час подолання становить: " + parseInt(hours + parseInt(hours / 4)) + " год ")
    else alert("Час подолання становить: " + parseInt(hours + parseInt(hours / 4)) + " год " + parseInt((hours - parseInt(hours)) * 60) + " хв");
}
function task3() {
    let fracTemp1 = prompt("Будь ласка, введіть перший дріб:", "2/3");
    let fracTemp2 = prompt("Будь ласка, введіть другий дріб:", "5/7");
    let numbersOne = fracTemp1.split("/");
    let numbersTwo = fracTemp2.split("/");
    let fracOne = new fraction(parseInt(numbersOne[0]), parseInt(numbersOne[1]));
    let fracTwo = new fraction(parseInt(numbersTwo[0]), parseInt(numbersTwo[1]));
    let fracThree = new fraction((fracOne.num * fracTwo.den + fracTwo.num * fracOne.den), (fracOne.den * fracTwo.den));
    fracThree = Abb(fracThree);
    if (fracThree.num % fracThree.den == 0) alert(fracTemp1 + " + " + fracTemp2 + " = " + (fracThree.num / fracThree.den));
    else alert(fracTemp1 + " + " + fracTemp2 + " = " + fracThree.num + "/" + fracThree.den);
}
function Abb(fracThree) {
    let minNumber;
    if (fracThree.num > fracThree.den) minNumber = fracThree.den;
    else minNumber = fracThree.num;
    for (let i = minNumber; i >= 2; --i) {
        if (fracThree.num % i == 0 && fracThree.den % i == 0) {
            fracThree.num /= i;
            fracThree.den /= i;
        }
    }
    return fracThree;
}
function task4() {
    let fracTemp1 = prompt("Будь ласка, введіть перший дріб:", "2/3");
    let fracTemp2 = prompt("Будь ласка, введіть другий дріб:", "5/7");
    let numbersOne = fracTemp1.split("/");
    let numbersTwo = fracTemp2.split("/");
    let fracOne = new fraction(parseInt(numbersOne[0]), parseInt(numbersOne[1]));
    let fracTwo = new fraction(parseInt(numbersTwo[0]), parseInt(numbersTwo[1]));
    let fracThree = new fraction((fracOne.num * fracTwo.den - fracTwo.num * fracOne.den), (fracOne.den * fracTwo.den));
    fracThree = Abb(fracThree);
    if (fracThree.num % fracThree.den == 0) alert(fracTemp1 + " - " + fracTemp2 + " = " + (fracThree.num / fracThree.den));
    else alert(fracTemp1 + " - " + fracTemp2 + " = " + fracThree.num + "/" + fracThree.den);
}
function task5() {
    let fracTemp1 = prompt("Будь ласка, введіть перший дріб:", "2/3");
    let fracTemp2 = prompt("Будь ласка, введіть другий дріб:", "5/7");
    let numbersOne = fracTemp1.split("/");
    let numbersTwo = fracTemp2.split("/");
    let fracOne = new fraction(parseInt(numbersOne[0]), parseInt(numbersOne[1]));
    let fracTwo = new fraction(parseInt(numbersTwo[0]), parseInt(numbersTwo[1]));
    let fracThree = new fraction((fracOne.num * fracTwo.num), (fracOne.den * fracTwo.den));
    fracThree = Abb(fracThree);
    if (fracThree.num % fracThree.den == 0) alert(fracTemp1 + " * " + fracTemp2 + " = " + (fracThree.num / fracThree.den));
    else alert(fracTemp1 + " * " + fracTemp2 + " = " + fracThree.num + "/" + fracThree.den);
}
function task6() {
    let fracTemp1 = prompt("Будь ласка, введіть перший дріб:", "2/3");
    let fracTemp2 = prompt("Будь ласка, введіть другий дріб:", "5/7");
    let numbersOne = fracTemp1.split("/");
    let numbersTwo = fracTemp2.split("/");
    let fracOne = new fraction(parseInt(numbersOne[0]), parseInt(numbersOne[1]));
    let fracTwo = new fraction(parseInt(numbersTwo[0]), parseInt(numbersTwo[1]));
    let fracThree = new fraction((fracOne.num * fracTwo.den), (fracOne.den * fracTwo.num));
    fracThree = Abb(fracThree);
    if (fracThree.num % fracThree.den == 0) alert(fracTemp1 + " / " + fracTemp2 + " = " + (fracThree.num / fracThree.den));
    else alert(fracTemp1 + " ÷ " + fracTemp2 + " = " + fracThree.num + "/" + fracThree.den);
}
function task7() {
    let nowTimeTemp = new Date();
    let nowTime = new time(nowTimeTemp.getHours(), nowTimeTemp.getMinutes(), nowTimeTemp.getSeconds());
    let nowTimeStr = "";
    if (nowTime.hour < 10) nowTimeStr += "0";
    nowTimeStr += nowTime.hour + ":";
    if (nowTime.minute < 10) nowTimeStr += "0";
    nowTimeStr += nowTime.minute + ":";
    if (nowTime.second < 10) nowTimeStr += "0";
    nowTimeStr += nowTime.second;
    alert("Зараз: " + nowTimeStr);
}
function task8() {
    let seconds = parseInt(prompt("Будь ласка, введіть скільки ви бажаєте додати секунд до поточного часу:", "120"));
    let nowTimeTemp = new Date();
    let nowTime = new time(nowTimeTemp.getHours(), nowTimeTemp.getMinutes(), nowTimeTemp.getSeconds());
    let secondTemp = nowTime.second + seconds;
    let minuteTemp = nowTime.minute + parseInt(secondTemp / 60);
    let hourTemp = nowTime.hour + parseInt(minuteTemp / 60);
    nowTime.second = secondTemp - parseInt(secondTemp / 60) * 60;
    nowTime.minute = minuteTemp - parseInt(minuteTemp / 60) * 60;
    nowTime.hour = hourTemp;
    nowTime.hour = nowTime.hour - 24 * parseInt(nowTime.hour / 24);
    let nowTimeStr = "";
    if (nowTime.hour < 10) nowTimeStr += "0";
    nowTimeStr += nowTime.hour + ":";
    if (nowTime.minute < 10) nowTimeStr += "0";
    nowTimeStr += nowTime.minute + ":";
    if (nowTime.second < 10) nowTimeStr += "0";
    nowTimeStr += nowTime.second;
    alert("Зараз: " + nowTimeStr);
}
function task9() {
    let minutes = parseInt(prompt("Будь ласка, введіть скільки ви бажаєте додати хвилин до поточного часу:", "55"));
    let nowTimeTemp = new Date();
    let nowTime = new time(nowTimeTemp.getHours(), nowTimeTemp.getMinutes(), nowTimeTemp.getSeconds());
    let minuteTemp = nowTime.minute + minutes;
    let hourTemp = nowTime.hour + parseInt(minuteTemp / 60);
    nowTime.minute = minuteTemp - parseInt(minuteTemp / 60) * 60;
    nowTime.hour = hourTemp;
    nowTime.hour = nowTime.hour - 24 * parseInt(nowTime.hour / 24);
    let nowTimeStr = "";
    if (nowTime.hour < 10) nowTimeStr += "0";
    nowTimeStr += nowTime.hour + ":";
    if (nowTime.minute < 10) nowTimeStr += "0";
    nowTimeStr += nowTime.minute + ":";
    if (nowTime.second < 10) nowTimeStr += "0";
    nowTimeStr += nowTime.second;
    alert("Зараз: " + nowTimeStr);
}
function task10(arrFruits) {
    let hours = parseInt(prompt("Будь ласка, введіть скільки ви бажаєте додати годин до поточного часу:", "1"));
    let nowTimeTemp = new Date();
    let nowTime = new time(nowTimeTemp.getHours(), nowTimeTemp.getMinutes(), nowTimeTemp.getSeconds());
    nowTime.hour += hours;
    nowTime.hour = nowTime.hour - 24 * parseInt(nowTime.hour / 24);
    let nowTimeStr = "";
    if (nowTime.hour < 10) nowTimeStr += "0";
    nowTimeStr += nowTime.hour + ":";
    if (nowTime.minute < 10) nowTimeStr += "0";
    nowTimeStr += nowTime.minute + ":";
    if (nowTime.second < 10) nowTimeStr += "0";
    nowTimeStr += nowTime.second;
    alert("Зараз: " + nowTimeStr);
}


