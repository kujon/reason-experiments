let round = value => {
  let floored = floor(value);
  let ceiled = ceil(value);
  abs_float(value -. floored) > abs_float(value -. ceiled) ? ceiled : floored;
};
