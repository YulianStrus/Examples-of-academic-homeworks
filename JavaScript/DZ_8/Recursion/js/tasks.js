function Pow(number, pow) {
    if (pow == 0) return 1;
    if (pow == 1) return number;
    return number * Pow(number, pow - 1);
}
function task1() {
    let number = parseInt(prompt("Будь ласка, введіть число:", 5));
    let pow = parseInt(prompt("Будь ласка, введіть степінь:", 3));
    alert(number + "^" + pow + " = " + Pow(number, pow));
}
function GCD(number1, number2, gcd) {
    if (number1 % gcd == 0 && number2 % gcd == 0)
        return gcd;
    else return GCD(number1, number2, gcd - 1);
}
function task2() {
    let number1 = parseInt(prompt("Будь ласка, введіть перше число:", 12));
    let number2 = parseInt(prompt("Будь ласка, введіть друге степінь:", 36));
    let gcd;
    if (number1 > number2) gcd = number2;
    else gcd = number1;
    alert("Найбільший спільний дільник " + number1 + " і " + number2 + " = " + GCD(number1, number2, gcd));
}
function maxDigit(number, max) {
    if (number > 0) {
        if (number % 10 > max)
            max = number % 10;
        number /= 10;
        tempNumber = parseInt(number);
        return maxDigit(tempNumber, max);
    }
    else return max;
}
function task3() {
    let number = parseInt(prompt("Будь ласка, введіть число:", 43798));
    alert("Найбільша цифра в числі  = " + maxDigit(number, 0));
}
function simpleNumber(number, tempNumber) {
    if (tempNumber > 1) {
        if (number % tempNumber == 0 && tempNumber != 1)
            return false;
        else return simpleNumber(number, tempNumber - 1);
    }
    else return true;
}
function task4() {
    let number = parseInt(prompt("Будь ласка, введіть число:", 7));
    if (simpleNumber(number, number - 1))
        alert("Це просте число!");
    else alert("Це НЕ просте число!");
}
function multiply(number, tempNumber, arrNumbers) {
    if (number > 1) {
        if (number % tempNumber == 0) {
            number /= tempNumber;
            arrNumbers.push(tempNumber);
            return multiply(number, 2, arrNumbers)
        }
        else return multiply(number, tempNumber + 1, arrNumbers);
    }
    else return arrNumbers;
}
function task5() {
    let number = parseInt(prompt("Будь ласка, введіть число:", 18));
    let arrNumbers = [];
    arrNumbers = multiply(number, 2, arrNumbers);
    let arrNumberStr = arrNumbers[0];
    for (let i = 1; i < arrNumbers.length; ++i)
        arrNumberStr += " * " + arrNumbers[i];
    alert("Число " + number + " - множники " + arrNumberStr);
}
function fibonacci(number) {
    if (number > 1)
        return fibonacci(number - 1) + fibonacci(number - 2);
    else return number;
}
function task6() {
    let number = parseInt(prompt("Будь ласка, введіть порядковий номер числа Фібоначчі:", 7));
    alert("Порядковий номер " + number + " - число " + fibonacci(number));
}
