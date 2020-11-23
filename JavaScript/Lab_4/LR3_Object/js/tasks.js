let rect = {
    "p1": {
        "x": "10",
        "y": "100"
    },
    "p3": {
        "x": "100",
        "y": "20"
    }
}
function task1() {
    alert("Координати прямокутника:\nP1: x = " + rect.p1.x + ", y = " + rect.p1.y + "\nP2: x = " + rect.p3.x + ", y = " + rect.p1.y + "\nP3: x = " + rect.p3.x + ", y = " + rect.p3.y + "\nP4: x = " + rect.p1.x + ", y = " + rect.p3.y);
}
function task2() {
    alert("Ширина прямокутника: " + (parseInt(rect.p3.x) - parseInt(rect.p1.x)));
}
function task3() {
    alert("Висота прямокутника: " + (parseInt(rect.p1.y) - parseInt(rect.p3.y)));
}
function task4() {
    alert("Площа прямокутника: " + ((parseInt(rect.p1.y) - parseInt(rect.p3.y)) * (parseInt(rect.p3.x) - parseInt(rect.p1.x))));
}
function task5() {
    alert("Периметр прямокутника: " + (((parseInt(rect.p1.y) - parseInt(rect.p3.y)) + (parseInt(rect.p3.x) - parseInt(rect.p1.x))) * 2));
}
function task6(xx) {
    alert("Ширина прямокутника: " + ((parseInt(rect.p3.x) - parseInt(rect.p1.x)) + xx));
}
function task7(yy) {
    alert("Висота прямокутника: " + ((parseInt(rect.p1.y) - parseInt(rect.p3.y)) + yy));

}
function task8(xx, yy) {
    alert("Ширина прямокутника: " + ((parseInt(rect.p3.x) - parseInt(rect.p1.x)) + xx) + "\nВисота прямокутника: " + ((parseInt(rect.p1.y) - parseInt(rect.p3.y)) + yy));
}
function task9(xx) {
    alert("Координати прямокутника:\nP1: x = " + (parseInt(rect.p1.x) + xx) + ", y = " + rect.p1.y + "\nP2: x = " + (parseInt(rect.p3.x) + xx) + ", y = " + rect.p1.y + "\nP3: x = " + (parseInt(rect.p3.x) + xx) + ", y = " + rect.p3.y + "\nP4: x = " + (parseInt(rect.p1.x) + xx) + ", y = " + rect.p3.y);

}
function task10(yy) {
    alert("Координати прямокутника:\nP1: x = " + rect.p1.x + ", y = " + (parseInt(rect.p1.y) + yy) + "\nP2: x = " + rect.p3.x + ", y = " + (parseInt(rect.p1.y) + yy) + "\nP3: x = " + rect.p3.x + ", y = " + (parseInt(rect.p3.y) + yy) + "\nP4: x = " + rect.p1.x + ", y = " + (parseInt(rect.p3.y) + yy));
}
function task11(xx,yy) {
    alert("Координати прямокутника:\nP1: x = " + (parseInt(rect.p1.x)+xx) + ", y = " + (parseInt(rect.p1.y) + yy) + "\nP2: x = " + (parseInt(rect.p3.x)+xx) + ", y = " + (parseInt(rect.p1.y) + yy) + "\nP3: x = " + (parseInt(rect.p3.x)+xx) + ", y = " + (parseInt(rect.p3.y) + yy) + "\nP4: x = " + (parseInt(rect.p1.x)+xx) + ", y = " + (parseInt(rect.p3.y) + yy));
}
function task12(xx,yy) {
    if(xx >= parseInt(rect.p1.x) && xx <= parseInt(rect.p3.x) && yy >= parseInt(rect.p3.y) && yy <= parseInt(rect.p1.y))
        alert("Точка в прямокутнику");
        else
        alert("Точка поза межами прямокутника");
}

