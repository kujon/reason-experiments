/* FIXME: No recursion. It makes it axceede the maximum call stack. */
let rec range = (min, max, step) =>
  if (min > max) {
    [];
  } else {
    [min, ...range(min +. step, max, step)];
  };
