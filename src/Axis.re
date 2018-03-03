let component = ReasonReact.statelessComponent("Axis");

type orientation =
  | X
  | Y;

let domainWidth = ((min, max)) => max -. min;

let rec range = (min, max, step) =>
  if (min > max) {
    [];
  } else {
    [min, ...range(min +. step, max, step)];
  };

let calculateTicks = ((min, max), tickCount) => {
  let tickGap = domainWidth((min, max)) /. float_of_int(tickCount);
  range(min, max, tickGap);
};

let make =
    (
      ~orientation,
      ~domain,
      ~tickCount,
      ~length,
      ~tickSize,
      ~thickness,
      ~scale,
      ~referenceScale,
      ~position,
      _children
    ) => {
  let (transform, width, height) =
    switch orientation {
    | X => (
        SVGUtils.translateTransform(0, position |> referenceScale),
        length |> string_of_int,
        thickness |> string_of_int
      )
    | Y => (
        SVGUtils.translateTransform(position |> referenceScale, 0),
        thickness |> string_of_int,
        length |> string_of_int
      )
    };
  let ticks = calculateTicks(domain, tickCount);
  let tickElements =
    List.map(
      t => {
        let (x, y, width, height) =
          switch orientation {
          | X => (
              scale(t) - thickness / 2,
              - tickSize / 2,
              thickness,
              tickSize
            )
          | Y => (
              - tickSize / 2,
              scale(t) - thickness / 2,
              tickSize,
              thickness
            )
          };
        <Rectangle x y width height key=(t |> string_of_float) />;
      },
      ticks
    );
  {
    ...component,
    render: _self =>
      <g transform>
        <g> (tickElements |> Array.of_list |> ReasonReact.arrayToElement) </g>
        <rect width height />
      </g>
  };
};
