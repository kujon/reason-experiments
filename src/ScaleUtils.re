let linear = ((domainMin, domainMax), (rangeMin, rangeMax), value) => {
  let domainSpan = domainMax -. domainMin;
  let rangeMaxF = float_of_int(rangeMax);
  let rangeMinF = float_of_int(rangeMin);
  let rangeSpan = rangeMaxF -. rangeMinF;
  let slope = rangeSpan /. domainSpan;
  let intercept = rangeMaxF -. slope *. domainMax;
  int_of_float(slope *. value +. intercept);
};
