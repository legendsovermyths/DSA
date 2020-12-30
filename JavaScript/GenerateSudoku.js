function hello(lst) {
  lst[2] = 2;
}
lst = [1, 4, 5, 6, 7, 8, 9];
lst2 = [...lst];
hello(lst);
console.log(lst2);
