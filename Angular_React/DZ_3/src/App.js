import React from "react";
import "./styles.css";
import FootballPlayer, {
  FootballAchievement,
  FootballClub
} from "./Controller";

export default function App() {
  let qInfo = `«Барселона»`;
  let qFullName = "Futbol Club Barcelona";
  let qYear = "1899";
  let qStadium = "Камп Ноу";
  let qPhoto =
    "https://upload.wikimedia.org/wikipedia/uk/thumb/4/47/FC_Barcelona.png/160px-FC_Barcelona.png";
  let qAchievement = "Досягнення:";
  let qChampionOfSpain = `1929, 1944-45, 1947-48, 1948-49, 1951-52, 1952-53, 1958-59, 1959-60, 1973-74, 1984-85, 1990-91, 1991-92, 1992-93, 1993-94, 1997-98, 1998-99, 2004-05, 2005-06, 2008-09, 2009-10, 2010-11, 2012-13, 2014-15, 2015-16, 2017-18, 2018-19`;
  let qSpanishCupWinner = `1910, 1912, 1913, 1920, 1922, 1925, 1926, 1928, 1942, 1951, 1952, 1953, 1957, 1959, 1963, 1968, 1971, 1978, 1981, 1983, 1988, 1990, 1997, 1998, 2009, 2012, 2015, 2016, 2017, 2018`;
  let qSpanishSuperCupWinner = `1983, 1991, 1992, 1994, 1996, 2005, 2006, 2009, 2010, 2011, 2013, 2016, 2018`;
  let qLeagueCupWinner = `1982, 1986`;
  let qFairCupWinner = `1958, 1960, 1966`;
  let qLatinCupWinner = `1949 і 1952`;
  let qChampionsLeagueWinner = `1992, 2006, 2009, 2011, 2015`;
  let qCupWinnersCupWinner = `1979, 1982, 1989, 1997`;
  let qUEFASuperCupWinner = `1992, 1997, 2009, 2011, 2015`;
  let qClubWorldChampion = `2009, 2011, 2015`;
  let qTeam = "Склад команди:";
  var qPlayer = [
    { num: " 1", pos: "ВР", name: "Марк-Андре тер Штеген" },
    { num: "13", pos: "ВР", name: "Нету" },
    { num: " 2", pos: "ЗХ", name: "Нелсон Семеду" },
    { num: " 3", pos: "ЗХ", name: "Жерард Піке" },
    { num: "15", pos: "ЗХ", name: "Клеман Лангле" },
    { num: "18", pos: "ЗХ", name: "Жорді Альба" },
    { num: "20", pos: "ЗХ", name: "Сержі Роберто" },
    { num: "23", pos: "ЗХ", name: "Самюель Умтіті" },
    { num: "24", pos: "ЗХ", name: "Хуніор Фірпо" },
    { num: " 4", pos: "ПЗ", name: "Іван Ракитич" },
    { num: " 5", pos: "ПЗ", name: "Серхіо Бускетс (віце-капітан)" },
    { num: " 8", pos: "ПЗ", name: "Артур Мело" },
    { num: "21", pos: "ПЗ", name: "Френкі де Йонг" },
    { num: "22", pos: "ПЗ", name: "Артуро Відаль" },
    { num: " 9", pos: "НП", name: "Луїс Суарес" },
    { num: "10", pos: "НП", name: "Ліонель Мессі (капітан)" },
    { num: "11", pos: "НП", name: "Усман Дембеле" },
    { num: "17", pos: "НП", name: "Антуан Грізманн" },
    { num: "31", pos: "НП", name: "Ансу Фаті" }
  ];

  return (
    <div className="App">
      <FootballClub
        info={qInfo}
        year={qYear}
        stadium={qStadium}
        fullname={qFullName}
        photo={qPhoto}
      />

      <hr />
      <FootballAchievement
        achievement={qAchievement}
        championOfSpain={qChampionOfSpain}
        spanishCupWinner={qSpanishCupWinner}
        spanishSuperCupWinner={qSpanishSuperCupWinner}
        leagueCupWinner={qLeagueCupWinner}
        fairCupWinner={qFairCupWinner}
        latinCupWinner={qLatinCupWinner}
        championsLeagueWinner={qChampionsLeagueWinner}
        cupWinnersCupWinner={qCupWinnersCupWinner}
        UEFASuperCupWinner={qUEFASuperCupWinner}
        clubWorldChampion={qClubWorldChampion}
      />

      <hr />
      <FootballPlayer team={qTeam} player={qPlayer} />
    </div>
  );
}
