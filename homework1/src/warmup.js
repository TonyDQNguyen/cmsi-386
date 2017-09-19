/* change(amount) takes in a monetery amount argument
and returns an array of most efficient change
in the American coin denomination */
function change(amount) {
  if (amount < 0) {
    throw new RangeError('amount cannot be negative');
  } else if (amount === 0) {
    return [0, 0, 0, 0];
  }
  const result = [];
  let remaining = amount;
  let i = 0;

  [25, 10, 5, 1].forEach((coin) => {
    result[i] = Math.floor(remaining / coin);
    i += 1;
    remaining %= coin;
  });
  return result;
}

/* stripQuotes(string) takes in a string argument
and returns a string with all apostrophes, double quotation marks,
and backslash escape replaced */
function stripQuotes(string) {
  return string.replace(/['"\\']+/g, '');
}

/* scramble(string) takes in a string argument and
returns a random permutation of the string with
each permutation option having equally likely
chances of appearing */
function scramble(string) {
  // split each char in string to an array stringArray
  const stringArray = [...string];
  let j = 0;
  for (let i = 0; i < stringArray.length; i += 1) {
    j = Math.floor(Math.random() * (stringArray.length - i + 1)) + i;
    const temp = stringArray[i];
    stringArray[i] = stringArray[j];
    stringArray[j] = temp;
  }
  return stringArray.join('');
}

function powers(base, limit, callbackFunc) {
  // exponent of the base initializes at 0
  let exponent = 0;
  // iterate until limit is reached
  while (base ** exponent <= limit) {
    callbackFunc(base ** exponent);
    // increment exponent
    exponent += 1;
  }
}

/* powersGenerator is a generator function that takes two arguments
base to raise to an exponent and the limit which is the
maximum value that the function could yield, and yields
a value raised by incrementing power starting from 1 to the limit */
function* powersGenerator(base, limit) {
  // exponent is the power to raise the base initialized at 0
  let exponent = 0;
  // iterate and yield all the raised base until reaching limit
  while (base ** exponent <= limit) {
    yield base ** exponent;
    // iterate exponent to raise as power of base
    exponent += 1;
  }
}
const a = say('Hello');
const b = a('my');

/* say utilizes closure with function add to recursively add the
next string parameter to the overall string until reaching an undefined
parameter in which it outputs the past accumulated string */

function say(string) {
  const arr = [];
  function add(b) {
    if (b === undefined) {
      return arr.join(' ');
    }
    arr.push(b);
    return add;
  }
  return add(string);
}

/* interleave take in an array of values, and more arguments after
the array, and interleave the values with the following arguments
based on the first array argument's length, then append the rest
of the arguments to the output array */
function interleave(...args) {
  // extract first array argument from the parameters
  const arrayInput = args[0];
  // initalize the output array
  const output = [];
  const arrayLength = arrayInput.length;
  // Check for null argument parameters
  if (arrayLength === 0 && args.length === 1) {
    return [];
  } else if (arrayLength === 0 && args.length > 1) {
    return args.slice(1, args.length);
  } else if (arrayLength !== 0 && args.length === 1) {
    return arrayInput;
  }

  // split up the arguments based on the first array's length
  const interleaveArgs = args.slice(1, arrayLength + 1);
  // interleaving the first array parameter with the following values
  for (let i = 0; i < arrayLength; i += 1) {
    output.push(arrayInput[i]);
    if (i < interleaveArgs.length) {
      output.push(interleaveArgs[i]);
    }
  }
  const restArgs = args.slice(arrayLength + 1, args.length);
  if (arrayLength >= args.length - 1) {
    return output;
  }
  return [...output, ...restArgs];
}

function cylinder({ radius = 1, height = 1 }) {
  const surfaceArea = () => 2 * Math.PI * radius * height
    + 2 * Math.PI * radius * radius;
  const volume = () => Math.PI * radius * radius * height;
  const widen = (factor) => { radius *= factor; };
  const stretch = (factor) => { height *= factor; };
  const toString = () => 'Cylinder with radius ${radius} and height ${height}';
  return Object.freeze({
    surfaceArea,
    volume,
    widen,
    stretch,
    toString,
    get radius() { return radius; },
    get height() { return height; },
  });
}


module.exports = {
  change, stripQuotes, scramble, powers, powersGenerator, interleave, say, cylinder,
};
