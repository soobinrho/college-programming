// BASICS OF JavaScript
// This file based on Microsoft's JavaScript tutorials.
// Source:
//   https://learn.microsoft.com/en-us/shows/beginners-series-to-javascript/

// ====================
// How to run this file
// ====================
// node js-documentation.js

// ======
// String
// ======
// const sub = "string substitution";
// console.log(`This is a ${sub}`);
// * Single quote and double quote behave the same.
// * However, note that `` is used for ${} substitution.
//   This is called template literals. Also, in template literals,
//   both \n and literal newlines work equally.
// * In template literals, we can also put numerics, such as ${1 + 1}.

// # Concatenation
// const twoStrings = "Hello" + " " + "World!";

// =============
// Logic Control
// =============
// # Equality
// Don't use == because it results in "23" == 23 true.
// Instead, use ===, which checks both the type and the value.
// Likewise, ues !==, not !=.

// # Shorter version of if else statement
// let number = true ? 1 : 0;

// # Loops: for ... of
// const ages = [21, 22, 23];
// for (let age of ages) {
//     console.log(age);
// }

// # Loops: while
// This is the usual while loop.

// # Loops: for
// This is the usual for loop.

// # Functions
// function printMessage (msg) {
//     console.log(msg);
// }

// # Anonymous Functions
// const result = (a, b) => a + b;  // Note that return is implicit here.
// const result2 = (c, d) => {
//     return c + d;
// }
// * Must be either immediately used or assigned to a variable.
// * Anonymous functions can (a) be used as objects, which means they
//   can be assigned to a variable, used as a parameter for other
//   functions, and also be used a return variable. 
// * While regular functions have the `this` reference, anonymous
//   functions don't have the `this` reference.

// ===============
// Data Structures
// ===============
// # Arrays
// let arr0 = [];          // arr1.length = 0
// let arr1 = Array(10);   // arr2.length = 10
// arr1.push(6);           // Add 6 to the end of the array
// arr1.unshift(6)         // Add 6 to the front of the array
// const a = arr1.pop()    // Get the last value and remove it
// const b = arr1.shift()  // Get the first value and remove it

// const arr2 = arr1.concat([10,11]);

// # Objects
// const book = {
//     name: "A Good Book",
//     releaseDate: "2023-03-18",
//     print() {
//         console.log(`${this.name} ${releaseDate}`);
//     }
// }

// # Alternative way of making an object
// const book2 = new Object();
// book2.ratings = 9;
// book2.name = "A Very Good Book";
// book2.doMagic = () => {
//     this.ratings = 10;
// }

// # Accessing objects
//  console.log(book2.ratings);

// # Accessing objects (another way)
// const attributeName = "ratings";
// console.log(book2[attributeName]);

// # JSON (JavaScript Object Notation)
// const bookJSON = JSON.stringify(book);
// * Results in {"name":"A Good Book","releaseDate":"2023-03-18"}

// const bookObject = JSON.parse(bookJSON);
// bookObject.print();

// =====================================
// Asynchronous Programming and Promises
// =====================================
// # Ancient way: Callbacks
// function printHi() {
//     console.log("Hi! 😎");
// }
// setTimeout(printHi, 10000);  // printHi after 10 seconds

// # Promises
// [skipped...]

// # async/await
// async function getSomething() {
//     await getPromise(10000);  // Must be a function that returns a promise
//     return 66;
// }
// const answer = getSomething();

// ========
// Numerics
// ========
// - +-*/% : the usual
// - ++variable : increment
// - --variable : decrement
// - Use the Math Object:
//     console.log(Math.PI);
//     console.log(Math.floor(4.21));

// # String & numbers conversion
// - parseInt(34) : convert to integer
// - parseFloat(23.2) : convert to float
// - (123).toString() : convert to string

// # Time
// const timeNow = new Date();
// * Note that the Date object internally stores time as UTC.
// let timeJanuary = new Date(2023, 0, 19);
// timeJanuary.setFullYear(2023);
// timeJanuary.setMonth(0);
// * Note that the month starts from 0. Only the month does that.
// timeJanuary.setDate(19);
// timeJanuary.setHours(23);
// timeJanuary.setMinutes(13);
// timeJanuary.setSeconds(46);

// ============
// VS Code Tips
// ============
// # TODO Highlight (Extension)
// TODO: and FIXME: become highlighted.

// # Tips
// - Use the vim extension.
// - ctrl + ` : Open / close a shell
// - ctrl + x : Open the extension tab
// - ctrl + w : Close the tab
// - ctrl + , : Open the settings
// - ctrl + tab : Switch to the next tab
// - ctrl + shift + tab : Switch to the next tab (reverse)

// - ctrl + space : Invoke Intellisense
// - ctrl + . : Invoke spellcheck
// - ctrl + j : Go down on the Intellisense list

// - ctrl + shift + . : All functions and objects
// - ctrl + shift + p : Open the command palette
// - [Inside command palette] > : All commands
// - [Inside command palette] # : All functions and objects in the entire project

// For declaring variables, generally use two ways, but 
// use const as much as you can.
//   let a = 1;
//   const b = 2;
// * var is available as well, but it's dangerous as it makes that variable
//   available even above the declaration line, unlike let.

// ==================
// Package Management
// ==================
// npm install <package_name>
// npm install --save-dev <package_name>