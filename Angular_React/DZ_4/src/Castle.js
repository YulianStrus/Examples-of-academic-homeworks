import React from "react";

let CastlePhoto =
  "https://upload.wikimedia.org/wikipedia/commons/thumb/1/10/Zamek_w_Kamie%C5%84cu_Podolskim_2019.jpg/250px-Zamek_w_Kamie%C5%84cu_Podolskim_2019.jpg";

export default function Castle() {
  return (
    <div>
      <h1>{"Kamianets-Podilskyi Castle"}</h1>
      <img class="img1" src={CastlePhoto} alt="img" />
      {
        <p>
          (Ukrainian: Кам'янець-Подільська фортеця; Polish: twierdza w Kamieńcu
          Podolskim; Russian: Каменец-Подольская крепость; Turkish: Kamaniçe
          Kalesi) is a former Ruthenian-Lithuanian[1] castle and a later
          three-part Polish fortress[2][3][4] located in the historic city of
          Kamianets-Podilskyi, Ukraine, in the historic region of Podolia in the
          western part of the country. Its name is attributed to the root word
          kamin', from the Slavic word for stone.
          <br />
          <br />
          Historical accounts date Kamianets-Podilskyi Castle to the early 14th
          century, although recent archaeological evidence has proved human
          existence in the area back to the 12th or 13th century.[5] Initially
          built to protect the bridge connecting the city with the mainland,[6]
          the castle sits on top of a peninsula carved out by the winding
          Smotrych River, forming a natural defense system for
          Kamianets-Podilskyi's historic Old Town neighborhood.
          <br />
          <br />
          Its location on a strategic transport crossroad in Podolia made the
          castle a prime target for foreign invaders, who rebuilt the castle to
          suit their own needs,[7] adding to its multicultural architectural
          diversity. Specifically, the complex consists of the Old Town
          fortified by King Casimir IV, the Old Castle rebuilt by Kings
          Sigismund I and Stephen Báthory, and the New Castle founded by Kings
          Sigismund III and Władysław IV.[2] However, in spite of the many
          architectural and engineering changes to the original structure, the
          castle still forms a coherent architectural design,[8][9] being one of
          the few medieval constructions in modern-day Ukraine that is
          relatively well preserved.[10]
          <br />
          <br />
          Along with the Old Town neighborhood, the castle is listed as part of
          the National Historical-Architectural Sanctuary "Kam'ianets" and the
          National Environmental Park "Podilski Tovtry". The complex is a
          candidate UNESCO World Heritage Site, nominated in 1989 by the
          Ukrainian representatives,[11] and also one of the Seven Wonders of
          Ukraine.[12] Today, Kamianets-Podilskyi Castle is the most recognized
          landmark of the city,[13] serving as an important regional and
          national tourist attraction.
        </p>
      }
    </div>
  );
}
