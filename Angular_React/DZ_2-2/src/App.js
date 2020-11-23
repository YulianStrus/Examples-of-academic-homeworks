import React from "react";
import "./styles.css";

function Quote(props) {
  return (
    <>
      <h3>{props.name}</h3>
      <h4>tel: {props.tel}</h4>
      <h4>e-mail: {props.email}</h4>
      <br />
      <img src={props.photo} alt="img" width="200" />
      <br />
      {props.text}
    </>
  );
}

export default function App() {
  let qName = `Струсь Юліан Васлильович`;

  let qTel = "+38(067)-986-22-80";

  let qEmail = "stryulvas@ukr.net";

  let qPhoto = "https://tanzolymp.com/images/default-non-user-no-photo-1.jpg";

  let qText = `Особисті якості: 
  Відповідальний, 
  чесний, 
  не конфліктний, 
  посидючий, 
  комунікабельний.`;

  return (
    <div className="App">
      <Quote
        name={qName}
        tel={qTel}
        email={qEmail}
        photo={qPhoto}
        text={qText}
      />
    </div>
  );
}
