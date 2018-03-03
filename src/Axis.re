let component = ReasonReact.statelessComponent("Axis");

type orientation =
  | X
  | Y;

let domainWidth = ((min, max)) => max -. min;

let calculateTicks = ((min, max), tickCount) => {
  let tickGap = domainWidth((min, max)) /. float_of_int(tickCount);
  FunctionalUtils.range(min, max, tickGap);
};

let make =
    (
      ~orientation,
      ~domain,
      ~length,
      ~scale,
      ~orthogonalScale,
      ~position=0.0,
      ~tickCount=5,
      ~tickSize=6.0,
      ~thickness=1.0,
      ~fill="#777DA7",
      _children
    ) => {
  let (transform, width, height) =
    switch orientation {
    | X => (
        SVGUtils.translateTransform(0.0, position |> orthogonalScale),
        length,
        thickness
      )
    | Y => (
        SVGUtils.translateTransform(position |> orthogonalScale, 0.0),
        thickness,
        length
      )
    };
  let ticks = calculateTicks(domain, tickCount);
  let tickElements =
    List.map(
      t => {
        let (x, y, width, height) =
          switch orientation {
          | X => (
              scale(t) -. thickness /. 2.0,
              -. tickSize /. 2.0,
              thickness,
              tickSize
            )
          | Y => (
              -. tickSize /. 2.0,
              scale(t) -. thickness /. 2.0,
              tickSize,
              thickness
            )
          };
        <Rectangle x y width height key=(t |> string_of_float) fill />;
      },
      ticks
    );
  {
    ...component,
    render: _self =>
      <g transform>
        <g> (tickElements |> Array.of_list |> ReasonReact.arrayToElement) </g>
        <Rectangle x=0.0 y=0.0 width height fill />
      </g>
  };
};
