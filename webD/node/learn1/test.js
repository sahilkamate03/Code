function* myGenerator() {
    yield 1;
    yield 2;
    yield 3;
}

const gen =myGenerator();

console.log(gen.next());
console.log(gen.next());
console.log(gen.next());
console.log(gen.next());