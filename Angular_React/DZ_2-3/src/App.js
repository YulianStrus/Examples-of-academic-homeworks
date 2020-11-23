import React from "react";
import "./styles.css";

class Timer extends React.Component {
  render() {
    return <>{this.props.time}</>;
  }
}

export default function App() {
  let qTime = new Date().toLocaleTimeString();

  return (
    <div className="App">
      <Timer time={qTime} />
    </div>
  );
}
