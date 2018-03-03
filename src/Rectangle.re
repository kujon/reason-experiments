let component = ReasonReact.statelessComponent("Rectangle");

let make = (~x, ~y, ~width, ~height, _children) => {
  let transform = SVGUtils.translateTransform(x, y);
  {
    ...component,
    render: _self =>
      <rect
        width=(width |> string_of_int)
        height=(height |> string_of_int)
        transform
      />
  };
};
