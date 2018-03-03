type action =
  | Toggle
  | Set(bool);

type state = {on: bool};

let component = ReasonReact.reducerComponent("Toggle");

let make = (~label, _children) => {
  ...component,
  initialState: () => {on: false},
  reducer: (action, state) =>
    switch action {
    | Toggle => ReasonReact.Update({on: ! state.on})
    | Set(value) => ReasonReact.Update({on: value})
    },
  render: self =>
    <button onClick=(_event => self.send(Toggle))>
      (
        ReasonReact.stringToElement(
          label ++ " is " ++ (self.state.on ? "on" : "off")
        )
      )
    </button>
};
