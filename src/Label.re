let component = ReasonReact.statelessComponent("Label");

let make = (~x, ~y, children: ReasonReact.reactElement) => {
  ...component,
  render: _self =>
    <text transform=(SVGUtils.translateTransform(x, y))> children </text>
};
