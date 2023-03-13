// Import the functions you need from the SDKs you need
import { initializeApp } from "firebase/app";
import { getAnalytics } from "firebase/analytics";
// TODO: Add SDKs for Firebase products that you want to use
// https://firebase.google.com/docs/web/setup#available-libraries

// Your web app's Firebase configuration
// For Firebase JS SDK v7.20.0 and later, measurementId is optional
const firebaseConfig = {
  apiKey: "AIzaSyB-EfHFzaMlniPO2RaViLmS2_Ibv0VG6Fk",
  authDomain: "testing-95674.firebaseapp.com",
  projectId: "testing-95674",
  storageBucket: "testing-95674.appspot.com",
  messagingSenderId: "602288075192",
  appId: "1:602288075192:web:b2834eb4c2aa04c0331f4d",
  measurementId: "G-3Y5VM0K4NG"
};

// Initialize Firebase
const app = initializeApp(firebaseConfig);
const analytics = getAnalytics(app);