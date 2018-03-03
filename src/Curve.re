let component = ReasonReact.statelessComponent("Curve");

let make = (~data, _children) => {
  let p = SVGUtils.linePath(data);
  {
    ...component,
    render: _self =>
      switch p {
      | Some(d) => <path d fill="none" stroke="black" />
      | None => ReasonReact.nullElement
      }
  };
};
