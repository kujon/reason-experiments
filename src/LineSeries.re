let component = ReasonReact.statelessComponent("LineSeries");

let make = (~xScale, ~yScale, ~data, ~stroke="#D5573B", _children) => {
  let pixels = List.map(((x, y)) => (x |> xScale, y |> yScale), data);
  {...component, render: _self => <g> <Curve data=pixels stroke /> </g>};
};
