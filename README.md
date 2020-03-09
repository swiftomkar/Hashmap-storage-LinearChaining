# LinearChaining 
## A hash map implementation of Bob Jenkin's hashing technique 
### Introduction

Made this out of curiosity of hash maps and how they store and get back data in ~O(1)! 
The idea is to explore if hashing techniques can be imporved.
### Linear Chaining - Concept

* The idea is to have a hash function eg: hash(key) = key mod n (The one used in this project is different).
* The hash function maps a location on an array.
* Every location on the array is a header to a linked list.
* The data is put into that linked list.

### Algorithm
```
LinearChaining.add(key)
	pos ← hash(key)
	p ← table[pos].head
	while p != null
		if p.key == key
			replace the value
			return
		p = p.next
	end
	table[pos].addStart(key)
end

LinearChaining.find(key)
	pos ← hash(key)
	p ← table[pos].head
	while p != null
		if p.key == key
			return true
		p = p.next
	end
	return false
end

class HashMapLinearChaining
private:
   LinkedList[] table;

```
The hash function is picked up from https://burtleburtle.net/bob/hash/spooky.html

The evaluation was done by loading an english dictionary in the hashmap. The results look good.

Results:
```
192933 - No Collisions
9818 - 1 Collision
314 - 2 Collisions
12 - 3 Collisions
0
0
```
https://burtleburtle.net/bob/ (A lot of interesting things to read here!)
