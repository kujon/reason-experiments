let linear = ((domainMin, domainMax), (rangeMin, rangeMax), value) => {
  let domainSpan = domainMax -. domainMin;
  let rangeSpan = rangeMax -. rangeMin;
  let slope = rangeSpan /. domainSpan;
  let intercept = rangeMax -. slope *. domainMax;
  slope *. value +. intercept;
};
