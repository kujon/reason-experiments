let component = ReasonReact.statelessComponent("Rectangle");

let make = (~x, ~y, ~width, ~height, ~fill, _children) => {
  let transform = SVGUtils.translateTransform(x, y);
  {
    ...component,
    render: _self =>
      <rect
        width=(width |> SVGUtils.floatToNumericValue)
        height=(height |> SVGUtils.floatToNumericValue)
        transform
        fill
      />
  };
};
