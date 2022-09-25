int i = 5;
void main() {
//   variable
  int p = 3;
  var a = 'Sahil is a good boy';
  print('Hello');

//   dict
  Map b = {'s': 1, 'a': 3};

  //  boolean
  bool isDartCool = false;

//   if else condition
  if (isDartCool) {
    print('Hello $isDartCool');
  } else {
    print('bye $isDartCool');
  }

//   loop
  int student = 0;

//   while loop
  while (student < 100) {
    print('Student $student');
    student++;
  }

//   for loop
  for (int i = 0; i <= 10; i++) {
    print(i);
  }

  List sahil = ['h', 'r', 'i'];

  sahil.forEach((element) {
    print(element);
  });
}

// function creation
int sum(int a, int b) {
  return a + b;
}

//   classes and object
class Sahil {
  Sahil() {
    print('sahil kamate');
  }
}
