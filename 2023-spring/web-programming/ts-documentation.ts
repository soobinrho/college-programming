/*
=======================================================================
BASICS OF TypeScript
This file is based on TypeScript's official documentation.
Source:
  https://www.typescriptlang.org/docs/handbook
=======================================================================
*/

// ===========================
// How to declare an interface
// ===========================
// interface Person {
//   name: string;
//   age: number;
// }
//
// const person: Person = {
//   name: "Soobin Rho",
//   age: 24
// };
//
// * Note that primitive types include `boolean`, `bigint`, `null`,
//   `number`, `string`, `symbol`, `any`, and `void`.
// * Prefer `interface` over `type`, unless we need the features
//   of `type` specifically.
// * Likewise, prefer `interface` over `class`.

// ===========================
// Specific features of `type`
// ===========================
// type RegistrationStatus = "registered" | "waitlisted" | "none";
// type StatusNumber = 1 | 3 | 5;
// type InputType = string | number;
//
// * This is called unions.

// ==========================
// Unions for parameter types
// ==========================
// function printString(str: string | string[]) {
//   console.log(str);
// }

// ===========================
// Find the type of a variable
// ===========================
// typeof name === "string"
// typeof isName === "boolean"

// =========================
// How to declare `readonly`
// =========================
// interface Person {
//   readonly name: string;
// }

// ===================
// Why use `readonly`?
// ===================
// const arr = [0, 1, 2];
//
// * `arr.push(3)` will give an error, but `arr[0] = -1;` will
//   still work, which is why we need `readonly`.
// * In case of just arrays, we can use `let arr = [1, 2, 3] as const;`.
