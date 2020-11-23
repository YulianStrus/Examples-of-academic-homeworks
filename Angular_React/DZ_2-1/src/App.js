import React from "react";
import "./styles.css";

function Quote(props) {
  return (
    <>
      <h1>{props.name}</h1>
      <h3>{props.author}</h3>
      <h3>{props.year}</h3>
      <br />
      <img src={props.photo} alt="img" />
      <br />
      <hr />
      {props.text}
    </>
  );
}

export default function App() {
  let qName = `"Форсаж"`;

  let qAuthor = "Режисер: Він Дізель";

  let qYear = "2001";

  let qPhoto =
    "https://i.pinimg.com/originals/e6/ff/51/e6ff51bd72e6a23d938ca4932f0ae25b.jpg";

  let qText = `«Форсаж» (англ. The Fast and the Furious; 
    — «Швидкі та Люті») — американська Медіафраншиза, 
    що складається на даний момент з восьми повнометражних 
    і двох короткометражних фільмів, 
    випущених з 2001 по 2019. 
    Є найбільш прибутковою франшизою студії Universal 
    — загальні збори всіх частин 
    складають 2,3 млрд доларів.`;

  return (
    <div className="App">
      <Quote
        name={qName}
        author={qAuthor}
        year={qYear}
        photo={qPhoto}
        text={qText}
      />
    </div>
  );
}
