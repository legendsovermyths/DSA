function isPalindrome(str) {
  var palindromeCheck = str;
  function helperFunc(str_1) {
    if (str_1.length === 0) return "";
    return str_1[str_1.length - 1] + helperFunc(str_1.slice(0, -1));
  }
  str = helperFunc(str);
  if (palindromeCheck === str) return true;
  else return false;
}
