# JavaScript Cheat Sheet

## Class

```javascript
function ClassName(val) {
    this.val = (val === undefined ? null : val)
}

let myClass = new ClassName(val);
```

## Control flow

```javascript
while (true) {}

for (let i = 0; i < 10; i++) {}

```

## Value Types

```javascript
let array = [1, 2, 3];
```

Int max: `Number.MAX_SAFE_INTEGER`

## Int function

`Math.min(a, b);`

## String function

- `s.length`

## Array

Sort int instead of string:

```javascript
nums.sort(function(a, b) { return a - b; });
```
