// Generated by BUCKLESCRIPT VERSION 2.2.2, PLEASE EDIT WITH CARE
'use strict';

var React = require("react");
var Pervasives = require("bs-platform/lib/js/pervasives.js");
var ReasonReact = require("reason-react/src/ReasonReact.js");
var SVGUtils$ReactTemplate = require("./SVGUtils.bs.js");

var component = ReasonReact.statelessComponent("Rectangle");

function make(x, y, width, height, _) {
  var transform = SVGUtils$ReactTemplate.translateTransform(x, y);
  var newrecord = component.slice();
  newrecord[/* render */9] = (function () {
      return React.createElement("rect", {
                  height: Pervasives.string_of_int(height),
                  width: Pervasives.string_of_int(width),
                  transform: transform
                });
    });
  return newrecord;
}

exports.component = component;
exports.make = make;
/* component Not a pure module */