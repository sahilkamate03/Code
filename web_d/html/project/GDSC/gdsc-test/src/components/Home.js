// import * as React from 'react';
import React from 'react'
// const fourdot = require('./images/fourdot.svg');
// const vector = require('./images/vector.svg');
// const vector1 = require('./images/vector1.svg');
// const threedot = require('./images/threedot.svg');

import fourdot from "../images/fourdot.svg"
import vector from "../images/vector.svg";
import vector1 from "../images/vector1.svg";
import threedot from "../images/threedot.svg";
import rocket from "../images/rocket.svg";
import top_right_corner from "../images/top_right_corner.svg";
import cloud from "../images/cloud.svg";

export const Home = () => {
    return (
        <>
            <div className="div-1">
                <div className="div-5">
                    <img className="img-2" src={fourdot} alt=" " />
                    <div className="div-6">
                        <img className="symbol_button-2" src={vector} alt=" " />
                        <img className="img-3" src={vector1} alt=" " />
                    </div>
                </div>
                <div className="div-7">
                    <button className="button-5">
                        <span className="join_as-1">Join as member</span>
                    </button>
                    <div className="div-8">
                        <img className="img-4" src={threedot} alt=" " />
                        <button className="button-7">
                            <span className="discord-join-2"> Join Discord</span>
                        </button>
                    </div>
                </div>
                <div>
                    <img className="img-5" src={rocket} alt=" " />
                </div>
                <div>
                    <img className="img-6" src={top_right_corner} alt='' />
                </div>
                <div>
                    <img className="img-7" src={cloud} alt=" " />
                </div>
                <span className="classname-3">
                    Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod
                    tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim
                    veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea
                    commodo consequat. Duis aute irure dolor in{" "}
                </span>
            </div>

        </>
    );
};

