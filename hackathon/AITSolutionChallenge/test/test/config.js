// Import the functions you need from the SDKs you need
const { initializeApp } = require("firebase/app");
const {collection, getFirestore, getDocs, setDoc, doc, addDoc} =require("firebase/firestore");

const firebaseConfig = {
  apiKey: "AIzaSyB-EfHFzaMlniPO2RaViLmS2_Ibv0VG6Fk",
  authDomain: "testing-95674.firebaseapp.com",
  projectId: "testing-95674",
  storageBucket: "testing-95674.appspot.com",
  messagingSenderId: "602288075192",
  appId: "1:602288075192:web:90f4ccec099ae0cb331f4d",
  measurementId: "G-BM9YL4FZ34"
};

// Initialize Firebase
const app = initializeApp(firebaseConfig);
const db = getFirestore(app);

const booksRef = collection(db, 'books');
// const cityRef = doc(db, 'cities', 'BJ');

const bookData = {
  'author' : 'Sahil',
  'title' : 'The Notebook',
  'rating' : 5,
  'subscriber' : ['Harsahl', 'Suraj', 'Shanta'],
  'wonOscar' : true
}

addDoc(booksRef, bookData);