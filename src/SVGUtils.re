let translateTransform = (x, y) =>
  "translate(" ++ (x |> string_of_int) ++ ", " ++ (y |> string_of_int) ++ ")";

let lineToSequence =
  List.fold_left(
    (memo, (x, y)) =>
      memo ++ "L" ++ (x |> string_of_int) ++ ", " ++ (y |> string_of_int),
    ""
  );

let linePath = data =>
  switch data {
  | [(startX, startY), ...xs] =>
    Some(
      "M"
      ++ (startX |> string_of_int)
      ++ ","
      ++ (startY |> string_of_int)
      ++ (xs |> lineToSequence)
    )
  | _ => None
  };
