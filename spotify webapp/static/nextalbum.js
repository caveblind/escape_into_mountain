/** 
 * Beau Albriton
 * CS2300
 * nextalbum.js
 * 
 * Simple javascript script that waits for a button press.
 * 
 * I'm not amazing at javascript. I frankensteined this beast of a function after scouring Stack Overflow and W3 schools
 * https://www.w3schools.com/js/js_htmldom_eventlistener.asp
 * 
 * 
 */



document.addEventListener('DOMContentLoaded', function() {
    var nextButton = document.getElementsByClassName('next')[0]; // Get the first button with class 'next'
    var albums = document.getElementsByClassName('album'); // Get all album elements
    var currentAlbum = 0;

    // Initially hide all albums except the first one
    for (var i = 0; i < albums.length; i++) {
        if (i !== currentAlbum) {
            albums[i].classList.remove('active'); // Ensure other albums are hidden
        }
    }

    // Show the first album initially
    albums[currentAlbum].classList.add('active');

    // Listen for a click on the button
    nextButton.onclick = function() {
        albums[currentAlbum].classList.remove('active'); // Hide current album
        currentAlbum = (currentAlbum + 1) % albums.length; // Go to the next album
        albums[currentAlbum].classList.add('active'); // Show next album
    };
});