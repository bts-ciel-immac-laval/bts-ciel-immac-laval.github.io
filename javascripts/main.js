fetch('https://redmo.fr/test.php').then(function (response) {
	// The API call was successful!
	return response.json();
}).then(function (data) {
	// This is the JSON from our response
	console.log(data);
}).catch(function (err) {
    
	console.warn('Something went wrong.', err);

});
