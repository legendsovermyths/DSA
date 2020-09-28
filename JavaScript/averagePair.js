function averagePair(arr, avg) {
  var left = 0;
  var right = arr.length - 1;
  var tempAvg = 0;
  for (var i = 0; i < arr.length; i++) {
    tempAvg = (arr[left] + arr[right]) / 2;
    if (tempAvg == avg) {
      return true;
    }
    if (tempAvg > avg) {
      right -= 1;
    }
    if (tempAvg < avg) {
      left += 1;
    }
  }
  return false;
}
console.log(averagePair([], 2));
