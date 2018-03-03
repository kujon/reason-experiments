type action =
  | Randomise;

type coordinates = list((float, float));

type state = {data: coordinates};

let component = ReasonReact.reducerComponent("Demo");

Random.init(0);

let createRandomData = () =>
  FunctionalUtils.range(-10.0, 10.0, 1.0)
  |> List.map(x => (x, Random.float(20.0) -. 10.));

let make = _children => {
  ...component,
  initialState: () => {data: createRandomData()},
  reducer: (action, _state) =>
    switch action {
    | Randomise => ReasonReact.Update({data: createRandomData()})
    },
  render: self =>
    <div>
      <Chart
        width=400
        height=400
        padding={top: 10, right: 10, bottom: 10, left: 10}
        data=self.state.data>
        ...(
             (
               ~xScale,
               ~yScale,
               ~xDomain,
               ~yDomain,
               ~canvasWidth,
               ~canvasHeight,
               ~data
             ) =>
               <>
                 <Axis
                   key="xAxis"
                   orientation=X
                   domain=xDomain
                   length=canvasWidth
                   scale=xScale
                   orthogonalScale=yScale
                 />
                 <Axis
                   key="yAxis"
                   orientation=Y
                   domain=yDomain
                   length=canvasHeight
                   scale=yScale
                   orthogonalScale=xScale
                 />
                 <LineSeries key="lineSeries" data xScale yScale />
               </>
           )
      </Chart>
      <button onClick=(_event => self.send(Randomise))>
        (ReasonReact.stringToElement("Randomise data"))
      </button>
    </div>
};
