import React from "react";
import "./styles.css";

function Artist() {
  return <h2>Гурт Скрябин </h2>;
}

function Musicians() {
  return (
    <>
      <p>
        Андрій Кузьменко (Кузьма) — вокал
        <br />
        Олексій Зволинський (Зваля) — гітара
        <br />
        Костянтин Сухоносов — клавішні
        <br />
        Костянтин Глітін — бас
        <br />
        Вадим Колісніченко — барабани
      </p>
    </>
  );
}

function Album25() {
  return (
    <>
      <b>«25»</b> <br />
      <small>2014 рік</small>
      <br />
      <img src="https://upload.wikimedia.org/wikipedia/uk/0/03/Skrybin_25.jpg" />
    </>
  );
}

function AlbumDobrjak() {
  return (
    <>
      <b>«Добряк»</b> <br />
      <small>2013 рік</small>
      <br />
      <img src="https://upload.wikimedia.org/wikipedia/uk/e/e3/Dobryak.jpg" />
    </>
  );
}
function AlbumRadioLove() {
  return (
    <>
      <b>«Радіо Любов»</b> <br />
      <small>2012 рік</small>
      <br />
      <img src="https://upload.wikimedia.org/wikipedia/uk/e/e2/Skryabin-radio.jpg" />
    </>
  );
}

function AlbumEvolution() {
  return (
    <>
      <b>«Моя еволюція»</b> <br />
      <small>2009 рік</small>
      <br />
      <img src="https://upload.wikimedia.org/wikipedia/uk/thumb/e/ed/Skr_evol.jpg/250px-Skr_evol.jpg" />
    </>
  );
}

function AlbumGlamur() {
  return (
    <>
      <b>«Гламур»</b> <br />
      <small>2007 рік</small>
      <br />
      <img src="https://upload.wikimedia.org/wikipedia/uk/thumb/d/da/Skr_glamur.jpg/250px-Skr_glamur.jpg" />
    </>
  );
}
function AlbumLove() {
  return (
    <>
      <b>«Про Любов?»</b> <br />
      <small>2006 рік</small>
      <br />
      <img src="https://upload.wikimedia.org/wikipedia/uk/thumb/6/63/Skr_pro_lubov.jpg/250px-Skr_pro_lubov.jpg" />
    </>
  );
}

export default function App() {
  return (
    <div className="App">
      <Artist />
      <p style={{ textAlign: "left" }}>
        {" "}
        <Musicians />
      </p>
      <td>
        <Album25 />
      </td>
      <td>
        <AlbumDobrjak />
      </td>
      <td>
        <AlbumRadioLove />
      </td>
      <tr />
      <td>
        <AlbumEvolution />
      </td>
      <td>
        <AlbumGlamur />
      </td>
      <td>
        <AlbumLove />
      </td>
    </div>
  );
}
