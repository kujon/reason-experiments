let component = ReasonReact.statelessComponent("Curve");

let make = (~data, ~stroke, _children) => {
  let p = SVGUtils.linePath(data);
  {
    ...component,
    render: _self =>
      switch p {
      | Some(d) => <path d fill="none" stroke />
      | None => ReasonReact.nullElement
      }
  };
};
