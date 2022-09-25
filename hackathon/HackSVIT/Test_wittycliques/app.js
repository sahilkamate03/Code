// set map options
var mylating = { lat: 38.3460, lng: -0.4907 };
var mapOptions = {
    center: mylating,
    zoom: 7,
    mapTypeId: google.maps.MapTypeId.ROADMAP
};

// create map
var map= new google.maps.Map(document.getElementById("googleMap"),mapOptions)