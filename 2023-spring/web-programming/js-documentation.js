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

// # Shorter version of if else statement
// let number = true ? 1 : 0;

// # Functions
// function getSomething (input) {output}

// # Anonymous Functions
// const result = (input) => output;
// * Anonymous functions can (a) be used as objects, which means they
//   can be assigned to a variable, used as a parameter for other
//   functions, and also be used a return variable. 
// * While regular functions have the `this` reference, anonymous
//   functions don't have the `this` reference.

// # Objects
// const Book = {
//     name: "A Good Book",
//     releaseDate: "2023-03-18",
//     print() {
//         console.log(`${this.name} ${releaseDate}`);
//     }
// }

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
// let timeJanuary = new Date(2023, 0, 19);
// * Note that the month starts from 0. (January)
// timeJanuary.setFullYear(2023);
// timeJanuary.setMonth(0);
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