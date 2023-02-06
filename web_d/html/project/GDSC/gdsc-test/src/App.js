import * as React from 'react';

import './App.css';
// copied from react router dom

// css files from bootstrap
import 'bootstrap/dist/css/bootstrap.min.css';

import {
  BrowserRouter as Router,
  Routes,
  Route,
  // Link
} from "react-router-dom";

//imports 
import Navbar from './components/Navbar';
// import { Home } from './components/Home';
import Home from './pages/homepage'
import About from './pages/aboutpage';
import Contact from './pages/contactpage';
import Events from './pages/eventspage';
import Projects from './pages/projectspage';
import Schedule from './pages/schedulepage';
import Team from './pages/teampage';

function App() {
  return (
    <>
      <Router>
        <Navbar />
        <div>
          <Routes>
            <Route path="/" element={<Home />}>
            </Route>
            <Route path="/about" element={<About />}>
            </Route>
            <Route path="/contact" element={<Contact />}>
            </Route>
            <Route path="/events" element={<Events />}>
            </Route>
            <Route path="/projects" element={<Projects />}>
            </Route>
            <Route path="/schedule" element={<Schedule />}>
            </Route>
            <Route path="/team" element={<Team />}>
            </Route>
          </Routes>
        </div>
      </Router>
    </>
  );
}

export default App;
