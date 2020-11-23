import React from "react";
import { BrowserRouter as Router, Route, Switch, Link } from "react-router-dom";
import "./styles.css";
import Main from "./MainMenu";
import Castle from "./Castle";
import Photo from "./Photo";

function NotFound() {
  return <h2>Not found</h2>;
}
function NavMenu() {
  return (
    <>
      <Link to="/" className="links">
        Main
      </Link>

      <Link to="/castle" className="links">
        Castle
      </Link>

      <Link to="/photo" className="links">
        Photo
      </Link>
    </>
  );
}
export default function App() {
  return (
    <div>
      <Router>
        <div>
          <h1> </h1>
          <NavMenu />
          <Switch>
            <Route exact path="/" component={Main} />
            <Route path="/castle" component={Castle} />
            <Route path="/photo" component={Photo} />
            <Route component={NotFound} />
          </Switch>
        </div>
      </Router>
    </div>
  );
}
