function maxSubarraySum(arr, consec) {
  var maxSum = 0;
  var tempSum = 0;
  if (consec > arr.length) {
    return null;
  }
  for (var i = 0; i < consec; i++) {
    tempSum += arr[i];
  }
  maxSum = tempSum;
  for (var j = 0; j < arr.length - consec + 1; j++) {
    tempSum = tempSum - arr[j] + arr[j + consec];
    if (tempSum > maxSum) {
      maxSum = tempSum;
    }
  }
  return maxSum;
}
console.log(maxSubarraySum([1, 4, 2, 1, 23, 3, 1, 9, 20], 7));
