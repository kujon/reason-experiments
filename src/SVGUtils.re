let floatToNumericValue = value =>
  value |> MathUtils.round |> int_of_float |> string_of_int;

let translateTransform = (x, y) =>
  "translate("
  ++ (x |> floatToNumericValue)
  ++ ", "
  ++ (y |> floatToNumericValue)
  ++ ")";

let lineToSequence =
  List.fold_left(
    (memo, (x, y)) =>
      memo
      ++ "L"
      ++ (x |> floatToNumericValue)
      ++ ", "
      ++ (y |> floatToNumericValue),
    ""
  );

let linePath = data =>
  switch data {
  | [(startX, startY), ...xs] =>
    Some(
      "M"
      ++ (startX |> floatToNumericValue)
      ++ ","
      ++ (startY |> floatToNumericValue)
      ++ (xs |> lineToSequence)
    )
  | _ => None
  };
