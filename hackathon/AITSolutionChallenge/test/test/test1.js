let p = new Promise((resolve, reject) => {
  let a =2;
  if (a===1){
    resolve('Success')
  } else {
    reject('Reject')
  }
})

p.then((message) => {
  console.log(message);
}).catch ((message) => {
  console.log(message);
})