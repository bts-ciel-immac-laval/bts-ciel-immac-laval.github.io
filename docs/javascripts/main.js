// fetch('http://api.f11.fr/test').then(function (response) {
// 	// The API call was successful!
// 	return response.json();
// }).then(function (data) {
// 	// This is the JSON from our response
// 	console.log(data);
// }).catch(function (err) {
    
// 	console.warn('Something went wrong.', err);

// });

var objectElts = document.querySelectorAll('object.fullScreenAble');
for (let i = 0; i < objectElts.length; i++ ) {
    objectElts[i].id = 'fullScreenAble_' + i;
    let parent = objectElts[i].parentNode;

    // Container
    let div = document.createElement('div');
    div.classList.add('bts-fullscreen-container');
    parent.insertBefore(div, objectElts[i]);
    div.insertBefore(objectElts[i], null);

    let button = document.createElement('button');
    button.title = "Ouvrir en plein écran";
    button.type = "button";
    button.dataset.target = 'fullScreenAble_' + i;
    button.classList.add('bts-fullscreen-button');
    button.addEventListener('click', function(e) {
        document.getElementById(this.dataset.target).requestFullscreen();
    });
    objectElts[i].parentNode.insertBefore(button, objectElts[i]);
}