// javascript:(function(){viewer.style = 'filter: grayscale(1) invert(1) sepia(1) contrast(75%)';})()	
function applyEffects() {
    const viewer = document.getElementById('viewer');
    viewer.style.filter = 'grayscale(1) invert(1) sepia(1) contrast(75%)';
    console.log("Fxn running.....");
}

document.getElementById('activateBtn').addEventListener('click', applyEffects);
