let component = ReasonReact.statelessComponent("LineSeries");

let make = _children => {
  ...component,
  render: _self => ReasonReact.nullElement
};
