import React from "react";

class Play extends React.Component {
  render() {
    return (
      <>
        <ul>
          <li>
            {this.props.num} "<b>{this.props.pos}" :</b> {this.props.name}
          </li>
        </ul>
      </>
    );
  }
}

export default class FootballPlayer extends React.Component {
  render() {
    return (
      <>
        <h1>{this.props.team}</h1>
        <p align="left">
          {this.props.player.map(item => (
            <Play {...item} />
          ))}
        </p>
      </>
    );
  }
}

export class FootballClub extends React.Component {
  render() {
    return (
      <>
        <h1>{this.props.info}</h1>
        <p align="left">
          <b>Повна назва: </b>
          {this.props.fullname}
          <br />
          <b>Засновано: </b>
          {this.props.year}
          <br />
          <b>Стадіон: </b>
          {this.props.stadium}
        </p>
        <br />
        <img src={this.props.photo} alt="img" />
      </>
    );
  }
}

export class FootballAchievement extends React.Component {
  render() {
    return (
      <>
        <h1>{this.props.achievement}</h1>
        <p align="left">
          <b>Чемпіон Іспанії: </b>
          {this.props.championOfSpain}
        </p>
        <p align="left">
          <b>Володар кубка Іспанії: </b>
          {this.props.spanishCupWinner}
        </p>
        <p align="left">
          <b>Володар Суперкубка Іспанії: </b>
          {this.props.spanishSuperCupWinner}
        </p>
        <p align="left">
          <b>Володар Кубка ліги: </b>
          {this.props.leagueCupWinner}
        </p>
        <p align="left">
          <b>Володар Кубка ярмарків: </b>
          {this.props.fairCupWinner}
        </p>
        <p align="left">
          <b>Володар Латинського кубка: </b>
          {this.props.latinCupWinner}
        </p>
        <p align="left">
          <b>Переможець Ліги чемпіонів: </b>
          {this.props.championsLeagueWinner}
        </p>
        <p align="left">
          <b>Володар Кубка володарів кубків: </b>
          {this.props.leagueCupWinner}
        </p>
        <p align="left">
          <b>Володар Суперкубка УЄФА: </b>
          {this.props.UEFASuperCupWinner}
        </p>
        <p align="left">
          <b>Клубний чемпіон світу: </b>
          {this.props.clubWorldChampion}
        </p>
      </>
    );
  }
}
