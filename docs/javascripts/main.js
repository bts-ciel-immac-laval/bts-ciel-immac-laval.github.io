document.addEventListener("DOMContentLoaded", (event) => {
    // fetch('http://api.f11.fr/test').then(function (response) {
    // 	// The API call was successful!
    // 	return response.json();
    // }).then(function (data) {
    // 	// This is the JSON from our response
    // 	console.log(data);
    // }).catch(function (err) {
        
    // 	console.warn('Something went wrong.', err);

    // });

    /* PDF */
    var imgPDF = document.querySelectorAll('img[src$="pdf" i]');
    window.pdfjsLib.GlobalWorkerOptions.workerSrc = '//cdnjs.cloudflare.com/ajax/libs/pdf.js/4.10.38/pdf.worker.mjs';
    for (let i = 0; i < imgPDF.length; i++) {
        let url = imgPDF[i].src;
        let title = imgPDF[i].alt;
        let parent = imgPDF[i].parentNode;
        
        let div = document.createElement('div');
        div.classList.add('bts-pdf-viewer-container');

        let iframe = document.createElement('iframe');
        iframe.title = title;
        iframe.src = '/javascripts/pdfjs/web/viewer.html?file=' + encodeURI(url);
        iframe.classList.add('bts-pdf-viewer-iframe');
        iframe.id = 'fullScreenAble_' + i;
        div.appendChild(iframe);

        let button = document.createElement('button');
        button.title = "Ouvrir en plein écran";
        button.type = "button";
        button.dataset.target = 'fullScreenAble_' + i;
        button.classList.add('bts-fullscreen-button');
        button.addEventListener('click', function(e) {
            document.getElementById(this.dataset.target).requestFullscreen();
        });
        div.appendChild(button);
        
        parent.insertBefore(div, imgPDF[i]);
        
        imgPDF[i].remove();
    }

    /* Exercices chronométrés */
    var exoChronosSummary = document.querySelectorAll(".exo-chrono > summary");
    if (exoChronosSummary.length > 0) {
        var exoChronos = [];
        var audio = new Audio('/sounds/ding_2.mp3');
        var exoChronoUpdate = function(i) {
            let ellapsedTime = Math.floor((exoChronos[i].end - Date.now()) / 1000);
            let minutes = Math.floor(ellapsedTime / 60);
            let seconds = Math.floor(ellapsedTime - minutes * 60);
            exoChronos[i].span.innerHTML = minutes.toString().padStart(2, '0') + ':' + seconds.toString().padStart(2, '0');
            if (ellapsedTime <= 0) {
                audio.play();
                exoChronos[i].span.classList.add('ellapsed');
                clearInterval(exoChronos[i].timerId);
            }
        }
        for (let i = 0; i < exoChronosSummary.length; i++) {
            let span = exoChronosSummary[i].querySelector("span.chrono");
            let duration = parseInt(span.innerHTML.split(':')[0]);
            exoChronos[i] = { end : 0, duration : duration, span : span, timerId : 0 };
            exoChronosSummary[i].parentNode.dataset.chronoI = i;
            exoChronosSummary[i].addEventListener('click', function(e) {
                let summary = e.target;
                let parent = summary.parentNode;
                let i = parent.dataset.chronoI;
                if (exoChronos[i].end == 0) {
                    parent.classList.add("started");
                    exoChronos[i].end = Date.now() + exoChronos[i].duration * 60000;
                    exoChronos[i].timerId = setInterval(exoChronoUpdate, 1000, i);
                    let solution = parent.querySelector('details.success summary');
                    solution.dataset.chronoI = i;
                    solution.addEventListener('click', function(e) {
                        clearInterval(exoChronos[e.target.dataset.chronoI].timerId);
                    });
                }
            });
        }
    }
});