let linear = ((domainMin, domainMax), (rangeMin, rangeMax), value) => {
  let domainSpan = domainMax -. domainMin;
  let rangeMaxF = rangeMax;
  let rangeMinF = rangeMin;
  let rangeSpan = rangeMaxF -. rangeMinF;
  let slope = rangeSpan /. domainSpan;
  let intercept = rangeMaxF -. slope *. domainMax;
  slope *. value +. intercept;
};
