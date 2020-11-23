let shoppingList = [
    {
        name: "Хліб",
        count: 2,
        buy: true
    },
    {
        name: "Молоко",
        count: 1,
        buy: false
    },
    {
        name: "Вода",
        count: 6,
        buy: true
    },
    {
        name: "Сир",
        count: 3,
        buy: false
    },
]
function fraction(num, den) {
    this.num = num;
    this.den = den;
}
function time(hour, minute, second) {
    this.hour = hour;
    this.minute = minute;
    this.second = second;
}
function task1(shoppingList) {
    shoppingListStr = "Список продуктів:\n";
    let count = 1;
    for (let i = 0; i < shoppingList.length; ++i) {
        if (shoppingList[i].buy == false) {
            shoppingListStr += count + ". " + shoppingList[i].name + " " + shoppingList[i].count + " шт. x\n";
            count++;
        }
    }
    for (let i = 0; i < shoppingList.length; ++i) {
        if (shoppingList[i].buy == true) {
            shoppingListStr += count + ". " + shoppingList[i].name + " " + shoppingList[i].count + " шт. ✓\n";
            count++;
        }
    }
    alert(shoppingListStr);
}
function task2(shoppingList) {
    let product = prompt("Будь ласка, введіть продукт який ви бажаєте добавити:", "Хліб");
    let countProduct = parseInt(prompt("Будь ласка, введіть кількість:", "2"));
    let count = 0;
    for (let i = 0; i < shoppingList.length; ++i) {
        if (shoppingList[i].name.toLowerCase() == product.toLowerCase()) {
            shoppingList[i].count += countProduct;
            count++;
        }
    }
    if (count == 0) {
        let newObj = {};
        newObj.name = product;
        newObj.count = countProduct;
        newObj.buy = false;
        shoppingList.push(newObj);
    }
    task1(shoppingList);
}
function task3(shoppingList) {
    let product = prompt("Будь ласка, введіть продукт який ви бажаєте відмітити:", "Хліб");
    let count = 0;
    for (let i = 0; i < shoppingList.length; ++i) {
        if (shoppingList[i].name.toLowerCase() == product.toLowerCase()) {
            if (shoppingList[i].buy == true) alert(product + " у списку вже відмічений як куплений!");
            else {
                shoppingList[i].buy = true;
                task1(shoppingList);
            }
            count++;
        }
    }
    if (count == 0) alert(product + " відсутній у списку покупок!");
}
let receipt = [
    {
        name: "Молоко",
        count: 1,
        price: 22.47
    },
    {
        name: "Вода",
        count: 6,
        price: 15
    },
    {
        name: "Хліб",
        count: 2,
        price: 11.53
    },
    {
        name: "Сир",
        count: 3,
        price: 57.63
    },
]
function task4(receipt) {
    receiptStr = "Чек:\n";
    let count = 1;
    for (let i = 0; i < receipt.length; ++i) {
        receiptStr += count + ". " + receipt[i].name + "   " + receipt[i].count + "х" + receipt[i].price + "   " + Math.round((receipt[i].count * receipt[i].price) * 100) / 100 + " грн.\n";
        count++;
    }
    alert(receiptStr);
}
function task5(receipt) {
    let sum = 0;
    for (let i = 0; i < receipt.length; ++i) {
        sum += (receipt[i].price * receipt[i].count);
    }
    alert("Сума по чеку: " + Math.round(sum * 100) / 100 + " грн.");
}
function task6(receipt) {
    let max = receipt[0].price * receipt[0].count;
    let maxBuyStr = "";
    for (let i = 1; i < receipt.length; ++i) {
        if (max < (receipt[i].price * receipt[i].count)) max = receipt[i].price * receipt[i].count;
    }
    for (let i = 0; i < receipt.length; ++i) {
        if (max == (receipt[i].price * receipt[i].count)) maxBuyStr += receipt[i].name;
    }
    alert("Найдорожча покупка: " + maxBuyStr + " за " + Math.round(max * 100) / 100 + " грн.");
}
function task7(receipt) {
    let sum = 0;
    let count = 0;
    for (let i = 0; i < receipt.length; ++i) {
        sum += (receipt[i].price * receipt[i].count);
        count += receipt[i].count;
    }
    alert("Середня ціна за товар: " + Math.round(sum / count * 100) / 100 + " грн.");
}
let cssStyle = [
    {
        color: "#8c7d32"
    },
    {
        fontSize: "50px"
    },
    {
        textAlign: "center"
    },
    {
        textDecoration: "underline"
    },
]
let text = "Це працює!!!"
function task8(cssStyle, text) {
    let textDiv = document.querySelector(".task3_div");
    textDiv.style.color = cssStyle[0].color;
    textDiv.style.fontSize = cssStyle[1].fontSize;
    textDiv.style.textAlign = cssStyle[2].textAlign;
    textDiv.style.textDecoration = cssStyle[3].textDecoration;
    textDiv.innerHTML = text;
}
let arrAuditory = [
    {
        name: "Радіофізична",
        count: 18,
        department: "Вищої математики"
    },
    {
        name: "Всесвітньої історії",
        count: 15,
        department: "Історичний"
    },
    {
        name: "Лекційна",
        count: 20,
        department: "Психології"
    },
    {
        name: "Англійської мови",
        count: 10,
        department: "Іноземних мов"
    },
]
function task9(arrAuditory) {
    let auditoryStr = "Список аудиторій:\n";
    let count = 1;
    for (let i = 0; i < arrAuditory.length; ++i) {
        auditoryStr += count + ". Аудиторія: " + arrAuditory[i].name + "\n    Кількість: " + arrAuditory[i].count + "\n    Факультет: " + arrAuditory[i].department + "\n\n";
        count++;
    }
    alert(auditoryStr);
}
function task10(arrAuditory) {
    let auditoryStr = "";
    let count = 0;
    let department = prompt("Будь ласка, введіть факультет:", "Вищої математики");
    for (let i = 0; i < arrAuditory.length; ++i) {
        if (department == arrAuditory[i].department) {
            auditoryStr += "Аудиторія: " + arrAuditory[i].name + "\nКількість: " + arrAuditory[i].count + "\nФакультет: " + arrAuditory[i].department;
            count++;
            break;
        }
    }
    if (count == 0)
        auditoryStr += "Такого факультету немає!";
    alert(auditoryStr);
}
let group = {
    name: "131",
    count: 21,
    department: "Вищої математики"
}
function task11(arrAuditory, group) {
    let auditoryStr = "";
    let count = 0;
    for (let i = 0; i < arrAuditory.length; ++i) {
        if (group.department == arrAuditory[i].department && group.count <= arrAuditory[i].count) {
            auditoryStr += "Група " + group.name + " (" + group.count + " студ.) факультета " + group.department + " може розміститися у власній аудиторії:\n\nАудиторія: " + arrAuditory[i].name + "\nКількість: " + arrAuditory[i].count + "\nФакультет: " + arrAuditory[i].department;
            count++;
            break;
        }
    }
    if (count == 0) {
        for (let i = 0; i < arrAuditory.length; ++i) {
            if (group.count <= arrAuditory[i].count) {
                if (count == 0) auditoryStr += "Група " + group.name + " (" + group.count + " студ.) факультета " + group.department + " може розміститися у аудиторіях інших факультетів:\n\n";
                count++;
                auditoryStr += count + ". Аудиторія: " + arrAuditory[i].name + "\n    Кількість: " + arrAuditory[i].count + "\n    Факультет: " + arrAuditory[i].department + "\n\n";
            }
        }
        if (count == 0) auditoryStr += "На жаль в такій кількості невдається помістити всіх студентів в одній аудиторії!";
    }
    alert(auditoryStr);
}
function task12(arrAuditory) {
    let temp = {};
    let auditorySort = [];
    for (let i = 0; i < arrAuditory.length; ++i) {
       auditorySort[i] = arrAuditory[i]; 
    }
    for (let i = 0; i < auditorySort.length - 1; ++i) {
        for (let k = 0; k < auditorySort.length - i - 1; ++k) {
            if (auditorySort[k].count < auditorySort[k + 1].count) {
                temp = auditorySort[k];
                auditorySort[k] = auditorySort[k + 1];
                auditorySort[k + 1] = temp;
            }
        }
    }
    let auditoryStr = "Список аудиторій за кількістю місць:\n";
    let count = 1;
    for (let i = 0; i < auditorySort.length; ++i) {
        auditoryStr += count + ". Аудиторія: " + auditorySort[i].name + "\n    Кількість: " + auditorySort[i].count + "\n    Факультет: " + auditorySort[i].department + "\n\n";
        count++;
    }
    alert(auditoryStr);
}
function task13(arrAuditory) {
    let temp = {};
    let auditorySort = [];
    for (let i = 0; i < arrAuditory.length; ++i) {
       auditorySort[i] = arrAuditory[i]; 
    }
    for (let i = 0; i < auditorySort.length - 1; ++i) {
        for (let k = 0; k < auditorySort.length - i - 1; ++k) {
            if (auditorySort[k].name.toLowerCase() > auditorySort[k + 1].name.toLowerCase()) {
                temp = auditorySort[k];
                auditorySort[k] = auditorySort[k + 1];
                auditorySort[k + 1] = temp;
            }
        }
    }
    let auditoryStr = "Список аудиторій за назвою:\n";
    let count = 1;
    for (let i = 0; i < auditorySort.length; ++i) {
        auditoryStr += count + ". Аудиторія: " + auditorySort[i].name + "\n    Кількість: " + auditorySort[i].count + "\n    Факультет: " + auditorySort[i].department + "\n\n";
        count++;
    }
    alert(auditoryStr);
}