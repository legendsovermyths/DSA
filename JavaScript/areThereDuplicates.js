function areThereDuplicates() {
  var obj = {};
  for (let arg in arguments) {
    if (arguments[arg] in obj) {
      obj[arguments[arg]] += 1;
    } else {
      obj[arguments[arg]] = 1;
    }
  }
  for (var ob in obj) {
    if (obj[ob] > 1) {
      return true;
    }
  }
  return false;
}
