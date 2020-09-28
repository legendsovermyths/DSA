function sameFrequency(num1, num2) {
  var obj1 = {};
  var obj2 = {};
  while (num1 > 0) {
    tempNum = num1 % 10;

    num1 = Math.floor(num1 / 10);
    if (tempNum in obj1) {
      obj1[tempNum] += 1;
    } else {
      obj1[tempNum] = 1;
    }
  }
  while (num2 > 0) {
    tempNum = num2 % 10;

    num2 = Math.floor(num2 / 10);
    if (tempNum in obj2) {
      obj2[tempNum] += 1;
    } else {
      obj2[tempNum] = 1;
    }
  }
  for (obj in obj1) {
    if (!(obj in obj2)) {
      return false;
    }
    if (obj in obj2) {
      if (obj2[obj] !== obj1[obj]) {
        return false;
      }
    }
  }
  return true;
}
