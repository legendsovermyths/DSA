function minSubArrayLen(arr, sum) {
  var minLength = Infinity;
  var left = 0;
  var right = 1;
  var length = 0;
  var tempSum = arr[0] + arr[1];
  while (right < arr.length) {
    if (arr[0] == sum) {
      return 1;
    }
    if (tempSum < sum) {
      right += 1;
      tempSum = arr[right] + tempSum;
    }
    if (tempSum >= sum) {
      length = right - left + 1;
      if (length <= minLength) {
        minLength = length;
      }
      tempSum = tempSum - arr[left];
      left += 1;
    }
  }
  if (minLength === Infinity) {
    return 0;
  }
  return minLength;
}
