let component = ReasonReact.statelessComponent("Chart");

type padding = {
  top: int,
  right: int,
  bottom: int,
  left: int
};

let findDomain =
  List.fold_left(
    ((cMin, cMax), value) => (min(cMin, value), max(cMax, value)),
    (infinity, -. infinity)
  );

let findXAndYDomains = data => (
  data |> List.map(((x, _)) => x) |> findDomain,
  data |> List.map(((_, y)) => y) |> findDomain
);

let make =
    (
      ~width,
      ~height,
      ~padding,
      ~data,
      ~xScale=ScaleUtils.linear,
      ~yScale=ScaleUtils.linear,
      children
    ) => {
  let (canvasWidth, canvasHeight) = (
    width - padding.left - padding.right,
    height - padding.top - padding.bottom
  );
  let (xDomain, yDomain) = findXAndYDomains(data);
  let (xScale, yScale) = (
    xScale(xDomain, (0, canvasWidth)),
    yScale(yDomain, (canvasHeight, 0))
  );
  {
    ...component,
    render: _self =>
      <svg width=(width |> string_of_int) height=(height |> string_of_int)>
        <g transform=(SVGUtils.translateTransform(padding.left, padding.top))>
          (
            children(
              ~xScale,
              ~yScale,
              ~xDomain,
              ~yDomain,
              ~canvasWidth,
              ~canvasHeight,
              ~data
            )
            |> Array.of_list
            |> ReasonReact.arrayToElement
          )
        </g>
      </svg>
  };
};
