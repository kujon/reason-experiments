let data = [
  (0.0, 0.0),
  (1.0, 1.0),
  (2.0, 3.0),
  (3.0, 7.0),
  (4.0, 4.0),
  (5.0, (-2.0))
];

ReactDOMRe.renderToElementWithId(
  <Chart
    width=400
    height=400
    padding={top: 10, right: 10, bottom: 10, left: 10}
    data
  />,
  "index"
);
