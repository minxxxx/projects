import firebase from 'firebase';

try {
  var config = {
    apiKey: "AIzaSyAwhVc2xm2sVPJJ5WwzYB_5xY4zVsBU_sk",
    authDomain: "social-tech-app.firebaseapp.com",
    databaseURL: "https://social-tech-app.firebaseio.com",
    projectId: "social-tech-app",
    storageBucket: "social-tech-app.appspot.com",
    messagingSenderId: "1063863987369"
  };
} catch(e) {
  console.error("Firebase error occured:", e);
}
firebase.initializeApp(config);

export var firebaseItems = firebase.database().ref().child('items');
export var firebaseAuth = firebase.auth();
export var googleProvider = new firebase.auth.GoogleAuthProvider();
export var facebookProvider = new firebase.auth.FacebookAuthProvider();
export var twitterProvider = new firebase.auth.TwitterAuthProvider();

firebaseAuth.setPersistence(firebase.auth.Auth.Persistence.SESSION);

export default firebase;
