class Node {
  constructor(val) {
    this.val = val;
    this.next = null;
  }
}
class SinglyLinkedList {
  constructor() {
    this.head = null;
    this.tail = null;
    this.length = 0;
  }
  push(val) {
    var node = new Node(val);
    if (this.head === null) {
      this.head = node;
      this.tail = node;
      this.length += 1;
    } else {
      this.tail.next = node;
      this.tail = node;
      this.length += 1;
    }
  }
  pop() {
    var prev = this.head;
    var curr;
    while (prev.next.next != null) {
      prev = prev.next;
      var curr = prev.next.next;
    }
    this.tail = prev;
    this.tail.next = null;
    this.length -= 1;
    if (this.length === 0) {
      this.head = null;
      this.tail = null;
      length = 0;
    }
    return curr;
  }
  shift() {
    if (this.head == null) return undefined;
    var curr = this.head.val;
    this.head = this.head.next;
    this.length -= 1;
    return curr;
  }
  unshift(val) {
    var newNode = new Node(val);
    newNode.next = this.head;
    this.head = newNode;
    this.length += 1;
  }
  get(val) {
    if (val >= this.length) return undefined;
    var count = 0;
    var newNode = new Node();
    newNode = this.head;
    while (count != val) {
      newNode = newNode.next;
      count += 1;
    }
    return newNode.val;
  }
}
list = new SinglyLinkedList();
list.push(12);
list.push(13);
list.push(14);
list.push(10);
console.log(list);
list.pop();
console.log(list);
list.shift();
console.log(list);
list.unshift(11);
console.log(list);
console.log(list.get(2));
