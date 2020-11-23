import React from "react";
import "./styles.css";

let NamePhoto =
  "https://upload.wikimedia.org/wikipedia/commons/thumb/5/5b/POL_Kamieniec_Podolski_COA.svg/110px-POL_Kamieniec_Podolski_COA.svg.png";
let HistoryPhoto =
  "https://upload.wikimedia.org/wikipedia/commons/thumb/3/34/Stephen_B%C3%A1thory_Gate.JPG/170px-Stephen_B%C3%A1thory_Gate.JPG";
export default function Main() {
  return (
    <div>
      <h1>Kamianets-Podilskyi</h1>
      <p>
        <b>Kamianets-Podilskyi</b> (Ukrainian: Ка́м'яне́ць-Поді́льський, Polish:
        Kamieniec Podolski, Romanian: Camenița, Russian: Каменец-Подольский,
        Yiddish: קאמענעץ־פאדאלסק‎) is a city on the Smotrych River in western
        Ukraine, to the north-east of Chernivtsi. Formerly the administrative
        center of the Khmelnytskyi Oblast, the city is now the administrative
        center of the Kamianets-Podilskyi Raion (district) within the
        Khmelnytskyi Oblast (province). The city itself is also designated as a
        separate district within the region.
        <br />
        <br />
        In 1919–1920 during the ongoing Ukrainian–Soviet War, the city had
        officially served as a temporary capital of Ukrainian People's
        Republic.[2]
        <br />
        <br />
        <h2>Name</h2>
        <hr />
        <img class="img1" src={NamePhoto} alt="img" />
        The first part of the city's dual name originates from kamin'
        (Ukrainian: камiнь) or kamen, meaning "stone" in Old Slavic. The second
        part of its name relates to the historic region of Podolia (Ukrainian:
        Подíлля) of which Kamianets-Podilskyi is considered to be the historic
        capital.
        <br />
        Equivalents of the name in other languages are Polish: Kamieniec
        Podolski; Romanian: Camenița Podoliei; Turkish: Kamaniçe; Latin:
        Camenecium; Hungarian: Kamenyeck-Podolszk; Yiddish: קאָמענעץ‎ (Komenets)
        <h2>Geography</h2>
        <hr />
        Kamianets-Podilskyi is located in the southern portion of the
        Khmelnytskyi Oblast, located in the western Ukrainian region of
        Podillia. The Smotrych River, a tributary of the Dniester, flows through
        the city. The total area of the city comprises 27.84 square kilometers
        (10.7 sq mi).[3] The city is located about 101 kilometres (62.8 mi) from
        the oblast's administrative center, Khmelnytskyi.[3]
        <h2>History</h2>
        <hr />
        Several historians consider that a city on this spot was founded by the
        ancient Dacians, who lived in what is now modern Romania, Moldova, and
        portions of Ukraine.[4] Historians write that the founders named the
        settlement Petridava or Klepidava, which originate from the Greek word
        petra or the Latin lapis meaning "stone" and the Dacian dava meaning
        "city".[4][5]
      </p>
    </div>
  );
}
